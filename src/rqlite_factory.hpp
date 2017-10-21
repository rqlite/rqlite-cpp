#ifndef RQLITE_FACTORY_HPP
#define RQLITE_FACTORY_HPP

#include <string>
#include "rqlite.hpp"
#include "impl/rqliteImpl.hpp"

class RqliteFactory {
    public:
        static Rqlite Connect(string proto, string host, int port) {
            return new RqliteImpl(proto,host, port);
        }
};

#endif  // RQLITE_FACTORY_HPP
