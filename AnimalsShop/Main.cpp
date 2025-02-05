#include <iostream>
#include <filesystem>
#include "Client.cpp"
#include "Cargo.cpp"
#include "Admin.cpp"
#include "Animal.cpp"

using namespace std;

Client client("", "", "", "");
Cargo cargo("", "", "");
Admin admin("", "", "");



int log(string name, string pass)
{
	vector<Client> clients = Client::output();
	for (auto cl : clients)
	{
		if (cl.GetName() == name && cl.GetPassword() == pass)
		{
			client.SetName(cl.GetName());
			client.SetEmail(cl.GetEmail());
			client.SetAdress(cl.GetAdress());
			return 1;
		}
	}

	vector<Cargo> cargos = Cargo::output();
	for (auto cr : cargos)
	{
		if (cr.GetName() == name && cr.GetPassword() == pass)
		{
			cargo.SetName(cr.GetName());
			cargo.SetNumber(cr.GetNumber());
			return 2;
		}
	}

	vector<Admin> admins = Admin::output();
	for (auto ad : admins)
	{
		if (ad.GetName() == name && ad.GetPassword() == pass)
		{
			admin.SetName(ad.GetName());
			admin.SetNumber(ad.GetNumber());
			return 3;
		}
	}
	return 0;
}


int addClient()
{
	Client newClient;
	int l = log(newClient.GetName(), newClient.GetPassword());
	if (l > 0)
	{
		cout << "����� ������� ��� ����������" << endl;
		return 0;
	}
	vector<Client> clients = Client::output();
	clients.push_back(newClient);
	Client::input(clients);

	client.SetName(newClient.GetName());
	client.SetEmail(newClient.GetEmail());
	client.SetAdress(newClient.GetAdress());
	return 1;
}


int login()
{
	int i;
	string name, pass;

	while (true)
	{
		cout << "������� ���: ";
		cin >> name;
		cout << "������� ������: ";
		cin >> pass;

		int l = log(name, pass);
		if (l > 0)
			return l;

		cout << "������ �������� ���" << endl << "[1] ����������� ��� ���" << endl << "[2] �����������������" << endl;
		cin >> i;
		if (i == 2)
			return addClient();
	}
}

int registrate()
{
	int i;
	while (true)
	{
		cout << "[1] �����" << endl << "[2] �����������������" << endl;
		cin >> i;
		if (i == 1)
			return login();
		if (i == 2)
		{
			int l = addClient();
			if (l != 0)
				return l;
		}
	}
}

void GetAnimals()
{
	cout << endl << endl;
	auto animals = Animal::output();
	for (auto c : animals)
		cout << c.GetId() << endl << c.GetType() << "  " << c.GetName() << endl << c.GetWeight()
		<< " kg;     " << c.GetHeight() << " cm;     " << c.GetColor() << " ����" << endl << c.GetCount()
		<< "��. �������� �� ������" << endl << endl << "=========================================================" << endl << endl << endl;
}

void clientAcc()
{
	int i;
	while (true)
	{
		cout << "������" << endl << client.GetName() << endl << endl << "[1] ���������� ������ ��������" 
			<< endl << "[2] ������ ��������" << endl << "[3] �����" << endl << endl;
		cin >> i;
		if (i == 1)
		{
			GetAnimals();
		}
		else if (i == 2)
		{
			int count;
			auto animals = Animal::output();
			cout << "������� ID ���������" << endl;
			cin >> i;
			cout << "������� ���������� ��������" << endl;
			cin >> count;
			for (int j = 0; j < animals.size(); j++)
			{
				if (animals[j].GetId() == i)
				{
					animals[j].Buy(count);
				}
			}
			Animal::input(animals);
		}
		else if (i == 3)
		{
			system("cls");
			return;
		}
	}
}

void cargoAcc()
{
	int i;
	while (true)
	{
		cout << "���������" << endl << admin.GetName() << endl << endl << "[1] ������� ������ ��������"
			<< endl << "[2] �������� ����������� ��������" << endl << "[3] �����" << endl << endl;
		cin >> i;
		if (i == 1)
		{
			GetAnimals();
		}
		else if (i == 2) //todo: change count
		{
			int id;
			int count;
			cout << "������� ����� ���������" << endl;
			cin >> id;
			cout << "������� ����� ����������" << endl;
			cin >> count;
			auto animals = Animal::output();
			for (auto c : animals)
			{
				if (c.GetId() == id)
					c.SetCount(count);
			}
			Animal::input(animals);
		}
		else if (i == 3)
		{
			system("cls");
			return;
		}
	}
}

void adminAcc()
{
	int i;
	while (true)
	{
		cout << "�����" << endl << admin.GetName() << endl << endl << "[1] �������� ��������" << endl 
			<< "[2] ������������� ��������" << endl << "[3] ������� ��������� ��������" << endl << "[4] ������� ������ ��������" 
			<< endl << "[5] �������� ����������" << endl << "[6] �������� ������" << endl << "[7] �����" << endl << endl;
		cin >> i;
		if (i == 1)
		{
			Animal newAnimal;
			auto animals = Animal::output();
			int max = 0;
			for (auto c : animals)
			{
				if (c.GetId() > max)
					max = c.GetId();
			}
			newAnimal.SetId(max + 1);
			animals.push_back(newAnimal);
			Animal::input(animals);

		}
		else if(i == 2)//todo: random
		{
			Animal newAnimal;
			auto animals = Animal::output();
			int max = 0;
			for (auto c : animals)
			{
				if (c.GetId() > max)
					max = c.GetId();
			}
			newAnimal.SetId(max + 1);
			animals.push_back(newAnimal);
			Animal::input(animals);
		}
		else if (i == 3)
		{
			auto animals = Animal::output();
			animals.pop_back();

		}
		else if (i == 4)
		{
			GetAnimals();
		}
		else if (i == 5)
		{
			Cargo newCargo;
			int l = log(newCargo.GetName(), newCargo.GetPassword());
			if (l > 0)
			{
				cout << "����� ������� ��� ����������" << endl;
			}
			else
			{
				vector<Cargo> cargos = Cargo::output();
				cargos.push_back(newCargo);
				Cargo::input(cargos);
			}
		}
		else if (i == 6)
		{
			Admin newAdmin;
			int l = log(newAdmin.GetName(), newAdmin.GetPassword());
			if (l > 0)
			{
				cout << "����� ������� ��� ����������" << endl;
			}
			else
			{
				vector<Admin> admins = Admin::output();
				admins.push_back(newAdmin);
				Admin::input(admins);
			}
		}
		else if (i == 7)
		{
			system("cls");
			return;
		}
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		int status = registrate();
		if (status == 1)
			clientAcc();
		if (status == 2)
			cargoAcc();
		if (status == 3)
			adminAcc();
	}
};