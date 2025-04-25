#include<bits/stdc++.h>
using namespace std;

long long midCount(long long x,long long n){
    long long cnt=0;
    for(long long i=1;i<=n;i++){
        cnt+=min(x/i,n);
    }
    return cnt;
}
signed main(){
    long long n;cin>>n;
    long long mdn=(n*n+1)/2;

    long long l=1,r=n*n;

    while(l<r){
        long long m=l+(r-l)/2;
        long long fr=midCount(m,n);
        if(fr>=mdn){
            r=m;
        }
        else{
            l=m+1;
        }
    }

    cout<<r<<endl;
}