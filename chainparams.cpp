#include "chainparams.h"
#include "consensus/merkle.h"
#include "util.h"
#include "crypto/sha256.h"
#include "miner.h"
#include "pow.h"

class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        consensus.nMaxMoneyOut = 210000000 * COIN;
        consensus.nSubsidyHalvingInterval = 210000; // Halving after every 210,000 blocks
        consensus.nBlockTime = 5 * 60; // 5 minutes per block
        consensus.nDifficultyAdjustmentInterval = 2016; // Difficulty adjustment interval, similar to Bitcoin
        
        // Genesis Block Parameters
        const char* pszTimestamp = "NoClueCoin Launch 2024";
        genesis = CreateGenesisBlock(pszTimestamp, 1640995200, 2083236893, 0x1d00ffff, 50 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        
        assert(consensus.hashGenesisBlock == uint256S("0x000000..."));
        assert(genesis.hashMerkleRoot == uint256S("0x4a5e1e..."));
    }
};

// Instantiate the main chain parameters
static CMainParams mainParams;
