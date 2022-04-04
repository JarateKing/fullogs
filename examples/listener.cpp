#include "../src/fullogs.h"

int main() {
	// setup logger
	fullogs_logger logger("{message}\n");
	
	// make logger listen for any logs
	fullogs_listen({logger.getNewLogs().printToStdout();});
	
	// write logs within code
	fullogs_log("Example Program", "Hello", "Showcasing logging");
	fullogs_log("Example Program", "World!", "Showcasing logging");
	fullogs_log("Example Program", "Yup!", "Showcasing logging");
}