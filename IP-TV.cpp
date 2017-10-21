
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
int parent[2005];

int find_set(int x) {
    if(parent[x]==x) return x;
    else find_set(parent[x]);
}

int unit(int x,int y) {
    int fx=find_set(x);
    int fy=find_set(y);
    parent[fy]=fx;
}

main()
{
   int t,cost,n,m,flag=0;
   string str1,str2;
   cin>>t;
   while(t--) {
        cin>>m>>n;
        map< string ,int >s1;
        //map< int,string  >s2;
        vector <pair <int , ii > >adj;
        int num=1;
        rep(i,0,n) {
            cin>>str1>>str2>>cost;
            if(s1[str1]==0) s1[str1]=num++;
            //s2[num]=str1;
            if(s1[str2]==0) s1[str2]=num++;
            //s2[num]=str2;
            adj.pb(mp(cost,mp(s1[str1],s1[str2])));
        }
        //for(int i=2;i<=m;i++) cout<<s2[i]<<" ";
        sort(adj.begin(),adj.end());
        int total=0;
        rep(i,0,2005) parent[i]=i;
        for(int i=0;i<adj.size();i++) {
            int x=adj[i].xx;
            int y=adj[i].yy.xx;
            int z=adj[i].yy.yy;
            if(find_set(y)!=find_set(z)) {
                total+=x;
                unit(y,z);
            }
        }
        if(flag) cout<<endl;
        cout<<total<<endl;
        flag=1;


   }

}


