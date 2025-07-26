#pragma once

#include <tuple>
#include "arc_concepts.hpp"


namespace arc
{
	
	template<numeric _type>
	struct vec3 // For vectors in 3D space
	{
	private:
		std::tuple<_type, _type, _type> vec_t;

	public:
		_type x, y, z;

		vec3(_type x, _type y, _type z);

		void logv();
		_type mag();
		std::tuple<_type, _type, _type> get(); 
	};

	template<numeric _type>
	struct vec2 // For vectors in 2D space
	{
	private:
		std::tuple<_type, _type> vec_t;

	public:
		_type x, y;

		vec2(_type x, _type y);

		void logv();
		_type mag();
		std::tuple<_type, _type> get();
	};

	/*template <numeric _type>
	struct  mat3
	{
	public:
		std::vector<std::vector<_type>> mat;
		mat3(_type diag)
		{
			mat =
			{
				{diag, 0, 0},
				{0, diag, 0},
				{0, 0, diag}
			}; 
		}
		void log_m()
		{
			for (int x = 0; x < mat.size(); x++)
			{
				for (int y = 0; y < mat[x].size(); y++)
				{
					std::cout << mat[x][y] << " ";
				}
				std::cout << std::endl;
			}
		}
	};	*/

	// vectors in 3D space
	template<numeric _type>
	vec3<_type> Add(vec3<_type> v1, vec3<_type> v2);

	template<numeric _type>
	vec3<_type> normalize(vec3<_type> v);
	
	template<numeric _type>
	vec3<_type> negate(vec3<_type> v);
	
	template<numeric _type>
	_type dot_product(vec3<_type> v1, vec3<_type> v2);
	
	template<numeric _type>
	vec3<_type> cross_product(vec3<_type> v1, vec3<_type> v2);

	// vectors in 2D space
	template<numeric _type>
	vec2<_type> Add(vec2<_type> v1, vec2<_type> v2);

	template<numeric _type>
	vec2<_type> normalize(vec2<_type> v);
	
	template<numeric _type>
	vec2<_type> negate(vec2<_type> v);
	

	template<numeric _type>
	_type dot_product(vec2<_type> v1, vec2<_type> v2);
	
	template<numeric _type>
	vec2<_type> cross_product(vec2<_type> v1, vec2<_type> v2);
}

#include "arc_vector_impl.hpp"
