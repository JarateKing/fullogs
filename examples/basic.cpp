#include "../src/fullogs.h"

int main() {
	fullogs_log("Starting Main", "Hello", "Initial Log", {"general"});
	fullogs_warn("Starting Main", "World!", "Second Log", {"general"});
	fullogs_error("Starting Main", "Yup!", "Third Log", {"specific"});
	
	Fullogs::Logger logger("{level} at {time} in {file}@{line} ({function}):\n{context}\n{message}\n{help}\n{tags}\n\n", Fullogs::LOG | Fullogs::ERROR, {"general"});
	logger.getAllLogs().printToStdout();
}