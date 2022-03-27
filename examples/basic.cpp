#include "../src/fullogs.h"

int main() {
	fullogs_log("Starting Main", "Hello", "Initial Log");
	fullogs_log("Starting Main", "World!", "Second Log");
	
	Fullogs::getAllLogs().printToStdout("{level} at {time}:\n{context}\n{message}\n{help}\n\n");
}