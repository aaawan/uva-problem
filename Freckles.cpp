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
int parent[105];
int find_set(int x) {
    if(parent[x]==x) return x;
    else find_set(parent[x]);
}
int unit(int x, int y) {
    int fx=find_set(x);
    int fy=find_set(y);
    parent[fx]=fy;
}
main()
{
    int t,flag=0,n;
    double a,b,x1,y1,x2,y2,cost;
    cin>>t;
    while(t--) {
        cin>>n;
        vector< pair < double, double > > node;
        vector< pair < double , ii> > adj;
        rep(i,0,n){
            cin>>a>>b;
            node.pb(mp(a,b));
        }
        rep(i,0,n) parent[i]=i;
        rep(i,0,node.size()) {
            rep(j,i+1,node.size()) {
                x1=node[i].xx;y1=node[i].yy;
                x2=node[j].xx;y2=node[j].yy;
                double dist=sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
                adj.pb(mp(dist,mp(i,j)));
            }
        }
        cost=0;
        sort(adj.begin(),adj.end());
        rep(i,0,adj.size()) {
            double s= adj[i].xx;
            x1=adj[i].yy.xx;
            x2=adj[i].yy.yy;
            if(find_set(x1)!=find_set(x2)) {
                cost+=s;
                unit(x1,x2);
            }
        }
        if(flag) cout<<endl;
        printf("%.2f\n",cost);
        flag=1;

    }

}


