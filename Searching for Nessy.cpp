#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,x,y,sum1,sum2;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y;
            sum1=x/3;
            sum2=y/3;
            cout<<sum1*sum2<<endl;
        }
    }
}
