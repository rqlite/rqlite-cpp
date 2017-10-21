#include "rqliteImpl.hpp"

const std::string DefaultProto = "http";
const std::string DefaultHost = "localhost";
const int DefaultPort = 4001;

RqliteImpl::RqliteImpl() {
    this->proto = DefaultProto;
    this->host = DefaultHost;
    this->port = DefaultPort;
}

RqliteImpl::RqliteImpl(std::string proto, std::string host, int port) {
    this->proto = proto;
    this->host = host;
    this->port = port;
}

void RqliteImpl::Open() {
}

void RqliteImpl::Close() {
}

Pong* RqliteImpl::Ping() {
    return NULL;
}
