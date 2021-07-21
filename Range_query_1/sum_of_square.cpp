

/*
Sum Of Squares
Send Feedback
Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to compute sums over a range in O(lg(n)), and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
The sum of squares over a range with range updates of 2 types:
1) increment in a range
2) set all numbers the same in a range.
There will be T test cases in the input file. First line of the input contains two positive integers, N and Q.
The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:
2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).

1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and 1 <= x <= 1,000).

0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and 1 <= x <= 1,000).
Input Format:
First line of input will contain T(number of test case), each test case follows as.
Line 1: contain two space-separated integers denoting the value of N and Q respectively
Line 2: contain N space-separated integers denoting th value of array elements
Next Q line contain the space separated value for queries as defined as above.
Constraints:
1 <= T <= 10
1 <= N <= 10000
1 <= arr[i] <= 1000
1 <= Q <= 10000
Output Format:
For each test case, print the answer in new line for query of type 2
Sample Input 1:
2
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
1 1
1
2 1 1
Sample Output 1:
30
7
13
1
*/




#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define REPI(i, a, b) for (ll i = b - 1; i >= a; i--)
#define i_os ios::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
#define INF (ll)1e18 + 100
#define endl "\n"

struct node {
    ll ss;
    ll s;
};

struct nodelazy {
    ll type;
    ll value;
};

void buildtree(node* tree, ll start, ll end, ll treenode, ll* arr) {
    if (start == end) {
        tree[treenode].ss = arr[start] * arr[start];
        tree[treenode].s = arr[start];
        return;
    }
    ll mid = (start + end) / 2;
    buildtree(tree, start, mid, 2 * treenode, arr);
    buildtree(tree, mid + 1, end, 2 * treenode + 1, arr);
    tree[treenode].ss = tree[2 * treenode].ss + tree[2 * treenode + 1].ss;
    tree[treenode].s = tree[2 * treenode].s + tree[2 * treenode + 1].s;
}

void lazytree(node* tree, nodelazy* lazy, ll start, ll end, ll treenode)
{
    ll x = lazy[treenode].value;
    // 1 is for adding some value in a range
    if (lazy[treenode].type == 1) {
        tree[treenode].ss += 2 * x * tree[treenode].s + (end - start + 1) * x * x;
        tree[treenode].s += (end - start + 1) * x;
        if (start != end) {
            if (lazy[2 * treenode].type == 0) {
                lazy[2 * treenode].type = 1;
            }
            if (lazy[2 * treenode + 1].type == 0) {
                lazy[2 * treenode + 1].type = 1;
            }
            lazy[2 * treenode].value += x;
            lazy[2 * treenode + 1].value += x;
        }
    }
    // 2 is for setting to some value in a range
    else if (lazy[treenode].type == 2) {
        tree[treenode].ss = (end - start + 1) * x * x;
        tree[treenode].s = (end - start + 1) * x;
        if (start != end) {
            lazy[2 * treenode].type = 2;
            lazy[2 * treenode + 1].type = 2;
            lazy[2 * treenode].value = x;
            lazy[2 * treenode + 1].value = x;
        }
    }
    lazy[treenode].type = 0;
    lazy[treenode].value = 0;
}

// left to right which is required range
node query(node tree[], nodelazy lazy[], ll start, ll end, ll treenode, ll left, ll right) {
    lazytree(tree, lazy, start, end, treenode);
    if (end < left || start > right) {
        node n;
        n.ss = 0;
        n.s = 0;
        return n;
    }
    if (left <= start && right >= end) {
        return tree[treenode];
    }
    ll mid = (start + end) / 2;
    node n1 = query(tree, lazy, start, mid, 2 * treenode, left, right);
    node n2 = query(tree, lazy, mid + 1, end, 2 * treenode + 1, left, right);
    node n3;
    n3.ss = n1.ss + n2.ss;
    n3.s = n1.s + n2.s;
    return n3;
}

// adding x in range [left,right]
void update1(node* tree, nodelazy* lazy, ll start, ll end, ll treenode, ll left, ll right, ll x) {
    lazytree(tree, lazy, start, end, treenode);
    if (start > right || left > end) {
        return;
    }
    if (start >= left && end <= right) {
        tree[treenode].ss += 2 * x * tree[treenode].s + (end - start + 1) * x * x;
        tree[treenode].s += (end - start + 1) * x;
        if (start != end) {
            if (lazy[2 * treenode].type == 0) {
                lazy[2 * treenode].type = 1;
            }
            if (lazy[2 * treenode + 1].type == 0) {
                lazy[2 * treenode + 1].type = 1;
            }
            lazy[2 * treenode].value += x;
            lazy[2 * treenode + 1].value += x;
        }
        return;
    }
    ll mid = (start + end) / 2;
    update1(tree, lazy, start, mid, 2 * treenode, left, right, x);
    update1(tree, lazy, mid + 1, end, 2 * treenode + 1, left, right, x);
    tree[treenode].ss = tree[2 * treenode].ss + tree[2 * treenode + 1].ss;
    tree[treenode].s = tree[2 * treenode].s + tree[2 * treenode + 1].s;
}

// setting all values to x in range [left,right]
void update2(node* tree, nodelazy* lazy, ll start, ll end, ll treenode, ll left, ll right, ll x) {
    lazytree(tree, lazy, start, end, treenode);
    if (start > right || left > end) {
        return;
    }
    if (start >= left && end <= right) {
        tree[treenode].ss = (end - start + 1) * x * x;
        tree[treenode].s = (end - start + 1) * x;
        if (start != end) {
            lazy[2 * treenode].type = 2;
            lazy[2 * treenode + 1].type = 2;
            lazy[2 * treenode].value = x;
            lazy[2 * treenode + 1].value = x;
        }
        return;
    }
    ll mid = (start + end) / 2;
    update2(tree, lazy, start, mid, 2 * treenode, left, right, x);
    update2(tree, lazy, mid + 1, end, 2 * treenode + 1, left, right, x);
    tree[treenode].ss = tree[2 * treenode].ss + tree[2 * treenode + 1].ss;
    tree[treenode].s = tree[2 * treenode].s + tree[2 * treenode + 1].s;
}

int main()
{
    ll t;
    cin >> t;
    REP(j, 0, t) {
        ll n, q;
        cin >> n >> q;
        ll arr[n];
        REP(i, 0, n) {
            cin >> arr[i];
        }
        node tree[4 * n];
        nodelazy lazy[4 * n];
        REP(i, 0, 4 * n) {
            lazy[i].type = 0;
            lazy[i].value = 0;
        }
        buildtree(tree, 0, n - 1, 1, arr);
        REP(i, 0, q) {
            ll x, y, z, w;
            cin >> x >> y >> z;
            y--; z--;
            if (x == 2) {
                node nd = query(tree, lazy, 0, n - 1, 1, y, z);
                cout << nd.ss << endl;
            }
            else if (x == 1) {
                cin >> w;
                update1(tree, lazy, 0, n - 1, 1, y, z, w);
            }
            else {
                cin >> w;
                update2(tree, lazy, 0, n - 1, 1, y, z, w);
            }
        }
    }
}