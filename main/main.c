#include <stdlib.h>
#include "../include/kitbuild.h"
#include "../include/logger.h"

int kitbuild_run(const char* compiler, const char* src_path, const char* out_path, const char** flags, int flag_count) {
    narrate_debug("🔧 kitbuild_run: compiler=%s, src=%s, out=%s", compiler, src_path, out_path);

    ExecResult result = builder_invoke(compiler, src_path, out_path, flags, flag_count);
    int code = result.exit_code;
    free(result.command);

    return code;
}

