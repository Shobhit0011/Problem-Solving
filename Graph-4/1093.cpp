#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;
vector<int> vec;
void solve()
{
	for (int i = 1; i < 300009; i++)
	{
		vec.push_back((vec[vec.size() - 1] * 2) % mod);
	}
}
bool dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, int& c1, int& c2)
{
	if (vis[node] == -1)
	{
		vis[node] = 1;
		c1++;
	}
	bool ans = true;
	for (auto it : adj[node])
	{
		if (vis[it] == -1)
		{
			vis[it] = 1 - vis[node];
			if (vis[it])
				c1++;
			else
				c2++;
			ans &= dfs(it, adj, vis, c1, c2);
		}
		else if (vis[it] == vis[node])
			ans = false;
	}
	return ans;
}
int main() {
	int t;
	cin >> t;
	vec.push_back(1);
	solve();
	while (t--)
	{
		int n, e;
		cin >> n >> e;
		vector<bool> vis(n, 0);
		vector<vector<int>> adj(n);
		for(int i=0;i<e;i++){
			int u, v;
			cin >> u >> v;
			adj[u - 1].push_back(v - 1);
			adj[v - 1].push_back(u - 1);
		}
		long long ans = 1;
		for (int i = 0; i < n; i++)
		{
			if (vis[i] == 0)
			{
				int a = 0, b = 0;
				bool c = dfs(i, adj, vis, a, b);
				if (!c)
				{
					ans = 0;
					break;
				}
				int x1 = vec[a] % mod;
				int x2 = vec[b] % mod;
				ans = (ans * (x1 + x2) % mod) % mod;
			}
		}
		cout << ans << endl;
	}

	return 0;

}
