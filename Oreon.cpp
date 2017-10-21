
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
int parent[26];
int find_set(int x) {
    if(parent[x]==x) return x;
    else find_set(parent[x]);
}
int unit(int x,int y) {
    int fx=find_set(x);
    int fy=find_set(y);
    parent[fx]=fy;
}
main()
{
    int t,n,a,cas=0;
    char ch;
    cin>>t;
    while(t--) {
        cin>>n;
        vector< pair < int , ii > > adj;
        rep(i,0,n) {
            rep(j,0,n-1) {
                cin>>a>>ch;
                if(a) adj.pb(mp(a,mp(i,j)));
            }
            cin>>a;
            if(a) adj.pb(mp(a,mp(i,n-1)));
        }
        rep(i,0,27) parent[i]=i;
        sort(adj.begin(),adj.end());
        printf("Case %d:\n",++cas);
        rep(i,0,adj.size()) {
            int cost=adj[i].xx;
            int x1=adj[i].yy.xx;
            int x2=adj[i].yy.yy;
            if(find_set(x1)!=find_set(x2)) {
                cout<<(char)(65+min(x1,x2))<<'-'<<(char)(65+max(x1,x2))<<' '<<cost<<endl;
                unit(x1,x2);
            }

        }
    }
}


