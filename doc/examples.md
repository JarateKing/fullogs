# Examples

## Basic

We can make simple use of fullogs like so:

```cpp
#include "../src/fullogs.h"

int main() {
	// write logs within code
	fullogs_log("Example Program", "Hello", "Showcasing logging");
	fullogs_log("Example Program", "World!", "Showcasing logging");
	fullogs_log("Example Program", "Yup!", "Showcasing logging");
	
	// handle logs with a logger
	fullogs_logger logger("{message}\n");
	logger.getNewLogs().printToStdout();
}
```

This results in the following logs:

```
Hello
World!
Yup!
```

## Listener

Alternatively, we can make use of a listener:

```cpp
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
```

```
Hello
World!
Yup!
```

## Multiple Loggers

You aren't limited to a single logger, and can create multiple. Each logger has access to the same logs (as long as they're not filtered out) and can handle their own formatting.

```cpp
#include "../src/fullogs.h"

int main() {
	// setup initial loggers
	fullogs_logger loggerOne("Logger 1: {message}\n");
	fullogs_logger loggerTwo("Logger 2: {message}\n");
	
	// write logs within code, and print logs periodically
	fullogs_log("Example Program", "Hello", "Showcasing logging");
	loggerOne.getNewLogs().printToStdout();
	loggerTwo.getNewLogs().printToStdout();
	
	fullogs_log("Example Program", "World!", "Showcasing logging");
	loggerOne.getNewLogs().printToStdout();
	loggerTwo.getNewLogs().printToStdout();
	
	fullogs_log("Example Program", "Yup!", "Showcasing logging");
	loggerOne.getNewLogs().printToStdout();
	loggerTwo.getNewLogs().printToStdout();
	
	// setup last logger
	fullogs_logger loggerThree("Logger 3: {message}\n");
	loggerThree.getNewLogs().printToStdout();
}
```

```
Logger 1: Hello
Logger 2: Hello
Logger 1: World!
Logger 2: World!
Logger 1: Yup!
Logger 2: Yup!
Logger 3: Hello
Logger 3: World!
Logger 3: Yup!
```

### Levels

There are multiple different 'levels' of logs available. These determine their severity, on a scale from completely benign to irrecoverably erroneous:

```cpp
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
```

```
log: logging!
debug: debugging!
alert: alerting!
warn: warning!
error: erroring!
fatal: fatal erroring!
```

### Print to File

So far the examples have all used `printToStdout`. Other methods are available, such as `printToFile`:

```cpp
#include "../src/fullogs.h"

int main() {
	// write logs within code
	fullogs_log("Example Program", "Hello", "Showcasing logging");
	fullogs_log("Example Program", "World!", "Showcasing logging");
	fullogs_log("Example Program", "Yup!", "Showcasing logging");
	
	// handle logs with a logger
	fullogs_logger logger("{time}: {message}\n");
	logger.getNewLogs().printToFile("output.log", true);
}
```

```
2022-01-02T03:04:05Z: Hello
2022-01-02T03:04:05Z: World!
2022-01-02T03:04:05Z: Yup!
```
