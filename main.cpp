#include "chainparams.h"
#include "miner.h"
#include "rpc.h"
#include "net.h"

int main(int argc, char* argv[]) {
    // Initialize network
    InitNetwork();

    // Start mining
    StartMining();

    return 0;
}
