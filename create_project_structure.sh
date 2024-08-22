#!/bin/bash

mkdir -p NoClueCoin/src/consensus
mkdir -p NoClueCoin/src/crypto
mkdir -p NoClueCoin/src/wallet
mkdir -p NoClueCoin/src/miner
mkdir -p NoClueCoin/src/rpc
mkdir -p NoClueCoin/doc
mkdir -p NoClueCoin/test/unittests
mkdir -p NoClueCoin/test/functional_tests
mkdir -p NoClueCoin/contrib/bash_completion
mkdir -p NoClueCoin/contrib/init
mkdir -p NoClueCoin/contrib/scripts

touch NoClueCoin/src/chainparams.cpp
touch NoClueCoin/src/consensus/consensus.h
touch NoClueCoin/src/consensus/merkle.cpp
touch NoClueCoin/src/consensus/merkle.h
touch NoClueCoin/src/crypto/sha256.cpp
touch NoClueCoin/src/crypto/sha256.h
touch NoClueCoin/src/crypto/pow.cpp
touch NoClueCoin/src/crypto/pow.h
touch NoClueCoin/src/main.cpp
touch NoClueCoin/src/wallet/wallet.cpp
touch NoClueCoin/src/wallet/wallet.h
touch NoClueCoin/src/miner/miner.cpp
touch NoClueCoin/src/miner/miner.h
touch NoClueCoin/src/rpc/rpc.cpp
touch NoClueCoin/src/rpc/rpc.h
touch NoClueCoin/src/net.cpp
touch NoClueCoin/src/net.h
touch NoClueCoin/src/util.cpp
touch NoClueCoin/src/util.h
touch NoClueCoin/src/genesis.py
touch NoClueCoin/src/Makefile
touch NoClueCoin/doc/README.md
touch NoClueCoin/doc/INSTALL.md
touch NoClueCoin/doc/CONFIG.md
touch NoClueCoin/doc/CONTRIBUTING.md
touch NoClueCoin/test/unittests/test_genesis.cpp
touch NoClueCoin/test/unittests/test_blockchain.cpp
touch NoClueCoin/test/unittests/CMakeLists.txt
touch NoClueCoin/test/functional_tests/test_mining.py
touch NoClueCoin/test/functional_tests/test_transaction.py
touch NoClueCoin/test/Makefile
touch NoClueCoin/contrib/bash_completion/nocluecoin.sh
touch NoClueCoin/contrib/init/nocluecoin.service
touch NoClueCoin/contrib/scripts/setup_node.sh
touch NoClueCoin/contrib/scripts/mine.sh
touch NoClueCoin/Dockerfile
touch NoClueCoin/LICENSE

echo "Project directory structure has been created."
