#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

template<typename T>
class List {
public:
	List();
	~List();

	void push_back(T data);
	void push_front(T data);
	void pop_front();
	void pop_back();
	void insert(T data, int index);
	void removeAt(int index);
	int getSize() { return Size; }
	void clear();
	T& operator[](const int index);
	bool isEmpty();

private:

	template<typename T>
	class Node {
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}

	};

	Node<T>* head;
	int Size;
};


template<typename T>
List<T>::List() {
	this->Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List() {
	clear();
}

template<typename T>
void List<T>::push_back(T data) {
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;

		}
		current->pNext = new Node<T>(data);
	}

	Size++;
}

template<typename T>
void List<T>::push_front(T data){
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index) {
	if (index == 0){
		push_front(data);
	}
	else {
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;

		/* Более короткая реализация:
		* previous -> pNext = new Node<T> (data, previous->pNext)*/
	
		Size++;
	}
}

template<typename T>
void List<T>::removeAt(int index) {
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T>* previous = head;

		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}

		Node<T> nodeToDelete = previous->pNext;
		previous->pNext = nodeToDelete->pNext;

		delete nodeToDelete ;
		Size--;
	}
}

template<typename T>
void List<T>::pop_front() {
	Node<T>* temp = head;
	head = head->pNext;

	delete temp;
	Size--;
}

template<typename T>
void List<T>::pop_back() {
	removeAt(Size - 1);
}

template<typename T>
void List<T>::clear()
{
	while (Size) {
		pop_front();
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;

	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
bool List<T>::isEmpty() {
	if (head == nullptr) return true;
	else return false;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	List<int> lst;

	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(15);

	cout << "Элементов в списке: " << lst.getSize() << endl;
	cout << "Эти элементы:";
	for (int i = 0; i < lst.getSize(); i++) {
		cout << " " << lst[i];
	}

	lst.push_front(1);
	cout << "\nПосле push_front(): " << endl;
	cout << "Элементов в списке: " << lst.getSize() << endl;
	cout << "Эти элементы:";
	for (int i = 0; i < lst.getSize(); i++) {
		cout << " " << lst[i];
	}

	lst.insert(19, 2);
	cout << "\nПосле insert(19, 2): " << endl;
	cout << "Элементов в списке: " << lst.getSize() << endl;
	cout << "Эти элементы:";
	for (int i = 0; i < lst.getSize(); i++) {
		cout << " " << lst[i];
	}


	return 0;
}
