#include<bits/stdc++.h>
using namespace std;

int main(){
    
    // unordered_set, unordered_map  -> O(1)
    // set, map  -> O(lgn(n))

    unordered_set<string>s;
    for(int i=0;i<5;i++){
        string d;cin>>d;
        s.insert(d);
    }

    if(s.find("alex")!=s.end()) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;

    s.erase("kamal");
    for(auto it:s){
        cout<<it<<endl;
    }
}