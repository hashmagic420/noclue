#include "chainparams.h"
#include "consensus/merkle.h"
#include "util.h"
#include "crypto/sha256.h"
#include "miner.h"
#include "pow.h"
#include <assert.h>
#include <vector>

static CBlock CreateGenesisBlock(const char* pszTimestamp, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward) {
    CMutableTransaction txNew;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = CScript() << ParseHex("04678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5f") << OP_CHECKSIG;

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(MakeTransactionRef(std::move(txNew)));
    genesis.hashPrevBlock.SetNull();
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        consensus.nMaxMoneyOut = 210000000 * COIN;
        consensus.nSubsidyHalvingInterval = 210000; // Halving every 210,000 blocks
        consensus.nBlockTime = 5 * 60; // 5 minutes per block
        consensus.nDifficultyAdjustmentInterval = 2016; // Difficulty adjustment interval
        consensus.nPowLimit = uint256S("00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffff"); // PoW limit

        // Genesis Block
        const char* pszTimestamp = "NoClueCoin Launch 2024";
        genesis = CreateGenesisBlock(pszTimestamp, 1640995200, 19617, 0x1d00ffff, 1, 50 * COIN); // nTime, nNonce, nBits from the mined genesis block
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x0007d372af03c3c540da4950ca9ab69984e92ca7f708cd27e514a5e58b42c4d2")); // Actual mined genesis block hash
        assert(genesis.hashMerkleRoot == uint256S("0x4a5e1e4baab89f3a32518a88b8a3025d11a3a987b12b8b9dbdd7d3a6d6e98fdd")); // Merkle root

        vSeeds.clear(); // List of seed nodes
        vFixedSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 60); // Starts with 'L' like Litecoin
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 50); 
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 128); 
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x88, 0xB2, 0x1E}; 
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x88, 0xAD, 0xE4}; 

        nDefaultPort = 8333; // Default port for P2P connections

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
    }
};

// Instantiate the main chain parameters
static CMainParams mainParams;

const CChainParams& Params() {
    return mainParams;
}
