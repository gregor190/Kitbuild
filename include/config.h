#ifndef CONFIG_H
#define CONFIG_H

#define MAX_ENTRIES 32
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

    // Future: build rules, architecture, etc.
} Config;

#endif

