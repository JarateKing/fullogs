#include "../src/fullogs.h"

int main() {
	// write logs within code
	fullogs_log("Example Program", "Hello", "Showcasing logging");
	fullogs_log("Example Program", "World!", "Showcasing logging");
	fullogs_log("Example Program", "Yup!", "Showcasing logging");
	
	// handle logs with a logger
	fullogs_logger logger("{time}: {message}\n");
	logger.getNewLogs().printToFile("output.log", true);
}