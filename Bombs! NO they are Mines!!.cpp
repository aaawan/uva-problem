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
typedef pair < pair < int,int >,int > iii;
typedef priority_queue<int, std::vector<int>, std::greater<int> > pqs;
int R,C,arr[1005][1005],start1,start2,dest1,dest2,TIME;
int time1[1005][1005];
int d1[4]= {1,0,-1,0};
int d2[4]= {0,1,0,-1};
main()
{
    int x,y,a,m;
    while(cin>>R>>C,C && R)
    {
        MS(arr,0);
        MS(time1,0);
        cin>>m;
        rep(i,0,m)
        {
            cin>>x>>y;
            rep(j,0,y)
            {
                cin>>a;
                arr[x][a]=1;
            }
        }
        cin>>start1>>start2>>dest1>>dest2;
        queue < ii > Q;
        Q.push((mp(start1,start2)));
        arr[start1][start2]=1;
        while(!Q.empty())
        {
            ii  v=Q.front();
            Q.pop();
            int x=v.xx;
            int y=v.yy;
            rep(i,0,4)
            {
                int a=x+d1[i],b=y+d2[i];
                if(a<R && b<C && a>=0 && b>=0 && !arr[a][b])
                {
                    time1[a][b]=time1[x][y]+1;
                    arr[a][b]=1;
                    Q.push(mp(a,b));
                }
            }

        }
        cout<<time1[dest1][dest2]<<endl;
    }
}


