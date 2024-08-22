#ifndef NOCLUECOIN_CONSENSUS_H
#define NOCLUECOIN_CONSENSUS_H

#include <stdint.h>

namespace Consensus {
    static const uint32_t BLOCK_TIME = 300; // 5 minutes
    static const uint32_t DIFFICULTY_ADJUSTMENT_INTERVAL = 2016; // Similar to Bitcoin
    static const uint32_t MAX_SUPPLY = 210000000; // 210 million coins
    static const uint32_t HALVING_INTERVAL = 210000; // Halving every 210,000 blocks
}

#endif // NOCLUECOIN_CONSENSUS_H
