#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<vector>
#define pp push_back
using namespace std;
main()
{
    vector<int>awan;
    int n,p,sum=0,q,s;
    double x,result;
    while(cin>>n)
    {
        for(int j=0;j<n;j++) {
        cin>>p;
        sum=0;s=0;
        for(int i=0;i<p;i++){
            cin>>q;
            awan.pp(q);
            sum+=q;
        }
        x=double(sum)/p;
        for(int i=0;i<p;i++)
        {
            if(awan[i]>x) s++;
        }
        result=((double)s/p)*100;
        printf("%0.3f\%\n",result);

        awan.erase(awan.begin(),awan.end());
        }
    }
}
