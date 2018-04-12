#pragma once

#include "wallet.h"

class Block : public Hashable {
public:
	Block();
	bool valid(int difficulty);
private:
	bool sealed;
	int nonce;
	std::vector<Transaction> transactions;
};
