#include <stdio.h>

int isArmstrong(int x)
{
	int i = 0, k = 0, a = 1, n = x, sum = 0;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	n = x;
	while (n != 0)
	{
		k = n % 10;
		for (int j = 0; j < i; j++)
		{
			a *= k;
		}
		sum += a;
		a = 1;
		n /= 10;
	}
	return x == sum;
}

int isPalindrome(int x)
{
	int a = 1, b = 0, n = x,c,d=x;
	while (n != 0)
	{
		b++;
		a *= 10;
		n /= 10;
	}
	b /= 2;
	for (int i = 0; i < b; i++)
	{
		a /= 10;
		c=(x / a)%10;
		if ( c!= d % 10)
			return 0;
		d/=10;
		
	}
	return 1;
}
