#include "arc.hpp"

void main()
{
	arc::mat3<float> matrix = arc::mat3<float>(1.0f);
	matrix.log_m();

	std::cin.get();
	exit(1);
}