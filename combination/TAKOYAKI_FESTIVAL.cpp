#include<bits/stdc++.h>
using namespace std;
using ll=long long;
static ll sum=0;

void calEnergy(vector<int>& comb){
	ll mul=1;
	for(int i=0;i<comb.size();i++){
		mul*=comb[i];
	}
	sum+=mul;
}
void combEnergy(vector<int>& arr,vector<int>& comb,int s,int r){
	if(comb.size()==r){
		calEnergy(comb);
		return;
	}
	for(int i=s;i<arr.size();i++){
		comb.push_back(arr[i]);
		combEnergy(arr,comb,i+1,r);
		comb.pop_back();
	}
}

int main(){
	int n;cin>>n;
	vector<int>arr(n);vector<int>comb;

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	combEnergy(arr,comb,0,2);
	cout<<sum<<endl;

}