#include<bits/stdc++.h>
using namespace std;

// brute force approach to celebrity problem
// A celebrity is known by everyone but doesn't know anyone

int main(){
    vector<vector<int>> v(3,vector<int>(3,0));

    // Input the matrix: 1 if person i knows person j, 0 otherwise
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>v[i][j];
        }
    }
    unordered_map<int,int> indegree,outdegree;

    // Calculate in-degree and out-degree for each person
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(v[i][j]==1){
                indegree[j]++;
                outdegree[i]++;
            }
        }
    }
    
    bool foundCelebrity = false;
    // For a celebrity: in-degree should be n-1 (everyone knows them)
    // and out-degree should be 0 (they know no one)
    for(int i=0;i<3;i++){
        if(indegree[i]==2 && outdegree[i]==0){
            cout<<i<<" is the celebrity"<<endl;
            foundCelebrity = true;
            break;
        }
    }
    
    if(!foundCelebrity){
        cout<<"No celebrity found"<<endl;
    }
    
    return 0;
}