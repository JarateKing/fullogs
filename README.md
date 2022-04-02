# Fullogs

This is a header-only logging library for C++. The intention is to make some things explicit and encourage best practices by the developer, while also providing flexibility in its usage. Features include:

* multiple levels: logs, debugs, alerts, warnings, errors, and fatal errors
* logs split by intention -- context, message, and help -- to ensure that developers always think to describe all three
* multiple loggers operating on the same logs concurrently
* flexibility between automatic or manual control over when loggers handle new logs

## Usage

Including the header file via `#include "fullogs.h"` is all that's needed to begin using them.
