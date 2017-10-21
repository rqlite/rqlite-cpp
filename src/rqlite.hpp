#ifndef RQLITE_H
#define RQLITE_H

#include <string>

enum ReadConsistencyLevel {
    kNone = 0,
    kWeak,
    kStrong
};

class Pong {
    public:
        std::string version;

        Pong() {
            this->version = "unknown";
        }

        Pong(std::string version) {
            this->version = version;
        }
};

class Rqlite {
    public:
        // Open opens a connection to the node.
        virtual void Open() = 0;

        // Close closes the connection to the node.
        virtual void Close() = 0;

        // Ping checks communication with the rqlite node. */
        virtual Pong* Ping() = 0;
};

#endif  // RQLITE_H
