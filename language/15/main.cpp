#include <iostream>

class IPv4 {
private:
	unsigned char octets[4];

public:
	
	IPv4(): octets{0,0,0,0} {}

	IPv4(unsigned char a, unsigned char b, unsigned char c, unsigned char d): octets{a,b,c,d} {}

	IPv4(unsigned long a): octets{
	  static_cast<unsigned char>((a >> 24) & 0xFF),
		static_cast<unsigned char>((a >> 16) & 0xFF),
		static_cast<unsigned char>((a >> 8) & 0xFF),
		static_cast<unsigned char>(a & 0xFF)
	} {}

	IPv4(IPv4 const& other): octets{other.octets[0], other.octets[1], other.octets[2], other.octets[3]} {}

	IPv4& operator=(IPv4 const& other) {
		for(size_t i=0; i<4; i++)
			octets[i] = other.octets[i];
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const IPv4& address);

	friend std::istream& operator>>(std::istream& is, IPv4& address);
};

std::ostream& operator<<(std::ostream& os, const IPv4& address) {
	os << int(address.octets[0]) << "."
		 << int(address.octets[1]) << "."
		 << int(address.octets[2]) << "."
		 << int(address.octets[3]);
  return os;
}

std::istream& operator>>(std::istream& is, IPv4& address) {
	int o1, o2, o3, o4;
	char d1, d2, d3;
	is >> o1 >> d1 >> o2 >> d2 >> o3 >> d3 >> o4;
	if (d1 == '.' && d2 == '.' && d3 == '.')
		address = IPv4(o1, o2, o3, o4);
	else
		is.setstate(std::ios_base::failbit);
	return is;
}

int main() {
	IPv4 a(127, 0, 0, 1);
	std::cout << a << "\n";

	std::cout << "Enter IPv4: ";
	std::cin >> a;

	std::cout << "Entered: " << a << "\n";

	return 0;
}
