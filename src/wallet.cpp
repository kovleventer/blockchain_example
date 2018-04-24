#include "wallet.h"

Wallet::Wallet(std::string name) : name(name) {
	picosha2::hash256_hex_string(name, publicKey);
}

std::string Wallet::getName() const {
	return name;
}

std::string Wallet::getPublicKey() const {
	return publicKey;
}

Wallet::operator std::string() const {
	return publicKey;
}
