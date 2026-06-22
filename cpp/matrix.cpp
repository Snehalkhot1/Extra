#include<iostream>
using namespace std;
int main()
{
    int i,j;
    int a[2][2];
    int b[2][2];
    int c[2][2];
    cout<<"Enter the elements of matrix a\n:";
    for(i=0;i<1;i++)
    {
        for(j=0;j<=1;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"Enter the matrix elements of matrix b\n:";
    for(i=0;i<=1;i++)
    {
        for(j=0;j<=1;j++)
        {
            cin>>b[i][j];
        }
    }
    for(i=0;i<=1;i++)
    {
        for(j=0;j<=1;j++)
        {
        c[i][j]=a[i][j]+b[i][j];
    }
}
cout<<"addition of two matrix is\n";
for(i=0;i<=1;i++)
{
    for(j=0;j<=1;j++)
    {
        cout<<c[i][j]<<" ";
    }
    return 0;

}
}