
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
typedef pair<int , int> ii;
typedef pair<double , double> dd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<ll> vl;
typedef priority_queue<int> pq;
typedef priority_queue<int, std::vector<int>, std::greater<int> > pqs;
char grid[105][105];
int visited[105][105];
int r[9]={1,1,0,-1,-1,-1,0,1};
int c[9]={0,1,1,1,0,-1,-1,-1};
int ans,R,C;
int dfs(int x,int y) {
    visited[x][y]=1;
    ans++;
    rep(i,0,8) {
        int a=x+r[i],b=y+c[i];
        if(a>=0 && a<R && b>=0 && b<C && !visited[a][b] && grid[a][b]=='W') dfs(a,b);
    }


}
main()
{
    int cas,r,c;
    char str[100];
    scanf("%d\n\n",&cas);
    rep(t,1,cas+1) {
        R=C=0;
        bool x=false;
        if(t!=1) x=true;;
        while( gets(str) && strlen(str)>0){
            if(str[0]=='W'|| str[0]=='L') {
                C=strlen(str);
                rep(i,0,C) grid[R][i]=str[i];
                R++;
            }
            else {
                sscanf(str,"%d %d",&r,&c);
                //cout<<r<<" "<<c<<endl;
                MS(visited,0);
                ans=0;
                dfs(r-1,c-1);
                if(x) {
                    cout<<endl;
                    x=false;
                }
                cout<<ans<<endl;
            }



        }




    }

}
