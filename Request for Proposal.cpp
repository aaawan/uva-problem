#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
main()
{
    int n,i,t,x=1,maxi=0;
    double price,low;
    string s,s3,s1;

    while(cin>>n>>i, n||i)
    {
        maxi=0;
        while(n--) {
                 cin.ignore();
                getline(cin,s);

        }

       while(i!=0){
            getline(cin,s1);
            scanf("%lf %d\n",&price,&t);
            if(t>maxi){

                s3=s1;
                maxi=t;
                low=price;
            }
            else if(t==maxi && price<low){

                s3=s1;
                low=price;
            }
          while(t--) getline(cin,s);
           i--;

        }
        if(x>1) cout<<endl;

        cout<<"RFP #"<<x++<<endl<<s3<<endl;

    }
}
