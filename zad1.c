#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
double wzor(double x)
{
	return (4*x)-(6*x)+5;
}
int main (int argc, char *argv[])
{

	int p=6;
	for(int j=0; j<p;j++)
	{
		int x=fork();
		if(x!=0)
		{
			srand(time(NULL) ^ (getpid()<<16));	
			double a=rand()%100;
			double b=rand()%100;
			if(a>b)
			{
				double zmienna=a;
				a=b;
				b=zmienna;
			}
			double n=100;
			//rand()%10000;
			double h = ((b - a) / n);
			double wynik;
			for (int i=0; i<n; i++)
			{
				
				wynik += wzor(a + ((i / n) * (b - a))) + wzor(a + (((i + 1) / n) * (b - a)));

			}
			wynik = (wynik * h) / 2;

			printf("/////////////////////////////////////////////////////////\n metoda pierwsza- A: %f, B: %f, próba N: %f, wynik: %f\n",a,b,n,wynik);
			
			double wynik2;
			h=h/2;
			double t;
			for(int i=0; i<n; i++)
			{
				t=(a+((i/n)*(b-a)))+(a+(((i+1)/n)*(b-a)));
			    	t=t/2;
				wynik2+=wzor(a+((i/n)*(b-a)))+(4*wzor(t))+wzor(a+(((i+1)/n)*(b-a)));
			}
			wynik2=(wynik2*h)/3;
			printf("metoda druga- A: %f, B: %f, próba N: %f, wynik: %f\n",a,b,n,wynik2);
				

			break;
		}

	}

}        
        
     
