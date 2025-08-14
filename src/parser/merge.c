#include <string.h>
#include "../../include/merge.h"

Config merge_configs(const Config* base, const Config* override) {
    Config merged = {0};

    // Merge compilers
    for (int i = 0; i < base->compiler_count; i++) {
        merged.compilers[merged.compiler_count++] = base->compilers[i];
    }
    for (int j = 0; j < override->compiler_count; j++) {
        if (merged.compiler_count < MAX_ENTRIES) {
            merged.compilers[merged.compiler_count++] = override->compilers[j];
        }
    }

    // Merge flags
    for (int i = 0; i < base->flag_count; i++) {
        merged.flags[merged.flag_count++] = base->flags[i];
    }
    for (int j = 0; j < override->flag_count; j++) {
        if (merged.flag_count < MAX_ENTRIES) {
            merged.flags[merged.flag_count++] = override->flags[j];
        }
    }

    return merged;
}

