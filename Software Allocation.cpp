//problem category: maxflow
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
int flow[40][40],capacities[40][40],parent[40];
void augment() {
    int current=37;
    while(current!=0) {
        int prev=parent[current];
        flow[prev][current]++;
        flow[current][prev]--;
        current=prev;
    }

}
bool bfs() {
    MS(parent,-1);
    queue<int>Q;
    Q.push(0);
    parent[0]=-2;
    while(!Q.empty()) {
        int u=Q.front();
        Q.pop();
        for(int i=0;i<38;i++) {
            if(capacities[u][i]>flow[u][i] && parent[i]==-1) {
                parent[i]=u;
                if(i==37) {
                    augment();
                    return true;
                }
                Q.push(i);
            }
        }
    }
    return false;
}

main()
{
    string str;
    int n,total=0,maxflow;;
    while(getline(cin,str),str!="")
    {
        total=0,maxflow=0;
        MS(flow,0);
        MS(capacities,0);
        do
        {
            int a=str[0]-65+11;
            int n=str[1]-'0';
            capacities[a][37]=n;
            total+=n;
            for(int i=3;; i++)
            {
                if(str[i]==';') break;
                int v=(str[i]-'0') + 1;
                capacities[v][a]=1;
            }
            getline(cin,str);
        }while(str!="");
        rep(i,1,11) capacities[0][i]=1;
        while(bfs()) maxflow++;
        if(maxflow!=total) {
                cout<<'!'<<endl;
               // cout<<total<<" "<<maxflow<<endl;
        }
        else {
            for(int i=1;i<11;i++) {
                bool flag=false;
                for(int j=11;j<37;j++) {
                    if(flow[i][j]==1) {
                        flag=true;
                        cout<<(char)((j-11)+65);
                        break;
                    }
                }
                if(!flag) cout<<'_';

            }
            cout<<endl;

        }
    }
}
