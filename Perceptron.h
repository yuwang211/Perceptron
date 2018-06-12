#ifndef perceptron_h__
#define perceptron_h__

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include "dataset.h"

class Perceptron{
	
	public:
	
		Dataset data;
		
		Perceptron();
		
		~Perceptron();
		
		void init(char *fn);
		
		//algorithms:
		
		void runDeletron(int max_lambda);
		
		void runMarginDeletron(int max_lambda, double gamma = 0);
		
		void runPriorMarginDeletron(int max_lambda, double gamma = 0);
		
		void runPerceptron(int max_lambda);
		
		void runBallceptron(double gamma);
		
		void runRevisedBallceptron(int max_lambda, double gamma);
		
		//statistic
		
		int error();
		
		int errorMargin(double gamma);
		
		double expectedX2();
		
		double R2();
		
		double D1(double gamma);
		
		double D2(double gamma);
		
		double pseudoGamma();
		
		
		
	private:
	
		static constexpr double EPS = 1E-12;
	
		double *w;
		double *y;
		//double gamma;
		int *lambda;
		double *len;
		
		// return a /cdot b
		double dot(double *a, double *b);
		// exec a = b
		void cpy(double *a, double *b);
		// exec a = a + b * c
		void add(double *a, double *b, double c = 1);
		// exec a = a * c
		void mul(double *a, double c);
		
		// return a random integer uniformly distributed in [0, 2^28)
		int random();
	
		Perceptron(const Perceptron&) {}
		Perceptron& operator = (const Perceptron&) {}
		
		
	
};

#include "perceptron.cpp"

#endif