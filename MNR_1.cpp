#include<bits/stdc++.h>
using namespace std;


double horners(double coeff[], int n, double x)
{
    double res= 0;

    for(int i=0; i<=n; i++)
    {
        res = res*x + coeff[i];
    }
    return res;
}



double df(double poly[], int n,double x)
{
    double value = 0;poly
    int i;
    for(i=0; i<n; i++)
    {
        value = value*x + (n-i)*poly[i];
    }
    return value; 


}

int main()
{
    int n,c = 0;
    double x, x1,f1, f2,e;
    double  coeff[n+1], temp[n+1];

    cout<<"\n Enter the highest degree of the equation: ";
    cin>>n;

    cout<<"\n Enter values of coefficients:\n ";
    for(int i=0;i<=n;i++)
    {
        cout<<"\n Coefficient x["<<n-i<<"]:" ;
        cin>>coeff[i];
    }

    cout<<"\n Enter the initial approximation:";
    cin>>x;


    while(n>1)
    {
        int k=1;
        do
        {
           c = 0;
           for(int i=0;i<=n;i++)
           {
                if(coeff[i]!= 0)
                    c++;
            }
            if(c == 1)
            break;
            c = 0;
            do{
                f1 = horners(coeff, n,x);
                f2 = df(coeff, n,x);
                if(f2==0)
                {

                }
                x1 = x - (f1/f2);
                e = fabs((x1-x)/x1);
                x = x1;
                c++;
                if(c > 100)
                    break ;
            }while(e>0.0001);

          cout<<" Iteration "<<k<<"    Root is: "<<x<<endl;


            temp[0] = coeff[0];
            for(int i=1;i<=n;i++)
            {
                temp[i] = (temp[i-1]*x)+coeff[i];
            }
            n = n-1;
            for(int i=0;i<=n;i++)
            {
                coeff[i] = temp[i];

            }

            k++;

        }while(n>0);

    }

 cout<<"\n Root: "<<x;

}
