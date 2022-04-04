#include "../src/fullogs.h"

int main() {
	// setup initial loggers
	fullogs_logger loggerOne("Logger 1: {message}\n");
	fullogs_logger loggerTwo("Logger 2: {message}\n");
	
	// write logs within code, and print logs periodically
	fullogs_log("Example Program", "Hello", "Showcasing logging");
	loggerOne.getNewLogs().printToStdout();
	loggerTwo.getNewLogs().printToStdout();
	
	fullogs_log("Example Program", "World!", "Showcasing logging");
	loggerOne.getNewLogs().printToStdout();
	loggerTwo.getNewLogs().printToStdout();
	
	fullogs_log("Example Program", "Yup!", "Showcasing logging");
	loggerOne.getNewLogs().printToStdout();
	loggerTwo.getNewLogs().printToStdout();
	
	// setup last logger
	fullogs_logger loggerThree("Logger 3: {message}\n");
	loggerThree.getNewLogs().printToStdout();
}
