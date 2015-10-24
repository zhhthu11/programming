#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
private:
	priority_queue<int, vector<int>, greater<int> > min_heap;
	priority_queue<int, vector<int>, less<int> > max_heap;
public:
    // Adds a number into the data structure.
    void addNum(int num) {
    	if (min_heap.size() == 0){
    		min_heap.push(num);
    		return;
    	}

        if (min_heap.size() == max_heap.size()){
        	if (num >= max_heap.top()){
        		min_heap.push(num);
        	}
        	else{
        		int m = max_heap.top();
        		max_heap.pop();
        		min_heap.push(m);
        		max_heap.push(num);
        	}
        }
        else{
        	if (num <= min_heap.top()){
        		max_heap.push(num);
        	}
        	else{
        		int m = min_heap.top();
        		min_heap.pop();
        		min_heap.push(num);
        		max_heap.push(m);
        	}
        }
    }

    // Returns the median of current data stream
    double findMedian() {
    	if (min_heap.size() == 0) return 0.0;
        if (min_heap.size() > max_heap.size())
        	return 1.0 * min_heap.top();
        else
        	return ((1.0 * min_heap.top() + 1.0 * max_heap.top()) / 2);
    }
};

int main(){
	MedianFinder mf;
	mf.addNum(1);
	cout << mf.findMedian() << endl;
	mf.addNum(5);
	cout << mf.findMedian() << endl;
	mf.addNum(3);
	cout << mf.findMedian() << endl;
	mf.addNum(2);
	cout << mf.findMedian() << endl;
}