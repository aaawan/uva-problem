#include<bits/stdc++.h>
#include<cstdio>
#include<string.h>
#define pp push_back
using namespace std;
main()
{
    int n,m,a,b;
    set<int>awan;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>m;
            for(int i=1;i<=m;i++)
            {
                cin>>a>>b;
                awan.insert(abs(a-b));

            }
            int l=awan.size();
            if(i>1) cout<<endl;
            if(l!=1) cout<<"no"<<endl;
            else cout<<"yes"<<endl;

            awan.erase(awan.begin(),awan.end());
        }


    }
}
