#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,x,y,sum,p;
    vector<int >awan;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            sum=0;
            cin>>x;
            for(int i=1;i<=x;i++)
            {
                cin>>y;
                awan.push_back(y);
            }
            sort(awan.begin(),awan.end());
            p=awan.size();
            for(int i=1;i<p;i++) sum+=(awan[i]-awan[i-1]);
            cout<<sum*2<<endl;
            awan.erase(awan.begin(),awan.end());
        }
    }
}
