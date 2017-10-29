#include <stdio.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>
#include <assert.h>
#include "main.h"
#include "utils.h"
#include "io.h"

// Main func
int main(int argc, const char * argv[])
{
    println("Welcome in Matrices Calculator!\n");
    main_menu();
    return 0;
}

// Program main menu
void main_menu()
{
    println("What do you want to do?");
    println("\t- A: Adding two matrices");
    println("\t- B: Subtracting two matrices");
    println("\t- C: Multiplying a matrix by a number");
    println("\t- D: Multiplying two matrices");
    println("\t- E: Exit");
    
    char resp = user_response();
    
    // Handle response
    switch(resp)
    {
        case 'A':
        case 'a':
            println("Operation: A+B:");
            Matrix matrix1 = in_matrix('A');
            
            int* values2 = in_values('B', matrix1.l, matrix1.c);
            println("");
            Matrix matrix2 = { values2, matrix1.l, matrix1.c };
            printf("'%c' is a %dx%d matrix:\n", 'B', matrix2.l, matrix2.c);
            display_matrix(matrix2);
            println("");
            
            println("A+B result:");
            display_matrix(add_matrices(matrix1, matrix2));
            println("\n");
            main_menu();
            break;
        case 'B':
        case 'b':
            println("Operation: A-B:");
            Matrix matrix3 = in_matrix('A');
            
            int* values4 = in_values('B', matrix3.l, matrix3.c);
            println("");
            Matrix matrix4 = { values4, matrix3.l, matrix3.c };
            printf("'%c' is a %dx%d matrix:\n", 'B', matrix4.l, matrix4.c);
            display_matrix(matrix4);
            println("");
            
            println("A+B result:");
            display_matrix(subtract_matrices(matrix3, matrix4));
            println("\n");
            main_menu();
            break;
        case 'C':
        case 'c':
            println("Operation: A*x:");
            Matrix matrix5 = in_matrix('A');
            
            int multiplier = in_multiplier();
            printf("\n%d*A result:\n", multiplier);
            display_matrix(multiply_matrix_by_n(matrix5, multiplier));
            println("\n");
            main_menu();
            break;
        case 'D':
        case 'd':
            println("Operation: A*B:");
            Matrix matrix6 = in_matrix('A');
            
            int columns7 = in_columns_count('B');
            println("");
            int* values7 = in_values('B', matrix6.c, columns7);
            println("");
            Matrix matrix7 = { values7, matrix6.c, columns7 };
            printf("'%c' is a %dx%d matrix:\n", 'B', matrix7.l, matrix7.c);
            display_matrix(matrix7);
            println("");
            
            println("A*B result:");
            display_matrix(multiply_matrix_by_m(matrix6, matrix7));
            println("\n");
            main_menu();
            break;
        case 'E':
        case 'e':
            println("Good bye!");
            exit(0);
        default:
            println("Your response is invalid.\n");
            main_menu();
    }
}

// Return the value to this element [x,y] of the given matrix
int matrix_get(Matrix matrix, int x, int y)
{
    // Close the program if x/y is cannot be in the given matrix
    assert(x < matrix.c && y < matrix.l);
    return matrix.values[(y * matrix.c) + x];
}

// Set a value to the element [x,y] of the given matrix
void matrix_set(Matrix matrix, int x, int y, int n)
{
    // Close the program if x/y is cannot be in the given matrix
    assert(x < matrix.c && y < matrix.l);
    matrix.values[(y * matrix.c) + x] = n;
}

// Add two matrices
Matrix add_matrices(Matrix matrix1, Matrix matrix2)
{
    // Close the program if the addition is impossible
    assert(matrix1.l == matrix2.l && matrix1.c == matrix2.c && matrix1.c && matrix1.l);
    Matrix newMatrix = { (int*)malloc(matrix1.l * matrix1.c * sizeof(int)), matrix1.l, matrix1.c };
    
    for(int i = 0; i < matrix1.l; i++)
        for(int j = 0; j < matrix2.c; j++)
            matrix_set(newMatrix, j, i, matrix_get(matrix1, j, i) + matrix_get(matrix2, j, i));
    
    return newMatrix;
}

// Substract two matrices
Matrix subtract_matrices(Matrix matrix1, Matrix matrix2)
{
    // Close the program if the substraction is impossible
    assert(matrix1.l == matrix2.l && matrix1.c == matrix2.c && matrix1.c && matrix1.l);
    Matrix newMatrix = { (int*)malloc(matrix1.l * matrix1.c * sizeof(int)), matrix1.l, matrix1.c };
    
    for(int i = 0; i < matrix1.l; i++)
        for(int j = 0; j < matrix2.c; j++)
            matrix_set(newMatrix, j, i, matrix_get(matrix1, j, i) - matrix_get(matrix2, j, i));
    
    return newMatrix;
}

// Multiply two matrices
Matrix multiply_matrix_by_m(Matrix matrix1, Matrix matrix2)
{
    // Close the program if the multiplication is impossible
    assert(matrix1.c && matrix2.c && matrix1.l && matrix1.c == matrix2.l);
    Matrix newMatrix = { (int*)malloc(matrix1.l * matrix2.c * sizeof(int)), matrix1.l, matrix2.c };
    
    for(int i = 0; i < matrix1.l; i++)
        for(int j = 0; j < matrix2.c; j++)
        {
            int coeffValue = 0;
            for(int l = 0; l < matrix1.c; l++)
                coeffValue += matrix_get(matrix1, l, i) * matrix_get(matrix2, j, l);
            
            matrix_set(newMatrix, j, i, coeffValue);
        }
    
    return newMatrix;
}

// Multiply a matrice by a number
Matrix multiply_matrix_by_n(Matrix matrix, int n)
{
    // Close the program if the multiplication is impossible
    assert(matrix.c && matrix.l);

    Matrix newMatrix = matrix;
    newMatrix.values = (int*)malloc(matrix.l * matrix.c * sizeof(int));

    for(int i = 0; i < matrix.l; i++)
        for(int j = 0; j < matrix.c; j++)
            matrix_set(newMatrix, j, i, matrix_get(matrix, j, i) * n);
    
    return newMatrix;
}

// Pretty print for matrices
void display_matrix(Matrix matrix)
{
    // Create an array to save max digits per column
    int *maxDigit = malloc(matrix.c * sizeof(int));
    
    // Initialize array
    for (int j=0;j<matrix.c;j++)
        maxDigit[j]= 0;
    
    // Looking for maxDigits
    for(int i = 0; i < matrix.l; i++)
        for(int j = 0; j < matrix.c; j++)
        {
            int value = matrix_get(matrix, j, i), digits = nDigits(value);
            
            if(digits > maxDigit[j])
                maxDigit[j] = digits;
        }
    
    // Print matrice
    for(int i = 0; i < matrix.l; i++)
    {
        if(i == 0)
            printf("\t| ");
        else
            printf(" |\n\t| ");
        
        for(int j = 0; j < matrix.c; j++)
        {
            int value = matrix_get(matrix, j, i), digits = nDigits(value);
            
            if(j == matrix.c-1)
                printf("%d", value);
            else
                printf("%d ", value);
            
            for(int x = 0; x < maxDigit[j]-digits; x++)
                printf(" ");
        }
    }
    printf(" |\n");
}
