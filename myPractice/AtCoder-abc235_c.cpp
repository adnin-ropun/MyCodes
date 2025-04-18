// https://vjudge.net/problem/AtCoder-abc235_c/origin

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t;cin>>n>>t;
    unordered_map<int,int> mp;
    map<pair<int,int>,int> r;

    for(int i=1;i<=n;i++){
        int d;cin>>d;
        mp[d]++;
        r[{d,mp[d]}]=i;
    }
    while(t--){
        int a,b;cin>>a>>b;
        if(r.find({a,b}) == r.end()) cout<<-1<<endl;
        else{
            cout<<r[{a,b}]<<endl;
        }
    }

}