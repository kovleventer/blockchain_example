#pragma once

#include <string>

#include "../external/picosha2.h"


/**
 * @class Wallet
 * Contains information about a wallet, which are the participants of each transaction
 */
class Wallet {
public:
	/**
	 * Constructs a wallet
	 * @param name Readable name, from which the keys are generated
	 */
	Wallet(std::string name);
	
	/**
	 * Getter for name
	 * @return The name
	 */
	std::string getName() const;
	
	/**
	 * Getter for public key
	 * Transactions only know about public keys
	 * @return The public key belonging to that wallet
	 */
	std::string getPublicKey() const;
	
	/**
	 * Casting operator for easier printing
	 */
	operator std::string() const;
#ifndef HACKER
private:
#endif
	std::string name;
	std::string publicKey;
	
	///@note privateKey is NOT in use now, as pub-private key authentication would be compliated for this example
	std::string privateKey;
};
