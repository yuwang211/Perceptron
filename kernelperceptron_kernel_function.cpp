#ifndef kernelperceptron_kernel_function_cpp__
#define kernelperceptron_kernel_function_cpp__


double KernelPerceptron::KERNEL_LINEAR_FUNC(double *p, double *q, int d)
{
	double x = 0;
	for (int i = 1; i <= d; ++i)
		x += p[i] * q[i];
	return x;
}

double KernelPerceptron::KERNEL_POLY2_FUNC(double *p, double *q, int d)
{
	double x = 0;
	for (int i = 1; i <= d; ++i)
		x += p[i] * q[i];
	return sqr(x + 1);
}

double KernelPerceptron::KERNEL_POLY3_FUNC(double *p, double *q, int d)
{
	double x = 0;
	for (int i = 1; i <= d; ++i)
		x += p[i] * q[i];
	return cube(x + 1);
}

double KernelPerceptron::KERNEL_GAUSSIAN_FUNC(double *p, double *q, int d)
{
	double x = 0;
	for (int i = 1; i <= d; ++i)
		x += sqr(p[i] - q[i]);
	return exp(-0.5 * x);
}

void KernelPerceptron::setKernel(kernel_func f)
{
	kernel = f;
}

#endif