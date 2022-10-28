#include<bits/stdc++.h>
using namespace std;
float x[10],y[10][10];
int n,value;
float proterm(int i)
{
    int pro=1;
    for(int j=0;j<i;j++)
    {
        pro=pro*(value-x[j]);
    }
    return pro;
}


void divide()
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            y[j][i]=(y[j][i-1]-y[j+1][i-1])/(x[j]-x[i+j]);
        }
    }


}


float formula()
{
    float sum=y[0][0];
    for(int i=1;i<n;i++)
    {
        sum=sum+(proterm(i)*y[0][i]);
    }
    return sum;
}


void print()
{
    cout<<"f(x)"<< "\t "<<"f^2(x)"<< "\t "<<"f^3(x)"<< "\t\t "<<"f^4(x)"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<setprecision(4)<<y[i][j]<< "\t ";
        }
        cout<<endl;
    }
}




int main()
{
    cin>>n;
     x[0]=5;
     x[1]=6;
     x[2]=9;
     x[3]=11;
     y[0][0]=12;
     y[1][0]=13;
     y[2][0]=14;
     y[3][0]=16;
     value=7;
     divide();

      print();
      cout<<endl;
     float c=formula();

     cout<<c;

}
