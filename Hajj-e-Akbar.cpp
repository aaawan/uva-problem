#include<bits/stdc++.h>
using namespace std;
main()
{
    int i=1;
    string s;
    while(1)
    {
        cin>>s;
        if(s=="*") return 0;
        else if(s=="Hajj") cout<<"Case "<<i<<": "<<"Hajj-e-Akbar"<<endl;
        else cout<<"Case "<<i<<": "<<"Hajj-e-Asghar"<<endl;
        i++;
    }
}
