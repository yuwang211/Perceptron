#ifndef perceptron_kernel_function_cpp__
#define perceptron_kernel_function_cpp__


double Perceptron::KERNEL_LINEAR_FUNC(double *p, double *q, int d)
{
	double x = 0;
	for (int i = 0; i < d; ++i)
		x += p[i] * q[i];
	return x;
}

double Perceptron::KERNEL_POLY2_FUNC(double *p, double *q, int d)
{
	double x = 0;
	for (int i = 0; i < d; ++i)
		x += p[i] * q[i];
	return sqr(x + 1);
}

double Perceptron::KERNEL_POLY3_FUNC(double *p, double *q, int d)
{
	double x = 0;
	for (int i = 0; i < d; ++i)
		x += p[i] * q[i];
	return cube(x + 1);
}

double Perceptron::KERNEL_GAUSSIAN_FUNC(double *p, double *q, int d)
{
	double x = 0;
	for (int i = 0; i < d; ++i)
		x += sqr(p[i] - q[i]);
	return exp(-0.5 * x);
}

void Perceptron::setKernel(kernel_func f)
{
	kernal = f;
}

#endif