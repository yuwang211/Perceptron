#ifndef kernelperceptron_tools_cpp__
#define kernelperceptron_tools_cpp__

double KernelPerceptron::sqr(double x)
{
	return x * x;
}
double KernelPerceptron::cube(double x)
{
	return x * x * x;
}

double KernelPerceptron::dot(double *a, double *b)
{
	double ret = 0;
	for (int i = 0; i <= data.d; ++i)
		ret += a[i] * b[i];
	return ret;
}

void KernelPerceptron::cpy(double *a, double *b)
{
	memcpy(a, b, sizeof(double)*(data.d + 1));
}

void KernelPerceptron::add(double *a, double *b, double c)
{
	for (int i = 0; i <= data.d; ++i)
		a[i] += b[i] * c;
}

void KernelPerceptron::mul(double *a, double c)
{
	for (int i = 0; i <= data.d; ++i)
		a[i] *= c;
}

int KernelPerceptron::random()
{
	return (rand() << 14)^ rand();
}



#endif