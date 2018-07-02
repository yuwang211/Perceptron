#ifndef kernelperceptron_cpp__
#define kernelperceptron_cpp__

KernelPerceptron::KernelPerceptron()
{
	lambda = NULL;
	len = NULL;
	w_c = NULL;
	w_next = NULL;
}

KernelPerceptron::~KernelPerceptron()
{
	if (!lambda) free(lambda);
	if (!len) free(len);
	if (!w_c) free(w_c);
	if (!w_next) free(w_next);
}

void KernelPerceptron::init(char *fn)
{
	data.loadFile(fn);
		
	lambda = (int *)malloc(sizeof(int) * data.n);
	len = (double *)malloc(sizeof(double) * data.n);
	
	
	w_c = (double *)malloc(sizeof(double) * data.n);
	w_next = (int *)malloc(sizeof(int) * data.n);

	//printf("Dataset [%s] contains %d points of %d dimension\n", fn, data.n, data.d);
}




#endif