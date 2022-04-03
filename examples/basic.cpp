#include "../src/fullogs.h"

int main() {
	// write logs within code
	fullogs_log("Example Program", "Hello", "Initial Log", {"general"});
	fullogs_log("Example Program", "World!", "Second Log", {"general"});
	fullogs_log("Example Program", "Yup!", "Third Log", {"general"});
	
	// handle logs with a logger
	fullogs_logger logger("{message}\n");
	logger.getNewLogs().printToStdout();
}