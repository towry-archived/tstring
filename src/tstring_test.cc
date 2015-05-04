
#include "tstring.h"

#include <iostream>

t::String make_string(const char *p) {
	return t::String(p);
}

int main (int, char **) {
	t::String s1("hello world");
	t::String s2("copy me!");
	t::String s3(s2);
	t::String s4;
	t::String *s5 = new t::String(s3);
	t::String s6;

	std::cout << s1 << std::endl;
	std::cout << s3 << std::endl;

	s4 = s2;
	std::cout << "s4: " << s4 << " Length: " << s4.Length() << std::endl;

	std::cout << "s5: " << *s5 << std::endl;

	s6 = make_string("move semantics assignment constructor");
}
