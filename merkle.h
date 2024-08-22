#ifndef NOCLUECOIN_MERKLE_H
#define NOCLUECOIN_MERKLE_H

#include <vector>
#include "uint256.h"

uint256 ComputeMerkleRoot(const std::vector<uint256>& leaves);

#endif // NOCLUECOIN_MERKLE_H
