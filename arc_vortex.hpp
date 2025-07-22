#pragma once

#include "arc_concepts.hpp"
#include <iostream>

namespace vortex // TO DO: ADD MORE
{
	namespace opt
	{
		template<numeric _type>
		struct shift
		{
		public:
			_type x, y, z;
			shift(_type x, _type y, _type z);

			shift operator>>(const shift& _this);

			void log();
		};

		template<numeric _type>
		struct expo // UPDATED...
		{
		public:
			_type x;
			expo(_type x);

			_type operator^(_type exponent);
		};
	}
}

#include "arc_vortex_impl.hpp"
