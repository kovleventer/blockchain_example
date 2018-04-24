#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "transaction.h"
#include "hashable.h"

class Block : public Hashable {
public:
	Block(std::vector<Transaction*> transactions, std::string prevHash, int difficulty, std::string timeStamp = Util::timeStamp());
	bool valid() const;
	std::string hash() const;
	int getDifficulty() const;
	std::string getTimeStamp() const;
	std::string getPreviousHash() const;
	void printBlock(std::ostream& os) const;
	
	void mine();
	void setDifficulty(int newDifficulty);
	~Block();
private:
	std::vector<Transaction*> transactions;
	std::string previousHash;
	int difficulty;
	std::string timeStamp;
	int nonce;
};
