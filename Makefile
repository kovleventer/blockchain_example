SOURCES = src/block.cpp src/blockchain.cpp src/transaction.cpp src/util.cpp src/wallet.cpp

all:
	g++ $(SOURCES) tests/bc_test.cpp -Wall -Werror -o Blockchain
