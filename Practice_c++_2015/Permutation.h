#pragma once
// Permutation function A!/(A-B)!
#include "fractal.h"
#include <exception>
unsigned long long Perm(const double & A, const double & B) {
	if(B>A)
		throw std::exception("F[Permutation]: negative number!\n");
	return fractal(A) / fractal(A - B);
}