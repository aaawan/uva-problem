//awan-ur-rahman
//CSE,2k15,KUET
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
main()
{
    int fib[1002][502]={0};
    int n;
    fib[0][0]=1;
    fib[1][0]=2;
    rep(i,2,1002) {
        rep(j,0,502) {
            fib[i][j]+=fib[i-1][j]+fib[i-2][j];
            if(fib[i][j]>9) {
                fib[i][j]%=10;
                fib[i][j+1]++;
            }
        }
    }

    while(cin>>n) {
        int i=501;
        while(!fib[n][i]) i--;
        for(;i>=0;i--) cout<<fib[n][i];
        cout<<endl;



    }


}










