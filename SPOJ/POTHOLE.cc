#include <iostream>
#include <climits>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 300, maxm = 300 * 300 * 2;
int go[maxm], flow[maxm], nextEdge[maxm], edge_num;
int fir[maxn], level[maxn], q[maxn];

void addedge(int x, int y, int flowNum){
	//cout << "add : " << "x = " << x << ", y = " << y << endl;
	//add edge from x to y
	go[edge_num] = y;
	flow[edge_num] = flowNum;
	nextEdge[edge_num] = fir[x];
	fir[x] = edge_num++;

	//add edge from y to x
	go[edge_num] = x;
	flow[edge_num] = 0;
	nextEdge[edge_num] = fir[y];
	fir[y] = edge_num++;
}

bool bfs(int source, int goal){
	memset(level, 0, sizeof(level));
	level[source] = 1;
	q[0] = source;

	int head = 0, tail = 1;
	while (head < tail){
		int x = q[head++], k = fir[x];
		while (k != -1){
			int y = go[k];
			if (level[y] == 0 && flow[k] > 0){
				level[y] = level[x] + 1;
				if (y == goal) return true;
				q[tail++] = y;
			}
			k = nextEdge[k];
		}
	}
	return false;
}

int min(int x, int y){
	return (x < y) ? x : y;
}

int dfs(int x, int goal, int maxflow){
	if (x == goal) return maxflow;
	int k = fir[x], ret = 0;
	while (k != -1){
		int y = go[k];
		if (flow[k] > 0 && level[x] + 1 == level[y]){
			int cur = dfs(y, goal, min(maxflow - ret, flow[k]));
			flow[k] -= cur;
			if (k % 2 == 0) flow[k + 1] += cur;
			else flow[k - 1] += cur;
			ret += cur;
			if (ret == maxflow) return ret;
		}
		k = nextEdge[k];
	}
	return ret;
}

int main(){
	int test, n, ans;
	cin >> test;
	for (int i = 0; i < test; ++i){
		//========Preprocessing==========
		edge_num = 0;
		memset(fir, -1, sizeof(fir));

		//============Input==============
		int connect_num, connect;
		cin >> n;
		for (int i = 0; i < n - 1; ++i){
			cin >> connect_num;
			for (int j = 0; j < connect_num; ++j){
				cin >> connect;
				addedge(i, connect - 1, (i == 0 || connect == n) ? 1 : INT_MAX);
			}
		}

		//============MaxFlow============
		ans = 0;
		while(bfs(0, n - 1))
			ans += dfs(0, n - 1, INT_MAX);
		cout << ans << endl;
	}
	return 0;
}