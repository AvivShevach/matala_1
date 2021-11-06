#include <stdio.h>

#define TEN 10

int isStrong(int x)   
{
	int a=1,b=0,c=x;
	while (c!=0)
	{
		for(int i=1;i<=c%TEN;i++)
		{
			a*=i;
		}
		b+=a;
		c/=TEN;
		a=1;
	}	
	return b==x;
}

int isPrime(int x)
{
    if(x==2)
		return 1;
	for(int i=2;i<=x/2;i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}
