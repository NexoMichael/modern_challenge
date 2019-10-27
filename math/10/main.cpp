#include <iostream>
#include <bitset>
#include <math.h>

#define MAX_BITS 5

unsigned long long graycode(unsigned long long bin) {
	return bin ^ (bin >> 1);
}

unsigned long long to_bin(unsigned long long gc) {
	unsigned long long bin;
	for(bin = 0; gc > 0; gc = gc >> 1)
		bin ^= gc;
	return bin;
}

int main() {
  std::cout << "10. Gray code\n";

	unsigned long long max = pow(2,MAX_BITS);

	for(unsigned long long i = 0; i < max ; i++) {
		std::bitset<MAX_BITS> bs(i);
		std::bitset<MAX_BITS> gc(graycode(i));
  	std::bitset<MAX_BITS> gc2bs(to_bin(graycode(i)));

		std::cout << i << ": " << bs << " " << gc << " " << gc2bs <<  "\n";
  }
	return 0;
}
