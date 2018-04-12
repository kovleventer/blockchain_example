#pragma once

#include "wallet.h"
#include "util.h"

class Transaction {
public:
	Transaction(Wallet sender, Wallet target, unsigned amount, std::string timeStamp = Util::timeStamp());
	
};
