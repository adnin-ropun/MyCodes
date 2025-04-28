#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

signed main() {
    fastio
    vector<int> v(5);
    for(auto &x:v) cin>>x;

    int target;cin>>target;

    int l=0,r=v.size()-1,res=0;

    while(l<r){
        if(v[l]+v[r]==target){cout<<l<<" "<<r<<endl;break;}
        else if(v[l]+v[r]>target){r--;}
        else{l++;}
    }
    return 0;
}