#include <iostream>
#include <math.h>
using namespace std;

const int max_num = 200000;

int main(){
    //First step: initialize
    int *check = new int[max_num];
    int *prime = new int[max_num];
    int prime_num = 0;
    for (int i = 0; i < max_num; i++){
        prime[i] = -1;
        check[i] = 1;
    }
    check[0] = 0;
    check[1] = 0;

    //Second step: find prime numbers between 1 and max_num
    for (int i = 2; i < max_num; i++){
        if (check[i] == 0) continue;
        prime[prime_num] = i;
        prime_num += 1;
        for (int j = 2; j < (max_num - 1) / i + 1; j++)
            check[i * j] = 0;
    }

    //Third Step, main procedure
    //Input pair (m, n) and find the related prime numbers
    int group, m, n, cur_prime, cur_left, cur_right;
    cin >> group;
    for (int i = 0; i < group; i++){
        if (i > 0) cout << endl;
        cin >> m >> n;
        if (m == 1) m = 2;
        for (int j = 0; j < n - m + 1; j++)
            check[j] = 1;

        for (int j = 0; j < prime_num; j++){
            cur_prime = prime[j];
            cur_left = (m - 1) / cur_prime + 1;
            cur_right = n / cur_prime;
            if (cur_left == 1) cur_left += 1;
            if (cur_right == 0) break;

            for (int k = cur_left; k < cur_right + 1; k++)
                check[cur_prime * k - m] = 0;
        }

        for (int j = m; j < n + 1; j++){
            if (check[j - m] == 1) cout << j << endl;
        }
    }
    return 0;
}
