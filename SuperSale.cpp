
/* 0-1 knapsack */
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
int value[1010];
int weight[1010];

int knapSack(int W, int n) {
   int arr[n+1][W+1];
   for(int i=0;i<=n;i++) {
    for(int j=0;j<=W;j++) {
        if(i==0 || j==0) arr[i][j]=0;
        else if(weight[i-1]<=j) arr[i][j]=max(value[i-1]+arr[i-1][j-weight[i-1]],arr[i-1][j]);
        else arr[i][j]=arr[i-1][j];
    }
   }
   return arr[n][W];
}
main() {
    int n,m,a,b,no,w;

    //freopen("input.txt","r",stdin);
    cin>>n;

    while(n--) {
        cin>>m;
        int sum=0;
        rep(i,0,m)   {
            cin>>a>>b;
            value[i]=a;
            weight[i]=b;
        }
        cin>>no;
        rep(i,0,no) {
            cin>>w;
            sum+=knapSack(w,m);
        }
        cout<<sum<<endl;
    }

}

