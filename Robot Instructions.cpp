#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define pp push_back
using namespace std;
main()
{

    int t,n,sum;
    string s,q;
    vector<int>awan;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n;
            sum=0;
            while(n--)
            {
                int x;
                cin>>s;
                if(s[0]=='S')
                {
                    cin>>q>>x;
                    sum+=awan[x-1];
                    awan.pp(awan[x-1]);
                }
                else if(s[0]=='L')
                {
                    sum--;
                    awan.pp(-1);
                }
                else
                {
                    sum++;
                    awan.pp(1);
                }

            }
            cout<<sum<<endl;
            awan.erase(awan.begin(),awan.end());
        }
    }

}
