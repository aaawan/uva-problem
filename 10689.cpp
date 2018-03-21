
#include<bits/stdc++.h>
#include<cassert>
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
class matrics {
public:
    int arr[5][5],row,col;
};
int mod;
matrics multiply(matrics a, matrics  b) {

    assert(a.col==b.row);
    matrics r;
    r.row=a.row,r.col=b.col;
    rep(i,0,r.row) {
        rep(j,0,r.col) {
            int sum=0;
            rep(k,0,a.col) {
                sum+=(a.arr[i][k]*b.arr[k][j]);
                sum%=mod;
            }
            r.arr[i][j]=sum;
        }
    }
    return r;
}

matrics power(matrics mat,int n) {
   assert(n>=1);
   if(n==1) return mat;
   if(n%2==1) return multiply(mat,power(mat,n-1));
   mat=power(mat,n/2);
   return multiply(mat,mat);
}
main()
{
    int n,test,a,b,m;
    cin>>test;
    while(test--) {
        cin>>a>>b>>n>>m;
        matrics mat;
        mat.row=mat.col=2;
        mat.arr[0][0]=mat.arr[0][1]=mat.arr[1][0]=1;
        mat.arr[1][1]=0;
        mod=1;
        rep(i,0,m) mod*=10;
         a%=mod,b%=mod;

        if(n<3) {
            if(n==0) cout<<a<<endl;
            else if(n==1) cout<<b<<endl;
            else cout<<(a+b)%mod<<endl;
        }
        else {
            mat=power(mat,n-1);
            int ans=mat.arr[0][0]*b + mat.arr[0][1]*a;
            ans%=mod;
            cout<<ans<<endl;
        }
    }
}
