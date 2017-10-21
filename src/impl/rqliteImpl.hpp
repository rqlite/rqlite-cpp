#ifndef RQLITE_IMPL_HPP
#define RQLITE_HPP

#include <string>
#include "rqlite.hpp"

class RqliteImpl : Rqlite {
    public:
        RqliteImpl();
        RqliteImpl(std::string proto, std::string host, int port);
        ~RqliteImpl() {};

        void Open();
        void Close();
        Pong* Ping();

    private:
        std::string proto;
        std::string host;
        int port;
};

#endif
