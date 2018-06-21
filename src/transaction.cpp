#include "transaction.h"

Transaction::Transaction(std::string sender, std::string target, double amount, std::string timeStamp)
	: sender(sender), target(target), amount(amount), timeStamp(timeStamp) {
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

void Transaction::printTransaction(std::ostream& os) const {
	os << "\t" << "Transaction: " << hash() << std::endl;
	os << "\t\t" << "Sender: " << sender << std::endl;
	os << "\t\t" << "Target: " << target << std::endl;
	os << "\t\t" << "Amount: " << amount << std::endl;
}
	
std::string Transaction::hash() const {
	std::stringstream ss;
	std::string hashString;
	ss << sender << target << amount << timeStamp;
	picosha2::hash256_hex_string(ss.str(), hashString);
	return hashString;
}
