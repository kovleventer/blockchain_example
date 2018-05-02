#pragma once

#include <string.h>

#include "../external/picosha2.h"


/**
 * @interface Hashable
 * For objects that should have a hashcode
 */
class Hashable {
public:
	/**
	 * Generates the hash code of the object
	 * @return The hash code as a string (encoding is not specified here)
	 */
	virtual std::string hash() const = 0;
	virtual ~Hashable() {} // Not used, should be declared
};
