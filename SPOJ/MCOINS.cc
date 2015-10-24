#include <iostream>
#include <cstring>
using namespace std;

int pos[1000020];

int main(){
	int k, l, m, n;
	scanf("%d%d%d", &k, &l, &m);
	string ans = "";
	for (int i = 0; i < m; ++i){
		scanf("%d", &n);
		for (int j = n + 1; j < n + 10; ++j) pos[j] = 1;
		pos[n] = 0;
		for (int j = n - 1; j >= 0; --j){
			if (pos[j + 1] == 0 || pos[j + k] == 0 || pos[j + l] == 0)
				pos[j] = 1;		//win
			else
				pos[j] = 0;		//lose
		}
		if (pos[0] == 1) ans += "A";
		else ans += "B";
	}
	printf("%s\n", ans.c_str());
	return 0;
}