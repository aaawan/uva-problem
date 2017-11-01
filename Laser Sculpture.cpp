#include<bits/stdc++.h>
#define    rep(a,b,n)   for(int a=b;a<n;a++)
using namespace std;
main()
{
    int n,m;
    while(cin>>n>>m,n&&m) {
        int arr[m+1];
        rep(i,0,m) cin>>arr[i];
        int times=0;
        rep(i,1,m)
            if(arr[i]>arr[i-1])  times+=abs(arr[i]-arr[i-1]);

        cout<<times+(n-arr[m-1])<<endl;
    }
}
