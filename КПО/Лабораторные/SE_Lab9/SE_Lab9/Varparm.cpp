#include"Varparm.h"
int Varparm::ivarparm(int n,...) {
	int result = 1;
	for (int* ptr = &n; n > 0; n--)
	{
		result *= *(++ptr);
	}
	return result;
}
int Varparm::svarparm(short n, ...) {
	int max = -99;
	for (int* ptr = (int*)(&n); n > 0; n--)
	{
		if (*(++ptr) >= max)
		{
			max = *(ptr);
		}
	}
	return max;
}
double Varparm::fvarparm(float a, ...) {
	float* ptr = &a;
	int k = 0;
	float sum = 0;
	while (ptr[k] != FLT_MAX)
	{
		float f = *(ptr + k);
		sum += *(ptr + k);
		k += 8;
	}
	return (double) sum;
}
double Varparm::dvarparm(double a, ...) {

	double* ptr = &a + 1;
	int k = 0;
	float sum = a;
	while (ptr[k] != DBL_MAX)
	{
		sum += *(ptr + k);
		k++;
	}
	return sum;
}
