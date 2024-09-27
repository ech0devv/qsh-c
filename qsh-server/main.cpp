#include "WebSocketServer.h"
#include <cstring>
#include <iomanip>
#include <iostream>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace hv;

class Room {
      private:
	std::string password;
	int sender_fd;
	int receiver_fd;

      public:
	Room(int sender_fd, std::string password) : sender_fd(sender_fd), password(password) {};
	std::string getPassword() {
		return password;
	}
	int getSenderFD() {
		return sender_fd;
	}
	void setReceiverFD(int n) {
		sender_fd = n;
		return;
	}
	int getReceiverFD() {
		return receiver_fd;
	}
};

std::vector<Room> rooms;

std::string createMessage(int value, const std::string &text) {
	std::string result(1, static_cast<char>(value));
	result += text;
	return result;
}

int main(int argc, char *argv[]) {
	unsigned char *random = new unsigned char[6];
	RAND_bytes(random, 6);
	unsigned char encoded[6];
	EVP_EncodeBlock(encoded, random, 6);
	WebSocketService ws;
	WebSocketServer server(&ws);
	ws.onopen = [](const WebSocketChannelPtr &channel, const HttpRequestPtr &req) {
		printf("onopen: GET %s\n", req->Path().c_str());
	};
	ws.onmessage = [](const WebSocketChannelPtr &channel, const std::string &msg) {
		/*
			unsigned char *random = new unsigned char[6];
			RAND_bytes(random, 6);
			unsigned char encoded[6];
			EVP_EncodeBlock(encoded, random, 6);
			std::cout << encoded << std::endl;
		*/
		std::istringstream stream(msg);
		std::vector<std::string> args;
		for (std::string arg; std::getline(stream, arg, '|');) {
			args.push_back(arg);
		}

		// printf("onmessage: %.*s %d\n", (int)msg.size(), msg.data(), channel->fd());
	};
	ws.onclose = [](const WebSocketChannelPtr &channel) {
		printf("onclose\n");
	};
	server.setPort(9999);
	server.setThreadNum(4);
	server.run();
	return 0;
}