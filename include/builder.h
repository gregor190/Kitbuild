#ifndef BUILDER_H
#define BUILDER_H

// Result of any shell command execution
typedef struct {
    int exit_code;
    char* command; // dynamically allocated
} ExecResult;

// Execute a shell command (e.g., compiler or binary)
ExecResult builder_exec(const char* command);

// Invoke a compiler with source, output, and flags
ExecResult builder_invoke(const char* compiler, const char* src_path, const char* out_path, const char** flags, int flag_count);

#endif


