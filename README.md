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

### Logging

There are multiple different types of logs that can be made:

* `fullogs_log`: A simple and generic log
* `fullogs_debug`: A log used for debugging purposes
* `fullogs_alert`: Something that users or developers should be aware of, but isn't necessarily a problem or cause for concern
* `fullogs_warn`: Something that isn't strictly a problem by itself, but may be a problem or lead to problems
* `fullogs_error`: Something wrong that's happened
* `fullogs_fatal`: Something wrong that's happened that can't be recovered from

