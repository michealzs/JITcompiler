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
        case OR:
            return left != 0 || right != 0;
            break;
        case NOT:
            return right == 0 ? 1 : 0;
            break;
	}
	return result;
}



double fold_right(Operators op, vector<double>* list) {
    double result = (list->empty()) ? 0 : list->back(); // Assuming a non-empty list
    for (size_t i = list->size() - 1; i-- > 0; ) {
        result = evaluateArithmetic(list->at(i), op, result);
    }
    return result;
}


double fold_left(Operators op, vector<double>* list) {
    double result = (list->empty()) ? 0 : list->front(); // Assuming a non-empty list
    for (size_t i = 1; i < list->size(); ++i) {
        result = evaluateArithmetic(result, op, list->at(i));
    }
    return result;
}
