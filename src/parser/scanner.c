#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/scanner.h"

int scan_line(const char* line, TokenList* out) {
    out->count = 0;
    const char* p = line;
    while (*p) {
        while (isspace(*p)) p++;  // Skip whitespace
        if (*p == '\0' || *p == '#') break;  // End or comment

        char buf[MAX_TOKEN_LEN] = {0};
        int i = 0;

        // Capture token until space, colon, or newline
        while (*p && !isspace(*p) && *p != ':' && *p != '\n') {
            if (i < MAX_TOKEN_LEN - 1) buf[i++] = *p;
            p++;
        }

        if (i > 0) {
            strncpy(out->tokens[out->count].text, buf, MAX_TOKEN_LEN);
            out->count++;
        }

        if (*p == ':') {
            out->tokens[out->count].text[0] = ':';
            out->tokens[out->count].text[1] = '\0';
            out->count++;
            p++;
        }
    }

    return out->count;
}

void print_tokens(const TokenList* list) {
    for (int i = 0; i < list->count; i++) {
        printf("[TOKEN] %s\n", list->tokens[i].text);
    }
}

