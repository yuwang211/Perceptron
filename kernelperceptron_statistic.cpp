#ifndef kernelperceptron_statistic_cpp__
#define kernelperceptron_statistic_cpp__



int KernelPerceptron::error()
{
	int ret = 0;
	for (int i = 0; i < data.n; ++i)
	{
		//if (i % 500 == 0)
		//	printf("Check (%d/%d)\n", i, data.n);
		double s = 0;
		for (int j = w_head; j != -1; j = w_next[j])
			s += w_c[j] * kernel(data.point(j), data.point(i), data.d);
		if (data.point(i)[0] * s < 0)
			++ret;
	}
	return ret;
}


int KernelPerceptron::errorMargin(double gamma)
{
}


double KernelPerceptron::expectedX2()
{
}


double KernelPerceptron::R2()
{
	double ret = 0;
	for (int i = 0; i < data.n; ++i)
	{
		double tmp = dot(data.point(i), data.point(i));
		if (tmp > ret) ret = tmp;
	}
	return ret;
}


double KernelPerceptron::D1(double gamma)
{
}


double KernelPerceptron::D2(double gamma)
{
}


double KernelPerceptron::pseudoGamma()
{
}



#endif
