#pragma once

#include <string>
#include <stdexcept>
#include <sstream>
#include <iostream>

#include "util.hpp"
#include "hashable.h"

/**
 * @class Transaction
 * Stores a transaction, the sender, the target, and the amount of coin sent
 */
class Transaction : public Hashable {
public:
	/**
	 * Creates an immutable transaction
	 * @param sender The public key of the wallet, which initiated the transaction
	 * @param target The public key of the wallet, to which the coins are sent
	 * @param amount The amount of coin sent through the network (no fees)
	 * @param timeStamp The time where the transaction was created as string
	 */
	Transaction(std::string sender, std::string target, double amount, std::string timeStamp = Util::timeStamp());
	
	/**
	 * Getter for sender
	 * @return The public key of the sender
	 */
	std::string getSenderKey() const;
	
	/**
	 * Getter for target
	 * @return The public key of the target
	 */
	std::string getTargetKey() const;
	
	/**
	 * Getter for amount
	 * @return The amount this transaction consists of
	 */
	double getAmount() const;
	
	/**
	 * Getter for timestamp
	 * @return The timestamp as string
	 */
	std::string getTimeStamp() const;
	
	/**
	 * Prints the transaction infos to an output stream
	 * @param os The output stream to write to
	 */
	void printTransaction(std::ostream& os) const;
	
	
	/**
	 * Gets the hash of the transaction
	 * @return The hash code as hex string
	 */
	std::string hash() const;
#ifndef HACKER
private:
#endif
	std::string sender, target;
	double amount;
	std::string timeStamp;
};
