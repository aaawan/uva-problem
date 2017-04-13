#include<bits/stdc++.h>
#define pp push_back
using namespace std;
main()
{
    int n,i,p,j,k,l=0;
    vector<int>awan,awan1;
    while(cin>>n)
    {
        l=0;
        while(n--)
        {
            for( i=1;i<=10;i++) {
                    cin>>p;
                    awan.pp(p);
                    awan1.pp(p);
        }
        if(l==0) cout<<"Lumberjacks:"<<endl;
        l=1;
        sort(awan1.begin(),awan1.end());
        for( j=0;j<10;j++)
        {
            if(awan[j]!=awan1[j]) break;
        }
        if(j==10) cout<<"Ordered"<<endl;
        else{
            reverse(awan1.begin(),awan1.end());

            for( k=0;k<10;k++)
            {
                if(awan[k]!=awan1[k]) break;

            }
            if(k==10) cout<<"Ordered"<<endl;
            else cout<<"Unordered"<<endl;
        }
        awan1.erase(awan1.begin(),awan1.end());
        awan.erase(awan.begin(),awan.end());
      }
    }
}
