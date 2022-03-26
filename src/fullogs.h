#include <iostream>
#include <vector>

namespace Fullogs {
	// structs
	struct LogItem {
		int level;
		string message;
	};
	
	struct LogItemsResult {
		std::vector<LogItem> items;
		
		void printToStdout() {
			for (int i = 0; i < items.size(); i++) {
				cout << items[i].message << '\n';
			}
		}
	};
	
	vector<LogItem> allItems;
	
	// API for writing logs
	static void log() {
		
	}
	static void debug() {
		
	}
	static void alert() {
		
	}
	static void warn() {
		
	}
	static void error() {
		
	}
	static void fatal() {
		
	}
	
	// API for getting logs
	static void getAllLogs() {
		
	}
	static void getNewLogs() {
		
	}
	static void getLastNLogs() {
		
	}
}
