#pragma once

#include <tuple>
#include <iostream>
#include "arc_concepts.hpp"

#define iota sqrt(-1)

  // complex numbers - lets see how it goes
  // [UPDATE] turned out pretty good i think
namespace complex_plane
{
	template<numeric _type>
	struct complex
	{
	public:
	  std::tuple<_type, _type> value;
	  _type re_comp, im_comp;
		
	  complex(_type re_comp, _type im_comp);
	  _type iabs(std::tuple<_type, _type>& value);
	  void log();
	};
}

#include "arc_complex_impl.hpp"
