/*

Segmented Sieve Problem
Send Feedback
In this problem you have to print all primes from given interval.
Input Format:
First line of input will contain T(number of test cases), each test case follows as.

On each line are written two integers L and U separated by a blank. L - lower bound of
interval, U - upper bound of interval.
Output Format:
For each test case output must contain all primes from interval [L; U] in increasing order.
Constraints:
1  <= T <= 100
1 <= L <= U <= 10^9
0 <= U - L <= 10^5
Sample Input:
2
2 10
3 7
Sample Output:
2 3 5 7
3 5 7

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxim = 1e5 + 1;
vector<ll> sieve() {
	bool isprime[maxim];
	memset(isprime, true, sizeof(isprime));
	isprime[0] = false;
	isprime[1] = false;
	for (ll i = 2; i * i < maxim; i++) {
		if (isprime[i]) {

			for (ll j = i * i; j < maxim; j += i) {
				isprime[j] = false;
			}
		}
	}

	vector<ll>v;
	v.push_back(2);
	for (ll i = 3; i < maxim; i += 2) {
		if (isprime[i]) {
			v.push_back(i);
		}
	}
	return v;

}

void prllprime(ll l, ll r, vector<ll>v) {
	bool isprime[r - l + 1];
	memset(isprime, true, sizeof(isprime));
	for (ll i = 0; v[i]*v[i] <= r; i++) {
		ll curprime = v[i];
		ll base = (l / curprime) * curprime; // just smaller or equal to base
		if (base < l) {
			base = base + curprime;
		}
		// mark all multiples to l to r as false
		for (ll j = base; j <= r; j += curprime) {
			isprime[j - l] = false; //chng
		}
		if (base == curprime) { // if our base is prime and it made false above;
			isprime[base - l] = true;
		}
	}
	for (ll i = 0; i <= r - l; i++) {

		if (isprime[i]) {
			if (l + i == 1) {
				continue;
			}
			cout << l + i << " ";
		}
	}
	cout << endl;
}





int main() {

	vector<ll>si = sieve();

	ll t;
	cin >> t;
	while (t--) {
		ll l, r;
		cin >> l >> r;
		prllprime(l, r, si);
	}

}