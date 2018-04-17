#pragma once

#include <vector>

#include "block.h"
#include "transaction.h"

class Blockchain {
public:
	Blockchain();
	void addTransaction(Transaction* t);
	bool valid();
	double getMiningReward();
	void mine();
	~Blockchain();
private:
	std::vector<Block*> blocks;
	std::vector<Transaction*> pendingTransactions;
};
