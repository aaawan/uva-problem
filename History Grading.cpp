
#include<bits/stdc++.h>
#define   rep(i,a,b)     for(int i=a;i<b;i++)
#define   REP(i,a,b)     for(int i=a;i>b;i--)
#define   MS(a,b)        memset(a,b,sizeof(a))
#define   pb             push_back
#define   mp(a,b)        make_pair(a,b)
#define   lcm(a,b)       (a*b)/__gcd(a,b)
#define   xx              first
#define   yy              second
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef pair<double , double> dd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<ll> vl;
typedef priority_queue<int> pq;
typedef priority_queue<int, std::vector<int>, std::greater<int> > pqs;
int n;
int arr[22];
int arr1[22];

int lcs() {
    int table[n+2][n+2];
    rep(i,0,n+1) {
        rep(j,0,n+1) {
            if(i==0 || j==0 )table[i][j]=0;
            else if(arr1[i-1]==arr[j-1]) table[i][j]=table[i-1][j-1]+1;
            else table[i][j]=max(table[i-1][j],table[i][j-1]);

        }
    }
    return table[n][n];




}
main() {
    int x;
    cin>>n;
    rep(i,0,n) {
        cin>>x;
        arr[x-1]=i;
    }
    while(cin>>x) {
        arr1[x-1]=0;
        rep(i,1,n) {
            cin>>x;
            arr1[x-1]=i;
        }
        int ans=lcs();
        cout<<ans<<endl;


    }

}
