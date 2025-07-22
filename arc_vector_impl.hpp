#pragma once

#include <iostream>

namespace arc
{
	template<numeric _type>
	vec3<_type>::vec3(_type x, _type y, _type z)
	{
		this->x = x;
		this->y = y;
		this->z = z;

		vec_t = std::make_tuple(this->x, this->y, this->z);
	}

	template<numeric _type>
	void vec3<_type>::logv() { std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl; }

	template<numeric _type>
	_type vec3<_type>::mag() { return x + y + z; }

	template<numeric _type>
	std::tuple<_type, _type, _type> vec3<_type>::get() { return vec_t; }

	template<numeric _type>
	vec2<_type>::vec2(_type x, _type y)
	{
		this->x = x;
		this->y = y;

		vec_t = std::make_tuple(this->x, this->y);
	}

	template<numeric _type>
	void vec2<_type>::logv() { std::cout << "(" << x << ", " << y << ")" << std::endl; }

	template<numeric _type>
	_type vec2<_type>::mag() { return x + y; }

	template<numeric _type>
	std::tuple<_type, _type> vec2<_type>::get() { return vec_t; }

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
	vec3<_type> Add(vec3<_type> v1, vec3<_type> v2)
	{
		vec3<_type> _out = vec3<_type>
			(
				v1.x + v2.x,
				v1.y + v2.y,
				v1.z + v2.z
			);

		return _out;
	}

	template<numeric _type>
	vec3<_type> normalize(vec3<_type> v)
	{
		vec3<_type> _out = vec3<_type>(
			v.x /= abs(v.x),
			v.y /= abs(v.y),
			v.z /= abs(v.z)
		);

		if (isnan(_out.x)) _out.x = 0;
		if (isnan(_out.y)) _out.y = 0;
		if (isnan(_out.z)) _out.z = 0;

		return _out;
	}

	template<numeric _type>
	vec3<_type> negate(vec3<_type> v)
	{
		v.x *= -1;
		v.y *= -1;
		v.z *= -1;

		return v;
	}

	template<numeric _type>
	_type dot_product(vec3<_type> v1, vec3<_type> v2)
	{
		return v1.mag() * v2.mag() * cos(atan2(v1.mag(), v2.mag()));
	}

	template<numeric _type>
	vec3<_type> cross_product(vec3<_type> v1, vec3<_type> v2)
	{
		vec3<_type> _out = vec3<_type>(0.0f, 0.0f, 0.0f);
		_out.x = v1.x * v2.x * sin(atan2(v1.mag(), v2.mag()));
		_out.y = v1.y * v2.y * sin(atan2(v1.mag(), v2.mag()));
		_out.z = v1.z * v2.z * sin(atan2(v1.mag(), v2.mag()));

		return _out;
	}

	// vectors in 2D space
	template<numeric _type>
	vec2<_type> Add(vec2<_type> v1, vec2<_type> v2)
	{
		vec2<_type> _out = vec2<_type>
			(
				v1.x + v2.x,
				v1.y + v2.y
			);

		return _out;
	}

	template<numeric _type>
	vec2<_type> normalize(vec2<_type> v)
	{
		vec2<_type> _out = vec2<_type>(
			v.x /= abs(v.x),
			v.y /= abs(v.y)
		);

		if (isnan(_out.x)) _out.x = 0;
		if (isnan(_out.y)) _out.y = 0;

		return _out;
	}

	template<numeric _type>
	vec2<_type> negate(vec2<_type> v)
	{
		v.x *= -1;
		v.y *= -1;

		return v;
	}

	template<numeric _type>
	 _type dot_product(vec2<_type> v1, vec2<_type> v2)
	{
		return v1.mag() * v2.mag() * cos(atan2(v1.mag(), v2.mag()));
	}

	template<numeric _type>
	vec2<_type> cross_product(vec2<_type> v1, vec2<_type> v2)
	{
		vec2<_type> _out = vec2<_type>(0.0f, 0.0f);
		_out.x = v1.x * v2.x * sin(atan2(v1.mag(), v2.mag()));
		_out.y = v1.y * v2.y * sin(atan2(v1.mag(), v2.mag()));

		return _out;
	}
}
