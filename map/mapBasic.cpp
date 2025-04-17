#include<bits/stdc++.h>
using namespace std;
int main(){
    // unordered_map<string,int>mp;

    // for(int i=0;i<5;i++){
    //     string s;cin>>s;
    //     int n;cin>>n;
    //     mp[s]=n;
    // }
    // // mp.erase("pizza");
    // if(mp.count("pizza")!=0){cout<<"Found and prize: "<<mp["pizza"]<<"$"<<endl;}
    // else cout<<"Not found"<<endl;

    // // using find()
    // // if(mp.find("pizza")!=mp.end()){cout<<"Found and prize: "<<mp["pizza"]<<"$"<<endl;}
    // // else cout<<"Not found"<<endl;

    // cout<<"List: "<<endl;
    // for(pair<string,int> it:mp){
    //     cout<<it.first<<" -> "<<it.second<<endl;
    // }

    map<string,vector<string>>phoneBook;

    for(int i=0;i<2;i++){
        string s1;cin>>s1;
        for(int j=0;j<2;j++){
            string s2;cin>>s2;
            phoneBook[s1].push_back(s2);
        }
    }

    phoneBook["ropun"].push_back("019");
    auto& it=phoneBook["rion"];
    it.erase(remove(it.begin(),it.end(),"015"),it.end());

    for(auto& it1:phoneBook){
        cout<<it1.first<<" -> ";
        for(auto it2:it1.second){
            cout<<it2<<"  ";
        }
        cout<<endl;
    }
}