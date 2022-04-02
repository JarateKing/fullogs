#include "../src/fullogs.h"

int main() {
	Fullogs::Logger loggerOne("1 {message}\n");
	Fullogs::Logger loggerTwo("2 {message}\n");
	
	fullogs_listen({loggerOne.getNewLogs().printToStdout();});
	fullogs_listen({loggerTwo.getNewLogs().printToStdout();});
	
	fullogs_log("Starting Main", "Hello", "Initial Log", {"general"});
	fullogs_log("Starting Main", "World!", "Second Log", {"general"});
	fullogs_log("Starting Main", "Yup!", "Third Log", {"general"});
}