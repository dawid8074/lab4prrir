#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <math.h>

int main()
{
	int p=6;
	for(int j=0; j<p;j++)
	{
		int x=fork();
		if(x!=0)
		{
		 long int i; 
		 srand(time(NULL) ^ (getpid()<<16));
		 long int n=(rand()%4900)+100;
		 double sum=0.0, term, pi;


		 for(i=0;i< n;i++)
		 {
		  term = pow(-1, i) / (2*i+1);
		  sum += term;
		 }
		 pi = 4 * sum;

		 printf("\nPI = %.6lf\n n wynosi: %ld\n", pi,n);
		 
		 break;
		}

	}
	
}