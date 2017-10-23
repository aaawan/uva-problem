
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
    int n,l,m,f;
    bool flag;
    cin>>n;
    string s1;
    char ch;
    getchar();
    while(n--) {
        m=f=0;
        getline(cin,s1);
        l=s1.length();
        rep(i,0,l) {
           if(s1[i]=='M') m++;
           else if(s1[i]=='F') f++;
         }

        if(m==f && l>3) cout<<"LOOP"<<endl;
        else cout<<"NO LOOP"<<endl;
    }

}


