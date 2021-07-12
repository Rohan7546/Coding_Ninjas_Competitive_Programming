/*
AIRPORTS
Send Feedback
The government of a certain developing nation wants to improve transportation in one of its most inaccessible areas, in an attempt to attract investment. The region consists of several important locations that must have access to an airport.
Of course, one option is to build an airport in each of these places, but it may turn out to be cheaper to build fewer airports and have roads link them to all of the other locations. Since these are long distance roads connecting major locations in the country (e.g. cities, large villages, industrial areas), all roads are two-way. Also, there may be more than one direct road possible between two areas. This is because there may be several ways to link two areas (e.g. one road tunnels through a mountain while the other goes around it etc.) with possibly differing costs.
A location is considered to have access to an airport either if it contains an airport or if it is possible to travel by road to another location from there that has an airport. You are given the cost of building an airport and a list of possible roads between pairs of locations and their corresponding costs. The government now needs your help to decide on the cheapest way of ensuring that every location has access to an airport. The aim is to make airport access as easy as possible, and with minimum cost.
Input Format:
The first line of input contains the integer T (the number of test cases), each test case follow as.
Line1: Three space-separated integers N, M and cost number of locations, number of possible roads and cost of airport respectively
The following M lines each contain three integers X, Y and C, separated by white space. X and Y are two locations, and C is the cost of building a road between X and Y .
Output Format:
For each test case print the cost in a newline.
Constraints:
1 <= T <= 20
1 <= N, M <= 10^5
1 <= cost <= 10^9
1 <= weight(of each road) <= 10^9
Sample Input
2
4 4 100
1 2 10
4 3 12
4 1 41
2 3 23
5 3 1000
1 2 20
4 5 40
3 2 30
Sample Output
145
2090
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct edge {
	ll v1;
	ll v2;
	ll weight;
};

bool compare(edge e1, edge e2) {
	return e1.weight < e2.weight;
}

ll getpar(ll n, ll *par) {

	if (par[n] < 0) {
		return n;
	}
	return par[n] = getpar(par[n], par);
}

void merge(ll x, ll y, ll *r, ll *par) {

	x = getpar(x, par);
	y = getpar(y, par);
	if (x == y)return;
	if (r[x] > r[y]) {
		par[y] = x;
		r[x] += r[y];
	}
	else {
		par[x] = y;
		r[y] += x;
	}
}




int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, m, cost;

		cin >> n >> m >> cost;
		edge arr[m];
		for (ll i = 0; i < m; i++) {
			cin >> arr[i].v1 >> arr[i].v2 >> arr[i].weight;
		}
		sort(arr, arr + m, compare);
		ll par[n + 1];
		ll r[n + 1] = {0};
		for (ll i = 0; i < n + 1; i++) {
			par[i] = -1;
		}

		ll cnt = 0;
		ll total_cost = 0;
		for (ll i = 0; i < m; i++) {

			ll p1 = arr[i].v1;
			ll p2 = arr[i].v2;
			ll p11 = getpar(p1, par);

			ll p12 = getpar(p2, par);

			if (p11 != p12) {
				merge(p11, p12, r, par);

				total_cost += min(arr[i].weight, cost);
				cnt++;
			}
		}

		ll ans = total_cost + cost + (n - cnt - 1) * cost;
		cout << ans << endl;

	}
}