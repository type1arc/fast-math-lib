#include "arc_vector.hpp"

int main()
{
  arc::vec3<float> v1 = arc::vec3(1.0f, 1.0f, 1.0f);
  std::cout << arc::dot_product(v1, arc::negate(v1)) << std::endl;

  std::cout << "test" << std::endl;

  v1.logv();

	exit(1);
}
