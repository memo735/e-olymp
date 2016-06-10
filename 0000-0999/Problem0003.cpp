#include <cstdlib>
#include <iostream>
#include <cmath>
 
using namespace std;
 
int main()
{
    double n, k=1, i=0, r, r1;
    cin>>n;
    for (; k<n ; ++i) k=pow(i+1,3);
    if (!i) i++;

    if ((i-1)*(i-1)*(i-1)<n && n<=(i-1)*(i-1)*i)
    {
        r=3*(i-1)*pow(i,2);									// 3n(n+1)^2
        n=n-pow(i-1,3);            
    }
    else
        if ((i-1)*(i-1)*i<n && n<=(i-1)*i*i)
        {
            r = 3*pow(i-1,3) + 9*pow(i-1,2) + 7*(i-1) + 1; // 3n^3 + 9n^2 + 7n + 1
            n=n-pow(i-1,2)*i;
        }
        else
            if ((i-1)*i*i<n && n<=i*i*i )
            {
                r = 3*(pow(i,3) + pow(i,2))-i-1;     		// 3n^3 + 3n^2 -n-1
                n=n-pow(i,2)*(i-1);
            }
            else
            {
                cout << i << "???";
                return 0;
            }
    for (int i1=1; n; i1+=2)
    {
        for (int i2=0; i2<i1 && n; i2++, n--)
        {
            if (i1 == 1) r=r+8;    
            else
                if (i2 == 0 || i2 == i1/2) r=r+5;
                else r=r+3;                    
        }
                   
    }
    cout << r << endl;
    return 0;
}
