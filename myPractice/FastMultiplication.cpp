#include<bits/stdc++.h>
using namespace std;

long long midCount(long long x,long long n){
    long long cnt=0,j;
    for(long long i=1;i<=n;i++){
        j=x/i;
        (j<n) ? cnt+=j : cnt+=n;
    }
    return cnt;
}
signed main(){
    long long n;cin>>n;
    long long mdn=((n*n+1)/2)-1;

    long long l=1,r=n*n;

    // cout<<midCount(6,n)<<endl;
    long long ans=-1;
    while(l<=r){
        long long m=(l+r)/2;
        long long fr=midCount(m,n);
        if(fr==mdn){
            ans=m;
        }
        else if(fr<mdn){
            l=m+1;
        }else{
            r=m-1;
        }
    }

    (ans==-1)?cout<<l<<endl : cout<<ans;
}