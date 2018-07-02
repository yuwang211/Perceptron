#ifndef perceptron_cpp__
#define perceptron_cpp__

Perceptron::Perceptron()
{
	w = NULL;
	lambda = NULL;
	len = NULL;
	y = NULL;
}

Perceptron::~Perceptron()
{
	if (!w) free(w);
	if (!lambda) free(lambda);
	if (!len) free(len);
	if (!y) free(y);
}

void Perceptron::init(char *fn)
{
	data.loadFile(fn);
		
	w = (double *)malloc(sizeof(double) * (data.d + 1));
	y = (double *)malloc(sizeof(double) * (data.d + 1));
	lambda = (int *)malloc(sizeof(int) * data.n);
	len = (double *)malloc(sizeof(double) * data.n);
	
	
	double *cur = data.x;
	for (int i = 0; i < data.n; ++i)
	{
		double tmp = (*(cur++));
		len[i] = 1;
		for (int j = 1; j <= data.d; ++j)
		{
			len[i] += (*cur) * (*cur);
			(*(cur++)) *= tmp;
		}
		len[i] = 1.0 / len[i];
	}
	//printf("Dataset [%s] contains %d points of %d dimension\n", fn, data.n, data.d);
}




#endif