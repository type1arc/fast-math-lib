#include "arc.hpp"

void main()
{
	arc::mat3<float> matrix = arc::mat3<float>(1.0f);
	matrix.log_m();

	std::vector<arc::algorithms::Complex> time_signal(8); 

	time_signal[0] = 1.0f;											 
	for (int n = 1; n < 8; n++)
		time_signal[n] = 0.0f;

	arc::algorithms::fft(time_signal);								
	
	for (int n = 0; n < 8; n++)
		std::cout << std::abs(time_signal[n]) << " ";	

	std::cin.get();
	exit(1);
}
