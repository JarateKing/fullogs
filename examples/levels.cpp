#include "../src/fullogs.h"

int main() {
	// go through various levels
	fullogs_log("Example Program", "logging!", "Showcasing logging");
	fullogs_debug("Example Program", "debugging!", "Showcasing logging");
	fullogs_alert("Example Program", "alerting!", "Showcasing logging");
	fullogs_warn("Example Program", "warning!", "Showcasing logging");
	fullogs_error("Example Program", "erroring!", "Showcasing logging");
	fullogs_fatal("Example Program", "fatal erroring!", "Showcasing logging");
	
	fullogs_logger logger("{level}: {message}\n");
	logger.getNewLogs().printToStdout();
}