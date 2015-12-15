#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 310, maxm = 91000;
int go[maxm], flow[maxm], nextEdge[maxm], edge_num;
int fir[maxn], level[maxn], q[maxn];
int n, m, S, T;
 
void addedge(int x, int y, int flowNum){
	//add edge from x to y
	go[edge_num] = y;
	flow[edge_num] = flowNum;
	nextEdge[edge_num] = fir[x];
	fir[x] = edge_num++;
}
 
int bfs(){
	int tail = 0;
	memset(level, -1, sizeof(level[0]) * (T + 1));
	level[S] = 0, q[tail++] = S;
	for (int i = 0; i < tail; ++i)
		for (int j = fir[q[i]]; j != -1; j = nextEdge[j])
			if (flow[j] && level[go[j]] == -1){
				level[go[j]] = level[q[i]] + 1;
				q[tail++] = go[j];
				if (go[j] == T) return 1;
			}
	return 0;
}
 
int dfs(int x, int maxflow){
	if (x == T) return maxflow;
	for (int i = fir[x]; i != -1; i = nextEdge[i])
		if (flow[i] && level[go[i]] == level[x] + 1)
			if (int t = dfs(go[i], std::min(maxflow, flow[i]))){
				flow[i] -= t, flow[i ^ 1] += t;
				return t;
			}
	return 0;
}
 
int main(){
	while (scanf("%d%d", &n, &m), n || m){
		//========Preprocessing==========
		S = 0, T = n + 1, edge_num = 0;
		memset(fir, -1, sizeof(fir[0]) * (T + 1));
 
		//============Input==============
		int x, y;
		for (int i = 1; i <= n; ++i){
			scanf("%d", &x);
			if (x)
				addedge(S, i, 1), addedge(i, S, 0);
			else
				addedge(i, T, 1), addedge(T, i, 0);
		}
		for (int i = 0; i < m; ++i){
			scanf("%d%d", &x, &y);
			addedge(x, y, 1), addedge(y, x, 1);
		}
 
		//============MaxFlow============
		int t, ans = 0;
		while(bfs()){
			while ((t = dfs(S, INT_MAX)))
				ans += t;
		}
		printf("%d\n", ans);
	}
 
	return 0;
} 