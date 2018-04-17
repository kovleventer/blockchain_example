#pragma once

class Wallet {
public:
	Wallet(std::string name);
	std::string getName() const;
	std::string getPublicKey() const;
private:
	std::string name;
	std::string publicKey;
};
