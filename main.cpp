#include "arc.hpp"

void main()
{
	arc::vec3<float> x = arc::vec3(1.0f, 1.0f, 1.0f);
	arc::vec3<float> y = arc::vec3(0.5f, 0.5f, 0.5f);

	float dot = arc::dot_product(x, y);
	arc::vec3<float> cross = arc::cross_product<float>(x, y);

	std::cin.get();
	exit(1);
}
