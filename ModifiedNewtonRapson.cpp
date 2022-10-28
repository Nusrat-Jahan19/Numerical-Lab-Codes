#include<bits/stdc++.h>
using namespace std;

double error = .0001;
int degree;

double coff[100],coffprime[100],temp[100];

double x0;


double f(double x)
{
    double ans = coff[degree];

    for(int i =degree-1;i>=0;i--)
    {
       ans = ans*x+coff[i];
    }

    return ans;
}

double ff(double x)
{
    for(int i=degree;i>0;i--)
    {
        coffprime[i-1]=coff[i]*i;

    }


     double ans = coffprime[degree-1];

    for(int i =degree-2;i>=0;i--)
    {
       ans = ans*x+coffprime[i];
    }


    return ans;


}



void modifiedNewton(double x0)
{
    double xr=0,c=1;
    while(degree>1)
    {

        while(true)
        {

            double f1 = f(x0);
            double f2 = ff(x0);

            xr = x0-(f1/f2);

            if(fabs((xr-x0)/xr)<error)
            {
                cout<<"Root"<<c<<" "<<xr<<"\n";
                c++;
                break;
            }


                x0=xr;



        }

          temp[degree]=0;
        for(int i=degree;i>0;i--)
        {
            temp[i-1]=coff[i]+xr*temp[i];
        }
        degree--;
        for(int i=0;i<=degree;i++)
        {
            coff[i]=temp[i];
        }
        x0=xr;




    }
    double x=-coff[0]/coff[1];
    cout<<"root"<<c<<" "<<x;

    return;

}

int main()
{
    cout<<"Enter The degree: ";
    cin>>degree;

    cout<<"\nEnter the coffecients:\n";

    for(int i=degree;i>=0;i--)
    {
        cout<<"x^"<<i<<": ";
        cin>>coff[i];

    }


    cout<<"Enter initial guess: ";
    cin>>x0;


    modifiedNewton(x0);

}
