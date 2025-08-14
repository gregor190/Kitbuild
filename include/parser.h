#ifndef PARSER_H
#define PARSER_H

#include "config.h"

#define MAX_ENTRIES 64
#define MAX_KEY_LEN 64
#define MAX_VAL_LEN 128

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VAL_LEN];
} Entry;

typedef struct {
    Entry compilers[MAX_ENTRIES];
    int compiler_count;

    Entry flags[MAX_ENTRIES];
    int flag_count;
} Config;

// Loader
int load_config(const char* path, Config* cfg);

// Resolver
const char* resolve_compiler(const Config* cfg, const char* name);
const char* resolve_flags(const Config* cfg, const char* mode);

#endif

