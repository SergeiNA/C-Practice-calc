#pragma once
namespace parcl {
	// Combination function A!*B!/(A-B)! or P(A,B)/B!
#include <exception>
#include "Permutation.h"
#include "fractal.h"
	unsigned long long comb(const double & A, const double & B) {
		return Perm(A, B) / fractal(B);
	}
}