#ifndef MERGE_H
#define MERGE_H

#include "parser.h"

// Ritual to fuse two Config glyphbooks into one
Config merge_configs(const Config* base, const Config* override);

#endif

