/////////////////////////////////////////////////////////////////////////////
// INTEGRITY INSTRUCTIONS

// Explicitly state the level of collaboration on this question
// Examples:
//   * I discussed ideas with classmate(s) [include name(s)]
//   * I worked together with classmate(s) in the lab [include name(s)]
//   * Classmate [include name] helped me debug my code
//   * I consulted website [include url]
//   * None
// A "None" indicates you completed this question entirely by yourself
// (or with assistance from course staff)
/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT:
// I received help from the following sources:

// None

// Name: Jiadong Mai
// login ID: j4mai
/////////////////////////////////////////////////////////////////////////////

#include "cs136.h"

///////////////////////////////////
/// DO NOT MODIFY THESE DEFINITIONS:

struct clickers {
  int correct;
  int wrong;
  int absent;
};
// requires: correct, wrong, absent >= 0
//           correct + wrong + absent >= 2

struct grades {
  struct clickers participation;
  int assignments;
  int midterm;
  int final;
};
// requires: 0 <= assignments, midterm, final <= 100

///////////////////////////////////

// participation(c) returns the participation grade for a student in CS 136
// requires: correct, wrong, absent >= 0
//           correct + wrong + absent >= 2
int participation(struct clickers c) {
  int total_question = c.correct + c.wrong + c.absent;
  int best_75 = total_question * 75 / 100;
  
  if (best_75 <= c.correct) {
    return 100;
  } else {
    int participation_grade = c.correct *100 / best_75;
    return participation_grade;
  }
}

// final_grade(g) returns a final cs136 grade from each of the components, 
//   participation, assignments, midterm and final.
// requries: correct, wrong, absent >= 0
//           correct + wrong + absent >= 2
//           midterm, assignments, final >= 0
int final_grade(struct grades g) {
  int participation_grade = (participation(g.participation)*5);
  int assignments_grade = (g.assignments * 20);
  int midterm_grade = (g.midterm * 25);
  int finals_grade = (g.final * 50);
  int grade = (participation_grade + assignments_grade + midterm_grade + 
    finals_grade)/100;
  return grade;
}

// adjusted_final_grade(g) calculates the same grade as final_grade, except one
//    of the assignment or weighted exam portion low than 50% grade. 
// requries: correct, wrong, absent >= 0
//           correct + wrong + absent >= 2
//           midterm, assignments, final >= 0
int adjusted_final_grade(struct grades g) {
  int exam_portion = (g.midterm * 25 + g.final * 50) / 75;
  if (g.assignments < 50){
    if (final_grade(g) >= 46) {
      return 46;
    } else {
      return final_grade(g);
    }
  }
  if (exam_portion < 50) {
    if (final_grade(g) >= 46) {
      return 46;
    } else {
      return final_grade(g);
    }
  }
  return final_grade(g);
}

int main(void) {
  struct clickers perfect_clickers = {100, 0, 0};
  struct grades perfect = {perfect_clickers, 100, 100, 100};
  
  
  assert(participation(perfect_clickers) == 100);
  assert(final_grade(perfect) == 100);
  assert(adjusted_final_grade(perfect) == 100);
  
  // student tests
  struct clickers a = {50, 83, 0};
  struct grades b = {a, 0, 50, 0};
  assert(participation(a) == 50);
  assert(final_grade(b) == 15);
  assert(adjusted_final_grade(b)== 15);
  
  struct clickers c = {0, 50, 50};
  struct grades d = {c, 50,50,50};
  assert(participation(c)==0);
  assert(final_grade(d)== 47);
  assert(adjusted_final_grade(d) == 47);
  
  d.midterm = 49;
  assert(final_grade(d)== 47);
  assert(adjusted_final_grade(d) == 46);
  
  struct clickers e = {1,0,1};
  struct grades f = {e,0,0,0};
  assert(participation(e)== 100);
  assert(final_grade(f)== 5);
  assert(adjusted_final_grade(f) == 5);
  
}
