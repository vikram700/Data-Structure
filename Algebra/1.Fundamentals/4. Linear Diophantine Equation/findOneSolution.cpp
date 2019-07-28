/*
    In this solution we will find one solution for diophantine equation

                    ax + by = c
    
    here we will use extended eucliden algo
                   
                   a*xg + b*yg = gcd(a, b)

                   a * xg + b * yg = g;

                   multiply by c/y to both side

                   a * xg * (c/g) + b * yg * (c/g) = c;

                   so this solution is only present when c%g == 0 mean c should be divible by g.

                   so x0 = xg * (c/g);
                      y0 = yg * (c/g);

 */

#include<bits/stdc++.h>

using namespace std;

#define int long long

int gcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }

    int x1, y1;
    int g = gcd(b, a%b, x1, y1);

    x = y1;
    y = x1 - y1 * (a/b);
    return g;
}


void findOneSolution(int a, int b, int c, int &x0, int &y0, int &g){
    g = gcd(abs(a), abs(b), x0, y0);
    
    cout<<"values of x0 and y0 is : "<<x0<<" "<<y0<<"\n";
    if(c%g){
        cout<<"solution for the equation is not available \n";
        return;
    }

    x0 *= (c/g);
    y0 *= (c/g);

    if(a < 0) x0 = -x0;
    if(b < 0) y0 = -y0;

    cout<<"solution for the problem is present : "<<" ";
    cout<<x0<<" "<<y0<<"\n";

    return;
}


signed main(){
    int a, b, c;
    
    cout<<"enter three values of diophantine equation : "<<"\n";
    cin>>a>>b>>c;
    
    int x0, y0, g;

    findOneSolution(a, b, c, x0, y0, g);
    
    return 0;
}