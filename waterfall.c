/* autotest.c */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

const unsigned int blockSize = BLOCK_SIZE;

void process(uint8_t* p) {
	for (size_t i = 0; i < BLOCK_SIZE / 2; ++i) {
		if (p[i]) {
			p[i] = 0;
			break;
		}
	}

	for (size_t i = BLOCK_SIZE; i > BLOCK_SIZE / 2; --i) {
		if (p[i]) {
			p[i] = 0;
			break;
		}
	}
}

int main(void) {
	assert(BLOCK_SIZE % 2);
	uint8_t* p = malloc(BLOCK_SIZE);
	memset(p, 0xff, BLOCK_SIZE);

	for (size_t i = 0; i <= BLOCK_SIZE / 2; ++i)
		process(p);

	return 0;
}
