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
		cout << "Введите вид животного: ";
		cin >> Type;
		cout << endl << "Введите имя животного: ";
		cin >> Name;
		cout << endl << "Введите цвет животного: ";
		cin >> Color;
		cout << endl << "Введите вес животного: ";
		cin >> Weight;
		cout << endl << "Введите рост животного: ";
		cin >> Height;
		cout << endl << "Введите цену животного: ";
		cin >> Price;
		cout << endl << "Введите возраст животного: ";
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
		cout << Type << " " << Name << endl << "Цвет: " << Color << endl << "Вес: " << Weight << " КГ" << endl << "Рост: " << " См" << Height << endl << "Возраст: " << Age << endl << "Цена: " << Price << endl;
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
		cout << "Введите вид животного: ";
		cin >> Type;
		cout << endl << "Введите имя животного: ";
		cin >> Name;
		cout << endl << "Введите цвет животного: ";
		cin >> Color;
		cout << endl << "Введите вес животного: ";
		cin >> Weight;
		cout << endl << "Введите рост животного: ";
		cin >> Height;
	}
};

