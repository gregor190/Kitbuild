#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include "../../include/logger.h"

static const char* level_to_str(LogLevel level) {
    switch (level) {
        case LOG_INFO:  return "📘 INFO";
        case LOG_WARN:  return "⚠️ WARN";
        case LOG_ERROR: return "❌ ERROR";
        case LOG_DEBUG: return "🧪 DEBUG";
        default:        return "❓ UNKNOWN";
    }
}

void narrate(LogLevel level, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    // Optional: timestamp
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    char timebuf[16];
    strftime(timebuf, sizeof(timebuf), "%H:%M:%S", t);

    fprintf(stderr, "[%s] %s: ", timebuf, level_to_str(level));
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");

    va_end(args);
}

