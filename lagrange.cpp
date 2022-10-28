#include<bits/stdc++.h>
using namespace std;
double sum,f,x[100],y[100],n;
void lagrange(double xp)
{
    for(int i=0;i<n;i++)
    {
      f=1.0;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                f=f*(xp-x[j])/(x[i]-x[j]);
            }
        }
        sum=sum+f*y[i];
    }
    cout<<"The lagrange value is: "<<sum;


}

int main()
{
    sum=0.0;

    double xp;
    cout<<"number of data entry "<<endl;
    cin>>n;
    cout<<"Enter the elements of x and y: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
        cin>>y[i];
    }
    cout<<"Enter the value "<<endl;
    cin>>xp;
    lagrange(xp);

}




