#include "miner.h"
#include "crypto/sha256.h"

bool MineBlock(CBlockHeader& block, const ConsensusParams& consensusParams) {
    uint256 target = uint256().SetCompact(block.nBits);
    while (true) {
        block.nNonce++;
        uint256 hash = block.GetHash();
        if (hash <= target) {
            return true;  // Successfully mined a block
        }
    }
}
