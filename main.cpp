#include <cstdio>
#include <ctime>
#include "perceptron.h"

FILE *fout;

void Run(Perceptron &p, int lambda, double gamma)
{
	//MarginDeletron
	clock_t start, finish;  
    start = clock();  
	p.runMarginDeletron(lambda, gamma);
    finish = clock();  
	
	//gamma
	fprintf(fout, "%.4lf ", gamma);
	printf("%.4lf ", gamma);
	//lambda
	fprintf(fout, "%d ", lambda);
	printf("%d ", lambda);
	//error
	fprintf(fout, "%d ", p.error());
	printf("%d ", p.error());
	//margin error
	fprintf(fout, "%d ", p.errorMargin(gamma));
	printf("%d ", p.errorMargin(gamma));
	//D1
	fprintf(fout, "%.4lf ", p.D1(gamma));
	printf("%.4lf ", p.D1(gamma));
	//D2
	fprintf(fout, "%.4lf ", p.D2(gamma));
	printf("%.4lf ", p.D2(gamma));
	//Pseudo gamma
	double pg = p.pseudoGamma();
	fprintf(fout, "%.4lf ", pg);
	printf("%.4lf ", pg);
	//Pseudo margin error
	fprintf(fout, "%d ", p.errorMargin(pg));
	printf("%d ", p.errorMargin(pg));
	//Pseudo D1
	fprintf(fout, "%.4lf ", p.D1(pg));
	printf("%.4lf ", p.D1(pg));
	//Pseudo D2
	fprintf(fout, "%.4lf ", p.D2(pg));
	printf("%.4lf ", p.D2(pg));
	fprintf(fout, "\n");
	printf("\n");
}

int main1(int args, char **argv)
{
	//printf("Lambda = %s, Gamma = %s\n", argv[2], argv[3]);
	Perceptron p;
	p.init(argv[1]);
	clock_t start, finish;  
	

	
	//MarginDeletron
    start = clock();  
	p.runMarginDeletron(atoi(argv[2]), atof(argv[3]));
    finish = clock();  
	
	//gamma
	printf("%.4lf ", atof(argv[3]));
	//lambda
	printf("%d ", atoi(argv[2]));
	//error
	printf("%d ", p.error());
	//margin error
	printf("%d ", p.errorMargin(atof(argv[3])));
	//D1
	printf("%.4lf ", p.D1(atof(argv[3])));
	//D2
	printf("%.4lf ", p.D2(atof(argv[3])));
	//Pseudo gamma
	double pg = p.pseudoGamma();
	printf("%.4lf ", pg);
	//Pseudo margin error
	printf("%d ", p.errorMargin(pg));
	//Pseudo D1
	printf("%.4lf ", p.D1(pg));
	//Pseudo D2
	printf("%.4lf ", p.D2(pg));
	printf("\n");
	

	
	return 0;
}


//const int Lambda[] = {1,50,100,150,200,250,300,350,400,450,500};
const int Lambda[] = {1,5,10,20,30,40,50,60,70,80,90,100};
//const double Gamma[] = {0, 0.02, 0.04, 0.06, 0.08, 0.10, 0.12, 0.14, 0.16, 0.18, 0.2};
//const double Gamma[] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200};
//const double Gamma[] = {0, 0.4, 0.8, 1.2, 1.6, 2.0, 2.4, 2.8, 3.2, 3.6, 4};
const double Gamma[] = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};

int main(int args, char **argv)
{
	fout = fopen(argv[3], "w");
	Perceptron p;
	p.init(argv[1]);
	for (int j = 0; j <= 10; ++j)
	{
		for (int i = 0; i <= 11; ++i)
		{
			Run(p, Lambda[i], Gamma[j] * atof(argv[2]));
		}
		fprintf(fout, "\n");
		printf("\n");
	}
	return 0;
}