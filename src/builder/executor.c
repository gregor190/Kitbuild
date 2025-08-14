#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/builder.h"
#include "../../include/logger.h"

ExecResult builder_exec(const char* command) {
    narrate_info("🧾 Executing: %s", command);
    int exit_code = system(command);

    if (exit_code != 0) {
        narrate_warn("⚠️ Command failed with exit code %d", exit_code);
    } else {
        narrate_debug("✅ Command succeeded.");
    }

    ExecResult result = {
        .exit_code = exit_code,
        .command = strdup(command) // caller must free
    };
    return result;
}

