#include "MyClass.h"
#include <iostream> 
using namespace std;

//����������� �� ��������� // ������� ������ �� 10 ��������� //
MyClass::MyClass()
{
	cout << "\n����������� �� �����. - ��������������� ������ �� 10 ���������, ������ " << this << ":";
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
		*(data + i) = rand() % 10;
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
	if (check == true) { cout << "������� " << this << " & " << &other << " ����� "; }
	else { cout << "������� " << this << " & " << &other << " �� ����� "; }

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
				cout << " - ���� ����� �����!" << endl;
				return true;
			}			
		}
	}
	cout << " - ��� ������ �����!" << endl;
	return false;
}
int MyClass::getNum(int i)//������� ��������� �������� ��������
{
	return this->data[i];
}

//������� ���������� �������� � ������//
MyClass& MyClass::add(int d)
{
	if (!isInclude(d)) {//���� ������ ����� ��� � �������
		int* temp = new int[this->Size + 1];//����.����. ������� �� 1 ��-� ������
		for (int j = 0; j < Size; j++) { //����������� ��-��� � ����. ������
			temp[j] = data[j];//�������� �� ������� ������� � ����� 
		}
		temp[Size] = d;//���������� �������� ��������� ������������ ��������
		delete[] data;//������� �������� ������� �������
		data = temp;//��������� ������� ������� ����� ������ 
		Size++;//����������� ������ ��� �������� ������
	}
	cout << "������ " << this << " ����� ���������� ����� " << d << ":" << endl;
	PrintArr(data, Size); cout << endl;
	return *this;
}
//������� �������� ����� �� �������//
MyClass & MyClass::exclude(int d)
{
	cout << "�������� ����� " << d << " �� ������� " << this << ":" << endl;
	PrintArr(data, Size); cout << endl;
	int found = 0;
	if (isInclude(d)) {//�������� ������� �����		
		for (int i = 0; i < Size; i++) { //����������� ��-��� � ����. ������			
			if (*(data+i) == d)//���� ������� ������� ��������� � ������� ���������
			{
				for (int j = i; j<Size; j++)//�� ������� �� �������� � ����������� ��������� ��������� �� ����� ������� 
				{
					*(data+j) = *(data +j + 1); //� ��������� ������� �������� �������� ���������� (����� �����)					
				}
				i--; //��������� ������� ���� �������� ������ � ���������� �������, �� ������ � ���� ������� ����� 
				     //������ ��� ������ ������� �����, � �� ����� ���������� ����� ������ �������
				Size--; //������ ��������� �� ������� ��-�� ������
				found++; //������� ��������� �����
			}			
		}
		cout << "����� " << d << " ������� " << found << " ���" << endl;
		cout << "������ " << this << " ����� �������� ����� " << d << ":" << endl;
		PrintArr(data, Size); cout << endl;
	}
	else cout << "������ �� �������" << endl;
	
	return *this;
}

//�������� �������� ��������//DRAFT DRAFT DRAFT
MyClass & MyClass::operator+(const MyClass & other)
{
	cout << "�������� ��������: " << this << endl;
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

//���������� ������� � �������//
MyClass::~MyClass()
{	
	cout << "���������� ������� " << this << endl;
	delete[] data; //� ����������� ����� ���������� ��� ������, ����� �� ���� ������ ������
}

