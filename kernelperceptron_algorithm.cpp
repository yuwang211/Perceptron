#ifndef kernelperceptron_algorithm_cpp__
#define kernelperceptron_algorithm_cpp__


void KernelPerceptron::runDeletron(int max_lambda)
{
	/*for (int i = 0; i < data.n; ++i)
	{
		len[i] = 1.0 / (*kernel)(data.point(i), data.point(i), data.d);
	}*/
	
	w_head = -1;
	memset(w_c, 0, sizeof(double) * data.n);
	memset(w_next, 0x80, sizeof(int) * data.n);
	
	for (int i = 0; i < data.n; ++i)
		lambda[i] = max_lambda;
	int tot = 0;
	bool flag = true;
	int percent = 1;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < data.n; ++i)
		if (lambda[i] > 0)
		{
			/*if ((double)i / (double)data.n * 100.0 >= percent)
			{
				printf("(%d/%d)\n", i, data.n);
				++percent;
			}
			if ((double)i / (double)data.n * 100.0 >= 99)
				printf("(%d/%d)\n", i, data.n);*/
			double s = 0;
			for (int j = w_head; j != -1; j = w_next[j])
				s += w_c[j] * kernel(data.point(j), data.point(i), data.d);
			if (data.point(i)[0] * s < EPS)
			{
				int t = (int)(-s * len[i] - EPS) + 1;
				
				w_c[i] += data.point(i)[0];
				if (w_next[i] < -1)
				{
					w_next[i] = w_head;
					w_head = i;
				}
				
				--lambda[i];
				flag = true;
				++tot;
			}
		}
	}
	//printf("Number of deletion %d\n", tot);
}


#endif