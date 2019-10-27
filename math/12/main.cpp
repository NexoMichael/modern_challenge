#include<iostream>
#include<array>

#define MAX 1000000

int main() {
	std::cout << "Largest Collatz sequence\n";
	auto max_size = 0;
  auto max_size_value = 0;
	for(auto i = 1; i < MAX; i++) {
		auto val = i;
		auto size = 0;
		while(val > 1) {
			if ((val % 2) == 0)
				val = val / 2;
			else
				val = 3 * val + 1;
			size++;
		}
		if (size > max_size) {
			max_size = size;
			max_size_value = i;
		}

		std::cout << "\rChecked value " << i << " Collatz sequence max size is " << max_size << " for value " << max_size_value;
	}
	std::cout << "\n\n";

	auto val = max_size_value;

	while(val > 1) {
		std::cout << val << " ";
		if ((val % 2) == 0)
			val = val / 2;
		else
			val = 3 * val + 1;
	}
	std::cout << "1\n\n";
}
