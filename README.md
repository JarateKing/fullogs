# Fullogs

This is a header-only logging library for C++. The intention is to make some things explicit and encourage best practices by the developer, while also providing flexibility in its usage. Features include:

* multiple levels: logs, debugs, alerts, warnings, errors, and fatal errors
* logs split by intention -- context, message, and help -- to ensure that developers always think to describe all three
* multiple loggers operating on the same logs concurrently
* flexibility between automatic or manual control over when loggers handle new logs

## Usage

Including the header file via `#include "fullogs.h"` is all that's needed to begin using Fullogs. One can then log like so:

```cpp
fullogs_log("Context", "Message", "Help");
```

These logs are captured by loggers, which can either get logs after they've been run:

```cpp
fullogs_logger logger("{message}\n");
// ...
logger.getNewLogs().printToStdout();
```

Or alternatively, can be set up beforehand to listen for any new logs:

```cpp
fullogs_logger logger("{message}\n");
fullogs_listen({logger.getNewLogs().printToStdout();});
```
