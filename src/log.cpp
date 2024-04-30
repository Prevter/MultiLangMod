#include <geode/log.h>
#include <fmt/args.h>

EXTERNC GEODE_INTEROP_API void log_vimpl(LogSeverity severity, const char* fmt, va_list args) {
    char buffer[1024];
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    switch (severity) {
        case LOG_Severity_DEBUG:
            geode::log::debug("{}", buffer);
            break;
        case LOG_Severity_INFO:
            geode::log::info("{}", buffer);
            break;
        case LOG_Severity_WARN:
            geode::log::warn("{}", buffer);
            break;
        case LOG_Severity_ERROR:
            geode::log::error("{}", buffer);
            break;
    }
}

EXTERNC GEODE_INTEROP_API void log_debug(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    log_vimpl(LOG_Severity_DEBUG, fmt, args);
    va_end(args);
}

EXTERNC GEODE_INTEROP_API void log_info(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    log_vimpl(LOG_Severity_INFO, fmt, args);
    va_end(args);
}

inline void log_warn(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    log_vimpl(LOG_Severity_WARN, fmt, args);
    va_end(args);
}

EXTERNC GEODE_INTEROP_API void log_error(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    log_vimpl(LOG_Severity_ERROR, fmt, args);
    va_end(args);
}