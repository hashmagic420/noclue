#ifndef NOCLUECOIN_RPC_H
#define NOCLUECOIN_RPC_H

#include <string>
#include <json/json.h>

Json::Value HandleRPCCommand(const std::string& command, const Json::Value& params);

#endif // NOCLUECOIN_RPC_H
