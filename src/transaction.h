#pragma once

#include <string>
#include <stdexcept>
#include <sstream>

#include "wallet.h"
#include "util.h"
#include "hashable.h"

class Transaction : public Hashable {
public:
	Transaction(std::string sender, std::string target, double amount, std::string timeStamp = Util::timeStamp());
	std::string getSenderKey() const;
	std::string getTargetKey() const;
	double getAmount() const;
	std::string getTimeStamp() const;
	
	std::string hash() const;
private:
	std::string sender, target;
	double amount;
	std::string timeStamp;
};
