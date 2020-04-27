#pragma once
#ifndef CLIENT_RPC_H
#define CLIENT_RPC_H

#include "info_code.h"
#include "feverrpc/feverrpc-client.hpp"
#include "feverrpc/feverrpc-factory.hpp"
#include "feverrpc/feverrpc.hpp"
#include "feverrpc/utils.hpp"

extern FeverRPC::Client client_rpc;


void initClientRpc();

#endif // CLIENT_RPC_H