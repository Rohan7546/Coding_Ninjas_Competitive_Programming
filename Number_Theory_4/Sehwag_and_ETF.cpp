/*
Sehwag and ETF
Send Feedback
Sehwag has been solving a lot of mathematical problems recently. He was learning ETF (Euler Totient Function) and found the topic quite interesting. So, he tried solving a question on ETF. He will be given two numbers L and R. He has to find the probability that the ETF of a number in the range [L, R] is divisible by a number K.
Input Format:
The first line contains an integer T, representing the number of test cases.
The next T lines will contain three integers L, R and K.
Constraints:
1 <= T <= 10
1 <= L <= R <= 10^12
0 <= R - L <= 10^5
1 <= K <= 10^6
Output Format:
Print the answer in a new line after rounding off the first 6 digits after the decimal place.
Sample Input 1:
3
1 4 2
2 5 2
3 10 4
Sample Output 1:
0.500000
0.750000
0.375000 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mex = 1e5 + 1;

vector<ll> sieve() {
	bool isprime[mex];
	memset(isprime, true, sizeof(isprime));
	isprime[0] = false;
	isprime[1] = false;
	for (ll i = 2; i < mex; i++) {
		if (isprime[i]) {
			for (ll j = i * i; j < mex; j += i) {
				isprime[j] = false;
			}
		}
	}

	vector<ll>v;
	v.push_back(2);
	for (ll i = 3; i < mex; i += 2) {
		if (isprime[i]) {
			v.push_back(i);
		}
	}
	return v;
	// do someting
}
int main() {

	ll t;
	cin >> t;
	vector<ll>v = sieve();

	while (t--) {

		ll a, b, k;
		cin >> a >> b >> k;
		ll phi[mex];
		ll arr[mex];

		for (ll i = a; i <= b; i++) {
			phi[i - a] = i;
			arr[i - a] = i;
		}


		for (ll i = 0; v[i]*v[i] <= b; i++) {
			ll curx = v[i];
			ll base = (a / curx) * curx;
			if (base < a) {
				base += curx;
			}


			for (ll j = base; j <= b; j += curx) {
				while (arr[j - a] % v[i] == 0)
					arr[j - a] /= v[i];
				phi[j - a] -= phi[j - a] / v[i];
			}
		}





		for (ll i = a; i <= b; i++) {
			if (arr[i - a] > 1) {
				phi[i - a] -= phi[i - a] / arr[i - a];

			}
			arr[i - a] = 1;
		}
		ll cnt = 0;

		for (ll i = a; i <= b; i++) {
			if (phi[i - a] % k == 0) {
				cnt++;
			}
		}
		cout << fixed << setprecision(6) << double(cnt) / double(b - a + 1) << endl;



	}





}
