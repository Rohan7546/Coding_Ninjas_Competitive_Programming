/*

Divisors Of Factorial
Send Feedback
Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.
Input Format:
The first line contains T, number of test cases.
T lines follow each containing the number N.
Output Format:
Print T lines of output each containing the answer.
Constraints
1 <= T <= 500
0 <= N <= 50000
Sample Input:
3
2
3
4
Sample Output:
2
4
8

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mex = 1e5 + 7;
const ll mod = 1e9 + 7;
vector<ll>fun() {
	bool isprime[mex];
	memset(isprime, true, sizeof(isprime));

	isprime[0] = 0;
	isprime[1] = 0;
	for (ll i = 2 ; i * i <= mex; i++) {

		if (isprime[i]) {
			for (ll j = i * i; j <= mex; j += i) {
				isprime[j] = false;
			}
		}
	}
	vector<ll>v;
	for (ll i = 2; i <= mex; i++) {
		if (isprime[i]) {
			v.push_back(i);
		}
	}
	return v;


}


ll divisors(ll n, vector<ll>prime) {
	ll result = 1;
	for (ll i = 0; prime[i] <= n; i++) {

		ll k = prime[i];
		ll count = 0;

		while (n / k) {
			count += (n / k) % mod;
			k = k * prime[i];
		}

		result = (result % mod * (count + 1) % mod) % mod;
	}
	return result;
}



int main() {
	vector<ll>v = fun();

	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		cout << divisors(n, v) << endl;
	}
	return 0;
}