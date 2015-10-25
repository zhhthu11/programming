#include <iostream>
#include <cstring>
using namespace std;

int pos[1000020];

int main(){
	int k, l, m, a[50], n = -1;
	scanf("%d%d%d", &k, &l, &m);
	for (int i = 0; i < m; ++i){
		scanf("%d", &a[i]);
		if (a[i] > n) n = a[i];
	}

	for (int j = n + 1; j < n + 10; ++j) pos[j] = 1;
	pos[n] = 0;
	for (int j = n - 1; j >= 0; --j){
		if (pos[j + 1] == 0 || pos[j + k] == 0 || pos[j + l] == 0)
			pos[j] = 1;		//win
		else
			pos[j] = 0;		//lose
	}

	string ans = "";
	for (int i = 0; i < m; ++i)
		if (pos[n - a[i]] == 1) ans += "A";
		else ans += "B";
	cout << ans << endl;
	return 0;
}