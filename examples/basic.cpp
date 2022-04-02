#include "../src/fullogs.h"

int main() {
	// write logs within code
	fullogs_log("Starting Main", "Hello", "Initial Log", {"general"});
	fullogs_log("Starting Main", "World!", "Second Log", {"general"});
	fullogs_log("Starting Main", "Yup!", "Third Log", {"general"});
	
	// handle logs with a logger
	fullogs_logger logger("{message}\n");
	logger.getNewLogs().printToStdout();
}