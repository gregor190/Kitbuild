#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/parser.h"

int load_config(const char* path, Config* cfg) {
    FILE* file = fopen(path, "r");
    if (!file) {
        fprintf(stderr, "[SCROLL-ERROR] Could not open config: %s\n", path);
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char key[MAX_KEY_LEN], val[MAX_VAL_LEN];
        if (sscanf(line, " compilers.%[^:]: %[^\n]", key, val) == 2) {
            if (cfg->compiler_count < MAX_ENTRIES) {
                strncpy(cfg->compilers[cfg->compiler_count].key, key, MAX_KEY_LEN);
                strncpy(cfg->compilers[cfg->compiler_count].value, val, MAX_VAL_LEN);
                cfg->compiler_count++;
            }
        } else if (sscanf(line, " flags.%[^:]: %[^\n]", key, val) == 2) {
            if (cfg->flag_count < MAX_ENTRIES) {
                strncpy(cfg->flags[cfg->flag_count].key, key, MAX_KEY_LEN);
                strncpy(cfg->flags[cfg->flag_count].value, val, MAX_VAL_LEN);
                cfg->flag_count++;
            }
        }
    }

    fclose(file);
    return 0;
}

