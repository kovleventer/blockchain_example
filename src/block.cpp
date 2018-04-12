#include "block.h"

Block::Block() : sealed(false), nonce(0) {
	
}

bool Block::valid(int difficulty) {
	std::string h = hash();
	for (int i = 0; i < difficulty; i++) {
		if (h[i] != '0') {
			return false;
		}
	}
	return true;
}
