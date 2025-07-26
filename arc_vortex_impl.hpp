#pragma once

#include "arc_vortex.hpp"

namespace vortex
{
	namespace opt
	{
		template<numeric _type>
		shift<_type>::shift(_type x, _type y, _type z) : x(x), y(y), z(z) {}

		template<numeric _type>
		shift<_type> shift<_type>::operator>>(const shift<_type>& _this)
		{
			return shift(x = _this.y, y = _this.z, z = _this.x);
		}
		
		template<numeric _type>
		void shift<_type>::log()
		{
			std::cout << "(" << x << ", " << y << ", " << ")";
		}
		
		// exponentiation
		template<numeric _type>
		expo<_type>::expo(_type x) : x(x) {}

		template<numeric _type>
		_type expo<_type>::operator^(_type exponent)
		{
			return std::pow(x, exponent);
		}
	}
}
