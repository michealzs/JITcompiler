
// This file contains type definitions and the function
// definitions for the evaluation functions
#define MAX_CASES 10
#include <vector>

typedef char* CharPtr;

enum Operators {ADD, SUBTRACT, MULTIPLY, DIVIDE, MODULO, EXPONENT, NEGATE,
    LESS, LEQ, GREATER, GEQ, EQUAL, NOTEQUAL,
    AND, OR, NOT, IMPLIES};

double evaluateArithmetic(double left, Operators operator_, double right);
double evaluateRelational(double left, Operators operator_, double right);
double fold_right(Operators op, vector<double>* list);
double fold_left(Operators op, vector<double>* list);

typedef struct {
    int caseValue;
    double statementValue; 
} Case;
