#ifndef RQLITE_H
#define RQLITE_H

#include <string>

enum ReadConsistencyLevel {
    kNone = 0,
    kWeak,
    kStrong
}

class Pong {
    public:
        string version;

        Pong() {
            this.version = "unknown";
        }

        Pong(string version) {
            this.version = version;
        }
};

class Rqlite {
    public:
        // Ping checks communication with the rqlite node. */
        virtual Pong Ping() = 0;
}

class RqliteFactory {
    public:
        static Rqlite Connect(string proto, string host, int port) {
            return new RqliteImpl(proto,host, port);
        }
};

#endif  // RQLITE_H
