#include "wallet.h"

Wallet::Wallet(std::string name) : name(name) {
	picosha2::hash256_hex_string(name, publicKey);
}

std::string getName() {
	return name;
}
