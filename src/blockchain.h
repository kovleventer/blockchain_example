#pragma once

#include <vector>
#include <iostream>
#include <string>

#include "block.h"
#include "transaction.h"
#include "util.hpp"

/**
 * @class Blockchain
 * Encapsulates the whole blockchain
 */
class Blockchain {
	Blockchain(const Blockchain&); // Should not be used
public:
	/**
	 * Construct a new an empty blockchain with only a single genesis block in it
	 */
	Blockchain();
	
	/**
	 * Adds a new transaction to the list of pending transactions
	 * @param t The new Transaction to add
	 */
	void addTransaction(Transaction* t);
	
	/**
	 * Validates the whole blockchain
	 * Checks if the blocks itself are validated and that the blocks are chained correctly by their previousHash fields
	 * @return True if the chain is valid
	 */
	bool valid();
	
	/**
	 * Retrieves the mining reward
	 * @note This function is not a getter, in real blockchain systems the reward can scale with the amount of blocks stored in the chain
	 * @return The amount of coin, which a miner recieves for mining a block
	 */
	double getMiningReward();
	
	/**
	 * Creates a new block
	 * Adds all pending transactions to that block
	 * Mines that new blocks and adds that to the end of the chain
	 * Miner reward is added as a new transaction
	 * This ensures, that the list of pendingTransactions won't be empty ever
	 * @param minerKey The public key of the miner
	 */
	void mine(std::string minerKey);
	
	/**
	 * Prints the whole blockchain (each transaction in each block)
	 * @param os The output stream to write into
	 */
	void print(std::ostream& os);
	
	/**
	 * Destructor for blockchain
	 */
	~Blockchain();
#ifndef HACKER
private:
#endif
	std::vector<Block*> blocks;
	std::vector<Transaction*> pendingTransactions;
	int difficulty;
};
