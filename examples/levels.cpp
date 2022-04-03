#include "../src/fullogs.h"

int main() {
	// go through various levels
	fullogs_log("Example Program", "logging!", "");
	fullogs_debug("Example Program", "debugging!", "");
	fullogs_alert("Example Program", "alerting!", "");
	fullogs_warn("Example Program", "warning!", "");
	fullogs_error("Example Program", "erroring!", "");
	fullogs_fatal("Example Program", "fatal erroring!", "");
	
	fullogs_logger logger("{level}: {message}\n");
	logger.getNewLogs().printToStdout();
}