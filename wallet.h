#ifndef NOCLUECOIN_WALLET_H
#define NOCLUECOIN_WALLET_H

#include <map>
#include "uint256.h"

class CWallet {
public:
    CWallet();

    void AddTransaction(const uint256& txid, int64_t amount);
    int64_t GetBalance() const;

private:
    std::map<uint256, int64_t> mapWallet; // Key-value pairs of txid and amount
};

#endif // NOCLUECOIN_WALLET_H
