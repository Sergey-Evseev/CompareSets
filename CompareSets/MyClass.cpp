#include "MyClass.h"
#include <iostream> 
using namespace std;

//конструктор по умолчанию // создает массив на 10 элементов //
MyClass::MyClass()
{
	cout << "\nКонструктор по умолч. - отсортированный массив на 10 элементов, объект " << this << ":";
	int Size{ 10 };
	this->data = new int[Size]; //int arr[10];
	for (int i = 0; i < Size; i++) //заполняем массив рандомными значениями
	{
		data[i] = rand() % 100;
	}
	PrintArr(data, Size); cout << "- массив до сортировки" << endl;
	MyClass::quickSort(data, (Size - 1));//вызов быстрой сортировки
	PrintArr(data, Size);//вывод отсортированного массива
	cout << "- массив после сортировки" << endl;
}

//Конструктор создания массива заданного размера//
MyClass::MyClass(int size)//передаем размерность массива
{
	cout << "\nМассив на " << size << " элементов, создан объект " << this << " :" << endl;
	this->Size = size;
	this->data = new int[size];//создаем дин.массив и присваиваем его переменной-указателю класса 
	for (int i = 0; i < size; i++) //заполняем массив рандомными значениями
	{
		*(data + i) = rand() % 10;
	}
	PrintArr(data, Size);
}
//перегрузка оператора 'равно'//
bool MyClass::operator==(const MyClass & other)//принимаем константный объект класса, с которым сравниваем
{
	bool check = true;
	if (this->Size != other.Size) { check = false; }//если длина массивов отличается вернуть false
	else for (int i = 0; i < Size; i++) {//если длина одинаковая в цикле сравниваем i-тый элемент каждого массива
		if (*(data + i) != *(other.data + i))
		{
			check = false;//при нахождении первого неравного элемента прерываем цикл
			break;
		}		
	}
	if (check == true) { cout << "Объекты " << this << " & " << &other << " равны "; }
	else { cout << "Объекты " << this << " & " << &other << " не равны "; }

	return check;
}
//перегрузка конструктора копирования//
MyClass::MyClass(const MyClass& other)
{
	cout << "\nКонструктор копирования, создан объект " << this << ": " << endl;
	//this->data = other.data; реализация конструктора копирования по умолчанию
	this->Size = other.Size;
	this->data = new int[other.Size]; //наша реализация конструктора копирования 
	for (int i = 0; i < other.Size; i++)
	{
		this->data[i] = other.data[i];
	}
	PrintArr(data, Size); cout << endl;
}
//перегрузка оператора присваивания//
MyClass& MyClass::operator=(const MyClass& other)
{
	cout << "Оператор присваивания, создан объект: " << this << endl;
	this->Size = other.Size;//поле Size просто копируем, так как он в динамической памяти не выделяется (очищать не нужно)
	if (this->data != nullptr)//проверка на ненулевой указатель
	{
		delete[] this->data;
	}
	//логика поэлементного копирования после очистки текущего объекта:
	this->data = new int[other.Size];
	for (int i = 0; i < other.Size; i++)
	{
		this->data[i] = other.data[i];
	}
	PrintArr(data, Size); cout << endl;
	return *this;
}

//функция вывода PrintArr//
void MyClass::PrintArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
}
//функция быстрой сортировки для конструктора по умолчанию//
void MyClass::quickSort(int* data, int N) //data[N]-послед. эл. массива
{
	int i = 0, j = N; int temp, p;
	p = data[N / 2];
	do {
		while (data[i] < p) i++;
		while (data[j] > p) j--;
		if (i <= j) {
			temp = data[i]; data[i] = data[j]; data[j] = temp;
			i++; j--;
		}
	} while (i <= j);
	if (j > 0) quickSort(data, j);
	if (N > i) quickSort(data + i, N - i);
}
//функция проверки числа в массиве
bool MyClass::isInclude(int d)
{
	cout << "Поиск числа: " << d << " в массиве " << this;
	if (data != nullptr) {
		for (int i = 0; i < Size; i++) {
			if (d == getNum(i)) {
				cout << " - есть такое число!" << endl;
				return true;
			}			
		}
	}
	cout << " - нет такого числа!" << endl;
	return false;
}
int MyClass::getNum(int i)//функция получения значения элемента
{
	return this->data[i];
}

//функция добавления элемента в массив//
MyClass& MyClass::add(int d)
{
	if (!isInclude(d)) {//если такого числа нет в массиве
		int* temp = new int[this->Size + 1];//созд.врем. массива на 1 эл-т больше
		for (int j = 0; j < Size; j++) { //копирование эл-тов в врем. массив
			temp[j] = data[j];//копируем из старого массива в новый 
		}
		temp[Size] = d;//последнему элементу присвоить передаваемое значение
		delete[] data;//удалить элементы старого массива
		data = temp;//присвоить массиву объекта новый массив 
		Size++;//увеличиваем память под итоговый массив
	}
	cout << "Массив " << this << " после добавления числа " << d << ":" << endl;
	PrintArr(data, Size); cout << endl;
	return *this;
}
//функция удаления числа из массива//
MyClass & MyClass::exclude(int d)
{
	cout << "Удаление числа " << d << " из массива " << this << ":" << endl;
	PrintArr(data, Size); cout << endl;
	int found = 0;
	if (isInclude(d)) {//проверка наличия числа		
		for (int i = 0; i < Size; i++) { //копирование эл-тов в врем. массив			
			if (*(data+i) == d)//если текущий элемент совпадает с искомым значением
			{
				for (int j = i; j<Size; j++)//то начиная от элемента с совпадающим значением пробегать до конца массива 
				{
					*(data+j) = *(data +j + 1); //и присвоить каждому элементу значение следующего (сдвиг влево)					
				}
				i--; //следующий внешний цикл проверки начать с предыдущей позиции, на случай в если текущем цикле 
				     //стояли два подряд искомых числа, и на месте удаленного снова пришло искомое
				Size--; //массив уменьшить на единицу из-за сдвига
				found++; //счетчик найденных чисел
			}			
		}
		cout << "Число " << d << " удалено " << found << " раз" << endl;
		cout << "Массив " << this << " после удаления числа " << d << ":" << endl;
		PrintArr(data, Size); cout << endl;
	}
	else cout << "Ничего не удалено" << endl;
	
	return *this;
}

//оператор сложения массивов//DRAFT DRAFT DRAFT
MyClass & MyClass::operator+(const MyClass & other)
{
	cout << "Оператор сложения: " << this << endl;
	this->Size = other.Size;//поле Size просто копируем, так как он в динамической памяти не выделяется (очищать не нужно)
	if (this->data != nullptr)//проверка на ненулевой указатель
	{
		delete[] this->data;
	}
	//логика поэлементного копирования после очистки текущего объекта:
	this->data = new int[other.Size];
	for (int i = 0; i < other.Size; i++)
	{
		this->data[i] = other.data[i];
	}
	PrintArr(data, Size); cout << endl;
	return *this;
}

//Деструктор объекта и массива//
MyClass::~MyClass()
{	
	cout << "Деструктор объекта " << this << endl;
	delete[] data; //в деструкторе также уничтожаем сам массив, чтобы не было утечек памяти
}

