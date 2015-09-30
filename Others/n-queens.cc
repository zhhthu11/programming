#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        if (n <= 0) return vector<vector<string> >();
        int *check = new int[n * n];
        for (int i = 0; i < n * n; ++i) check[i] = 0;
        vector<vector<int> > ans;
        int total = 0;
        for (int i = 0; i < n / 2; ++i){
            vector<int> tmp(1, i);
            total += dfs(0, i, check, n, tmp, ans);
        }
        if (n % 2 == 1){
            vector<int> tmp(1, n / 2);
            dfs(0, n / 2, check, n, tmp, ans);
        }
        for (int i = total - 1; i >= 0; --i){
            vector<int> cur;
            for (int j = 0; j < ans[i].size(); ++j)
                cur.push_back(n - 1 - ans[i][j]);
            ans.push_back(cur);
        }
        vector<vector<string> > ret;
        for (int i = 0; i < ans.size(); ++i){
            vector<string> cur_string_vec;
            for (int j = 0; j < n; ++j){
                string cur_string = "";
                for (int k = 0; k < ans[i][j]; ++k) cur_string += ".";
                cur_string += "Q";
                for (int k = ans[i][j] + 1; k < n; ++k) cur_string += ".";
                cur_string_vec.push_back(cur_string);
            }
            ret.push_back(cur_string_vec);
        }
        return ret;
    }
    
    void change_check(int x, int y, int *check, int n, int value){
        bool flag = true;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (check[i * n + j] < 0) flag = false;

        if (flag == false){
            cout << "before change.." << endl;
            for (int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j) cout << check[i * n + j] << ",";
                cout << endl;
            }
            cout << "x = " << x << ", y = " << y  << ", value = " << value << endl;
            exit(0);
        }

        for (int i = 0; i < n; ++i){
            if (x - i >= 0) check[(x - i) * n + y] += value;
            if (x + i < n) check[(x + i) * n + y] += value;
            if (y - i >= 0) check[x * n + (y - i)] += value;
            if (y + i < n) check[x * n + (y + i)] += value;
            if ((x - i >= 0) and (y - i >= 0)) check[(x - i) * n + (y - i)] += value;
            if ((x - i >= 0) and (y + i < n)) check[(x - i) * n + (y + i)] += value;
            if ((x + i < n) and (y - i >= 0)) check[(x + i) * n + (y - i)] += value;
            if ((x + i < n) and (y + i < n)) check[(x + i) * n + (y + i)] += value;
        }

        flag = true;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (check[i * n + j] < 0) flag = false;

        if (flag == false){
            cout << "after change.." << endl;
            for (int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j) cout << check[i * n + j] << ",";
                cout << endl;
            }
            cout << "x = " << x << ", y = " << y  << ", value = " << value << endl;
            exit(0);
        }
    }
    
    int dfs(int x, int y, int *check, int n, vector<int> &status, vector<vector<int> > &ans){
        if (x == n - 1){
            ans.push_back(status);
            return 1;
        }

        change_check(x, y, check, n, 1);
        int ret = 0;
        for (int i = 0; i < n; ++i)
            if (check[(x + 1) * n + i] == 0){
                status.push_back(i);
                ret += dfs(x + 1, i, check, n, status, ans);
                status.pop_back();
            }
        change_check(x, y, check, n, -1);
        return ret;
    }
};

int main(){
    Solution test;
    vector<vector<string> > ans = test.solveNQueens(7);
    for (int i = 0; i < ans.size(); ++i){
        for (int j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j] << endl;
        cout << endl;
    }
    cout << "num = " << ans.size() << endl;
    return 0;
}