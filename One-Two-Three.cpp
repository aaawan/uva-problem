#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    string s;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            if(s.length()==5) cout<<3<<endl;
            else if((s[0]=='o' &&s[1]=='n')|| (s[1]=='n' &&s[2]=='e') || (s[0]=='o' &&s[2]=='e')) cout<<1<<endl;
            else cout<<2<<endl;
        }
    }
}
