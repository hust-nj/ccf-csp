#include <iostream>
#include <vector>
using namespace std;
#define Q 1000000007

bool dfs_add(vector<int> &a, vector<vector<int> > &adj, int u, int v, int d, int parents)//dfs(u)
{
	if (u == v)
	{
		a[u] += d;
		a[u] %= Q;
		return true;
	}
	else
	{
		int x;
		for (/*auto i : adj[u]*/x = 0; x < adj[u].size(); x++)
		{
			int i = adj[u][x];
			if (i == parents)continue;
			if (dfs_add(a, adj, i, v, d, u))
			{
				a[u] += d;
				a[u] %= Q;
				return true;
			}
		}
		return false;
	}
}

void add(vector<int> &a, vector<vector<int> > &adj, int u, int v, int d)
{
	dfs_add(a, adj, u, v, d, u);
}

int dfs_sum(vector<vector<int> > &adj, int u, vector<bool> &travel_flag, int L, int R, int i, vector<int> &weight)//start with u, return the times collected
{
	if (travel_flag[u])//only can be dfs(parents)
	{
		if (i - 1 >= L && i - 1 <= R)
		{
			return 1;
		}
		else return 0;
	}
	else
	{
		int collect = 0;
		travel_flag[u] = true;
		int x;
		for (/*auto v : adj[u]*/x = 0; x < adj[u].size(); x++)
		{
			int v = adj[u][x];
			collect += dfs_sum(adj, v, travel_flag, L, R, i + 1, weight);
		}
		weight[u] += collect;
		return collect;
	}
}

int sum(vector<int> &a, vector<int> &weight)
{
	int sum = 0, i, j;
	for (i = 0; i < a.size(); i++)
		for (j = 0; j < weight[i]; j++)
		{
			sum += a[i];
			sum %= Q;
		}
	return sum;
}



int main()
{
	int T;
	cin >> T;
	int i;
	for (i = 0; i < T; i++)
	{
		int n, m, L, R;
		int u, v, d;
		int i, j;
		vector<int> a;
		vector<int> inadj;
		cin >> n >> m >> L >> R;
		vector<vector<int> > adj(n, vector<int>());
		vector<int> weight(n, 0);
		for (j = 0; j < n; j++)
		{
			int w;
			cin >> w;
			a.push_back(w);
		}
		for (j = 0; j < n - 1; j++)
		{
			int tmp;
			cin >> tmp;
			inadj.push_back(tmp - 1);
		}
		for (j = 0; j < n - 1; j++)
		{
			adj[j + 1].push_back(inadj[j]);
			adj[inadj[j]].push_back(j + 1);
		}
		for (u = 0; u < n; u++)
		{
			vector<bool> travel_flag(n, false);
			dfs_sum(adj, u, travel_flag, L, R, 1, weight);
		}
		for (u = 0; u < n; u++)
		{
			weight[u] /= 2;
		}
		for (i = 0; i < m; i++)
		{
			cin >> u >> v >> d;
			u -= 1, v -= 1;
			add(a, adj, u, v, d);
			cout << sum(a, weight) << endl;
		}
	}
	return 0;
}
