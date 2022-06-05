#pragma once
#include <iostream>
using namespace std;

class MyClass
{
	int* data;//создаем переменную указатель для массива
private:
	int Size;
public:
	MyClass();//конструктор по умолчанию
	MyClass(int size); //конструктор массива заданного размера
	bool operator ==(const MyClass &other);//перегрузка оператора равно, принимает сравниваемый объект
	MyClass(const MyClass& other);//конструктор копирования
	MyClass& operator = (const MyClass& other);//перегруженный оператор присваивания
	void PrintArr(int* arr, int size);//вывод массива	
	void quickSort(int* arr, int N);//функция быстрой сортировки
	bool isInclude(int d);//функция проверки наличия числа
	int getNum(int i);//функция возвращает значение i-го элемента массива
	MyClass& add(int d); //добавление числа в массив
	MyClass& exclude(int d);//удаление числа из массива

	~MyClass();
};

