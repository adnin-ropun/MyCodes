#include<bits/stdc++.h>
using namespace std;

int main(){
    // // stl array

    // array<int,5> arr;
    // // arr.fill(5);
    // for(int i=0;i<5;i++){
    //     cin>>arr[i];
    // }
    // cout<<arr.front()<<" "<<arr.back()<<endl;
    // sort(arr.begin(),arr.end());



    // // classical array

    // // int arr[]={5,4,3,2,1};
    // // sort(arr,arr+5);

    // for(auto it:arr){
    //     cout<<it<<" ";
    // }


    // vector
    int arr[5] = {5,4,3,2,1};

    vector<int> first(5,20);
    vector<int> second = {5,4,3,3,2,1};
    vector<int> third(second.begin(),second.begin()+3);
    vector<int> fourth(arr+2,arr+5);
    vector<int> vec; vec.reserve(100);
    
    // first.clear();

    // second.erase(second.begin()+2,second.begin()+4);

    // second.erase(remove(second.begin(),second.end(),3),second.end());

    // second.insert(second.end(),0);

    // sort(second.begin(),second.end());

    // bool flag=binary_search(second.begin(),second.end(),3);
    // cout<<flag<<endl;

    // auto it=lower_bound(second.begin(),second.end(),3);
    // cout<<*it<<endl;

    // for(auto it:second) cout<<it<<" ";

    priority_queue<int,vector<int>,greater<int>>pq;

    for(int i=0;i<5;i++){
        int d;cin>>d;
        pq.push(d);
    }

    while(!pq.empty()){
            cout<<pq.top()<<" ";
            pq.pop();
        }
    }