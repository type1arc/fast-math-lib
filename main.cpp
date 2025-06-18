#include "arc.hpp"

void main()
{
	arc::vec3<float> v1 = arc::vec3<float>(1.0f, 1.0f, 1.0f);
	arc::vec3<float> v2 = arc::vec3<float>(-1.0f, 1.0f, -1.0f);

	float dot = arc::operators::dot_product<float>(v1, v2);
	arc::vec3<float> cross = arc::operators::cross_product(v1, v2);

	arc::mat3 matrix = arc::mat3(1.0f); // creating the matrix
	arc::logm(matrix.mat); // logging the matrix in tabular form


	std::cin.get();
	exit(1);
}