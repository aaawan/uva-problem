#include<bits/stdc++.h>
using namespace std;
main()
{
    int a,b,sum1,sum2;
    while(cin>>a>>b && ( a!=-1 || b!=-1))
    {
        sum1=abs(a-b);
        sum2=100-sum1;
        sum1<sum2 ?cout<<sum1<<endl:cout<<sum2<<endl;
    }
}
