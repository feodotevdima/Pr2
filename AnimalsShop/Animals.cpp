#include <iostream>
using namespace std;

class Animal
{
private:

	string Type, Name, Color;
	double Weight, Height;
	int Price, Age;

public:

	Animal()
	{
		cout << "������� ��� ���������: ";
		cin >> Type;
		cout << endl << "������� ��� ���������: ";
		cin >> Name;
		cout << endl << "������� ���� ���������: ";
		cin >> Color;
		cout << endl << "������� ��� ���������: ";
		cin >> Weight;
		cout << endl << "������� ���� ���������: ";
		cin >> Height;
		cout << endl << "������� ���� ���������: ";
		cin >> Price;
		cout << endl << "������� ������� ���������: ";
		cin >> Age;
	}

	Animal(string type, string name, string color, double weight, double height, int price, int age)
	{
		Type = type;
		Name = name;
		Color = color;
		Weight = weight;
		Height = height;
		Price = price;
		Age = age;
	}

	void GetInfo()
	{
		cout << Type << " " << Name << endl << "����: " << Color << endl << "���: " << Weight << " ��" << endl << "����: " << " ��" << Height << endl << "�������: " << Age << endl << "����: " << Price << endl;
	}

	void ChengeName(string name)
	{
		Name = name;
	}

	void ChengeWeight(double weight)
	{
		Weight = weight;
	}

	void ChengeHeight(double weight)
	{
		Weight = weight;
	}

	void Chenge()
	{
		cout << "������� ��� ���������: ";
		cin >> Type;
		cout << endl << "������� ��� ���������: ";
		cin >> Name;
		cout << endl << "������� ���� ���������: ";
		cin >> Color;
		cout << endl << "������� ��� ���������: ";
		cin >> Weight;
		cout << endl << "������� ���� ���������: ";
		cin >> Height;
	}
};

