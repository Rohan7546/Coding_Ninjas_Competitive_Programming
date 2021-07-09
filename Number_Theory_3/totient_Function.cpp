/*
Totient Function
Send Feedback
You are given an integer N and are supposed to find the value of Euler toient function for N phi(N)
Input Format:
First line of input will contain T(number of test case), each test case follows as.
An integer N in new line.
Output Format:
For each test case print the answer in new line
Constraints:
1 <= T <= 100
1 <= N <= 10^9
Sample Input:
2
20
21
Sample Output:
8
12
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {

//	ll *arr=new ll[mex]
	ll t;
	cin >> t;
	while (t--) {

		ll n;
		cin >> n;
		ll p = n;
		map<ll, ll>mp;
		for (ll i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				while (n % i == 0) {
					n /= i;
					mp[i]++;
				}
			}
		}
		if (n != 1) {
			mp[n]++;
		}
		ll ans = p;
		for (auto u : mp) {
			ans = (ans / u.first) * (u.first - 1);
			//	cout<<ans<<endl;
		}

		cout << ans << endl;
	}


}