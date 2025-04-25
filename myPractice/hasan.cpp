#include<bits/stdc++.h>
using namespace std;

int main(){
    int l=0,h=9;
    int arr[20]={1,2,3,4,5,6,7,8,9,10};

    while(l<h){
        
        int m=(h+l)/2;
        cout<<l<<"--"<<m<<"--"<<h<<endl;
        if(arr[m]<=10) h=m;
        else l=m+1;
        cout<<l<<"--"<<h<<endl;
    }
    
}