#include "../src/fullogs.h"

int main() {
	// setup initial loggers
	fullogs_logger loggerOne("Logger 1: {message}\n");
	fullogs_logger loggerTwo("Logger 2: {message}\n");
	
	// write logs within code, and print logs periodically
	fullogs_log("Example Program", "Hello", "Initial Log", {"general"});
	loggerOne.getNewLogs().printToStdout();
	loggerTwo.getNewLogs().printToStdout();
	
	fullogs_log("Example Program", "World!", "Second Log", {"general"});
	loggerOne.getNewLogs().printToStdout();
	loggerTwo.getNewLogs().printToStdout();
	
	fullogs_log("Example Program", "Yup!", "Third Log", {"general"});
	loggerOne.getNewLogs().printToStdout();
	loggerTwo.getNewLogs().printToStdout();
	
	// setup last logger
	fullogs_logger loggerThree("Logger 3: {message}\n");
	loggerThree.getNewLogs().printToStdout();
}
