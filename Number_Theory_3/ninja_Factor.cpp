/*

Ninja Factor
Send Feedback
Ninja is given an array of integers of size N and Q queries, each query will be consists of two integers l, r and ninja is supposed to calculate the number of i such that the ninja factor of array[i] is a prime number where l <= i <= r
Ninja factor of a Number A is defined as the number of integers B such that
1 <= B <= A
LCM (A, B) = A * B
Input Format:
 Line1: contain two space-separated integers N and Q denoting the number of elements in array and number of queries.
Line2: contain N space-separated integers denoting the elements of the array
Next, Q lines contain two space-separated integers l, r describing the query.
Output Format:
For each query print the answer in a newline.
Constraints:
1 <= N , Q <= 10^5
1 <= arr[i] <= 10^9
1 <= l, r <= N
Sample Input:
10 6
8 8 6 8 6 7 10 7 9 9
2 10
7 7
5 7
7 8
6 10
3 4
Sample Output:
2
0
1
0
0
1

*/
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAXN 1000005
using namespace std;
ll phi[MAXN];
ll dp[MAXN];
ll ans[MAXN];
bool isprime[MAXN];
void sieve() {
	//memset(isprime,true,sizeof(isprime));
	isprime[0] = false;
	isprime[1] = false;
	for (ll i = 2; i * i < MAXN; i++) {
		if (isprime[i]) {
			for (ll j = i * i; j < MAXN; j += i) {
				isprime[j] = false;
			}
		}
	}

}
void euler() {
	for (ll i = 1; i < MAXN; i++)
		phi[i] = i;
	for (ll i = 2; i < MAXN; i++) {
		if (phi[i] == i) {
			phi[i] -= 1;
			for (ll j = 2 * i; j < MAXN; j += i)
				phi[j] = (phi[j] * (ll)(i - 1)) / (ll)i;
		}
	}




}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(isprime, true, sizeof(isprime));
	sieve();
	euler();
	ll n, q;
	cin >> n >> q;
	ll a[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll dep[n + 1];
	dep[0] = 0;
	if (isprime[phi[a[0]]]) {
		dep[1] = 1;
	}
	else {
		dep[1] = 0;
	}
	/*	 cout<<isprime[5]<<endl;
		 for(ll i=0;i<n;i++){
		 	cout<<isprime[phi[a[i]]]<<" ";
		 } */
//	 cout<<endl;//
	for (ll i = 1; i <= n; i++) {
		if (isprime[phi[a[i - 1]]]) {
			dep[i] = dep[i - 1] + 1;
		}
		else {
			dep[i] = dep[i - 1];
		}

	}

	while (q--) {
		ll l, r;
		cin >> l >> r;

		cout << dep[r] - dep[l - 1] << endl;
	}
	return 0;
}
