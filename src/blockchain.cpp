#include "blockchain.h"

Blockchain::Blockchain() : difficulty(3) {
	blocks.push_back(new Block(std::vector<Transaction*>(), "", difficulty));
}

void Blockchain::addTransaction(Transaction* t) {
	pendingTransactions.push_back(t);
	//TODO check if user has enugh $
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
