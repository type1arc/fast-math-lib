#pragma once

#include "arc_constants.hpp"
#include "arc_algorithm.hpp"

namespace algorithm
{
	void fft(c_arr& x) // Fast-Fourier-Transform 
	{
		std::size_t N = x.size();
		if (N <= 1) return;

		c_arr even(N / 2), odd(N / 2);

		for (size_t i = 0; i < N / 2; ++i)
		{
		  even[i] = x[i * 2];
		  odd[i] = x[i * 2 + 1];

		  fft(even);
		  fft(odd);

		  for (size_t k = 0; k < N / 2; ++k) 
		  {
			Complex t = std::polar<float>(1.0, -2 * constants::pi * k / N) * odd[k];
			x[k] = even[k] + t;
			x[k + N / 2] = even[k] - t;
		  }

		}
	}

}
