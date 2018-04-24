#pragma once

#include <vector>
#include <iostream>
#include <string>

#include "block.h"
#include "transaction.h"
#include "util.hpp"

class Blockchain {
public:
	Blockchain();
	void addTransaction(Transaction* t);
	bool valid();
	double getMiningReward();
	void mine(std::string minerKey);
	void print(std::ostream& os);
	~Blockchain();
private:
	std::vector<Block*> blocks;
	std::vector<Transaction*> pendingTransactions;
	int difficulty;
};
