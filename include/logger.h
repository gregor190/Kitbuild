#ifndef LOGGER_H
#define LOGGER_H

// Log levels for bardic narration
typedef enum {
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_DEBUG
} LogLevel;

// Core narration function
void narrate(LogLevel level, const char* fmt, ...);

// Convenience macros
#define narrate_info(...)  narrate(LOG_INFO, __VA_ARGS__)
#define narrate_warn(...)  narrate(LOG_WARN, __VA_ARGS__)
#define narrate_error(...) narrate(LOG_ERROR, __VA_ARGS__)
#define narrate_debug(...) narrate(LOG_DEBUG, __VA_ARGS__)

#endif

