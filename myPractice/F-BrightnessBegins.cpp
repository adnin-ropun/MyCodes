#include<bits/stdc++.h>
using namespace std;
using ll=long long;
signed main(){

	ll t;cin>>t;while(t--){

		ll n;cin>>n;
		ll l=0,r=LLONG_MAX;
		ll ans=LLONG_MAX;
		while(r>=l){
			ll m=l+(r-l)/2;
			if((m-(int)sqrt(m) >= n)){ans=m;r=m-1;}

			else{
					l=m+1;
				}
		}
		cout<<ans<<endl;
	}


}