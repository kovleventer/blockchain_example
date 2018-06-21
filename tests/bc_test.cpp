#define HACKER

#include "../src/blockchain.h"
#include "../src/wallet.h"

#include <iostream>

int main() {
	
	Blockchain b;
	
	Wallet w1 = Wallet("Miner Mike");
	Wallet w2 = Wallet("Rich Richard");
	Wallet w3 = Wallet("Hacker Henry");
	Wallet w4 = Wallet("Blocky Bob");
	
	b.mine(w1);
	b.mine(w1);
	b.mine(w1);
	b.addTransaction(new Transaction(w1, w2, 3));
	b.addTransaction(new Transaction(w1, w4, 1));
	b.mine(w1);
	b.addTransaction(new Transaction(w4, w2, 1));
	b.mine(w3);
	
	
	try {
		b.addTransaction(new Transaction(w3, w2, -10));
	} catch (std::runtime_error e) {
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
	try {
		b.addTransaction(new Transaction(w2, w3, 10));
	} catch (std::runtime_error e) {
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
	
	b.print(std::cout);
	
	std::cout << "Is blockchain valid? " << b.valid() << std::endl;
	
#ifdef HACKER
	//Hacker Henry tweaks some block in the chain
	b.blocks[3]->transactions[0]->amount = 42;
	std::cout << "Is blockchain valid? " << b.valid() << std::endl;
	
	//He remines the block, in order to make his changes valid
	b.blocks[3]->mine();
	std::cout << "Is blockchain valid? " << b.valid() << std::endl;
	
	//In the end he fails to alter the blockchain
#endif
	
	return 0;
}
