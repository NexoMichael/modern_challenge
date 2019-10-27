#include <iostream>

int main() {
	std::cout << "Armstong numbers with 3 digits" << std::endl;

	for(int i = 1; i <= 9; i++)
		for(int j = 0; j <= 9; j++)
			for(int k = 0; k <= 9; k++) {
				int val = i*100 + j*10 + k;
				if (i*i*i + j*j*j + k*k*k == val)
					std::cout << " : " << val << "\n";
			}

	return 0;
}
