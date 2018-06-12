#ifndef dataset_h__
#define dataset_h__

#include <cstdio>
#include <cstring>
#include <cstdlib>

class Dataset{
	
	public:
		int n, d;
		double *x;
		
		Dataset(): n(0), d(0), x(NULL) {}
		~Dataset();
		
		void loadFile(char *fn);
		
		double* point(int id);
		
	private:
		Dataset(const Dataset&) {}
		Dataset& operator = (const Dataset&) {}
	
};

#include "dataset.cpp"

#endif