#include<stdio.h>
void main()
{
    int a,b,c;
    float average;
    printf("Enter the three numbers",a,b,c);
    scanf("%d%d%d",&a,&b,&c);
    average = a+b+c/300*100;
    printf("The average is=%f",average);
}