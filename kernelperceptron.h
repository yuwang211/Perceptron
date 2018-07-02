#ifndef kernelperceptron_h__
#define kernelperceptron_h__

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include "dataset.h"

class KernelPerceptron{
	
	public:
	
		Dataset data;
		
		KernelPerceptron();
		
		~KernelPerceptron();
		
		void init(char *fn);
		
		//kernel function
		
		typedef double(* kernel_func)(double*, double*, int);
		
		kernel_func kernel;
		
		static double KERNEL_LINEAR_FUNC(double *p, double *q, int d);
		static constexpr kernel_func KERNEL_LINEAR = &KERNEL_LINEAR_FUNC;
		
		static double KERNEL_POLY2_FUNC(double *p, double *q, int d);
		static constexpr kernel_func KERNEL_POLY2 = &KERNEL_POLY2_FUNC;
		
		static double KERNEL_POLY3_FUNC(double *p, double *q, int d);
		static constexpr kernel_func KERNEL_POLY3 = &KERNEL_POLY2_FUNC;
		
		static double KERNEL_GAUSSIAN_FUNC(double *p, double *q, int d);
		static constexpr kernel_func KERNEL_GAUSSIAN = &KERNEL_GAUSSIAN_FUNC;
		
		void setKernel(kernel_func f);
		
		
		//algorithm:
		
		void runDeletron(int max_lambda);
		
		
		
		
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
	
		int *lambda;
		double *len;
		
		int w_head;
		double *w_c;
		int *w_next;
		
		
		//tools:
		//return x*x
		static double sqr(double x);
		//return x*x*x
		static double cube(double x);
		// return a /cdot b
		double dot(double *a, double *b);
		// exec a = b
		void cpy(double *a, double *b);
		// exec a = a + b * c
		void add(double *a, double *b, double c = 1);
		// exec a = a * c
		void mul(double *a, double c);
		
		// return a random integer uniformly distributed in [0, 2^28)
		static int random();
	
		KernelPerceptron(const KernelPerceptron&) {}
		KernelPerceptron& operator = (const KernelPerceptron&) {}
		
		
	
};

#include "kernelperceptron.cpp"
#include "kernelperceptron_tools.cpp"
#include "kernelperceptron_statistic.cpp"
#include "kernelperceptron_algorithm.cpp"
#include "kernelperceptron_kernel_function.cpp"

#endif