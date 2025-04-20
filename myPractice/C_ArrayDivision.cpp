#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n,k;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    int l=*max_element(v.begin(),v.end());
    cout<<l<<endl;

    return 0;
}