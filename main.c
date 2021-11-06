#include <stdio.h>
#include "NumClass.h"

int main(int argc, char **argv)
{
    int a, b;
    
    if( argc !=3 )
    {
        printf("Usage: main <num1> <num2>\n");
        return 1;
    }
    sscanf(argv[1],"%d", &a);
    sscanf(argv[2],"%d", &b);

  //  printf("Two numbers %d %d\n", a, b);
    printf("The Armstrong numbers are:");
    for(int i=a;i<=b;i++)
    {
        if(isArmstrong(i))
           printf(" %d",i); 
    }
    printf("\n");
      printf("The Palindromes are:");
    for(int i=a;i<=b;i++)
    {
        if(isPalindrome(i))
           printf(" %d",i); 
    }
    
    printf("\n");
    printf("The Prime numbers are:"); 
    for(int i=a;i<=b;i++)
    {
        if(isPrime(i))
           printf(" %d",i); 
    }
  
    printf("\n");
    printf("The Strong numbers are:");
    for(int i=a;i<=b;i++)
    {
        if(isStrong(i))
           printf(" %d",i); 
    }
    printf("\n");
    return 0;
}