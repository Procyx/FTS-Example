#ifndef io_h
#define io_h

#include <stdio.h>
#include "utils.h"
#include "main.h"

char* user_response_sized(int size);

char user_response();

int in_lines_count(char name);

int in_columns_count(char name);

int* in_values(char name, int lines, int columns);

int in_multiplier();

Matrix in_matrix(char name);

void clear_buffer();

#endif
