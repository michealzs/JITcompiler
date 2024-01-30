// CMSC 430 Compiler Theory and Design
// Project 3 Skeleton
// UMGC CITE
// Summer 2023

// This file contains type definitions and the function
// definitions for the evaluation functions

typedef char* CharPtr;

enum Operators {ADD, SUBTRACT, MULTIPLY, DIVIDE, MODULO, EXPONENT, NEGATE,
    LESS, LEQ, GREATER, GEQ, EQUAL, NOTEQUAL,
    AND, OR, NOT, IMPLIES};

double evaluateArithmetic(double left, Operators operator_, double right);
double evaluateRelational(double left, Operators operator_, double right);
