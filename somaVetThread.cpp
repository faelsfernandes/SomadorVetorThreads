#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Digite o tamanho do vetor. \n");
		exit(1);
	}

	float *a =(float*)malloc(atoi(argv[1])*sizeof(float));;
	float *b =(float*)malloc(atoi(argv[1])*sizeof(float));;
	float *c =(float*)malloc(atoi(argv[1])*sizeof(float));;

	for(int i = 0; i < atoi(argv[1]); i++)
	{
		a[i] = i;
		b[i] = i;
	}
	int id;
	int nt;
	#pragma omp parallel num_threads(2)
	{	

		#pragma omp for
		for(int i = 0; i < atoi(argv[1]); i++)
		{
			c[i] = a[i] + b[i];
		}
	}
}