#pragma once
unsigned long long fractal(const double& num) {
	long long temp = num;
	if (temp == 0)
		return 1;
	long long res=1;
	while (temp > 1) {
		res *= temp;
		temp--;
	}
	return res;
}