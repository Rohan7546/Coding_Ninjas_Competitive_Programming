/*
Number Of Factors
Send Feedback
A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.
Input Format:
First line of input will contain T(number of test cases), each test case follows as.
Each test cases consists of a single line containing integers a, b, and n as described above.
Output Format:
Output for each test case one line containing the number of n-factorful integers in [a, b].
Constraints:
1 <= T <= 10000
1 ≤ a ≤ b ≤ 10^6
0 <= b - a <= 100
0 ≤ n ≤ 10
Sample Input
4
1 3 1
1 10 2
1 10 3
1 100 3
Sample Output
2
2
0
8
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const ll mex = 1e6 + 1;
inline void debugMode() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

vector<ll> sieve() {
	bool isprime[mex];
	memset(isprime, true, sizeof(isprime));
	isprime[0] = false;
	isprime[1] = false;
	for (ll i = 2; i * i <= mex; i++) {
		if (isprime) {
			for (ll j = i * i; j <= mex; j += i) {
				isprime[j] = false;
			}
		}
	}

	vector<ll>v;
	for (ll i = 0; i < mex; i++) {
		if (isprime[i]) {
			v.push_back(i);
		}
	}
	vector<ll>v1(mex, 0);
	for (ll i = 0; i < v.size(); i++) {
		for (ll j = v[i]; j <= mex; j += v[i]) {
			v1[j]++;
		}
	}

	return v1;


}
int main() {
	//debugMode();
	ios_base:: sync_with_stdio(false);
	cin.tie(0);

	vector<ll>s1 = sieve();

	ll t;
	cin >> t;
	while (t--) {
		ll a, b, n;
		cin >> a >> b >> n;
		ll cnt = 0;
		for (ll i = a; i <= b; i++) {
			if (s1[i] == n) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}

}