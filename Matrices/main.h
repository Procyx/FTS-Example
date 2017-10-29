#ifndef main_h
#define main_h

typedef struct s_matrix Matrix;

struct s_matrix
{
    int* values; // Values
    int l; // Lines
    int c; // Columns
};

void main_menu();

void display_matrix(Matrix matrix);

Matrix add_matrices(Matrix matrix1, Matrix matrix2);

Matrix subtract_matrices(Matrix matrix1, Matrix matrix2);

Matrix multiply_matrix_by_n(Matrix matrix, int n);

Matrix multiply_matrix_by_m(Matrix matrix1, Matrix matrix2);

#endif
