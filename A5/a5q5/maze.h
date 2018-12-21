#include <stdbool.h>

// SEASHELL_READONLY

// you MUST use these constants for the directions
extern const int UP;
extern const int DOWN;
extern const int LEFT;
extern const int RIGHT;

struct maze;

// read_maze() reads in a maze from input and returns a pointer 
//   to a new maze structure with the initial position 'S'tart
// effects:  if the maze is invalid, exits the program
struct maze *read_maze(void);

// is_wall(m, direction) determines if there is a wall in the
//   given direction in maze m (based on the current position)
// requires: direction is one of: UP, DOWN, LEFT, RIGHT
bool is_wall(const struct maze *m, int direction);

// moves(m, direction) moves in the given direction in maze m
//   (based on the current position) and prints the direction (U/D/L/R).
//   If the 'E'xit is reached, prints E and then exits the program
// requires: direction is one of: UP, DOWN, LEFT, RIGHT
// effects: modifies the maze *m (to store the new position)
//          displays output
//          if attempting to move through a wall, exits the program
void move(struct maze *m, int direction);
