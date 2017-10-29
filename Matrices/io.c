#include "io.h"
#include "utils.h"
#include "main.h"
#include <string.h>
#include <stdlib.h>

// User response with certain size
char* user_response_sized(int size)
{
    char* resp = malloc(size * sizeof(char));
    // Check error
    if(fgets(resp,size+1,stdin) == NULL)
    {
        println("Error: fgets == NULL");
        clear_buffer();
        return 0;
    }
    
    // Format str (clear buffer/remove new line)
    long max = strlen(resp)-1;
    if(resp[max] == '\n')
        resp[max] = '\0';
    else
        clear_buffer();
    
    return resp;
}

// User response with only one character
char user_response()
{
    return *user_response_sized(1);
}

// Lines
int in_lines_count(char name)
{
    printf("How many lines for '%c' ? (From 1 to 99) \n", name);
    char* resp = user_response_sized(2);
    int lines = parse_int(resp);
    
    // Check validity
    if(lines <= 0 || lines >= 100)
    {
        println("Invalid value.");
        return in_lines_count(name);
    }
    
    return lines;
}

// Columns
int in_columns_count(char name)
{
    printf("How many columns for '%c' ? (From 1 to 99) \n", name);
    char* resp1 = user_response_sized(2);
    int columns = parse_int(resp1);
    
    // Check validity
    if(columns <= 0 || columns >= 100)
    {
        println("Invalid value.");
        return in_columns_count(name);
    }
    
    return columns;
}

// Values
int* in_values(char name, int lines, int columns)
{
    printf("What values for '%c' ? (From -200 to 200)\n", name);
    println("-> Use spaces to separate values (Ex: '23 -45 1').");
    
    char* resp3 = user_response_sized(5 * lines*columns);
    int* values = malloc(lines * columns * sizeof(int));
    
    // Initialize values array
    for(int i = 0; i < lines * columns; i++)
        values[i] = 0;
    
    char* token;
    int count = 0;
    
    // Split " " (iteration)
    while ((token = strsep(&resp3, " ")) != NULL)
    {
        int value = parse_int(token);
        if(value < -200 || value > 200)
        {
            printf("Invalid value (%d)\n", value);
            return in_values(name, lines, columns);
        }
        
        values[count] = value;
        count++;
    }
    
    return values;
}

// Multiplier
int in_multiplier()
{
    printf("What is the value of the multiplier 'x' ? (From -200 to 200)\n");
    char* resp1 = user_response_sized(2);
    int mult = parse_int(resp1);
    
    // Check validity
    if(mult < -200 || mult > 200)
    {
        println("Invalid value.");
        return in_multiplier();
    }
    
    return mult;
}

// Full matrix def
Matrix in_matrix(char name)
{
    // Lines
    int lines = in_lines_count(name);
    println("");
    
    // Columns
    int columns = in_columns_count(name);
    println("");
    
    // Values
    int* values = in_values(name, lines, columns);
    println("");
    
    // Setup
    Matrix matrix = { values, lines, columns };
    
    printf("'%c' is a %dx%d matrix:\n", name, lines, columns);
    display_matrix(matrix);
    println("");
    return matrix;
}

// Clear buffer
void clear_buffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
        c = getchar();
}

