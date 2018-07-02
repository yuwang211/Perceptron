#ifndef perceptron_tools_cpp__
#define perceptron_tools_cpp__

double Perceptron::sqr(double x)
{
	return x * x;
}
double Perceptron::cube(double x)
{
	return x * x * x;
}

double Perceptron::dot(double *a, double *b)
{
	double ret = 0;
	for (int i = 0; i <= data.d; ++i)
		ret += a[i] * b[i];
	return ret;
}

void Perceptron::cpy(double *a, double *b)
{
	memcpy(a, b, sizeof(double)*(data.d + 1));
}

void Perceptron::add(double *a, double *b, double c)
{
	for (int i = 0; i <= data.d; ++i)
		a[i] += b[i] * c;
}

void Perceptron::mul(double *a, double c)
{
	for (int i = 0; i <= data.d; ++i)
		a[i] *= c;
}

int Perceptron::random()
{
	return (rand() << 14)^ rand();
}



#endif