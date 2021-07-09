/*
Sum of LCM
Send Feedback
Given n, calculate and print the sum :
LCM(1,n) + LCM(2,n) + .. + LCM(n,n)
where LCM(i,n) denotes the Least Common Multiple of the integers i and n.
Input Format :
First line of input will contain T(number of test case), each test case follows as.
An Integer N
Output Format :
Required sum for each test case in newline.
Constraints :
1 <= T <= 10^4
1 <= n <= 10^5
Sample Input 1 :
1
5
Sample Output 1 :
55
Sample Input 2 :
1
2
Sample Output 2 :
4
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mex = 1e5 + 3;
ll eulerphi[mex];
ll ans[mex];

void sieve() {
	for (ll i = 0; i < mex; i++) {
		eulerphi[i] = i;
	}
	for (ll i = 2; i < mex; i++) {
		if (eulerphi[i] == i) {

			for (ll j = i; j < mex; j += i) {
				eulerphi[j] = (eulerphi[j] * (i - 1) / i);
			}
		}
	}


	for (ll i = 1; i < mex; i++) {
		for (ll j = i; j < mex; j += i) {
			ans[j] += (eulerphi[i] * i);
		}
	}

}
int main() {
	sieve();
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		cout << n*(ans[n] + 1) / 2 << endl;
	}
}
