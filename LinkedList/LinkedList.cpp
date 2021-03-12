#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;

int main();

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
	double getAverage();
	void changeSourceDataToNewData(T sourceData, T newData);
	void changeFirstAndLast();

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

		Node<T>* nodeToDelete = previous->pNext;
		previous->pNext = nodeToDelete->pNext;

		delete nodeToDelete;
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

template<typename T>
double List<T>::getAverage()
{
	Node<T>* node = head;
	double amount = 0;

	for (int i = 0; i < Size; i++) {
		amount += node->data;
		node = node->pNext;
	}

	return amount / Size;
}

template<typename T>
void List<T>::changeSourceDataToNewData(T sourceData, T newData){
	Node<T>* node = head;
	for (int i = 0; i < Size; i++) {
		if (node->data == sourceData) {
			node->data = newData;
		}
		node = node->pNext;
	}
}

template<typename T>
void List<T>::changeFirstAndLast() {
	Node<T>* lastNode = head;
	for (int i = 0; i < Size-1; i++) {
		lastNode = lastNode->pNext;
	}

	T tempData = lastNode->data;
	lastNode->data = head->data;
	head->data = tempData;
}

template<typename T>
void printList(List<T>& lst) {
	for (int i = 0; i < lst.getSize(); i++) {
		cout << lst[i] << " ";
	}
	cout << endl;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	List<int> myList;
	int num1, num2;
	bool choice;

	// Работа с листом
	cout << "Введите размер листа, который будет заполнен случайными элементами: ";
	cin >> num1;
	for (int i = 0; i < num1; i++) {
		myList.push_back(rand() % 20);
	}
	printList(myList);
	
	cout << "Введите число, которое хотите добавить в конец листа: ";
	cin >> num1;
	myList.push_back(num1);
	printList(myList);

	cout << "Введите число, которое хотите добавить в начало листа: ";
	cin >> num1;
	myList.push_front(num1);
	printList(myList);

	cout << "Хотите удалить первый элемент списка?(0 - нет, 1 - да): ";
	cin >> choice;
	if (choice) {
		myList.pop_front();
	}
	printList(myList);

	cout << "Хотите удалить последний элемент списка?(0 - нет, 1 - да): ";
	cin >> choice;
	if (choice) {
		myList.pop_back();
	}
	printList(myList);

	cout << "Введите элемент и индекс, на который хотите вставить его (размер листа равен " << myList.getSize() << "): ";
	cin >> num1 >> num2;
	myList.insert(num1, num2);
	printList(myList);

	cout << "Введите индекс, с которого хотите удалить элемент(размер листа равен " << myList.getSize() << "): ";
	cin >> num1;
	myList.removeAt(num1);
	printList(myList);

	cout << "Среднее арифметическое листа: " << myList.getAverage() << endl;

	cout << "Введите элемент, который хотите заменить, и новый элемент, на который хотите заменить: ";
	cin >> num1 >> num2;
	myList.changeSourceDataToNewData(num1, num2);
	printList(myList);

	cout << "Смена первого и последнего элемента:" << endl;
	myList.changeFirstAndLast();
	printList(myList);

	cout << "Очистить лист:(0 - нет, 1 - да): ";
	cin >> choice;
	if (choice) {
		myList.clear();
	}

	cout << "Пуст ли список?: ";
	if (myList.isEmpty()) cout << "Да";
	else cout << "Нет";
	
	return 0;
}
