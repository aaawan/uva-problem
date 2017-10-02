//awan-ur-rahman
//CSE,2K15,KUET
#include<bits/stdc++.h>
#define   rep(i,a,b)     for(int i=a;i<b;i++)
#define   REP(i,a,b)     for(int i=a;i>b;i--)
#define   MS(a,b)        memset(a,b,sizeof(a))
#define   pb             push_back
#define   mp(a,b)        make_pair(a,b)
#define   lcm(a,b)       (a*b)/__gcd(a,b)
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
set<string>SET;
vi adjacent[27],V;
int dfs_num[27],dfs_low[27],dfsnum,visited[27],alp[27],cas=0;
int tarscc(int u)
{
    dfs_low[u]=dfs_num[u]=dfsnum++;
    visited[u]=1;
    V.pb(u);
    rep(i,0,adjacent[u].size())
    {
        int x=adjacent[u][i];
        if(!dfs_num[x]) tarscc(x);
        if(visited[x]) dfs_low[u]=min(dfs_low[u],dfs_low[x]);
    }
    if(dfs_low[u]==dfs_num[u])
    {
        int d=0;
        char s1[27];
        while(1)
        {

            int v=V.back();
            V.pop_back();
            visited[v]=0;
            s1[d++]=(char)(v+65);
            if(u==v) break;
        }
        s1[d]='\0';
        string str(s1);
        sort(str.begin(),str.end());
        SET.insert(str);
    }

}

main()
{
    int n,flag=0;
    char arr[6],ch;
    while(scanf("%d",&n), n)
    {
        MS(alp,0);
        while(n--)
        {
            rep(i,0,5)
            {
                cin>>arr[i];
                alp[arr[i]-'A']=1;
            }

            cin>>ch;
            rep(i,0,5)
            {
                if(ch!=arr[i])  adjacent[ch-'A'].pb(arr[i]-'A');
            }
        }
        //for(int i=0;i<27;i++) cout<<i<<" "<<alp[i]<<endl;;

        MS(visited,0);
        MS(dfs_low,0);
        MS(dfs_num,0);
        dfsnum=0,cas=0;
        rep(i,0,27)
        {
            if(!dfs_num[i] && alp[i]) tarscc(i);
        }
        if(flag) cout<<endl;
        flag=1;
        for(auto i=SET.begin(); i!=SET.end(); i++)
        {
            printf("%c",(*i)[0]);
            for(auto j=1; j<(*i).length(); j++) printf(" %c",(*i)[j]);
            cout<<endl;
        }
        rep(i,0,27) adjacent[i].clear();
        SET.clear();
        V.clear();


    }
    return 0;
}


