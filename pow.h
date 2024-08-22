#ifndef NOCLUECOIN_POW_H
#define NOCLUECOIN_POW_H

#include "uint256.h"
#include "block.h"

bool CheckProofOfWork(const CBlockHeader& blockHeader, const Consensus::Params& params);
uint256 CalculateNextWorkRequired(const CBlockIndex* pindexLast, const CBlockHeader* pblock, const Consensus::Params& params);

#endif // NOCLUECOIN_POW_H
