#include "blockchain.h"

Blockchain::Blockchain() {
	blocks.push_back(Block());
}

void addTransaction(Transaction* t) {
	pendingTransactions.push_back(t);
	//TODO check if user has enugh $
}

bool valid() {
	
}

double getMiningReward() {
	return 2;
}

~Blockchain() {
	Util::clearPointerVec(blocks);
	Util::clearPointerVec(pendingTransactions);
}
