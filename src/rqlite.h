#ifndef RQLITE_H
#define RQLITE_H

#include <string>
#include <vector>

#include <boost/any.hpp>
// JSON parsing also available in Boost.

enum ReadConsistencyLevel { 
    kNone = 0,
    kWeak,
    kStrong
}

class ExecuteResults {
    class Result {
        public:
            string error;
            int lastInsertId;
            int rowsAffected;
            float time;
    };

    public:
        std::vector<Result> results;
        float time;
};

class QueryResults {
    class Result {
        string error;
        std::vector<string> columns;
        std::vector<string> types;
        std::vector<string> values;
        std::vector<boost::any> values;
        float time;
    }

    public:
        std::vector<Result> results;
        float time;
};

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
    // Query executes a single statement that returns rows.
    virtual QueryResults Query(string q, ReadConsistencyLevel lvl) = 0;

    // Execute executes a single statement that does not return rows
    virtual ExecuteResults Execute(string q) = 0;

    // Ping checks communication with the rqlite node. */
    virtual Pong Ping() = 0;
}

#endif  // RQLITE_H