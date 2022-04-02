#include "../src/fullogs.h"

int main() {
	fullogs_logger loggerOne("1 {message}\n");
	fullogs_logger loggerTwo("2 {message}\n");
	
	fullogs_listen({loggerOne.getNewLogs().printToStdout();});
	fullogs_listen({loggerTwo.getNewLogs().printToStdout();});
	
	fullogs_log("Starting Main", "Hello", "Initial Log", {"general"});
	fullogs_log("Starting Main", "World!", "Second Log", {"general"});
	fullogs_log("Starting Main", "Yup!", "Third Log", {"general"});
}