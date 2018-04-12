#pragma once

class Wallet : public Hashable {
public:
	Wallet(std::string name);
private:
	std::string name;
	std::string publicKey;
};
