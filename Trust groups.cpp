

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include<cstdio>
#include<cstring>
#include <ctime>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define MS(a,b) memset(a,b,sizeof(a))
#define SI scanint()
#define gc getchar
#define pc putchar
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
int visited[1005],dfs_low[1005],dfs_num[1005],dfsnum,ans;
vi V,adjacent[1005];
int tarscc(int u)
{
    dfsnum++;
    dfs_num[u]=dfs_low[u]=dfsnum;
    V.pb(u);
    visited[u]=1;
    rep(i,0,adjacent[u].size())
    {
        int x=adjacent[u][i];
        if(dfs_num[x]==0) tarscc(x);
        if(visited[x]) dfs_low[u]=min(dfs_low[u],dfs_low[x]);

    }
    if(dfs_low[u]==dfs_num[u])
    {
        ans++;
        while(1)
        {
            int v=V.back();
            V.pop_back();
            visited[v]=0;
            if(u==v) break;
        }


    }

}

main()
{
    int p,t;
    while(scanf("%d %d",&p,&t), ( p || t))
    {
        map<string,int>name1;
        map<int,string>name;
        string s1,s2,s3,s4;
        rep(i,0,p)
        {
            cin>>s1>>s2;
            s3=s1+s2;
            name[i]=s3;
            name1[s3]=i;

        }
        rep(i,0,t)
        {
            cin>>s1>>s2;
            s3=s1+s2;
            cin>>s1>>s2;
            s4=s1+s2;
            adjacent[name1[s3]].pb(name1[s4]);
        }
        MS(visited,0);
        MS(dfs_num,0);
        MS(dfs_low,0);
        dfsnum=ans=0;
        rep(i,0,p) if(dfs_num[i]==0) tarscc(i);
        cout<<ans<<endl;
        rep(i,0,p) adjacent[i].clear();
    }
}
