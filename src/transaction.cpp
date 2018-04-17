#include "transaction.h"

Transaction(std::string sender, std::string target, double amount, std::string timeStamp)
	: sender(sender), target(target), amount(amount), timeStamp(timeStamp) {
	if (amount < 0) {
		throw std::runtime_error("Transaction amount can not be negative");
	}
}

std::string Transaction::getSenderKey() const {
	return sender;
}

std::string Transaction::getTargetKey() const {
	return target;
}

double Transaction::getAmount() const {
	return amount;
}

std::string Transaction::getTimeStamp() const {
	return timeStamp;
}
	
std::string Transaction::hash() const {
	std::stringstream ss;
	std::string hashString;
	ss << sender << target << amount << timeStamp;
	picosha2::hash256_hex_string(ss.str(), hashString);
	return hashString;
}
