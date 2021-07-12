/*
Distribute Candies
Send Feedback
Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000). Shaky want to distribute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. He wants to distribute them in a way such that:
1. All students get an equal number of candies.
2. All the candies which a student gets must be from a single box only.
As he wants to make all of them happy so he wants to give as many candies as possible. Help Shaky in finding out what is the maximum number of candies which a student can get.
Input
First-line contains T the number of test cases.
The first line of each test case contains N and K.
Next line contains N space-separated integers, ith of which is the number of candies in the ith box.
Output
For each test case print the required answer in a separate line.
Constraints
1<= T <= 10^5
1 <= N <= 10^5
1 <= K <= 10^9
0 <= A[i] <= 10^9
Sum of N over all test cases doesn't exceed 10^6
Sample Input:
2
3 2
3 1 4
4 1
3 2 3 9
Sample Output:
3
9
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

inline void debugMode() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
bool search(ll *a, ll n, ll p, ll d) {
	ll count = 0;
	for (int i = 0; i < n; i++) {
		count += (a[i] / p);
	}
	return count >= d;
}


int main() {
	//debugMode();
	ios_base:: sync_with_stdio(false);
	cin.tie(0);


	ll t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		ll a[n];
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];

		}
		ll j = *max_element(a, a + n);
		//cout << sum << endl;
		ll ans;
		ll i = 0;
		while (i <= j) {
			ll mid = (i + j) / 2;
			if (search(a, n, mid, k)) {
				i = mid + 1;
				ans = mid;
			}
			else {
				j = mid - 1;
			}
		}
		cout << ans << endl;

	}

	return 0;




}