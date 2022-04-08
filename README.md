# Fullogs

This is a header-only logging library for C++. The intention is to make some things explicit and encourage best practices by the developer, while also providing flexibility in its usage. Features include:

* multiple levels: logs, debugs, alerts, warnings, errors, and fatal errors
* logs split by intention -- context, message, and purpose -- to ensure that developers always think to describe all three
* multiple loggers operating on the same logs concurrently
* flexibility between automatic or manual control over when loggers handle new logs

## Usage

Including the header file via `#include "fullogs.h"` is all that's needed to begin using Fullogs. One can then log like so:

```cpp
fullogs_log("Context", "Message", "Purpose");
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

There are multiple different levels of logs that can be made:

* `fullogs_log`: A simple and generic log
* `fullogs_debug`: A log used for debugging purposes
* `fullogs_alert`: Something that users or developers should be aware of, but isn't necessarily a problem or cause for concern
* `fullogs_warn`: Something that isn't strictly a problem by itself, but may be a problem or lead to problems
* `fullogs_error`: Something wrong that's happened
* `fullogs_fatal`: Something wrong that's happened that can't be recovered from

Each of the above logging methods takes in a few parameters:

* `std::string context`: the information necessary to understand what the log is concerned with, or the background necessary to understand where the log is within the grand scheme of things
* `std::string message`: the log itself
* `std::string purpose`: a description of why the log exists and (when applicable, such as for errors) how to mitigate it
* `std::vector<std::string> tags`: an optional parameter for what tags a log has. These can be used for categorization purposes, or to filter specific logs for different loggers.

### Loggers

Loggers' constructors include a few different parameters:

* `std::string format`: how to format logs, see below for details
* `int flags`: optional parameter for which levels to include. Defaults to all (log, debug, alert, warn, error, fatal). Can be manually set in a manner like `Fullogs::LOG | Fullogs::ERROR | Fullogs::FATAL`.
* `std::vector<std::string> tags`: optional parameter which tags to limit this logger to. By default there are no tags, in which case nothing is filtered. Including tags means that *only* logs which include at least one of the tags are considered.

The format string inserts different information into variables within the string. These are:

* `{context}`: the context of the log
* `{message}`: the message of the log
* `{purpose}`: the purpose of the log
* `{level}`: which level of the log lowercased, ie. `log`
* `{iso}`, `{time}`: the iso8601 timestamp of the log
* `{yyyy}`, `{yy}`, `{mm}`, `{dd}`: years, months, days of the timestamp
* `{HH}`, `{MM}`, `{SS}`: hours, minutes, seconds of the timestamp
* `{dayname}`: the full name of the day, ie. `Monday`
* `{day}`: the shortened name of the day, ie. `Mon`
* `{month}`: the full name of the month, ie. `January`
* `{mon}`: the shortened name of the month, ie. `Jan`
* `{file}`: the file that contains the log
* `{line}`: the line that the log happened on
* `{func}`: the function name that the log happened in, ie. `main`
* `{function}`: the decorated function name that the log happened in, ie. `int main()`
* `{tags}`: the list of tags included with this log, comma separated

Loggers have a few different methods for getting logs:

* `getNewLogs()` gets all the logs since the last time this method was called.
* `getAllLogs()` gets every log
* `getLastNLogs(int amount)` gets the most recent logs, up to `amount`

After getting logs, there are multiple ways available to print them or obtain a different usable form:

* `printToStdout()` directly logs to stdout
* `printToStderr()` directly logs to stderr
* `printToFile(std::string filename, bool append)` logs to a file, creating it if it doesn't exist. `append` determines whether or not logging should add to an existing file, or if it should replace its current contents
* `getString()` converts the logs into a single string
* `getStringVector()` converts the logs into a vector of strings
