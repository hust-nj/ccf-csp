#include<iostream>
#include<vector>
using namespace std;

#define Q 1000000007

int dfs_sum(vector<vector<int> > &adj, int u, vector<bool> &travel_flag, int L, int R, int i, vector<int> & weight)
{
	if (travel_flag[u])
	{
		if (i - 1 >= L && i - 1 <= R)
			return 1;
		else return 0;
	}
	else if (i > R)
		return 0;
	else
	{
		int collect = 0;
		travel_flag[u] = true;
		for (vector<int>::iterator x = adj[u].begin(); x != adj[u].end(); ++x)
		{
			collect += dfs_sum(adj, *x, travel_flag, L, R, i + 1, weight);
		}
		weight[u] += collect;
		return collect;
	}
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n, m, L, R;
		cin >> n >> m >> L >> R;
		vector<int> a;
		vector<int> inadj;
		vector<vector<int> > adj(n);
		vector<int> weight(n, 0);
		for (int i = 0; i < n; i++)
		{
			int w;
			cin >> w;
			a.push_back(w);
		}
		for (int i = 0; i < n - 1; i++)
		{
			int tmp;
			cin >> tmp;
			inadj.push_back(tmp - 1);
		}
		for (int i = 0; i < n - 1; i++)
		{
			adj[i + 1].push_back(inadj[i]);
			adj[inadj[i]].push_back(i + 1);
		}
		for (int u = 0; u < n; u++)
		{
			vector<bool> travel_flag(n, false);
			dfs_sum(adj, u, travel_flag, L, R, 1, weight);
		}
		for (int u = 0; u < n; u++)
			weight[u] /= 2;
		int sumVal = 0;
		for (int u = 0; u < n; u++)
		{
			int t = weight[u];
			int e = a[u];
			while (t != 0)
			{
				sumVal += (t % 2) * e;
				sumVal %= Q;
				t = t / 2;
				e = e * 2;
				e %= Q;
			}
		}
		vector<int>depth;
		depth.push_back(0);
		for (int i = 0; i < n - 1; i++)
		{
			depth.push_back(depth[inadj[i]] + 1);
		}
		for (int i = 0; i < m; i++)
		{
			int u, v, d;
			cin >> u >> v >> d;
			u -= 1;
			v -= 1;
			int du = depth[u];
			int dv = depth[v];
			for (int j = 0; j < du - dv; j++)
			{
				int t = weight[u];
				int e = d;
				while (t != 0)
				{
					sumVal += (t % 2) * e;
					sumVal %= Q;
					t = t / 2;
					e = 2 * e;
					e %= Q;
				}
				u = inadj[u - 1];
			}
			for (int j = 0; j < dv - du; j++)
			{
				int t = weight[v];
				int e = d;
				while (t != 0)
				{
					sumVal += (t % 2) * e;
					sumVal %= Q;
					t = t / 2;
					e = 2 * e;
					e %= Q;
				}
				v = inadj[v - 1];
			}
			while (u != v)
			{
				int t = weight[u];
				int e = d;
				while (t != 0)
				{
					sumVal += (t % 2) * e;
					sumVal %= Q;
					t = t / 2;
					e = 2 * e;
					e %= Q;
				}
				u = inadj[u - 1];
				t = weight[v];
				e = d;
				while (t != 0)
				{
					sumVal += (t % 2) * e;
					sumVal %= Q;
					t = t / 2;
					e = 2 * e;
					e %= Q;
				}
				v = inadj[v - 1];
			}
			int t = weight[u];
			int e = d;
			while (t != 0)
			{
				sumVal += (t % 2) * e;
				sumVal %= Q;
				t = t / 2;
				e = 2 * e;
				e %= Q;
			}
			cout << sumVal << endl;
		}
	}
	return 0;
}
