#pragma once

#include <string.h>

#include "../external/picosha2.h"

class Hashable {
public:
	virtual std::string hash() const = 0;
};
