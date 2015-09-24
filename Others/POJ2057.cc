#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

const int max_n = 1010;
struct node
{
	int success, fail, leave;
	bool flag;
};

node status[max_n];
vector<int> children[max_n];

bool cmp(int x, int y){
	return ((status[x].fail + 2) * status[y].leave < (status[y].fail + 2) * status[x].leave);
}

void dfs(int root){
	for (int i = 0; i < children[root].size(); ++i)
		dfs(children[root][i]);

	status[root].success = status[root].fail = status[root].leave = 0;

	if (children[root].size() == 0){
		status[root].leave = 1;
		//cout << root << " = " << status[root].success << " :" << status[root].fail << " : " << status[root].leave << endl;
		return;
	}

	sort(children[root].begin(), children[root].end(), cmp);
	for (int i = 0; i < children[root].size(); ++i){
		int child = children[root][i];
		status[root].success += (status[root].fail + 1) * status[child].leave + status[child].success;
		status[root].fail += status[child].fail + 2;
		status[root].leave += status[child].leave;
	}

	if (status[root].flag) status[root].fail = 0;
	//cout << root << " = " << status[root].success << " :" << status[root].fail << " : " << status[root].leave << endl;
}

int main(){
	int n, pre;
	char s[2];
	while (scanf("%d", &n)){
		if (n == 0) break;
		for (int i = 0; i < n; ++i)
			children[i].clear();
		for (int i = 0; i < n; ++i){
			scanf("%d %s", &pre, s);
			if (pre != -1) children[pre - 1].push_back(i);
			status[i].flag = ((s[0] == 'Y') ? true : false);
		}
		dfs(0);
		double answer = 1.0 * status[0].success / status[0].leave;
		printf("%.4f\n", answer);
	}
	return 0;
}