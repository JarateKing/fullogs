#include "../src/fullogs.h"

int main() {
	Fullogs::log("Hello");
	Fullogs::log("World!");
	
	Fullogs::getAllLogs().printToStdout();
}