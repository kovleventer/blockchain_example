#pragma once

#include "block.h"
#include "transaction.h"

class Blockchain {
public:
	Blockchain();
	//Blockchain(const Blockchain& b);
	//Blockchain& operator=(const Blockchain& b);
	
	void addTransaction(Transaction t);
	
	bool validate();
private:
	std::vector<Block> blocks;
};
