#pragma once

#include <chrono>
#include <thread>

namespace arc_time 
{
	std::chrono::system_clock::time_point now()
	{
		return std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
	}

	std::chrono::system_clock::time_point elapsed_init() { return std::chrono::system_clock::now(); } // initial time value
	std::chrono::system_clock::time_point elapsed_final() { return std::chrono::system_clock::now(); } // final time value

	void delay(uint64_t duration)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(duration)); // delay by 100ms
	}

	std::chrono::system_clock::duration elapsed_time(std::chrono::system_clock::time_point _init, std::chrono::system_clock::time_point _final) // calculate elapsed time
	{
		return std::chrono::duration_cast<std::chrono::milliseconds> (_final - _init);
	}

}
