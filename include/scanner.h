#ifndef SCANNER_H
#define SCANNER_H

#define MAX_TOKENS 128
#define MAX_TOKEN_LEN 64

typedef struct {
    char text[MAX_TOKEN_LEN];
} Token;

typedef struct {
    Token tokens[MAX_TOKENS];
    int count;
} TokenList;

int scan_line(const char* line, TokenList* out);
void print_tokens(const TokenList* list);

#endif

