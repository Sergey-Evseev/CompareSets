﻿//Lesson 3. Task 1 Реализовать методы: 
//■■ • конструкторы (по умолчанию, с параметрами, копирования);
//■■ • деструктор;
//■■ • проверка принадлежности элемента множеству.
//Реализовать операции :
//■■ • добавление элемента в множество(+, +=);
//■■ объединение двух множеств(+, +=);
//■■ удаление элемента(-, -=);
//■■ разность множеств(-, -=);
//■■ пересечение множеств(*, *=);
//■■ • присваивание(= );
//■■ • сравнения множеств(== );
//■■ потоковый вывод и ввод(<< , >> ).
#include <iostream>
#include "MyClass.h"
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	int size1 = 0; int size2 = 0;
	cout << "Введите размеры массивов через пробел:" << endl;
	cin >> size1 >> size2;
	MyClass d; //конструктор по умолчанию - создает массив из 10 рандомных элементво
	MyClass a(size1); //создаем объекты класса (массивы) через конструктор с параметрами
	MyClass b(size2);
	bool equal = a == b; //вызов перегруженного оператора равенства
	cout << "(объекты равны: " << equal << ")" << endl;
	MyClass c(b); //перегрузка конструктора копирования (объект с новым адресом с новыми скопированными данными)
	b = c;//присваивание объекта через перегруженный оператор "равно" (объект с тем же адресом с новыми данными)
	//b = a = c; //последовательное присваивание через перегруженный оператор равно (то же адрес, новые данные, с конца выражения)
	b.isInclude(10); //поиск числа в массиве объекта
	b.add(99);//добавление числа в массив 
	a.exclude(10);
	return 0;
}