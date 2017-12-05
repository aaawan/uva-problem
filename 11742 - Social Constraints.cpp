
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

    int n,m,a[21],b[21],c[21];
    int arr[8]={0,1,2,3,4,5,6,7};
    while(cin>>n>>m,n||m) {
        rep(i,0,m) cin>>a[i]>>b[i]>>c[i];
        int count=0;
        bool valid;
        do{
            valid=true;
            rep(i,0,m) {
                if(c[i]<0 && abs( find(arr,arr+n,a[i]) - find(arr,arr+n,b[i]) ) <abs(c[i])) {
                    valid=false;
                    break;
                }
                else if(c[i]>0 && abs( find(arr,arr+n,a[i]) - find(arr,arr+n,b[i]) ) >abs(c[i])) {
                    valid=false;
                    break;
                }
            }
            if(valid) count++;

        } while(next_permutation(arr,arr+n));
        printf("%d\n",count);

    }


}
