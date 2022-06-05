#pragma once
#include <iostream>
using namespace std;

class MyClass
{
	int* data;//������� ���������� ��������� ��� �������
private:
	int Size;
public:
	MyClass();//����������� �� ���������
	MyClass(int size); //����������� ������� ��������� �������
	bool operator ==(const MyClass &other);//���������� ��������� �����, ��������� ������������ ������
	MyClass(const MyClass& other);//����������� �����������
	MyClass& operator = (const MyClass& other);//������������� �������� ������������
	void PrintArr(int* arr, int size);//����� �������	
	void quickSort(int* arr, int N);//������� ������� ����������
	bool isInclude(int d);//������� �������� ������� �����
	int getNum(int i);//������� ���������� �������� i-�� �������� �������
	MyClass& add(int d); //���������� ����� � ������
	MyClass& exclude(int d);//�������� ����� �� �������

	~MyClass();
};

