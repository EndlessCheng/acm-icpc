#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN = 10010;
int n;
int a[MAXN];
int root, left[MAXN], right[MAXN], parent[MAXN], size[MAXN];
int tot;
pair<int, int> ans[600000];

inline void update(int t)
{
	size[t] = size[left[t]] + size[right[t]] + 1;
}

void zig(int t)
{
	int p = parent[t], g = parent[p];
	if (right[t]) parent[right[t]] = p;
	left[p] = right[t]; right[t] = p;
	parent[p] = t; parent[t] = g;
	update(p); update(t);
	if (g) p == left[g] ? left[g] = t : right[g] = t;
}

void zag(int t)
{
	int p = parent[t], g = parent[p];
	if (left[t]) parent[left[t]] = p;
	right[p] = left[t]; left[t] = p;
	parent[p] = t; parent[t] = g;
	update(p); update(t);
	if (g) p == left[g] ? left[g] = t : right[g] = t;
}

void splay(int t, int &root)
{
	int p = parent[t], g = parent[p], header = parent[root];
	for (; p != header; p = parent[t], g = parent[p]) {
		if (p == root) t == left[p] ? zig(t) : zag(t);
		else if (p == left[g]) t == left[p] ? zig(p) : zag(t), zig(t);
		else t == right[p] ? zag(p) : zig(t), zag(t);
	}
	root = t;
}

void select(int &root, int k)
{
	int t = root;
	while (k != size[left[t]] + 1) {
		if (k <= size[left[t]]) t = left[t];
		else k -= size[left[t]] + 1, t = right[t];
	}
	splay(t, root);
}

int merge(int l, int r)
{
	select(r, 1);
	left[r] = l;
	parent[l] = r;
	update(r);
	return r;
}

void del(int x)
{
	splay(x, root);
	int l = left[root], r = right[root];
	root = merge(l, r);
}

bool foo(int x)
{
	splay(x, root);
	int l = left[root], r = root;
	parent[l] = parent[r] = 0;
	left[root] = 0;
	update(root);
	if (size[l] == 0) return false;
	if (size[l] == size[r]) {
		ans[tot++] = make_pair(x, n);
		root = merge(r, l);
		return false;
	} else if (size[l] < size[r]) {
		ans[tot++] = make_pair(x, x + size[l] * 2 - 1);
		select(r, size[l] + 1);
		swap(parent[l], parent[left[r]]);
		swap(l, left[r]);
		root = merge(l, r);
		return false;
	} else {
		ans[tot++] = make_pair(x + size[l] - size[r], n);
		select(l, size[l] - size[r]);
		swap(parent[r], parent[right[l]]);
		swap(r, right[l]);
		root = merge(l, r);
		return true;
	}
}

void init()
{
	memset(left, 0, sizeof(left));
	memset(right, 0, sizeof(right));
	memset(parent, 0, sizeof(parent));
	memset(size, 0, sizeof(size));
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	a[n + 1] = 0;
	root = a[1];
	for (int i = 1; i <= n; ++i) {
		parent[a[i]] = a[i - 1];
		left[a[i]] = 0;
		right[a[i]] = a[i + 1];
		size[a[i]] = n - i + 1;
	}
}

void solve()
{
	tot = 0;
	for (int i = 1; i <= n; ++i) {
		while (foo(i));
		del(i);
	}
	printf("%d\n", tot);
	for (int i = 0; i < tot; ++i) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
}

int main()
{
	int dat;
	scanf("%d", &dat);
	while (dat--) {
		init();
		solve();
	}
}
