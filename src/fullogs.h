#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <sstream>
#include <iomanip>

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
		std::string iso8601;
		std::string yyyy, yy, mm, dd, HH, MM, SS;
		
		void writeTime(std::string& str, std::string format, time_t current_time) {
			std::ostringstream ss;
			ss << std::put_time(gmtime(&current_time), format.c_str());
			str = ss.str();
		}
		
		void setupTime() {
			time_t current_time;
			time(&current_time);
			writeTime(iso8601, "%Y-%m-%dT%H:%M:%SZ", current_time);
			writeTime(yyyy, "%Y", current_time);
			writeTime(yy, "%y", current_time);
			writeTime(mm, "%m", current_time);
			writeTime(dd, "%d", current_time);
			writeTime(HH, "%H", current_time);
			writeTime(MM, "%M", current_time);
			writeTime(SS, "%S", current_time);
		}
		
		LogItem(int level, LogArgument arg) {
			this->level = level;
			context = arg.context;
			message = arg.message;
			help = arg.help;
			
			setupTime();
		}
	};
	
	struct LogItemsResult {
		std::vector<LogItem> items;
		
		void replaceAll(std::string& text, std::string find, std::string replace) {
			int pos = text.find(find);
			while (pos != std::string::npos) {
				text = text.replace(pos, find.length(), replace);
				pos = text.find(find);
			}
		}
		
		std::string replaceFormat(std::string format, LogItem item) {
			// TODO: optimize this
			// - formatting can be cached
			// - replacement can be done in one go
			// TODO: improve behavior
			// - cannot make `{message}` literal, for example
			// - cannot have a replacement section include its own tag
			std::string toret = format;
			replaceAll(toret, "{context}", item.context);
			replaceAll(toret, "{message}", item.message);
			replaceAll(toret, "{help}", item.help);
			replaceAll(toret, "{level}", LEVELS.at(item.level));
			replaceAll(toret, "{iso}", item.iso8601);
			replaceAll(toret, "{time}", item.iso8601);
			replaceAll(toret, "{yyyy}", item.yyyy);
			replaceAll(toret, "{yy}", item.yy);
			replaceAll(toret, "{mm}", item.mm);
			replaceAll(toret, "{dd}", item.dd);
			replaceAll(toret, "{HH}", item.HH);
			replaceAll(toret, "{MM}", item.MM);
			replaceAll(toret, "{SS}", item.SS);
			return toret;
		}
		
		void printToStdout(std::string format) {
			for (int i = 0; i < items.size(); i++) {
				std::cout << replaceFormat(format, items[i]);
			}
		}
		void printToStdout() {
			printToStdout("{message}\n");
		}
		void printToStderr(std::string format) {
			for (int i = 0; i < items.size(); i++) {
				std::cerr << replaceFormat(format, items[i]);
			}
		}
		void printToStderr() {
			printToStderr("{message}\n");
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
