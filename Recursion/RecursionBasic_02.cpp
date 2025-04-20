#include<bits/stdc++.h>
using namespace std;

int fibo(int n){
if(n==0) return 0;
else if(n==1) return 1;

return fibo(n-1)+fibo(n-2);

}
int fact(int n){
	if(n==1) return 1;
	return n*fact(n-1);
}

bool is_Sorted(vector<int>& v,int i=0){
	if(i==v.size()) return 1;

	if(v[i]<v[i+1]){
		is_Sorted(v,i+1);
	}
	else return 0;

}

int main(){

	// cout<<fibo(10);
	cout<<fact(7);
	
}