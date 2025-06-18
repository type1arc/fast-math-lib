#include <iostream>
#include <tuple>
#include <math.h>
#include <cmath>
#include <thread>
#include <chrono>
#include <array>
#include <complex>
#include <vector>
#include <concepts>
#include <stdfloat>
#include <numbers>
#include <random>

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

constexpr float pi = std::numbers::pi_v<float>;

namespace arc
{	
	// data structures
	template<typename _type>
	concept numeric = std::is_arithmetic_v<_type>;
	template<numeric _type>
	struct vec3 // For vectors in 3D space
	{
	private:
		std::tuple<_type, _type, _type> vec_t;

	public:
		_type x, y, z;

		vec3<_type>(_type x, _type y, _type z)
		{
			this->x = x;
			this->y = y;
			this->z = z;

			vec_t = std::make_tuple(this->x, this->y, this->z);
		}

		void logv() { std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl; }
		float mag() { return x + y + z; }
		std::tuple<_type, _type, _type> get() { return vec_t; }
	};

	template<numeric _type>
	struct vec2 // For vectors in 2D space
	{
	private:
		std::tuple<float, float> vec_t;

	public:
		float x, y;

		vec2(float x, float y)
		{
			this->x = x;
			this->y = y;

			vec_t = std::make_tuple(this->x, this->y);
		}

		void logv() { std::cout << "(" << x << ", " << y << ")" << std::endl; }
		float mag() { return x + y; }
		std::tuple<float, float> get() { return vec_t; }
	};

	struct mat3
	{
		int const rows = 3;
		int const columns = 3;

		public:
			float mat[3][3];


			mat3(float diag)
			{
				int i = 0;
				int row = 0;


				while (row < 3)
				{
					i++;
					if (i > 2)
					{
						i = 0;
						row++;
					}

					mat[row][i] = 1;

				}
			}
	};

	void logm(float matrix[3][3]) // for logging or printing the matrix into the terminal
	{
		int i = 0;
		int row = 0;

		std::cout << "[mat3]" << std::endl;
		while (row < 3)
		{
			if (i > 2)
			{
				std::cout << std::endl;
				i = 0;
				row++;

				if (row > 2)
					break;
			}

			i++;
			std::cout << matrix[row][i] << " ";
		}
	}

	// operators
	namespace operators
	{
		// vectors in 3D space
		template<numeric _type>
		vec3<_type> Add(vec3<_type> v1, vec3<_type> v2)
		{
			vec3<_type> _out = vec3<_type>
			(
				v1.x + v2.x,
				v1.y + v2.y,
				v1.z + v2.z
			);

			return _out;
		}

		template<numeric _type>
		vec3<_type> normalize(vec3<_type> v)
		{
			vec3<_type> _out = vec3<_type>(
				v.x /= abs(v.x),
				v.y /= abs(v.y),
				v.z /= abs(v.z)
			);

			if (isnan(_out.x)) _out.x = 0;
			if (isnan(_out.y)) _out.y = 0;
			if (isnan(_out.z)) _out.z = 0;

			return _out;
		}

		template<numeric _type>
		vec3<_type> negate(vec3<_type> v)
		{
			v.x *= -1;
			v.y *= -1;
			v.z *= -1;

			return v;
		}

		template<numeric _type>
		float dot_product(vec3<_type> v1, vec3<_type> v2)
		{
			return v1.mag() * v2.mag() * cos(atan2(v1.mag(), v2.mag()));
		}

		template<numeric _type>
		vec3<_type> cross_product(vec3<_type> v1, vec3<_type> v2)
		{
			vec3<_type> _out = vec3<_type>(0.0f, 0.0f, 0.0f);
			_out.x = v1.x * v2.x * sin(atan2(v1.mag(), v2.mag()));
			_out.y = v1.y * v2.y * sin(atan2(v1.mag(), v2.mag()));
			_out.z = v1.z * v2.z * sin(atan2(v1.mag(), v2.mag()));

			return _out;
		}

		// vectors in 2D space
		template<numeric _type>
		vec2<_type> Add(vec2<_type> v1, vec2<_type> v2)
		{
			vec2<_type> _out = vec2<_type>
			(
				v1.x + v2.x,
				v1.y + v2.y
			);

			return _out;
		}

		template<numeric _type>
		vec2<_type> normalize(vec2<_type> v)
		{
			vec2<_type> _out = vec2<_type>(
				v.x /= abs(v.x),
				v.y /= abs(v.y)
			);

			if (isnan(_out.x)) _out.x = 0;
			if (isnan(_out.y)) _out.y = 0;

			return _out;
		}

		template<numeric _type>
		vec2<_type> negate(vec2<_type> v)
		{
			v.x *= -1;
			v.y *= -1;

			return v;
		}

		template<numeric _type>
		float dot_product(vec2<_type> v1, vec2<_type> v2)
		{
			return v1.mag() * v2.mag() * cos(atan2(v1.mag(), v2.mag()));
		}

		template<numeric _type>
		vec2<_type> cross_product(vec2<_type> v1, vec2<_type> v2)
		{
			vec2<_type> _out = vec2<_type>(0.0f, 0.0f);
			_out.x = v1.x * v2.x * sin(atan2(v1.mag(), v2.mag()));
			_out.y = v1.y * v2.y * sin(atan2(v1.mag(), v2.mag()));

			return _out;
		}
	}
	
	// time
	namespace time
	{
		std::chrono::system_clock::time_point now()
		{
			return std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
		}

		std::chrono::system_clock::time_point elapsed_init() { return std::chrono::system_clock::now();	} // initial time value
		std::chrono::system_clock::time_point elapsed_final() {	return std::chrono::system_clock::now(); } // final time value

		void delay()
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100)); // delay by 100ms
		}

		std::chrono::system_clock::duration elapsed_time(std::chrono::system_clock::time_point _init, std::chrono::system_clock::time_point _final) // calculate elapsed time
		{
			return std::chrono::duration_cast<std::chrono::milliseconds> (_final - _init);
		}
	

	// vortex - utilities
	
	namespace vortex // TO DO: ADD MORE
	{
		namespace opt
		{
			template<numeric _type>
			struct shift
			{
			public:
				_type x, y, z;
				shift(_type x, _type y, _type z) : x(x), y(y), z(z) {}
			
				shift operator>>(const shift& ott)
				{
					return shift(x = ott.y, y = ott.z, z = ott.x);
				}
			
				void log()
				{
					std::cout << "(" << x << ", " << y << ", " << ")";
				}
			};

			template<numeric _type>
			struct expo // UPDATED...
			{
				public:
					_type x;
					expo(_type x) : x(x) {}
			
					_type operator^(_type exponent)
					{
						return std::pow(x, exponent);
					}
			};
		}

		template<numeric _type>
		_type sqroot(_type _x) // SQR ROOT FUNCTION using Newton-Raphson Method
		{
			if (_x < 0.0f) {
				errlog("complex-plane: arg < 0");
				return EXIT_FAILURE;
			}

			_type guess = _x / 2.0f;
			_type epsilon = 0.00000001f;

			while (abs(guess * guess - 1) > epsilon)
			{
				guess = (guess + _x / guess) / 2.0f;
			}

			return guess;
		}

		#define iota sqroot(-1)


		// complex numbers - lets see how it goes
		namespace complex_plane
		{
			template<numeric _type>
			struct complex
			{
				public:
					std::tuple<_type, _type> value;
					_type re_comp, im_comp;
					complex(_type re_comp, _type im_comp) : re_comp(re_comp), im_comp(im_comp)
					{
						value = std::make_tuple(re_comp, im_comp);
					}

					_type iabs(std::tuple<_type, _type>& value)
					{
						return sqroot(re_comp * re_comp + im_comp * im_comp);
					}

					void log()
					{
						std::string sign;

						if (std::get<1>(value) > 0)
							sign = "+";
						if (std::get<1>(value) < 0)
							sign = "-";

						std::cout << std::get<0>(value) << sign << std::get<1>(value) << "i" << std::endl;
					}
			};
		}
	}

	// algorithms
	namespace algorithms
	{
		using Complex = std::complex<float>;
		using CArr = std::vector<Complex>;

		void fft(CArr& x) // Fast-Fourier-Transform 
		{
			std::size_t N = x.size();
			if (N <= 1) return;

			CArr even(N / 2), odd(N / 2);
			
			for (size_t i = 0; i < N / 2; ++i)
			{
				even[i] = x[i * 2];
				odd[i] = x[i * 2 + 1];

				fft(even);
				fft(odd);

				for (size_t k = 0; k < N / 2; ++k) {
					Complex t = std::polar<float>(1.0, -2 * pi * k / N) * odd[k];
					x[k] = even[k] + t;
					x[k + N / 2] = even[k] - t;
				}

			}
		}

		template<typename _type>
		_type get_random(_type min, _type max)
		{
			static_assert(std::is_arithmetic<_type>::value, "arithmetic type not found.");

			std::random_device id;
			std::mt19937 generator(id());
			if constexpr (std::is_integral<_type>::value)
			{
				std::uniform_int_distribution<_type> dist(min, max);
				return dist(generator);
			}
			else
			{
				std::uniform_real_distribution dist(min, max);
				return dist(generator);
			}
		}
	}
}