#include "../src/fullogs.h"

int main() {
	fullogs_log("Starting Main", "Hello", "Initial Log");
	fullogs_log("Starting Main", "World!", "Second Log");
	
	fullogs_getAllLogs().printToStdout("{level} at {time} in {file}@{line} ({function}):\n{context}\n{message}\n{help}\n\n");
}