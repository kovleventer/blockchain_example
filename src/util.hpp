#pragma once

#include <string>
#include <sstream>
#include <vector>

/**
 * @namespace Util
 * Contains various utility functions which are not strictly related to each other.
 */
namespace Util {

/**
 * Gets the current timestamp in a string format
 * @return The timestamp
 */ 
std::string timeStamp();


/**
 * Deletes all elements from a vector of pointers
 * Also removes those tangling deleted pointers from the vector
 * @param v The vector to clear
 */
template<typename Vector>
void clearPointerVector(Vector& v) {
	while (!v.empty()) {
		delete v.back();
		v.pop_back();
	}
	v.clear();
}

}
