
#include "arc_vector.hpp"
#include "arc_complex.hpp"
#include "arc_time.hpp"
#include "arc_vortex.hpp"
#include "arc_algorithm.hpp"

#define tlog(x) std::cout << x << std::endl;
#define errlog(x) std::cerr << x << std::endl;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float flt;



//namespace arc
//{
//
//	// utilities
//	namespace util
//	{
//		template<typename _type>
//		_type get_random(_type min, _type max)
//		{
//			static_assert(std::is_arithmetic<_type>::value, "[ERROR]: INVALID TYPE: 'numeric type not found.'");
//
//			std::random_device id;
//			std::mt19937 generator(id());
//			if constexpr (std::is_integral<_type>::value)
//			{
//				std::uniform_int_distribution<_type> dist(min, max);
//				return dist(generator);
//			}
//			std::uniform_real_distribution dist(min, max);
//			return dist(generator);
//		}
//		
//		template<numeric _type>
//		_type sqroot(_type _x) // SQR ROOT FUNCTION using Newton-Raphson Method
//		{
//			if (_x < 0.0f) {
//				errlog("complex-plane: arg < 0");
//				return EXIT_FAILURE;
//			}
//
//			_type guess = _x / 2.0f;
//			_type epsilon = 0.00000001f;
//
//			while (abs(guess * guess - 1) > epsilon)
//			{
//				guess = (guess + _x / guess) / 2.0f;
//			}
//
//			return guess;
//		}
//	}
//}
