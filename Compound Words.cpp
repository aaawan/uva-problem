
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
main()
{
    vector<string >S;
    map<string,int>m;
    string str;
    while(cin>>str) {
        m[str]=1;
        S.pb(str);
    }
    rep(i,0,S.size()) {
        int l=S[i].length();
        rep(j,1,l) {
            if(m[S[i].substr(0,j)] && m[S[i].substr(j,l)]) {
                cout<<S[i]<<endl;
                break;
            }
        }
    }
}



