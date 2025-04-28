#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

signed main() {
    fastio
    int a1[5]={1,3,5,7,9},a2[5]={2,4,6,8,10},res[10];
    int l1=0,l2=0,i=0;

    while(l1<5 && l2<5){
        if(a1[l1]<=a2[l2]){
            res[i]=a1[l1];
            i++;l1++;
        }
        else{
            res[i]=a2[l2];
            i++;l2++;
        }
    }
    while(l1<5){
        res[i]=a1[l1++];
    }
    while(l2<5){
        res[i]=a2[l2++];
    }

    for(int i=0;i<10;i++) cout<<res[i]<<" ";
    
    return 0;
}