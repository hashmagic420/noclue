#include "merkle.h"
#include "crypto/sha256.h"

uint256 ComputeMerkleRoot(const std::vector<uint256>& leaves) {
    if (leaves.empty()) return uint256();

    std::vector<uint256> currentLayer = leaves;
    while (currentLayer.size() > 1) {
        if (currentLayer.size() % 2 == 1) {
            currentLayer.push_back(currentLayer.back());
        }

        std::vector<uint256> nextLayer;
        for (size_t i = 0; i < currentLayer.size(); i += 2) {
            uint256 combined = Hash(currentLayer[i].begin(), currentLayer[i].end(), currentLayer[i + 1].begin(), currentLayer[i + 1].end());
            nextLayer.push_back(combined);
        }

        currentLayer = nextLayer;
    }
    return currentLayer[0];
}
