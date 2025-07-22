#pragma once
#include <concepts>

template<typename _type>
concept numeric = std::is_arithmetic_v<_type>;