#include <string.h>
#include "../include/parser.h"

const char* resolve_compiler(const Config* cfg, const char* name) {
    for (int i = 0; i < cfg->compiler_count; i++) {
        if (strcmp(cfg->compilers[i].key, name) == 0) {
            return cfg->compilers[i].value;
        }
    }
    return NULL;
}

const char* resolve_flags(const Config* cfg, const char* mode) {
    for (int i = 0; i < cfg->flag_count; i++) {
        if (strcmp(cfg->flags[i].key, mode) == 0) {
            return cfg->flags[i].value;
        }
    }
    return NULL;
}

