#include "util.hpp"

namespace Util {
	
std::string timeStamp() {
	time_t currentTime = time(0);
	tm timeStruct;
	#if (defined(WIN32)  || defined(_WIN32) ||defined (__WIN32__))
		localtime_s(&timeStruct, &currentTime);
	#else
		localtime_r(&currentTime, &timeStruct);
	#endif
	std::stringstream timeString;
	timeString << (timeStruct.tm_year + 1900)
		<< "-"
		<< (timeStruct.tm_mon + 1)
		<< "-"
		<< (timeStruct.tm_mday)
		<< "-"
		<< (timeStruct.tm_hour)
		<< ":"
		<< (timeStruct.tm_min)
		<< ":"
		<< (timeStruct.tm_sec);
	return timeString.str();
}

}
