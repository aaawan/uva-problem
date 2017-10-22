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
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<ll> vl;
typedef priority_queue<int> pq;
typedef priority_queue<int, std::vector<int>, std::greater<int> > pqs;
int parent[1005];
int find_set(int x)
{
    if(parent[x]==x) return x;
    else find_set(parent[x]);
}
int unit(int x,int y)
{
    int fx=find_set(x);
    int fy=find_set(y);
    parent[fx]=fy;
}
main()
{
    int t,n,x,y,x1,x2,y1,y2,state,cas=0;
    double road,rail,a;
    cin>>t;
    while(t--)
    {
        cin>>n>>a;
        vector< ii >node;
        vector< pair < double, ii > >adj;
        rep(i,0,n+2) parent[i]=i;
        rep(i,0,n)
        {
            cin>>x>>y;
            node.pb(mp(x,y));
        }
        rep(i,0,node.size())
        {
            x1=node[i].xx,y1=node[i].yy;
            rep(j,i+1,node.size())
            {
                x2=node[j].xx,y2=node[j].yy;
                double z=sqrt((double)((x1-x2)*(x1-x2) +(y1-y2)*(y1-y2)));
                adj.pb(mp(z,mp(i,j)));
            }
        }
        sort(adj.begin(),adj.end());
        road=rail=0;
        state=1;
        rep(i,0,adj.size())
        {
             double dist=adj[i].xx;
            x=adj[i].yy.xx;
            y=adj[i].yy.yy;
            if(find_set(x)!=find_set(y))
            {
                if(dist<=a)
                {
                    road+=dist;
                }
                else
                {
                    rail+=dist;
                    state++;
                }
                unit(x,y);

            }


        }
        printf("Case #%d: %d %.0f %.0f\n",++cas,state,floor(road+.5),floor(rail+.5));


    }

}



