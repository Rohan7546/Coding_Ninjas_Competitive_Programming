/*
Special Prime is a prime number that can be written as the sum of two neighbouring primes and 1.
You are given an integer N and you are supposed to find the number special prime in the range: [1, N].
Example of special prime 19 = 7 + 11 + 1
Neighbouring primes are prime number such that there is no other prime number between them.
Input Format:
An integer N.
Output Format:
Print the number of special primes
Constraints:
1 <= N <= 2*10^5
Sample Input:
27
Sample Output:
2
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mex = 1e6 + 1;

ll solve(ll n) {

	bool isprime[mex];
	memset(isprime, true, sizeof(isprime));

	for (ll i = 2; i * i <= mex; i++) {
		if (isprime[i]) {
			for (ll j = i * i; j <= mex; j += i)
			{
				 

				isprime[j] = false;
			}
		}
	}

	vector<ll>v;
	for (ll i = 2; i <= n; i++) {
		if (isprime[i]) {
			v.push_back(i);
		}

	}
int cnt=0;
  int i=0,j=i+1;
  while(j<v.size()){
  	if(v[i]+v[j]+1<=n &&isprime[v[i]+v[j]+1]){
  		cnt++;
	  }
	  i++;
	  j++;
  }
 

 
	return cnt;
}
int main(){
	ll n;
	cin>>n;
	cout<<solve(n);
}
