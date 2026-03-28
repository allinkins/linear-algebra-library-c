#ifndef SLAE_H
#define SLAE_H

#include "matrix.h"
#include "vector.h"

int solve_slae_gauss(const Matrix *A, const Vector *b, Vector *x);

#endif