
/*awan-ur-rahman
/CSE,2k15,KUET */
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
vector< int >blocks[30];

int parent[25];
void pop(int a,int prev)
{
    for(int i=blocks[prev].size()-1;; i-- )
    {
        int u=blocks[prev][i];
        blocks[prev].pop_back();
        if(u==a) return;
        blocks[u].pb(u);
        parent[u]=u;
    }
}

void piling(int a, int prev1,int prev2)
{
    //pos.clear();
    vector<int>pos;
    //cout<<blocks[prev1].size()<<endl;
    for(int i=blocks[prev1].size()-1;; i--)
    {
        int x=blocks[prev1][i];
        pos.pb(x);
        blocks[prev1].pop_back();
        if(x==a) break;
    }
    for(int i=pos.size()-1; i>=0; i--)
    {
        int x=pos[i];
        blocks[prev2].pb(x);
        parent[x]=prev2;
    }
    return ;

}
void move1(int a,int b)
{
    if(parent[a]==parent[b]) return ;
    int prev=parent[a];
    pop(a,prev);
    prev=parent[b];
    pop(b,prev);
    parent[a]=parent[b];
    blocks[prev].pb(b);
    blocks[prev].pb(a);
    return ;
}
void move2(int a,int b)
{
    if(parent[a]==parent[b]) return ;
    int prev=parent[a];
    pop(a,prev);
    prev=parent[b];
    blocks[prev].pb(a);
    parent[a]=parent[b];

}
void pile1(int a,int b)
{
    if(parent[a]==parent[b]) return ;
    int prev2=parent[b];
    pop(b,prev2);
    blocks[prev2].pb(b);
    int prev1=parent[a];
    piling(a,prev1,prev2);
    return ;

}

void pile2(int a,int b)
{
    if(parent[a]==parent[b]) return ;
    int prev2=parent[b];

    int prev1=parent[a];
    piling(a,prev1,prev2);
    return ;
}
main()
{

    int n,a,b;

    cin>>n;
    string str1,str2;
    getchar();
    for(int i=0; i<=n; i++)
    {
        parent[i]=i;
        blocks[i].pb(i);
    }

    while(1)
    {
       cin>>str1;
        if(str1=="quit") break;
       cin>>a>>str2>>b;
        if(str1=="move")
        {

            if(str2=="onto") move1(a,b);
            else  move2(a,b);
        }
        else
        {

            if(str2=="onto") pile1(a,b);
            else  pile2(a,b);
        }

    }
    for(int i=0; i<n; i++)
    {
        cout<<i<<':';
        for(int j=0; j<blocks[i].size(); j++) cout<<' '<<blocks[i][j];
        cout<<endl;

    }


}


