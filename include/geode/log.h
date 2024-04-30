#ifndef GEODE_INTEROP_LOG_H
#define GEODE_INTEROP_LOG_H

#include "utils.h"
#include <stdarg.h>

typedef enum {
    LOG_Severity_DEBUG = 0,
    LOG_Severity_INFO = 1,
    LOG_Severity_WARN = 2,
    LOG_Severity_ERROR = 3
} LogSeverity;

EXTERNC GEODE_INTEROP_API void log_vimpl(LogSeverity severity, const char* fmt, va_list args);

EXTERNC GEODE_INTEROP_API void log_debug(const char* fmt, ...);

EXTERNC GEODE_INTEROP_API void log_info(const char* fmt, ...);

EXTERNC GEODE_INTEROP_API void log_warn(const char* fmt, ...);

EXTERNC GEODE_INTEROP_API void log_error(const char* fmt, ...);

#endif //GEODE_INTEROP_LOG_H