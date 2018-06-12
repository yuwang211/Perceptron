#ifndef dataset_cpp__
#define dataset_cpp__

Dataset::~Dataset()
{
	if (!x) free(x);
}
		
void Dataset::loadFile(char *fn)
{
	if (!x) free(x);
	FILE *fin;
	fin = fopen(fn, "rb");
	fread(&n, sizeof(int), 1, fin);
	fread(&d, sizeof(int), 1, fin);
	x = (double *) malloc(sizeof(double) * n * (d + 1));
	fread(x, sizeof(double), n * (d + 1), fin);
	fclose(fin);
}
		
double* Dataset::point(int id)
{
	return x + id * (d + 1);
}


#endif