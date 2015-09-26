#include <iostream>
using namespace std;

int main(){
    uint32_t n = 4294967295;
    int ret = 0;
    /*for (int i = 0; i < 32; ++i){
        if (((1 << i) & n) != 0) ++ret;
        cout << ((1 << i) & n) << endl;
    }*/
    while (n){
        n &= (n - 1);
        ++ret;
    }
    cout << "ret = " << ret << endl;
    return 0;
}
