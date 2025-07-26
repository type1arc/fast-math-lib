#pragma once

#include <iostream>
#include "arc_complex.hpp"

namespace complex_plane
{
	template<numeric _type>
	complex<_type>::complex(_type re_comp, _type im_comp) : re_comp(re_comp), 
													 im_comp(im_comp), 
													 value(std::make_tuple(re_comp, im_comp))
	{}

	template<numeric _type>
	_type complex<_type>::iabs(std::tuple<_type, _type>& value)
	{
		return sqroot(re_comp * re_comp + im_comp * im_comp);
    }

	template<numeric _type>
	void complex<_type>::log()
      {
        std::string sign;

        if (std::get<1>(value) > 0)
          sign = "+";
        if (std::get<1>(value) < 0)
          sign = "-";
        std::cout << std::get<0>(value) << sign << std::get<1>(value) << "i" << std::endl;
      }

} 
