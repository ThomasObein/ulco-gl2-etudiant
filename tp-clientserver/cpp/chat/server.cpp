#include <hv/WebSocketServer.h>

#include "Net.hpp"

#include <chrono>
#include <iostream>
#include <thread>

int main() {
    Net net;

    hv::WebSocketService ws;
    ws.onopen = [&net](const WebSocketChannelPtr& channel, const HttpRequestPtr& req) {
        net.addPending(channel);
        std::cout << "client connected" << std::endl;
    };
    ws.onmessage = [&net](const WebSocketChannelPtr& channel, const std::string& msg) {
        if (net.isPending(channel)) {
            if (msg != "") {
                if (!net.giveName(channel, msg)) {
                    channel->send("Ce nom d'utilisateur existe déjà.");
                }
                else {
                    channel->send("Bienvenue " + msg + "!");
                }
            }
        }
        else {
            auto name = net.findName(channel);
            if (name.has_value()) {
                std::string message = name.value() + ": " + msg;
                auto sendInput = [&net, &message](const WebSocketChannelPtr & channel) {
                    if (!net.isPending(channel)) channel->send(message);
                };
                net.map(sendInput);
            }
        }
    };
    ws.onclose = [&net](const WebSocketChannelPtr& channel) {
        if (net.isPending(channel)) net.delPending(channel);
        else net.delConnection(channel);
        std::cout << "client disconnected" << std::endl;
    };

    hv::WebSocketServer server;
    server.registerWebSocketService(&ws);
    server.setPort(9000);
    std::cout << "waiting for clients..." << std::endl;
    server.run();

    return 0;
}

