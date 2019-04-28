#ifndef DEFINITIONS_HEADER__
    #define DEFINITIONS_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define COMMAND_LENGTH 1000
#define FALSE 0
#define TRUE 1

#define MAX_MATRICES 10
#define MAX_NAME 10
#define STR_MAX_NUMBER 20
#define STR_MAX_MATRIX 20
#define MAX_MATRIX_ROWS 10
#define MAX_MATRIX_COLS 10

#define VARIABLE_MAX_NAME 30
#define MAX_DATA_TYPE 30
#define MAX_VARIABLES 100
#define MAX_ASSIGNMENTS 5

// Structs declaration - Start
typedef struct {
    int numerator, denominator;
} Q;

typedef long double Real;
typedef unsigned int Natural;

struct MATRIX {
    // char name[MAX_NAME];
    int rows;
    int columns;
    Q matrix[MAX_MATRIX_ROWS][MAX_MATRIX_COLS];
};


typedef struct 
{
    char name[VARIABLE_MAX_NAME];
    //void *pt;
    union 
    {
        Natural n;
        int z;
        Q q;
        Real r;
    }
    char data_type[MAX_DATA_TYPE];
} var;
// Structs declaration - End

// Global vars declaration - Start
extern var variables[MAX_VARIABLES];
extern int matrices_qt; // quantity
struct MATRIX matrices[MAX_MATRICES];
// Global vars declaration - End

// Functions declaration - Start
Q q_mult(Q, Q);
Q q_quoc(Q, Q);
Q q_add( Q, Q);
Q q_simplify(Q);
// struct MATRIX escal_mat(); what the heck is this?
// Functions declaration - End


// Back-end functions declarations - Start
int find_matrix(); // search for a matrix by name
int edit_matrix(); // edit the entrances of a matrix
int dump_mat(); // dumb matrix info at exit // what does this really mean?
int add_line(); 
int is_natural();
int is_integer();
int is_rational();
int is_real();
int is_matrix();
char is_validexp();
int is_varname();
int equation_handler();
// Back-end functions declarations - End

// Front-end functions declaratins - Start
int matrices_list();
int show_matrix();
int matrix_insert();
int edit_matrix();
int delete_matrix();
int transpose_matrix();
int matrix_product();
int echelon_matrix();
// Front-end functions declaratins - End

int str_to_q(const char *, Q *);

int var_qt;
#endif