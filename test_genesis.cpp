#include <assert.h>
#include "chainparams.h"

int main() {
    assert(consensus.hashGenesisBlock == uint256S("0x000000..."));
    return 0;
}
