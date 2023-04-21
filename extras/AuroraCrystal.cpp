#include <bits/stdc++.h>
using namespace std;

#define ll long long


ll x,y; vector<ll> prime; bool sieve[2000030];

void construct_sieve(){
	sieve[0] = true, sieve[1] = true;
	for(ll i = 2; i <= 20000000; i++){
		for(ll j = i*i; j <= 2000000; j += i){
			sieve[j] = true;
		}
	}
}

ll product[150030], ce[150030];

int main(){
	cin >> x >> y;
	construct_sieve();
	
	ll k = 2;
	product[0] = 0;
	product[1] = 1, ce[1] = 1;
	
	ll ganjil = 3;
	
	for(ll i = 3; i <= x; i++){
		if(!sieve[i]){
			ce[k] = i - ganjil;
			if(ce[k] != ce[k-1]) product[k] = product[k-1] + ce[k];
			else product[k] = product[k-1] + ce[k] + 1;
			ganjil += 2;
			++k;
		}
		
	}
	
	if(x==1) cout << "Out of Crystal Energy\n";
	else{
		vector<ll> result;
		for(ll i = k-1; y > 0 && i >= 0; i--){
			if(product[i] <= y){
				y -= product[i];
				result.push_back(i);
			}
		}
		if(y != 0) cout << "Out of Crystal Energy\n";
		else{
			for(ll i = 0; i < result.size(); i++){
				cout << result[i] << " ";
			}
			cout << "\n";
		}
		
		
	}
	
}