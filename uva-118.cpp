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
main()
{
    int x,y,a,b,n,ans1,ans2;
    char ch;
    string str;
    cin>>x>>y;
    map<pair<int,int>,int >scent;
    while(cin>>a>>b>>ch>>str) {
        bool flag=false;
        for(int i=0;i<str.length();i++) {
            if(str[i]=='R') {
                switch(ch) {
                case 'E':
                    ch='S';
                    break;
                case 'S':
                    ch='W';
                    break;
                case 'W':
                    ch='N';
                    break;
                case 'N':
                    ch='E';
                    break;
                }
            }
             else if(str[i]=='L') {
                switch(ch) {
                case 'E':
                    ch='N';
                    break;
                case 'S':
                    ch='E';
                    break;
                case 'W':
                    ch='S';
                    break;
                case 'N':
                    ch='W';
                    break;
                }
            }
            else if(str[i]=='F') {
                if(ch=='E') {
                    ans1=a+1;
                    if(ans1>x) {
                       if(scent[mp(a,b)]==0) flag=true;
                       scent[mp(a,b)]=1;
                       break;
                    }
                    else a++;
                }
                if(ch=='S') {
                    ans2=b-1;
                    if(ans2<0) {
                       if(scent[mp(a,b)]==0) {flag=true;
                       scent[mp(a,b)]=1;
                       break;
                       }
                    }
                    else b--;
                }
                if(ch=='W') {
                    ans1=a-1;
                    if(ans1<0) {
                       if(scent[mp(a,b)]==0) {flag=true;
                       scent[mp(a,b)]=1;
                       break;
                       }
                    }
                    else a--;
                }
                if(ch=='N') {
                    ans2=b+1;
                    if(ans2>y) {
                       if(scent[mp(a,b)]==0) { flag=true;
                       scent[mp(a,b)]=1;
                       break;
                       }
                    }
                    else b++;
                }
            }

        }
        if(flag) cout<<a<<' '<<b<<' '<<ch<<' '<<"LOST"<<endl;
        else cout<<a<<' '<<b<<' '<<ch<<endl;
    }
}
