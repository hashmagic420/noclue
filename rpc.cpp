#include "rpc.h"

Json::Value HandleRPCCommand(const std::string& command, const Json::Value& params) {
    Json::Value result;

    if (command == "getbalance") {
        result["balance"] = 1000; // Example value
    }

    return result;
}
