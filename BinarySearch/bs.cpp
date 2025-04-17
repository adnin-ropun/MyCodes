#include<bits/stdc++.h>
using namespace std;

int bs(vector<int>& v,int t){
    int l=0,r=v.size()-1;

    while(l<=r){
        int m=l+(r-l)/2;
        // till here everything is same

        if(v[m]==t) return m;   //immediately return

        else if(v[m]<t) l=m+1;  //eleminate left(<) half including mid
        else r=m-1;   //eleminate right(>) half including mid
    }
    return -1;
}

int upper_bound(vector<int>& v,int t){
        int l=0,r=v.size()-1,ans=-1;

        while(l<=r){
            int m=l+(r-l)/2;

            if(v[m]>t) {
                ans=v[m];
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
}

int lower_bound(vector<int>& v,int t){
        int l=0,r=v.size()-1,ans=-1;

        while(l<=r){
            int m=l+(r-l)/2;

            if(v[m]>=t) {
                ans=v[m];
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
}



int main(){
    vector<int>v{1,2,3,4,8,9,9,10};
    // cout<<bs(v,3);
    // bool chk=binary_search(v.begin(),v.end(),11);
    // cout<<chk<<endl;

    // auto it=lower_bound(v.begin(),v.end(),5);
    // auto it=upper_bound(v.begin(),v.end(),11);

    // cout<<*it<<endl;
    // cout<<upper_bound(v,9);

    cout<<lower_bound(v,5);

}