#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Animal
{
private:

	string Type, Name, Color;
	double Price, CostPrice, Weight, Height, Age;
	int Id, Count, Sold=0;

public:

	Animal()
	{
		/*cout << "������� Id: ";
		cin >> Id;*/
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
		cout << "������� ������������� ���������: ";
		cin >> CostPrice;
		cout << endl << "������� ������� ���������: ";
		cin >> Age;
		cout << endl << "������� ���������� ��������: ";
		cin >> Count;
	}

	Animal(int id, string type, string name, string color, double weight, double height, double price, double costPrice, double age, int count)
	{
		Id = id;
		Type = type;
		Name = name;
		Color = color;
		Weight = weight;
		Height = height;
		Price = price;
		CostPrice = costPrice;
		Age = age;
		Count = count;
	}

	void GetInfo()
	{
		cout << Type << " " << Name << endl << "����: " << Color << endl << "���: " << Weight << " ��" << endl << "����: " << " ��" << Height << endl << "�������: " << Age << endl << "����: " << Price << endl;
	}


	//Id
	int GetId()
	{
		return Id;
	}
	void SetId(int id)
	{
		Id = id;
	}


	//Type
	string GetType()
	{
		return Type;
	}
	void SetType(string type)
	{
		Type = type;
	}


	//Name
	string GetName()
	{
		return Name;
	}
	void SetName(string name)
	{
		Name = name;
	}


	//Color
	string GetColor()
	{
		return Color;
	}
	void SetColor(string color)
	{
		Color = color;
	}


	//Weight
	double GetWeight()
	{
		return Weight;
	}
	void SetWeight(double weight)
	{
		Weight = weight;
	}


	//Height
	double GetHeight()
	{
		return Height;
	}
	void SetHeight(double height)
	{
		Height = height;
	}


	// Price
	double GetPrice()
	{
		return Price;
	}
	void SetPrice(double price)
	{
		Price = price;
	}


	//CostPrice
	double GetCostPrice()
	{
		return CostPrice;
	}
	void SetCostPrice(double costPrice)
	{
		CostPrice = costPrice;
	}


	//Age
	double GetAge()
	{
		return Age;
	}
	void SetAge(double age)
	{
		Age = age;
	}


	//Count
	int GetCount()
	{
		return Count;
	}
	void SetCount(int count)
	{
		if (count >= 0)
			Count = count;
		else
			cerr << "�������� �� �������!!!" << endl;
	}


	//Sold
	int GetSold()
	{
		return Sold;
	}
	void SetSold(int sold)
	{
		if (sold >= 0)
			Sold = sold;
		else
			cerr << "��� �� ������!!!" << endl;
	}

	void Buy(int count)
	{
		if (Count - count >= 0)
		{
			Count -= count;
			Sold += count;
			cout << "�� ������ " << count << " " << Type << Name << endl;
		}
		else
			cerr << "�� ������� �� ������" << endl;
	}

	void AddCount(int count)
	{
		Count += count;
	}


	static void input(vector<Animal>& animals)
	{
		ofstream out("Animals.txt");
		if (!out) {
			cerr << "������ �������� ����� ��� ������!" << std::endl;
			return;
		}
		for (const auto& animal : animals) {
			out << animal.Id << '\n' << animal.Type << '\n' << animal.Name << '\n' << animal.Color << '\n' << animal.Weight << '\n' << animal.Height
				<< '\n' << animal.Price << '\n' << animal.CostPrice << '\n' << animal.Age << '\n' << animal.Count << '\n' << animal.Sold << '\n';
		}
		out.close();
	}


	static vector<Animal> output() {
		vector<Animal> animals;
		ifstream in("Animals.txt");
		if (!in) {
			return animals;
		}

		while (in.peek() != EOF) {
			Animal animal(0, "", "", "", 0, 0, 0, 0, 0, 0);
			in >> animal.Id;
			in.ignore();
			getline(in, animal.Type);
			getline(in, animal.Name);
			getline(in, animal.Color);
			in >> animal.Weight;
			in.ignore();
			in >> animal.Height;
			in.ignore();
			in >> animal.Price;
			in.ignore();
			in >> animal.CostPrice;
			in.ignore();
			in >> animal.Age;
			in.ignore();
			in >> animal.Count;
			in.ignore();
			in >> animal.Sold;
			in.ignore();

			animals.push_back(animal);
		}

		in.close();
		return animals;
	}
};

