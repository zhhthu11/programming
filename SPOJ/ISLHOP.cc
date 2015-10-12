#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

struct node{
	int n1, n2;
	double dis;
};

const int maxn = 50;
int x[maxn], y[maxn], num[maxn], father[maxn], queue[maxn];
node nodes[maxn * maxn];
double dis[maxn][maxn], cost[maxn];

double calculate(int x1, int y1, int x2, int y2){
	return sqrt(1.0 * (x1 - x2) * (x1 - x2) + 1.0 * (y1 - y2) * (y1 - y2));
}

double max(double x, double y){
	return (x >= y) ? x : y;
}

bool cmp(node x, node y){
	return (x.dis <= y.dis) ? true : false;
}

int find(int x){
	if (father[x] == -1) return x;
	father[x] = find(father[x]);
	return father[x];
}

int main(){
	int groups = 0, n, m;
	while (scanf("%d", &n)){
		if (n == 0) break;

		//Input and preprocessing
		for (int i = 0; i < n; ++i)
			scanf("%d%d%d", &x[i], &y[i], &num[i]);

		m = 0;
		for (int i = 0; i < n; ++i){
			for (int j = i + 1; j < n; ++j){
				nodes[m].n1 = i;
				nodes[m].n2 = j;
				nodes[m].dis = calculate(x[i], y[i], x[j], y[j]);
				++m;
			}
		}

		for (int i = 0; i < n; ++i){
			father[i] = -1;
			cost[i] = -1.0;
			for (int j = 0; j < n; ++j) dis[i][j] = -1;
		}

		//Sort
		sort(nodes, nodes + m, cmp);
		/*cout << "nodes information" << endl;
		for (int i = 0; i < m; ++i)
			cout << nodes[i].n1 << " : " << nodes[i].n2 << " = " << nodes[i].dis << endl;
		cout << endl;*/

		//Kruskal
		int fa_n1, fa_n2, have_find = 0;
		for (int i = 0; i < m; ++i){
			fa_n1 = find(nodes[i].n1);
			fa_n2 = find(nodes[i].n2);
			if (fa_n1 == fa_n2) continue;
			father[fa_n2] = fa_n1;
			dis[nodes[i].n1][nodes[i].n2] = nodes[i].dis;
			dis[nodes[i].n2][nodes[i].n1] = nodes[i].dis;
			//cout << "add edge : " << nodes[i].n1 << " - " << nodes[i].n2 << " = " << nodes[i].dis << endl;
			if (++have_find == n - 1) break;
		}

		//BFS
		int head = 0, tail = 1;
		queue[0] = 0;
		cost[0] = 0.0;
		while (head < tail){
			int cur = queue[head++];
			for (int i = 0; i < n; ++i){
				if (dis[cur][i] >= 0){
					cost[i] = max(dis[cur][i], cost[cur]);
					//cout << "cost[" << i << "] = " << cost[i] << endl;
					queue[tail++] = i;
					dis[cur][i] = dis[i][cur] = -1;
				}
			}
		}

		//Calculate answer
		double ans = 0;
		int total = 0;
		for (int i = 0; i < n; ++i){
			ans += cost[i] * num[i];
			total += num[i];
		}
		if (total > 0) ans = ans / total;

		//Output
		printf("Island Group: %d Average %.2f\n", ++groups, ans);
	}
	return 0;
}