
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
#define inf -1
#define gc getchar
#define pc putchar
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
int visited[305],color[305];
queue<int>Q;
main()
{
    int n,a,b;
    while(cin>>n,n) {
            vi adjacent[n+2];
        while(scanf("%d %d",&a,&b),( a && b)) {
            adjacent[a].pb(b);
            adjacent[b].pb(a);
        }
        MS(visited,0);
        MS(color,0);
        bool isbipartite=true;
        color[1]=0;
        Q.push(1);
        while(!Q.empty()){
            int x=Q.front();
            Q.pop();
            visited[x]=1;
            rep(i,0,adjacent[x].size()) {
                if(!visited[adjacent[x][i]]) {
                    color[adjacent[x][i]]=1-color[x];
                    Q.push(adjacent[x][i]);
                }
                else if(color[adjacent[x][i]]==color[x]) isbipartite=false;

            }
        }
        if(isbipartite) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}
