#include "block.h"

Block::Block(std::vector<Transaction*> transactions, std::string prevHash, int difficulty, std::string timeStamp)
	: nonce(0), transactions(transactions), previousHash(prevHash), difficulty(difficulty), timeStamp(timeStamp) {}

bool Block::valid() const {
	std::string h = hash();
	for (int i = 0; i < difficulty; i++) {
		if (h[i] != '0') {
			return false;
		}
	}
	return true;
}

std::string Block::hash() const {
	std::string hashString;
	std::stringstream ss;
	ss << nonce;
	ss << previousHash;
	ss << timeStamp;
	ss << difficulty;
	for (size_t i = 0; i < transactions.size(); i++) {
		ss << transactions[i];
	}
	picosha2::hash256_hex_string(ss.str(), hashString);
	return hashString;
}

std::string Block::getTimeStamp() const {
	return timeStamp;
}

std::string Block::getPreviousHash() const {
	return previousHash;
}

int Block::getDifficulty() const {
	return difficulty;
}

void Block::printBlock(std::ostream& os) const {
	os << "Block hash: " << hash() << std::endl;
	os << "\t" << "Timestamp: " << timeStamp << std::endl;
	os << "\t" << "Previous Hash: " << previousHash << std::endl;
	for (size_t i = 0; i < transactions.size(); i++) {
		transactions[i]->printTransaction(os);
	}
}

void Block::mine() {
	while (!valid()) {
		nonce++;
	}
}

void Block::setDifficulty(int newDifficulty) {
	difficulty = newDifficulty;
}

Block::~Block() {
	Util::clearPointerVector(transactions);
}
