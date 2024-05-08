#include <iostream>
#include "Queue.h"

using namespace std;

int main(){
	Queue <int>a;
	int j = 1;
	char c;
	for (int i = 0; i < 10; i++){
		a.push_back(i);
	}
	a.pop();
	Queue <int>b(a);
	a.clear();
	cout << b;
	Queue <char>a1;
	Queue <char>b1;
	cout << "Input letter : ";
	cin >> c;
	for (int i = 0; i < 10; i++) {
		a1.push_back(c);
	}
	a1.pop();
	b1 = a1;
	a1.clear();
	cout << b1;
	Queue <double>a2;
	Queue <double>b2;
	double y = 1.1;
	for (int i = 0; i < 10;i++) {
		a2.push_back(y);
		y++;
	}
	a2.pop();
	b2 = a2;
	a2.clear();
	cout << b2;
	Queue <Point>a3;
	Queue <Point>b3;
	Point w;
	for(int i = 0;i < 10;i++){
		a3.push_back(w);
	}
	a3.pop();
	b3 = a3;
	a3.clear();
	cout << b3;
	Queue <bool>a4;
	Queue <bool>b4;
	bool r = 1;
	for (int i = 0; i < 10;i++) {
		a4.push_back(r);
	}
	a4.pop();
	b4 = a4;
	a4.clear();
	cout << b4;
	try{
		a4.pop();
	}
	catch (Error &ex){
		cout << ex.what() << endl;
	}
	return 0;
}