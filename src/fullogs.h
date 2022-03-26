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
		std::string message;
	};
	
	struct LogItemsResult {
		std::vector<LogItem> items;
		
		void printToStdout() {
			for (int i = 0; i < items.size(); i++) {
				std::cout << items[i].message << '\n';
			}
		}
	};
	
	std::vector<LogItem> allItems;
	
	// API for writing logs
	static void log(std::string message) {
		allItems.push_back({LOG, message});
	}
	static void debug(std::string message) {
		allItems.push_back({DEBUG, message});
	}
	static void alert(std::string message) {
		allItems.push_back({ALERT, message});
	}
	static void warn(std::string message) {
		allItems.push_back({WARN, message});
	}
	static void error(std::string message) {
		allItems.push_back({ERROR, message});
	}
	static void fatal(std::string message) {
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
