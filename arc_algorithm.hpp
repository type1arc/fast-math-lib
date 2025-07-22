#pragma once

#include "arc_complex.hpp"
#include <complex>

// algorithms
namespace algorithm
{
  using Complex = std::complex<float>;
  using c_arr = std::vector<Complex>;

  void fft(c_arr& x);
}

#include "arc_algorithm_impl.hpp"
