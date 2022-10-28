#include<bits/stdc++.h>
#define error .001
using namespace std;

int n;
double ar[100],apr[100],br[100];



double func(double x)
{
    double res=ar[n];

    for(int i=n-1;i>=0;i--)
    {
        res=res*x+ar[i];
    }
    return res;
}
double fprime(double x)
{
    for(int i=n;i>0;i--)
    {
       apr[i-1]=ar[i]*i;
    }
    double res=apr[n-1];
    for(int i=n-2;i>=0;i--)
    {
       res=res*x+apr[i];
    }
    return res;

}


int main()
{
    double f1,f2,f3,x1,x2,f0,xr,x0;
    int c=0;

 cout<<"Enter the highest degree of the equation:";
    cin>>n;
    cout<<"Enter values of coefficients:";
    for(int i=n;i>=0;i--)
    {
        cout<<"Coefficient x["<<i<<"]"<<endl;
        cin>>ar[i];
    }


    cout<<"Enter the initial value:";
    cin>>x0;
     while(n>1)
    {
        while(true)
        {
            double y=func(x0);
            double z=fprime(x0);
            xr=x0-(y/z);
            double err=fabs((xr-x0)/xr);
            if(err<=error)
            {
                cout<<"Iteration "<<c<<"  Root is: "<<xr<<endl;
                c++;
                break;
            }
            x0=xr;
        }
        br[n]=0;
        for(int i=n;i>0;i--)
        {
            br[i-1]=ar[i]+xr*br[i];
        }
        n--;
        for(int i=0;i<=n;i++)
        {
            ar[i]=br[i];
        }
        x0=xr;



    }
    double x=-ar[0]/ar[1];
    cout<<"Iteration "<<c<<"  Root is  "<<x;


}


