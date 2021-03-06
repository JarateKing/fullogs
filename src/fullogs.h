#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <stack>
#include <functional>
#include <fstream>

// macros
#define __FULLOGS_STR(a) __FULLOGS_STR2(a)
#define __FULLOGS_STR2(a) #a
#define __FULLOGS_ARGS(a, b, c, ...) {__FILE__, __FULLOGS_STR(__LINE__), __func__, __PRETTY_FUNCTION__, a, b, c, __VA_ARGS__}
#define fullogs_log(a, b, c, ...) Fullogs::log(__FULLOGS_ARGS(a, b, c, __VA_ARGS__));
#define fullogs_debug(a, b, c, ...) Fullogs::debug(__FULLOGS_ARGS(a, b, c, __VA_ARGS__));
#define fullogs_alert(a, b, c, ...) Fullogs::alert(__FULLOGS_ARGS(a, b, c, __VA_ARGS__));
#define fullogs_warn(a, b, c, ...) Fullogs::warn(__FULLOGS_ARGS(a, b, c, __VA_ARGS__));
#define fullogs_error(a, b, c, ...) Fullogs::error(__FULLOGS_ARGS(a, b, c, __VA_ARGS__));
#define fullogs_fatal(a, b, c, ...) Fullogs::fatal(__FULLOGS_ARGS(a, b, c, __VA_ARGS__));
#define fullogs_listen(a) Fullogs::addToListener([&]a);
#define fullogs_logger Fullogs::Logger

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
		std::string file;
		std::string line;
		std::string function;
		std::string prettyfunction;
		std::string context;
		std::string message;
		std::string purpose;
		std::vector<std::string> tags;
	};
	
	struct LogItem {
		int level;
		std::string file;
		std::string line;
		std::string function;
		std::string prettyfunction;
		std::string context;
		std::string message;
		std::string purpose;
		std::vector<std::string> tags;
		std::string tagstring;
		std::string iso8601;
		std::string day;
		std::string month;
		
		void writeTime(std::string& str, std::string format, time_t current_time) {
			std::ostringstream ss;
			ss << std::put_time(gmtime(&current_time), format.c_str());
			str = ss.str();
		}
		
		void setupTime() {
			time_t current_time;
			time(&current_time);
			writeTime(iso8601, "%Y-%m-%dT%H:%M:%SZ", current_time);
			writeTime(day, "%A", current_time);
			writeTime(month, "%B", current_time);
		}
		
		void setupTags() {
			for (int i = 0; i < tags.size(); i++) {
				tagstring += tags[i];
				if (i != tags.size() - 1)
					tagstring += ", ";
			}
		}
		
		LogItem(int level, LogArgument arg) {
			this->level = level;
			context = arg.context;
			message = arg.message;
			purpose = arg.purpose;
			file = arg.file;
			line = arg.line;
			function = arg.function;
			prettyfunction = arg.prettyfunction;
			tags = arg.tags;
			
			setupTime();
			setupTags();
		}
	};
	
	struct LogItemsResult {
		std::vector<LogItem> items;
		std::string format;
		
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
			replaceAll(toret, "{purpose}", item.purpose);
			replaceAll(toret, "{level}", LEVELS.at(item.level));
			replaceAll(toret, "{iso}", item.iso8601);
			replaceAll(toret, "{time}", item.iso8601);
			replaceAll(toret, "{yyyy}", item.iso8601.substr(0, 4));
			replaceAll(toret, "{yy}", item.iso8601.substr(2, 2));
			replaceAll(toret, "{mm}", item.iso8601.substr(5, 2));
			replaceAll(toret, "{dd}", item.iso8601.substr(8, 2));
			replaceAll(toret, "{HH}", item.iso8601.substr(11, 2));
			replaceAll(toret, "{MM}", item.iso8601.substr(14, 2));
			replaceAll(toret, "{SS}", item.iso8601.substr(17, 2));
			replaceAll(toret, "{dayname}", item.day);
			replaceAll(toret, "{day}", item.day.substr(0, 3));
			replaceAll(toret, "{month}", item.month);
			replaceAll(toret, "{mon}", item.month.substr(0, 3));
			replaceAll(toret, "{file}", item.file);
			replaceAll(toret, "{line}", item.line);
			replaceAll(toret, "{func}", item.function);
			replaceAll(toret, "{function}", item.prettyfunction);
			replaceAll(toret, "{tags}", item.tagstring);
			return toret;
		}
		
		void printToStdout() {
			for (int i = 0; i < items.size(); i++) {
				std::cout << replaceFormat(format, items[i]);
			}
		}
		void printToStderr() {
			for (int i = 0; i < items.size(); i++) {
				std::cerr << replaceFormat(format, items[i]);
			}
		}
		void printToFile(std::string filename, bool append) {
			std::ofstream ofs;
			std::ios_base::openmode flags = std::ofstream::out;
			if (append)
				flags |= std::ofstream::app;
			ofs.open(filename, flags);
			for (int i = 0; i < items.size(); i++) {
				ofs << replaceFormat(format, items[i]);
			}
			ofs.close();
		}
		std::string getString() {
			std::string toret;
			for (int i = 0; i < items.size(); i++) {
				toret += replaceFormat(format, items[i]);
			}
			return toret;
		}
		std::vector<std::string> getStringVector() {
			std::vector<std::string> toret;
			for (int i = 0; i < items.size(); i++) {
				toret.push_back(replaceFormat(format, items[i]));
			}
			return toret;
		}
	};
	
	std::vector<LogItem> allItems;
	std::vector<std::function<void(void)>> listeners;
	
	static void onItemAdded() {
		for (int i = 0; i < listeners.size(); i++)
			listeners[i]();
	}
	
	// API for writing logs
	static void log(LogArgument arg) {
		allItems.push_back(LogItem(LOG, arg));
		onItemAdded();
	}
	static void debug(LogArgument arg) {
		allItems.push_back(LogItem(DEBUG, arg));
		onItemAdded();
	}
	static void alert(LogArgument arg) {
		allItems.push_back(LogItem(ALERT, arg));
		onItemAdded();
	}
	static void warn(LogArgument arg) {
		allItems.push_back(LogItem(WARN, arg));
		onItemAdded();
	}
	static void error(LogArgument arg) {
		allItems.push_back(LogItem(ERROR, arg));
		onItemAdded();
	}
	static void fatal(LogArgument arg) {
		allItems.push_back(LogItem(FATAL, arg));
		onItemAdded();
	}
	
	// struct for getting logs
	struct Logger {
		std::string format;
		int flags;
		std::vector<std::string> tags;
		int newLogsIndex = 0;
		
		Logger(std::string format, int flags, std::vector<std::string> tags) {
			this->format = format;
			this->flags = flags;
			this->tags = tags;
		}
		Logger(std::string format, int flags) {
			this->format = format;
			this->flags = flags;
		}
		Logger(std::string format) {
			this->format = format;
			this->flags = LOG | DEBUG | ALERT | WARN | ERROR | FATAL;
		}
		Logger() {
			this->format = "{message}\n";
			this->flags = LOG | DEBUG | ALERT | WARN | ERROR | FATAL;
		}
		
		bool passesFilter(LogItem item) {
			if (item.level & flags) {
				if (tags.size() == 0 || item.tags.size() == 0)
					return true;
					
				for (int i = 0; i < tags.size(); i++)
					for (int j = 0; j < item.tags.size(); j++)
						if (tags[i] == item.tags[j])
							return true;
			}
			
			return false;
		}
		
		LogItemsResult getAllLogs() {
			std::vector<LogItem> toret;
			for (auto e : allItems)
				if (passesFilter(e))
					toret.push_back(e);
			
			return {toret, format};
		}
		LogItemsResult getNewLogs() {
			std::vector<LogItem> toret;
			for (int i = newLogsIndex; i < allItems.size(); i++)
				if (passesFilter(allItems[i]))
					toret.push_back(allItems[i]);
			
			newLogsIndex = allItems.size();
			return {toret, format};
		}
		LogItemsResult getLastNLogs(int amount) {
			std::stack<int> topop;
			for (int i = allItems.size() - 1; i >= 0 && topop.size() < amount; i--)
				if (passesFilter(allItems[i]))
					topop.push(i);
			
			std::vector<LogItem> toret;
			while (!topop.empty()) {
				toret.push_back(allItems[topop.top()]);
				topop.pop();
			}
			return {toret, format};
		}
	};
	
	static void addToListener(std::function<void(void)> func) {
		listeners.push_back(func);
	}
}
