

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
main() {

    int v,d;
    //freopen("input(3).txt","r",stdin);
    while(cin>>v>>d,v || d) {
        double maxi=0.00;
        int index=0;
        for(int i=1;i<=v;i++) {
            double vol=(double)v/i;
            if(vol<=d) break;
            double c=0.3*sqrt(vol-d)*i;
            if(c>=maxi) {
                if(abs(c-maxi)<1e-8) {
                    maxi=0;
                    index=0;
                    break;
                }
                maxi=c;
                index=i;
            }
        }
        if(v && d) cout<<index<<endl;
        else cout<<0<<endl;



    }

}
