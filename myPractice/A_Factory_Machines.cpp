#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll sol(vector<ll>& v,ll t){
	ll p=0;

	for(ll i=0;i<v.size();i++){
		p+=(t/v[i]);
	}
	return p;
}

signed main(){

	ll n,p;cin>>n>>p;

	vector<ll> v(n);

	for(ll i=0;i<n;i++){

		cin>>v[i];
	}
	ll mi=*(min_element(v.begin(),v.end()));
	ll l=1,r=p*mi;

	ll ans=r;
	while(r>=l){

		ll m=(l+r)/2;
		ll P=sol(v,m);

		if(P>=p) {ans=m;r=m-1;}
		else {l=m+1;}
	}

	cout<<ans<<endl;
}