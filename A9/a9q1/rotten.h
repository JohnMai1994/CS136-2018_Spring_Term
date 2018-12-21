#include <stdbool.h>
#include <string.h>
#include "cs136-trace.h"

// is_fresh (review, review_length, positive, num_positive, negative,
// num_negative) calculates the number of positive and negative
// words used in the review; if there are no negative words or the 
// number of positive words is at least twice the number of negatives, 
// then it returns true.
// time:  O(nm), where m is the number of words in the review and n
//        is the total number of negative and positive words
bool is_fresh (char *review[],   const int review_length, 
               char *positive[], const int num_positive, 
               char *negative[], const int num_negative);
