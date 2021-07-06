/*
A number is called super-prime if it has exactly two distinct prime divisors
Example 10 , 6
You are supposed to find the count of super-prime numbers between 1 and N (inclusive).
Input Format:
Contain an integer N
Output Format:
Print the number of super prime between [1, N]
Constraints:
1 <= N <= 10^6
Sample Input:
10
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
				/* code */

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

	ll arr[n+1]={0};
	for (ll i = 0; i < v.size(); i++) {
		for (ll j = v[i]; j <= n; j += v[i]) {
			arr[j]++;
		}
	}
	ll count = 0;
//	for (auto u : v) {cout << u << endl;}
	for (ll i = 0; i <= n; i++) {
		//	cout << arr[i] << " ";
	//	cout<<arr[i]<<" ";
		if (arr[i] == 2) {
			count++;
		}
	}


 
	return count;
}
int main(){
	ll n;
	cin>>n;
	cout<<solve(n);
}
