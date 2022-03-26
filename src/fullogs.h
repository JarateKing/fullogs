#include <iostream>
#include <vector>

namespace Fullogs {
	// levels
	const int LOG = 1;
	const int DEBUG = 2;
	const int ALERT = 4;
	const int WARN = 8;
	const int ERROR = 16;
	const int FATAL = 32;
	
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
	static void log(string message) {
		allItems.push_back({LOG, message});
	}
	static void debug(string message) {
		allItems.push_back({DEBUG, message});
	}
	static void alert(string message) {
		allItems.push_back({ALERT, message});
	}
	static void warn(string message) {
		allItems.push_back({WARN, message});
	}
	static void error(string message) {
		allItems.push_back({ERROR, message});
	}
	static void fatal(string message) {
		allItems.push_back({FATAL, message});
	}
	
	// API for getting logs
	static LogItemsResult getAllLogs() {
		return {allItems};
	}
	static void getNewLogs() {
		
	}
	static void getLastNLogs() {
		
	}
}
