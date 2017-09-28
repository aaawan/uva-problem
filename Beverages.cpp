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
vi alcohol[105],result;
int visited[105];


main()
{
    int n,m,cas=1;
    string s,s1,s2;
    while(scanf("%d",&n)!=EOF)
    {
        map<int,string>index;
        map<string,int>st,indegree;
        rep(i,0,n)
        {
            cin>>s;
            st[s]=i;
            index[i]=s;
        }
        cin>>m;
        rep(i,0,m)
        {
            cin>>s1>>s2;
            indegree[s2]++;
            alcohol[st[s1]].pb(st[s2]);
        }
        MS(visited,0);
        cout<<"Case #"<<cas++<<": Dilbert should drink beverages in this order:";
        rep(i,0,n)
        {
            rep(j,0,n)
            {
                if(!indegree[index[j]] && !visited[j])
                {
                    visited[j]=1;
                    result.pb(j);
                    rep(k,0,alcohol[j].size())
                    {
                        indegree[index[alcohol[j][k]]]--;
                    }
                    break;
                }
            }
        }
        rep(i,0,result.size()) cout<<" "<<index[result[i]];
        cout<<'.'<<endl<<endl;
        rep(i,0,n) alcohol[i].clear();
        result.clear();


    }
}

