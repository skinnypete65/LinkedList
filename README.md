# LinkedList
Задание с университета. Нужно было реализовать однонаправленный связанный список.

Методы класса List:

void push_back(T data) - добавляет элемент в конец листа

void push_front(T data) - добавляет элемент в начало листа

void pop_front() - удаляет элемент с начала листа

void pop_back() - удаляет элемент с конца листа

void insert(T data, int index) - вставляет элемент на указанный индекс

void removeAt(int index) - удаляет элемент с указанного индекса

int getSize() - возвращает количество элементов листа

void clear() - очищает лист

T& operator[](const int index) - перегруженный оператор [], который дает доступ к элементу по индексу

bool isEmpty() - проверяет, пуст ли лист

double getAverage() - возвращает среднее арифметическое элементов листа

void changeSourceDataToNewData(T sourceData, T newData) - меняет все указанные исходные элементы на новые

void changeFirstAndLast() - меняет первый и последний элемент
