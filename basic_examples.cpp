#include<iostream>
#include<string>
#include "modifiable_priority.h"
int main(){
	/*
		Example 1, String
	*/
	modifiabale_priority<string> mp_string;
	mp_string.push("Task Manager", 5);
	mp_string.push("Firefox", 7);
	std::cout <<"Highest Priorty : "<< mp_string.top() <<endl;
	mp_string.improve("Firefox", 2);
	std::cout <<"Highest Priorty : "<< mp_string.top() <<endl;
	/*
		OUTPUT:
			Highest Priorty : Task Manager
			Highest Priorty : Firefox
	*/
	/*
		Example 2, int
		You can always choose an integer id for your objects and work with
		these numbers its the fastest form.
	*/
    modifiabale_priority<int> mp_int;
	mp_int.push(777, 9);
	mp_int.push(999, 8);
	std::cout << "Highest Priorty : " << mp_int.top() << endl;
	mp_int.improve(777, 7);
	std::cout << "Highest Priorty : " << mp_int.top() << endl;
	/*
		OUTPUT:
			Highest Priorty : 999
			Highest Priorty : 777
	*/
	/*
		Example 3, Your defined class can be used here if < operator has been
		implemented on it or you may just pick up an id and work with that 
		integer id.
	*/
	class worker {
		public:
			string name;
			string lname;
			worker() :name(""), lname("") {}
			worker(string name, string lname) :name(name), lname(lname){}
			bool operator < (const worker &e) const {
				if(name != e.name)return name < e.name;
				return lname < e.lname;
			}
	};
	modifiabale_priority<worker> mp_worker;
	worker w1("Ali", "Hasani");
	worker w2("Reza", "Hoseyni");
	worker w3("Mohammad", "Rezayii");
	mp_worker.push(w1, 125);
	mp_worker.push(w2, 111);
	mp_worker.push(w3, 90);
	std::cout << "Highest Priorty : " << mp_worker.top().lname << endl;
	mp_worker.improve(w1, 80);
	std::cout << "Highest Priorty : " << mp_worker.top().lname << endl;
	mp_worker.improve(w2, 70);
	std::cout << "Highest Priorty : " << mp_worker.top().lname << endl;
	/*
		OUTPUT:
			Highest Priorty : Rezayii
			Highest Priorty : Hasani
			Highest Priorty : Hoseyni
	*/
    return 0;
}
