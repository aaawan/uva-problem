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
int value[100];
int arr[50010];
int knapSack(int W, int n) {
   for(int i=0;i<=W;i++) arr[i]=0;
   for(int i=1;i<=n;i++) {
       for(int j=W;j>0;j--) {
        if(value[i]<=j) arr[j]=max(arr[j],value[i]+arr[j-value[i]]);
       }

   }
   return arr[W];
}
main() {
    int n,m,a;

    //freopen("input.txt","r",stdin);
    cin>>n;

    while(n--) {
        cin>>m;
        int sum=0;
        rep(i,1,m+1)   {
            cin>>a;
            value[i]=a;
            sum+=a;
        }
        int z=sum/2;
        int v=knapSack(z,m);
        int d=sum-v;
        cout<<abs(v-d)<<endl;
    }

}

