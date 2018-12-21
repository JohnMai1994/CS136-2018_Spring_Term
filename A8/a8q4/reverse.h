// reverse module

// reverse(s) reverses the order of all of the characters in s
// effects: modifies s
void reverse(char *s);

// reverse_words(s) reverses the order of all of the "words" in s
//   where a "word" is any contiguous sequence of non-whitespace chars
//   it also reverses the relative position of all whitespace
// effects: modifies s
// examples: "I am Batman" ==> "Batman am I"
//           "I   am Batman" ==> "Batman am   I"
//           "   ___I <3 Batman___" ==> "Batman___ <3 ___I   "
void reverse_words(char *s);
