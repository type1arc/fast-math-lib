#pragma once
#include <concepts>
#include <iostream>

template<typename _type>
concept numeric = std::is_arithmetic_v<_type>;
