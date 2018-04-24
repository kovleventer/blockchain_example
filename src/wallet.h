#pragma once

#include <string>

#include "../external/picosha2.h"

class Wallet {
public:
	Wallet(std::string name);
	std::string getName() const;
	std::string getPublicKey() const;
	operator std::string() const;
private:
	std::string name;
	std::string publicKey;
	std::string privateKey;
};
