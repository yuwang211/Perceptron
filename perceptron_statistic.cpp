#ifndef perceptron_statistic_cpp__
#define perceptron_statistic_cpp__



int Perceptron::error()
{
	int ret = 0;
	for (int i = 0; i < data.n; ++i)
		if (dot(w, data.point(i)) < 0)
			++ret;
	return ret;
}


int Perceptron::errorMargin(double gamma)
{
	int ret = 0;
	double c = 0;
	for (int i = 0; i <= data.d; ++i)
		c += w[i] * w[i];
	c = sqrt(c);
	for (int i = 0; i < data.n; ++i)
		if (dot(w, data.point(i)) < gamma * c)
			++ret;
	return ret;
}


double Perceptron::expectedX2()
{
	double ret = 0;
	for (int i = 0; i < data.n; ++i)
		ret += dot(data.point(i), data.point(i));
	return ret / data.n;
}


double Perceptron::R2()
{
	double ret = 0;
	for (int i = 0; i < data.n; ++i)
	{
		double tmp = dot(data.point(i), data.point(i));
		if (tmp > ret) ret = tmp;
	}
	return ret;
}


double Perceptron::D1(double gamma)
{
	double ret = 0;
	double c = 0;
	for (int i = 0; i <= data.d; ++i)
		c += w[i] * w[i];
	c = sqrt(c);
	for (int i = 0; i < data.n; ++i)
		if (dot(w, data.point(i)) < gamma * c)
			ret += (gamma - dot(w, data.point(i)) / c);
	return ret;
}


double Perceptron::D2(double gamma)
{
	double ret = 0;
	double c = 0;
	for (int i = 0; i <= data.d; ++i)
		c += w[i] * w[i];
	c = sqrt(c);
	for (int i = 0; i < data.n; ++i)
		if (dot(w, data.point(i)) < gamma * c)
		{
			double tmp = (gamma - dot(w, data.point(i)) / c);
			ret += tmp * tmp;
		}
	return sqrt(ret);
}


double Perceptron::pseudoGamma()
{
	double ret = 1E+20;
	double c = 0;
	for (int i = 0; i <= data.d; ++i)
		c += w[i] * w[i];
	c = sqrt(c);
	for (int i = 0; i < data.n; ++i)
		if (lambda[i] > 0)
		{
			double tmp = dot(w, data.point(i)) / c;
			if (tmp < ret) ret = tmp;
		}
	return ret;
}



#endif
