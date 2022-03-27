#include <iostream>
#include <vector>
#include <map>

namespace Fullogs {
	// levels
	const int LOG = 1;
	const int DEBUG = 2;
	const int ALERT = 4;
	const int WARN = 8;
	const int ERROR = 16;
	const int FATAL = 32;
	const std::map<int, std::string> LEVELS = {{LOG, "log"}, {DEBUG, "debug"}, {ALERT, "alert"}, {WARN, "warn"}, {ERROR, "error"}, {FATAL, "fatal"}};
	
	// structs
	struct LogArgument {
		std::string context;
		std::string message;
		std::string help;
	};
	
	struct LogItem {
		int level;
		std::string context;
		std::string message;
		std::string help;
		
		LogItem(int level, LogArgument arg) {
			this->level = level;
			context = arg.context;
			message = arg.message;
			help = arg.help;
		}
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
	static void log(LogArgument arg) {
		allItems.push_back(LogItem(LOG, arg));
	}
	static void debug(LogArgument arg) {
		allItems.push_back(LogItem(DEBUG, arg));
	}
	static void alert(LogArgument arg) {
		allItems.push_back(LogItem(ALERT, arg));
	}
	static void warn(LogArgument arg) {
		allItems.push_back(LogItem(WARN, arg));
	}
	static void error(LogArgument arg) {
		allItems.push_back(LogItem(ERROR, arg));
	}
	static void fatal(LogArgument arg) {
		allItems.push_back(LogItem(FATAL, arg));
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
