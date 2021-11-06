#include <math.h>

int isArmstrong2( int x, int i)
{
  int k, sum = 0;
  if (x > 0)
   {
     k = x %10;
     sum = pow(k,i);
     return sum +isArmstrong2(x /10, i);
   }
   else
     return 0;
}
int isArmstrong3(int x)
{
    if (x==0)
      return 0;
    return 1+isArmstrong3(x/10);
}
int isArmstrong(int x)
{
   int i=isArmstrong3(x);
  
   return isArmstrong2(x,i)==x;

}

int reverse(int a,int b)
{
    if(a==0)
        return b;
    b= (b*10)+(a%10);
    return reverse(a/10,b);
}
int isPalindrome(int x)
{   int a;
    a = reverse(x,0);
    return x==a;
}

