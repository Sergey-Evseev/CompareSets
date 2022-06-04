#include "MyClass.h"
#include <iostream> 
using namespace std;

//����������� �� ��������� // ������� ������ �� 10 ��������� //
MyClass::MyClass()
{
	cout << "\n����������� �� �����. - ��������������� ������ �� 10 ���������, ������ " << this << ": ";
	int Size{ 10 };
	this->data = new int[Size]; //int arr[10];
	for (int i = 0; i < Size; i++) //��������� ������ ���������� ����������
	{
		data[i] = rand() % 100;
	}
	PrintArr(data, Size); cout << "- ������ �� ����������" << endl;
	MyClass::quickSort(data, (Size - 1));//����� ������� ����������
	PrintArr(data, Size);//����� ���������������� �������
	cout << "- ������ ����� ����������" << endl;
}

//����������� �������� ������� ��������� �������//
MyClass::MyClass(int size)//�������� ����������� �������
{
	cout << "\n������ �� " << size << " ���������, ������ ������ " << this << " :" << endl;
	this->Size = size;
	this->data = new int[size];//������� ���.������ � ����������� ��� ����������-��������� ������ 
	for (int i = 0; i < size; i++) //��������� ������ ���������� ����������
	{
		*(data + i) = rand() % 100;
	}
	PrintArr(data, Size);
}
//���������� ��������� '�����'//
bool MyClass::operator==(const MyClass & other)//��������� ����������� ������ ������, � ������� ����������
{
	bool check = true;
	if (this->Size != other.Size) { check = false; }//���� ����� �������� ���������� ������� false
	else for (int i = 0; i < Size; i++) {//���� ����� ���������� � ����� ���������� i-��� ������� ������� �������
		if (*(data + i) != *(other.data + i))
		{
			check = false;//��� ���������� ������� ��������� �������� ��������� ����
			break;
		}		
	}
	if (check == true) { cout << "������� " << this << " & " << &other << " �����" << endl; }
	else { cout << "������� " << this << " & " << &other << " �� �����" << endl; }

	return check;
}
//���������� ������������ �����������//
MyClass::MyClass(const MyClass& other)
{
	cout << "\n����������� �����������, ������ ������ " << this << ": " << endl;
	//this->data = other.data; ���������� ������������ ����������� �� ���������
	this->Size = other.Size;
	this->data = new int[other.Size]; //���� ���������� ������������ ����������� 
	for (int i = 0; i < other.Size; i++)
	{
		this->data[i] = other.data[i];
	}
	PrintArr(data, Size); cout << endl;
}
//���������� ��������� ������������//
MyClass& MyClass::operator=(const MyClass& other)
{
	cout << "�������� ������������, ������ ������: " << this << endl;
	this->Size = other.Size;//���� Size ������ ��������, ��� ��� �� � ������������ ������ �� ���������� (������� �� �����)
	if (this->data != nullptr)//�������� �� ��������� ���������
	{
		delete[] this->data;
	}
	//������ ������������� ����������� ����� ������� �������� �������:
	this->data = new int[other.Size];
	for (int i = 0; i < other.Size; i++)
	{
		this->data[i] = other.data[i];
	}
	PrintArr(data, Size); cout << endl;
	return *this;
}

//������� ������ PrintArr//
void MyClass::PrintArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
}
//������� ������� ���������� ��� ������������ �� ���������//
void MyClass::quickSort(int* data, int N) //data[N]-������. ��. �������
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
//������� �������� ����� � �������
bool MyClass::isInclude(int d)
{
	cout << "����� �����: " << d << " � ������� " << this;
	if (data != nullptr) {
		for (int i = 0; i < Size; i++) {
			if (d == getNum(i)) {
				cout << " - ���� ����� �����!" << endl << endl;
				return true;
			}
		}
	}
	cout << " - ��� ������ �����!" << endl << endl;
	return false;
}
int MyClass::getNum(int i)//������� ��������� �������� ��������
{
	return this->data[i];
}

//������� ���������� �������� � ������//
MyClass& MyClass::add(int i)
{
	if (!isInclude(i)) {//���� ������ ����� ��� � �������
		int* temp = new int[this->Size + 1];//����.����. ������� �� 1 ��-� ������
		for (int j = 0; j < Size; j++) { //����������� ��-��� � ����. ������
			temp[j] = data[j];//�������� �� ������� ������� � ����� 
		}
		temp[Size] = i;//���������� �������� ��������� ������������ ��������
		delete[] data;//������� �������� ������� �������
		data = temp;//��������� ������� ������� ����� ������ 
		Size++;//����������� ������ ��� �������� ������
	}
	cout << "������ " << this << " ����� ���������� ����� " << i << ":" << endl;
	PrintArr(data, Size); cout << endl;
	return *this;
}

//���������� ������� � �������//
MyClass::~MyClass()
{
	cout << "���������� ������� " << this << endl;
	delete[] data; //� ����������� ����� ���������� ��� ������, ����� �� ���� ������ ������
}

