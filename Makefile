$SOURCES = src/block.cpp src/blockchain.cpp src/transaction.cpp src/util.cpp src/wallet.cpp

all:
	g++ src/block.cpp src/blockchain.cpp src/transaction.cpp src/util.cpp src/wallet.cpp tests/bc_test.cpp -o Blockchain
