#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "transaction.h"
#include "hashable.h"

/**
 * @class Block
 * Encapsulates zero, one or multiple transactions
 * Each block is linked to the previous one by containing its hash
 * Each block's hash code can be calculated from its properties (timestamp, previous hash and transactions)
 */
class Block : public Hashable {
public:
	/**
	 * Creates a block
	 * @param transactions The list of transactions can not be modified after added to a block
	 * @param prevHash The hash string of the previous block
	 * @param timeStamp When the block was created (timestamp is stored as a string)
	 */
	Block(std::vector<Transaction*> transactions, std::string prevHash, int difficulty, std::string timeStamp = Util::timeStamp());
	
	/**
	 * Checks if the block is valid and mined (proof of work was done)
	 * Implementation: the hash string's first [difficutly] characters must be zero
	 * @return A logical value whether the block is mined already
	 */
	bool valid() const;
	
	/**
	 * Retrieves the block's hash code as a hex string
	 * Implemented by throwing each relevant class field into a stringstream then hashing the resulting string
	 * @return The generated hash
	 */
	std::string hash() const;
	
	/**
	 * Getter for difficulty
	 * Difficult scales exponentally
	 * p = 1 / 16^difficulty, where p is the chance of getting a valid difficulty (assuming hashes are distributed evenly by digits)
	 * @return The difficulty value
	 */
	int getDifficulty() const;
	
	/**
	 * Getter for timestamp (no setter so can not be modified later)
	 * @return The timestamp value
	 */
	std::string getTimeStamp() const;
	
	/**
	 * Getter for previous hash (can not be modified later after set in constructor)
	 * @return The hash value
	 */
	std::string getPreviousHash() const;
	
	/**
	 * Prints a block to an output stream by printing its relevant values
	 * @param os The stream to write into
	 */
	void printBlock(std::ostream& os) const;
	
	/**
	 * Sums all received and sent money within this current block
	 * @param publicKey The public key of the wallet
	 * @return The sum of received money minus the sum of sent money
	 */
	double getProfitOfWallet(std::string publicKey) const;
	
	
	/**
	 * Mines a block
	 * Increments the value of 'nonce', whose only purpose is to alter the hash every time its incremented
	 * Mining is considered successful if it is valid
	 */
	void mine();
	
	/**
	 * Setter for difficulty
	 * @param newDifficulty The new difficulty value
	 */
	void setDifficulty(int newDifficulty);
	
	/**
	 * Destructor for Block
	 */
	~Block();
#ifndef HACKER
private:
#endif
	std::vector<Transaction*> transactions;
	std::string previousHash;
	int difficulty;
	std::string timeStamp;
	int nonce;
};
