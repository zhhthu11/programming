#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
    	auto found = this->cache_map.find(key);
    	if (found == this->cache_map.end()) return -1;
    	this->cache.splice(this->cache.begin(), this->cache, found->second);
    	return found->second->second;
    }
    
    void set(int key, int value) {
    	auto found = this->cache_map.find(key);
    	//Succefully find
    	if (found != this->cache_map.end()){
    		this->cache.splice(cache.begin(), cache, found->second);
    		found->second->second = value;
    		return;
    	}
    	//Is not able to find
    	if (this->capacity == this->cache_map.size()){
    		this->cache_map.erase(cache.back().first);
    		this->cache.pop_back();
    	}
    	this->cache.push_front(make_pair(key, value));
    	this->cache_map[key] = this->cache.begin();
    }

private:
	int capacity;
	list<pair<int, int> > cache;
	unordered_map<int, list<pair<int, int> >::iterator> cache_map;
};

int main(){
	return 0;
}