#include "blockchain.h"

Blockchain::Blockchain() : difficulty(2) {
	blocks.push_back(new Block(std::vector<Transaction*>(), "", difficulty));
}

void Blockchain::addTransaction(Transaction* t) {
	if (t->getAmount() < 0) {
		delete t;
		throw std::runtime_error("Transaction amount can not be negative");
	}
	
	//Check if user has enugh $
	std::string sender = t->getSenderKey();
	double money = 0;
	for (size_t i = 0; i < blocks.size(); i++) {
		money += blocks[i]->getProfitOfWallet(sender);
	}
	for (size_t i = 0; i < pendingTransactions.size(); i++) {
		if (pendingTransactions[i]->getSenderKey() == sender) {
			money -= pendingTransactions[i]->getAmount();
		}
		if (pendingTransactions[i]->getTargetKey() == sender) {
			money += pendingTransactions[i]->getAmount();
		}
	}
	if (money < t->getAmount()) {
		delete t;
		throw std::runtime_error("Insufficient funds");
	}
	
	pendingTransactions.push_back(t);
}

bool Blockchain::valid() {
	for (size_t i = 1; i < blocks.size(); i++) {
		if (blocks[i - 1]->hash() != blocks[i]->getPreviousHash()) return false;
		if (!blocks[i]->valid()) return false;
	}
	return true;
}

double Blockchain::getMiningReward() {
	return 2;
}

void Blockchain::mine(std::string minerKey) {
	Block* b = new Block(pendingTransactions, blocks[blocks.size() - 1]->hash(), difficulty);
	b->mine();
	blocks.push_back(b);
	
	pendingTransactions = std::vector<Transaction*>();
	pendingTransactions.push_back(new Transaction("", minerKey, getMiningReward()));
}

void Blockchain::print(std::ostream& os) {
	os << "---BLOCKS---" << std::endl;
	for (size_t i = 0; i < blocks.size(); i++) {
		blocks[i]->printBlock(os);
	}
	os << "--PENDING--" << std::endl;
	for (size_t i = 0; i < pendingTransactions.size(); i++) {
		pendingTransactions[i]->printTransaction(os);
	}
}

Blockchain::~Blockchain() {
	Util::clearPointerVector(blocks);
	Util::clearPointerVector(pendingTransactions);
}
