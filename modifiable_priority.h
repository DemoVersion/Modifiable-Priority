#include<iostream>
#include<map>
#include<set>
using namespace std;
#ifndef MODIFIABLE_PRIORITY
#define MODIFIABLE_PRIORITY
template <typename T>
class modifiabale_priority {
private:
	map<T, int> mp;
	set<pair<int, T> > ps;
public:
	T top();/// returns TOP of priority queue
	void pop();/// remove TOP of priority queue
	void push(T const&, int p);/// insert something into priority queue WARNING! recomended to use improve instead
	int improve(T const&, int p);/// insert something into priority queue, in case it exist before improve that.
	void remove(T const&);/// remove an object from priorty queue, ( form middle,down, not necessary top).
	int size();/// returns the size of priority queue
	int empty();/// return true if priority queue is empty
};

/*
if object exists on the Queue, improve only affect when priority improves.
In other case it acts like normal push.
*/
template <typename T>
int modifiabale_priority<T>::improve(T const& obj, int p) {
	pair<int, T> pstate_new = pair<int, T>(p, obj);
	if (mp.count(obj)) {
		int last_p = mp[obj];
		if (p < last_p) {
			pair<int, T> pstate_old = pair<int, T>(last_p, obj);
			ps.erase(pstate_old);
			ps.insert(pstate_new);
			mp[obj] = p;
			return 1;
		}
		return 0;
	}
	else {
		mp[obj] = p;
		ps.insert(pstate_new);
		return 1;
	}
}
/*
Use push in case you are sure that Object does not exist on the Queue.
*/
template <typename T>
void modifiabale_priority<T>::push(T const& obj, int p) {
	pair<int, T> pstate_new = pair<int, T>(p, obj);
	mp[obj] = p;
	ps.insert(pstate_new);
}
template <typename T>
T modifiabale_priority<T>::top() {
	pair<int, T> ret = *ps.begin();
	ps.erase(ret);
	return ret.second;
}
template <typename T>
void modifiabale_priority<T>::pop() {
	pair<int, T> ret = *ps.begin();
	ps.erase(ret);
}
template <typename T>
void modifiabale_priority<T>::remove(T const& obj) {
	if (mp.count(obj)) {
		int last_p = mp[obj];
		pair<int, T> pstate_old = pair<int, T>(last_p, obj);
		ps.erase(pstate_old);
		mp.erase(obj);
	}
}
template <typename T>
int modifiabale_priority<T>::size() {
	return mp.size();
}
template <typename T>
int modifiabale_priority<T>::empty() {
	if (mp.size()>0) {
		return 1;
	}
	else {
		return 0;
	}
}
#endif
