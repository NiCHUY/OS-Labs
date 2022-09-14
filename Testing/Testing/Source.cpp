#include <iostream>
#include "Vector.h"

int main() {
	vector::Vector abb(Number::Number(2), Number::Number(4));
	std::cout << abb.GetAngle();
}