#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

signed main() {
    fastio

    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    int l=0,r=0,res=0,ans=0,con_barano=0,msz=0;
    multiset<int> ms;

    while(r<v.size()){
        int komano=0;
            while(l<=r && ms.count(v[r])>=1){
                komano+=v[l];
                ms.erase(v[l]);
                l++;
            }
            con_barano-=komano;

            con_barano+=v[r];
            ms.insert(v[r]); 
        ans=max(ans,con_barano);
        r++;
        msz=max(msz,(int)ms.size());
        }
        cout<<msz<<endl;
    }