/* encryption/decryption for copie_scr.sh script used on Audi/Volkswagen MMI (Becker/Harman) */
#include <stdio.h>

unsigned int seed = 0x001be3ac;

unsigned int prng_rand() {
	unsigned int r1, r3, r0;
	
	r0 = seed;
	r1 = (seed >> 1) | (seed << 31);
	r3 = ((r1 >> 16) & 0xFF) + r1;
	r1 = ((r3 >> 8) & 0xFF) << 16;
	r3 -= r1;
	seed = r3;
	
	return r0;
}

int main(int argc, char *argv[]) {
	int c;
	
	prng_rand();
	
	c = getchar();
	while (c != EOF) {
		c ^= (prng_rand() & 0xFF);
		putchar(c);
		c = getchar();
	}
}