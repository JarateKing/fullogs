#include "../src/fullogs.h"

int main() {
	// setup logger
	fullogs_logger logger("{message}\n");
	
	// make logger listen for any logs
	fullogs_listen({logger.getNewLogs().printToStdout();});
	
	// write logs within code
	fullogs_log("Example Program", "Hello", "Initial Log", {"general"});
	fullogs_log("Example Program", "World!", "Second Log", {"general"});
	fullogs_log("Example Program", "Yup!", "Third Log", {"general"});
}