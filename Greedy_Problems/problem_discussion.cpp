/*

Problem Discussion
Send Feedback
Harshit gave Aahad an array of size N. He asked Aahad to minimize the difference between the maximum value and minimum value by modifying the array under some condition. The condition is that each array element either increases or decreases by K (only once).
The task seems difficult to Aahad, so he has asked you for your help. Are you up to the challenge?
Input Format:
First line of input contains an integer T, representing the number of test cases.
For each test case, first line contains two space-separated integers: N, K
Next lines contain N space-separated integers denoting elements of the array
Constraints
1 <= T <= 100
1 =< N <= 10^5
1 <= Ai,K <= 10^9
Output Format
The output contains a single integer denoting the minimum difference between maximum value and the minimum value in the array
Sample Input 1:
1
3 6
1 15 10
Sample Output 1:
5
Explaination
We change from 1 to 6, 15 to  9 and 10 to 4. Maximum difference is 5 (between 4 and 9). We can't get a lower difference.

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		ll a[n];
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		ll i = 0, j = n - 1;
		ll ans;
		ll smaller = a[i] + k;
		ll bigger = a[j] - k;
		if (smaller > bigger) {
			swap(smaller, bigger);
		}
		ans = a[n - 1] - a[0];
		for (ll i = 1; i < n - 1; i++) {
			if (a[i] - k >= smaller || a[i] + k <= bigger) {
				continue;
			}

			if (bigger - a[i] + k <= a[i] + k - smaller) {
				smaller = a[i] - k;
			}
			else {
				bigger = a[i] + k;
			}

		}
		ans = min(ans, bigger - smaller);
		cout << ans << endl;
	}
}