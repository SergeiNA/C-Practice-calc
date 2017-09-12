#pragma once
#include <exception>
#include "Permutation.h"
#include "fractal.h"
unsigned long long comb(const double & A, const double & B) {
	return Perm(A, B) / fractal(B);
}