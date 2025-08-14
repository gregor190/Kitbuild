#ifndef KITBUILD_H
#define KITBUILD_H

#include "builder.h"

// Top-level Kitbuild invocation
int kitbuild_run(const char* compiler, const char* src_path, const char* out_path, const char** flags, int flag_count);

#endif

