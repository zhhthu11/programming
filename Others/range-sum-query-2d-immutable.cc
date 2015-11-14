#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
private:
    int **sum;
public:
    NumMatrix(vector<vector<int> > &matrix) {
        sum = NULL;
        if (matrix.size() > 0){
            int n = matrix.size(), m = matrix[0].size();
            sum = new int*[n + 1];
            for (int i = 0; i <= n; ++i){
                sum[i] = new int[m + 1];
                for (int j = 0; j <= m; ++j)
                    sum[i][j] = 0;
            }
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    sum[i + 1][j + 1] = matrix[i][j] + sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
    }
};


int main(){
    vector<vector<int> > test(5, vector<int>(5, 1));
    NumMatrix matrix(test);
    cout << matrix.sumRegion(2,1,4,3) << endl;
    cout << matrix.sumRegion(1,1,2,2) << endl;
    cout << matrix.sumRegion(1,2,2,4) << endl;
    return 0;
}