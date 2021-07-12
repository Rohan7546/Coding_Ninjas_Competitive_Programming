/*

Product of first N natural numbers
Send Feedback
You are given an integer N and you have to calculate the product of the first N natural numbers.
As the answer will be large, print the answer modulo 10^9+7.
Input Format :
The first line of input contains an integer, that denotes the value of the number of test cases. Let us denote it with the symbol T.
Each test case consists of a single integer N in a separate line.
Output Format :
For each test case, print the product of the first N natural numbers modulus 10^9 + 7 in a separate line.
Constraints :
1 <= T <= 100
1 <= N <= 10^5
Time Limit: 1 second
Sample Input 1:
2
3
4
Sample output 1:
6
24

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define m 1000000007


ll solve(ll n) {
	ll ans = 1;
	for (ll i = 1; i <= n; i++) {
		ans = ((ans % m * i % m) % m);
	}
	return ans;
}

int main() {



	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		cout << solve(n) << endl;
	}
}
