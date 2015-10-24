#include <iostream>
#include <queue>
using namespace std;

int main(){
	cout << "======q1=======" << endl;
	priority_queue<int, vector<int>, less<int> > q1;
	for (int i = 0; i < 10; ++i)
		q1.push(i);
	cout << "size = " << q1.size() << endl;
	while (!q1.empty()){
		cout << q1.top() << endl;
		q1.pop();
	}
	cout << "size = " << q1.size() << endl;

	cout << "======q2=======" << endl;
	priority_queue<int, vector<int>, greater<int> > q2;
	for (int i = 0; i < 10; ++i)
		q2.push(i);
	cout << "size = " << q2.size() << endl;
	while (!q2.empty()){
		cout << q2.top() << endl;
		q2.pop();
	}
	cout << "size = " << q2.size() << endl;

	return 0;
}