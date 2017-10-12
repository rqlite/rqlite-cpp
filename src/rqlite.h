#ifndef RQLITE_H
#define RQLITE_H

#include <string>

enum ReadConsistencyLevel { 
	kNone = 0,
	kWeak,
	kStrong
}

class Rqlite {
public:
	// Query executes a single statement that returns rows.
	QueryResults Query(string q, ReadConsistencyLevel lvl) = 0;

	// Execute executes a single statement that does not return rows
	ExecuteResults Execute(string q) = 0;
};

#endif  // RQLITE_H