#include<bits/stdc++.h>
using namespace std;

struct Point
{
    double x;
    double y;
};


void bestApproximate(Point *a, int n)
{
    double sum_x = 0;
    double sum_y = 0;
    double sum_xy = 0;
    double sum_x2 = 0;
    for(int i=0; i<n; i++)
    {
        sum_x = sum_x + a[i].x;
        sum_y = sum_y + a[i].y;
        sum_xy = sum_xy + (a[i].x*a[i].y);
        sum_x2 = sum_x2 + (a[i].x*a[i].x);
    }
    double m,c;

    m = ((n*sum_xy) - (sum_x*sum_y))/((n*sum_x2) - pow((sum_x),2));
    c = (sum_y - (m*sum_x))/n;

    cout<<"The gradient of the line is: "<<m<<endl;
    cout<<"The y intercept: "<<c<<endl;
    cout<<"\n";
}


int main()
{
    int n;
    cout<<"Enter the number of points: ";
    cin>>n;

    Point *arr = new Point[n];
    for(int i=0; i<n; i++)
    {
        double x,y;
        cin>>x>>y;
        arr[i].x = x;
        arr[i].y = y;
    }
    bestApproximate(arr, n);
    return 0;
}
