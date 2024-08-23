#ifndef NOCLUECOIN_MINER_H
#define NOCLUECOIN_MINER_H

#include "block.h"
#include "wallet.h"
#include "consensus.h"

bool MineBlock(CBlockHeader& block, const Consensus::Params& consensusParams);

#endif // NOCLUECOIN_MINER_H
