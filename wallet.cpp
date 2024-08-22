#include "wallet.h"

CWallet::CWallet() {}

void CWallet::AddTransaction(const uint256& txid, int64_t amount) {
    mapWallet[txid] = amount;
}

int64_t CWallet::GetBalance() const {
    int64_t balance = 0;
    for (const auto& entry : mapWallet) {
        balance += entry.second;
    }
    return balance;
}
