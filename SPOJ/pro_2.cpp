#include <iostream>
#include <math.h>
using namespace std;

const int max_num = 200000;
int check[max_num];
int prime[max_num];
//int prime

int main()
{
    //First step, preprepossing
    //Find prime numbers between 1 and max_num
    int prime_num = 0;
    for (int i = 0; i < max_num; i++)
    {
        prime[i] = -1;
        check[i] = 1;
    }
    check[0] = 0;
    check[1] = 0;

    for (int i = 2; i < max_num; i++)
    {
        if (check[i] == 0)
        {
            continue;
        }

        prime[prime_num] = i;
        prime_num += 1;
        /*if (i < 20)
        {
            cout << "i = " << i << endl;
            cout << "prime[" << prime_num - 1 << "] = " << prime[prime_num - 1] << endl;
            cout << "prime_num = " << prime_num << endl;
        }*/

        for (int j = 2; j < max_num / i + 1; j++)
        {
            check[i * j] = 0;        
        }
    }

    /*cout << prime_num << endl;
    for (int i = 0; i < 10; i++)
        cout << "prime[" << i << "] = " << prime[i] << endl;*/
    prime[0] = 2;

    //Second Step, main procedure
    //Input pair (m, n) and find the related prime numbers
    int group, m, n, cur_prime, cur_left, cur_right;
    cin >> group;

    for (int i = 0; i < group; i++)
    {
        if (i > 0)
        {
            cout << endl;
        }

        cin >> m >> n;
        
        if (m == 1)
        {
            m = 2;
        }
        //cout << "m = " << m << endl;
        //cout << "n = " << n << endl;

        for (int j = 0; j < n - m + 1; j++)
        {
            check[j] = 1;
        }

        /*for (int j = 0; j < n - m + 1; j++)
            cout << j << " = " << check[j] << " ; ";
        cout << endl;*/

        for (int j = 0; j < prime_num; j++)
        {
            cur_prime = prime[j];
            cur_left = (m - 1) / cur_prime + 1;
            cur_right = n / cur_prime;
            if (cur_left == 1)
            {
                cur_left += 1;
            }

            /*cout << "cur_prime = " << cur_prime << endl;
            cout << "cur_left = " << cur_left << endl;
            cout << "cur_right = " << cur_right << endl;*/
            if (cur_right == 0)
            {
                break;
            }

            for (int k = cur_left; k < cur_right + 1; k++)
            {
                check[cur_prime * k - m] = 0;                
            }
        }

        /*for (int j = 0; j < n - m + 1; j++)
            cout << j << " = " << check[j] << " ; ";
        cout << endl;*/

        for (int j = m; j < n + 1; j++)
        {
            if (check[j - m] == 1)
            {
                cout << j << endl;
            }
        }        
    }

    return 0;
}
