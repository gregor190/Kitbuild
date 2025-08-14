#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/builder.h"
#include "../../include/logger.h"

ExecResult builder_invoke(const char* compiler, const char* src_path, const char* out_path, const char** flags, int flag_count) {
    char command[1024] = {0};
    snprintf(command, sizeof(command), "%s -o %s %s", compiler, out_path, src_path);

    for (int i = 0; i < flag_count; ++i) {
        strncat(command, " ", sizeof(command) - strlen(command) - 1);
        strncat(command, flags[i], sizeof(command) - strlen(command) - 1);
    }

    narrate_info("🔨 Compiler command prepared: %s", command);
    return builder_exec(command);
}

