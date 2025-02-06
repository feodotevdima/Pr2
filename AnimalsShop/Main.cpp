#include <random>
#include "Client.cpp"
#include "Cargo.cpp"
#include "Admin.cpp"
#include "Animal.cpp"
#include <time.h>

using namespace std;

Client client("", "", "", "");
Cargo cargo("", "", "");
Admin admin("", "", "");
string randomType[] = { "собака", "кошка", "волк", "крыса", "обезьяна", "кабан", "крокодил"};
string randomName[] = { "Лакки", "Рокки", "Микки", "Юма", "Мира", "Бим", "Вольт" };
string randomColor[] = { "чёрный", "белый", "серый", "синий", "зелёный", "красный", "розовый" };

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
		cout << "Такой аккаунт уже существует" << endl;
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
		cout << "Введите имя: ";
		cin >> name;
		cout << "Введите пароль: ";
		cin >> pass;

		int l = log(name, pass);
		if (l > 0)
			return l;

		cout << "Такого аккаунта нет" << endl << "[1] Попробовать ёщё раз" << endl << "[2] Зареистрироваться" << endl;
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
		cout << "[1] Войти" << endl << "[2] Зареистрироваться" << endl;
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
		<< " kg;     " << c.GetHeight() << " cm;     " << c.GetColor() << " цвет" << endl << c.GetCount()
		<< "шт. осталось на складе" << endl<< c.GetPrice() << " рублей" << endl << endl << "=========================================================" << endl << endl << endl;
}

void clientAcc()
{
	int i;
	while (true)
	{
		cout << endl << "Клиент" << endl << client.GetName() << endl << endl << "[1] Посмотреть список животных"
			<< endl << "[2] Купить животное" << endl << "[3] Выйти" << endl << endl;
		cin >> i;
		if (i == 1)
		{
			system("cls");
			GetAnimals();
		}
		else if (i == 2)
		{
			int count;
			auto animals = Animal::output();
			cout << "Введите ID животного" << endl;
			cin >> i;
			cout << "Введите Количество животных" << endl;
			cin >> count;
			for (int j = 0; j < animals.size(); j++)
			{
				if (animals[j].GetId() == i)
				{
					animals[j].Buy(count);
				}
			}
			Animal::input(animals);
			system("cls");
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
		cout << endl << "Кладовщик" << endl << cargo.GetName() << endl << endl << "[1] Вывести список животных"
			<< endl << "[2] Изменить колличество животных" << endl << "[3] Выйти" << endl << endl;
		cin >> i;
		if (i == 1)
		{
			system("cls");
			GetAnimals();
		}
		else if (i == 2) 
		{
			int id;
			int count;
			cout << "Введите номер животного" << endl;
			cin >> id;
			cout << "Введите новое количество" << endl;
			cin >> count;
			auto animals = Animal::output();
			for (auto& c : animals)
			{
				if (c.GetId() == id)
				{
					c.SetCount(count);
					break;
				}
			}
			Animal::input(animals);
			system("cls");
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
		cout << endl << "Админ" << endl << admin.GetName() << endl << endl << "[1] Добавить животное" << endl
			<< "[2] Сгенерировать животное" << endl << "[3] Удалить последнее животное" << endl << "[4] Вывести список животных" 
			<< endl << "[5] Добавить кладовщика" << endl << "[6] Добавить админа" << endl << "[7] Выйти" << endl << endl;
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
			system("cls");
		}
		else if(i == 2)
		{
			double price = ((double)rand() / RAND_MAX) * 90000 + 1000;
			double costPrice = price - (((double)rand() / RAND_MAX) * price*0.5 )+ price * 0.45;

			auto animals = Animal::output();
			int max = 0;
			for (auto& c : animals)
			{
				if (c.GetId() > max)
					max = c.GetId();
			}

			Animal newAnimal(max+1, randomType[rand() % (sizeof(randomType) / sizeof(randomType[0]))], randomName[rand() % (sizeof(randomName) / sizeof(randomName[0]))],
				randomColor[rand() % (sizeof(randomColor) / sizeof(randomColor[0]))], ((double)rand() / RAND_MAX) * 40 + 1, ((double)rand() / RAND_MAX) * 90 + 10,
				price, costPrice, ((double)rand() / RAND_MAX) * 20, rand() % 50 + 1);
			animals.push_back(newAnimal);
			Animal::input(animals);
			system("cls");
		}
		else if (i == 3)
		{
			auto animals = Animal::output();
			animals.pop_back();
			system("cls");

		}
		else if (i == 4)
		{
			system("cls");
			GetAnimals();
		}
		else if (i == 5)
		{
			Cargo newCargo;
			int l = log(newCargo.GetName(), newCargo.GetPassword());
			if (l > 0)
			{
				cout << "Такой аккаунт уже существует" << endl;
			}
			else
			{
				vector<Cargo> cargos = Cargo::output();
				cargos.push_back(newCargo);
				Cargo::input(cargos);
			}
			system("cls");
		}
		else if (i == 6)
		{
			Admin newAdmin;
			int l = log(newAdmin.GetName(), newAdmin.GetPassword());
			if (l > 0)
			{
				cout << "Такой аккаунт уже существует" << endl;
			}
			else
			{
				vector<Admin> admins = Admin::output();
				admins.push_back(newAdmin);
				Admin::input(admins);
			}
			system("cls");
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
	srand(time(NULL));

	setlocale(LC_ALL, "Russian");
	while (true)
	{
		int status = registrate();
		system("cls");
		if (status == 1)
			clientAcc();
		if (status == 2)
			cargoAcc();
		if (status == 3)
			adminAcc();
	}
};