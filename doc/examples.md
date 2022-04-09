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
}```

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
}```

```
Hello
World!
Yup!
```