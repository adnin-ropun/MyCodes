#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<long long>&v,long long m,long long k){

    long long cnt=0,sumContainer=0;
    for(auto elem:v){
        if(elem>m) return 0;
        if((sumContainer+elem) >m ){
            cnt++;
            sumContainer=0;
        }
        sumContainer+=elem;
    }
    if(sumContainer>0) cnt++;

    return cnt<=k;

}

signed main(){
    long long n,k;
    cin >> n >> k;  

    vector<long long> v(n);
    for(long long i=0;i<n;i++) cin>>v[i];
    
    long long l=*max_element(v.begin(),v.end());
    long long r=accumulate(v.begin(),v.end(),0ll);

    // cout<<isValid(v,8,k);

    long long ans=-1; // Initialize to -1 to indicate "no solution found"
    while(r>=l){
        long long m=l+(r-l)/2;

        if(isValid(v,m,k)){
            r=m-1;
            ans=m;
        }
        else{
            l=m+1;
        }
    }
    if(ans != -1)
    cout<<ans<<endl;
    else cout<<l<<endl;
    return 0;
}