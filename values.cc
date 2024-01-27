// CMSC 430 Compiler Theory and Design
// Project 3 Skeleton
// UMGC CITE
// Summer 2023

// This file contains the bodies of the evaluation functions

#include <string>
#include <cmath>

using namespace std;

#include "values.h"
#include "listing.h"

double evaluateArithmetic(double left, Operators operator_, double right) {
	double result;
	switch (operator_) {
		case ADD:
			result = left + right;
			break;
		case SUBTRACT:
            result =  left - right;
            break;
		case MULTIPLY:
			result = left * right;
			break;
		case DIVIDE:
            result = right != 0 ? left / right : 0;
        	break;
        case MODULO:
            result = right != 0 ? std::fmod(left, right) : 0;
			break;
		case EXPONENT:
            result =  std::pow(left, right);
			break;
	}	
	return result;
}

double evaluateRelational(double left, Operators operator_, double right) {
	double result;
	switch (operator_) {
		case LESS:
			result = left < right;
			break;
		case GREATER:
            result = left > right;
            break;
        case LEQ:
            result = left <= right;
            break;
        case GEQ:
            result = left >= right;
            break;
        case EQUAL:
            result = left == right;
            break;
        case NOTEQUAL:
            result = left != right;
            break;
	}
	return result;
}