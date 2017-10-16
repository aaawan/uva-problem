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
int parent[100005];
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
    int n,a,b,c,k,weight,weight1,flag=0,m;
    while(cin>>n) {
        weight=weight1=0;
        rep(i,0,n-1) {
            cin>>a>>b>>c;
            weight+=c;
        }
        cin>>k;
        vector< pair <int , ii > > adjacent;
        rep(i,0,k) {
            cin>>a>>b>>c;
            adjacent.pb(mp(c,mp(a,b)));
        }
        cin>>m;
        rep(i,0,m) {
            cin>>a>>b>>c;
            adjacent.pb(mp(c,mp(a,b)));
        }
        rep(i,0,n+1) parent[i]=i;
        sort(adjacent.begin(),adjacent.end());
        int m_edge=0;
        rep(i,0,m+k) {
            int x1=adjacent[i].yy.xx;
            int x2=adjacent[i].yy.yy;
            int w=adjacent[i].xx;
            if(find_set(x1)!=find_set(x2)) {
                weight1+=w;
                unit(x1,x2);
                m_edge++;
                if(m_edge == n-1) break;
            }
        }
        if(flag) {
            cout<<endl;
            flag=1;
        }
        cout<<weight<<endl<<weight1<<endl;

    }
}


