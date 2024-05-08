#ifndef Queue_H
#define Queue_H
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

class MyException : public runtime_error{
public:
	MyException(const char *msg) : runtime_error(msg)
	{}
private:
};
class Error : public MyException{
public:
	Error(const char *msg) : MyException(msg)
	{}
private:

};

template <typename T>
class Queue{
private:
	struct comp{
		T number;
		comp *next;
		comp *prev;
	};
	comp *head = NULL;
	comp *tail = NULL;
	int size = 0;
public:
	Queue() {};
	void push_back(const T a){
		comp *q;
		q = new comp;
		q->number = a;

		if (size == 0){
			q->next = q->prev = NULL;
			head = tail = q;
		}
		else{
			q->prev = NULL;
			q->next = tail;
			tail = q;
			q = q->next;
			q->prev = tail;
		}
		size++;
	};
	void print()const{
		if (size == 0){
			cout << "The queue is empty" << endl;
		}
		else{
			comp *q = head;
			while (q != NULL){
				cout << q->number;
				cout << "\t" << q->next << "\t" << q->prev << endl;
				q = q->prev;
			}
		}
		cout << "size Queue = " << size << endl;
	}
	bool empty()const{
		if (head == NULL && tail == NULL){
			return 1;
		}
		return 0;
	};
	int GetSize()const{
		return size;
	};
	T back()const{
		comp *q = tail;
		return q->number;
	};
	T front()const{
		comp *q = head;
		return q->number;
	};
	void pop(){
		if (size > 1){
			comp *q = head;
			q = q->prev;
			q->next = NULL;
			delete head;
			head = q;
			size--;
		}
		else{
			if (size == 0){
				throw Error("QUEUE IS EMPTY");
			}
			delete head;
			size--;
		}
	};
	void clear(){
		while (size != 0){
			pop();
		}
	};
	Queue(const Queue &h){
		clear();
		int i = h.size;
		comp *other = h.head;
		while (i != 0){
			push_back(other->number);
			other = other->prev;
			i--;
		}
		size = h.size;
	};
	Queue& operator =(const Queue &h){
		if (this == &h) {
			return *this;
		}
		clear();
		int i = h.size;
		comp *other = h.head;
		while (i != 0){
			push_back(other->number);
			other = other->prev;
			i--;
		}
		size = h.size;
		return *this;
	};
};

struct Point
{
	int x = 5;
	int y = 3;
	int z = 7;
};

template <typename T>
ostream& operator<<(ostream& os, const Queue<T>& h){
	Queue<T> a = h;
	int i = a.GetSize();
	T j;
	while (a.GetSize() != 0){
		j = a.front();
		cout << j << " ";
		a.pop();
	}
	os << endl << "size Queue = " << i << endl;
	return os;
};

ostream& operator<<(ostream& os, const Point& h){
	os << " x = " << h.x << " y = " << h.y << " z = " << h.z << endl;
	return os;
};


#endif