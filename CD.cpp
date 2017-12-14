
/* problem category: 0_1 knapsack*/
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
int CD[22];
vector< int >seq;
int knapsack(int d,int n) {
    int arr[n+1][d+1];
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=d;j++) {
            if(i==0 || j==0) arr[i][j]=0;
            else if(CD[i-1]<=j) arr[i][j]=max(CD[i-1]+arr[i-1][j-CD[i-1]],arr[i-1][j]);
            else arr[i][j]=arr[i-1][j];

        }
    }
    int w=d;
    for(int i=n;i>0;i--) {
        if(arr[i][w]!=arr[i-1][w]) {
            seq.pb(CD[i-1]);
            w-=CD[i-1];
        }
        if(w==0) break;
    }
    return arr[n][d];

}
main() {
    int d,n;
    while(cin>>d) {
        cin>>n;
        rep(i,0,n) {
            cin>>CD[i];
        }
        seq.clear();
        int ans=knapsack(d,n);
        int l=seq.size();
        for(int i=l-1;i>=0;i--) cout<<seq[i]<<" ";
        cout<<"sum:"<<ans<<endl;

    }

}
