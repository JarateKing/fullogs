#include "../src/fullogs.h"

int main() {
	Fullogs::log({"Starting Main", "Hello", "Initial Log"});
	Fullogs::log({"Starting Main", "World!", "Second Log"});
	
	Fullogs::getAllLogs().printToStdout("{level} at {time}:\n{context}\n{message}\n{help}\n\n");
}