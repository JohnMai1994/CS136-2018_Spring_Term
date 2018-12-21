// A module for working with phonetic alphabets

// see assignment for more details

// speak_io(s) displays the string msg using the given alphabet
// requires: alphabet[0] is not NULL
// effects:  displays output
// time:     O(???)
void speak_io(const char *msg, const char *alphabet[]);


// speak_str(s) is similar to speak_io, except that it modifies the
//   string s to store the result intead of printing it out.
//   If the maxlen of s would be exceeded, the result is truncated so the
//   strlen of s is exactly maxlen
// requires: alphabet[0] is not NULL
//           length of s is at least maxlen + 1
// effects:  modifies s
// time:     O(???)
void speak_str(const char *msg, const char *alphabet[], char *s, int maxlen);
