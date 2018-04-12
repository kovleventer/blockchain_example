#pragma once

#include <string.h>

class Hashable {
public:
	virtual std::string hash() = 0;
};
