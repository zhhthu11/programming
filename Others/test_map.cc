#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<int, char> m;
    m[0] = '0';
    m[1] = '2';
    unordered_map<int, char>::iterator it;
    for (it = m.begin(); it != m.end(); ++it)
        cout << it->first << " - " << it->second << endl;
    return 0;
}
