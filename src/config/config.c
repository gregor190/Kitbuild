#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/config.h"
#include "../../include/parser.h"  // Assumes parse_config() lives here

void print_config(const Config* cfg) {
    printf("🧾 Config Summary:\n");

    for (int i = 0; i < cfg->compiler_count; i++) {
        printf("🛠️ Compiler[%d]: %s = %s\n", i,
               cfg->compilers[i].key, cfg->compilers[i].value);
    }

    for (int i = 0; i < cfg->flag_count; i++) {
        printf("⚙️ Flag[%d]: %s = %s\n", i,
               cfg->flags[i].key, cfg->flags[i].value);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <config.cfg>\n", argv[0]);
        return 1;
    }

    Config cfg = {0};

    if (!parse_config(argv[1], &cfg)) {
        fprintf(stderr, "❌ Failed to parse config: %s\n", argv[1]);
        return 1;
    }

    print_config(&cfg);
    return 0;
}

