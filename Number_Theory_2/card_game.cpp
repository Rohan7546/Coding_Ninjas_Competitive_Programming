/*

Card Game
Send Feedback
Vova again tries to play some computer card game.
The rules of deck creation in this game are simple. Vova is given an existing deck of n cards and a magic number k. The order of the cards in the deck is fixed. Each card has a number written on it; number ai is written on the i-th card in the deck.
After receiving the deck and the magic number, Vova removes x (possibly x = 0) cards from the top of the deck, y (possibly y = 0) cards from the bottom of the deck, and the rest of the deck is his new deck (Vova has to leave at least one card in the deck after removing cards). So Vova's new deck actually contains cards x + 1, x + 2, ... n - y - 1, n - y from the original deck.
Vova's new deck is considered valid iff the product of all numbers written on the cards in his new deck is divisible by k. So Vova received a deck (possibly not a valid one) and a number k, and now he wonders, how many ways are there to choose x and y so the deck he will get after removing x cards from the top and y cards from the bottom is valid?
Input
The first line contains two integers n and k (1 ≤ n ≤ 100 000, 1 ≤ k ≤ 10^9).

The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 10^9) — the numbers written on the cards.
Output
Print the number of ways to choose x and y so the resulting deck is valid.
Sample Input 1
3 4
6 2 8
Sample Output 1
4
Sample Input 2
3 6
9 1 14
Sample Output 2
1

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll n, p;
	cin >> n >> p;
	ll k = p;
	ll a[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<pair<ll, ll>>factor;
	for (ll i = 2; i * i <= p; i++) {
		if (k % i == 0) {

			ll cnt = 0;
			while (k % i == 0) {
				k /= i;
				cnt++;
			}
			factor.push_back({i, cnt});
		}
	}

	if (k != 1) {
		factor.push_back({k, 1});
	}

	vector<pair<ll, ll>>v1 = factor;

	for (ll i = 0; i < v1.size(); i++) {
		v1[i].second = 0;
	}
	ll j = 0;

	ll res = 0;
	for (ll i = 0; i < n; i++) {


		for (ll x = 0; x < factor.size(); x++) {
			if (a[i] % factor[x].first == 0) {
				ll y = a[i];
				ll cnt = 0;
				while (y % factor[x].first == 0) {
					y /= factor[x].first;
					cnt++;
				}
				v1[x].second += cnt;

			}

		}

		while (j <= i) {
			bool flag = true;
			for (ll x = 0; x < factor.size(); x++) {
				if (v1[x].second < factor[x].second) {
					flag = false;
					break;
				}
			}
			if (!flag) {
				break;
			}
			res += (n - i);


			for (ll x = 0; x < factor.size(); x++) {
				if (a[j] % factor[x].first == 0) {
					ll y = a[j];
					ll cnt = 0;
					while (y % factor[x].first == 0) {
						y /= factor[x].first;
						cnt++;
					}
					v1[x].second -= cnt;
				}
			} j++;

		}



	}



	cout << res << endl;



}