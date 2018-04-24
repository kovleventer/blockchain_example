#include "../src/blockchain.h"
#include "../src/wallet.h"

#include <iostream>

int main() {
	
	Blockchain b;
	
	Wallet w1 = Wallet("Miner Mike");
	Wallet w2 = Wallet("Rich Richard");
	Wallet w3 = Wallet("Hacker Henry");
	
	b.mine(w1);
	b.mine(w1);
	b.mine(w1);
	b.addTransaction(new Transaction(w1, w2, 1));
	b.addTransaction(new Transaction(w3, w2, 10));
	
	b.print(std::cout);
	
	return 0;
}
