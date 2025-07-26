#pragma once

#include <complex>
#include <vector>

// algorithms
namespace algorithm
{
  using Complex = std::complex<float>;
  using c_arr = std::vector<Complex>;

  void fft(c_arr& x);
}

