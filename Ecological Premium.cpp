#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
main()
{
    int n,m,a,b,c,sum;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>m;
            sum=0;
            for(int j=1;j<=m;j++)
            {
                cin>>a>>b>>c;
                sum+=(a*c);
            }
            cout<<sum<<endl;
        }
    }
}
