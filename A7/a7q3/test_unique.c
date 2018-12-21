#include <assert.h>
#include "unique.h"

// an assertion-based test client for unique

int main(void) {
	int len = 3;
	int a[3] = {1, 2, 3};

	assert(distinct(a, len) == true);

	assert(distinct_range(a, len) == true);

	int b[3] = {1, 3};
	assert(missing(b, len) == 2);
}