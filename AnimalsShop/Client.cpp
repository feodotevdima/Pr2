#include "User.cpp"
using namespace std;


class Client : public User
{
private:

	string Email, Adress;

public:

	Client() : User() 
	{
		cout << "Введите Почту: ";
		cin >> Email;
		cout << "Введите Адресс: ";
		cin >> Adress;
	}

	Client(string name, string password, string email, string adress) : User(name, password)
	{
		Email = email;
		Adress = adress;
	}


	string GetEmail()
	{
		return Email;
	}
	void SetEmail(string email)
	{
		Email = email;
	}

	string GetAdress()
	{
		return Adress;
	}
	void SetAdress(string adress)
	{
		Adress = adress;
	}


	static void input(vector<Client>& people)
	{
		ofstream out("Clients.txt");
		if (!out) {
			cerr << "Ошибка открытия файла для записи!" << std::endl;
			return;
		}
		for (const auto& person : people) {
			out << person.Name << '\n' << person.Password << '\n' << person.Email << '\n' << person.Adress << '\n';
		}
		out.close();
	}


	static vector<Client> output() {
		vector<Client> people;
		ifstream in("Clients.txt");
		if (!in) {
			return people;
		}

		while (in.peek() != EOF) { 
			Client person("","","","");
			getline(in, person.Name);
			in >> person.Password;
			in.ignore();
			getline(in, person.Email);
			getline(in, person.Adress);
			people.push_back(person);
		}

		in.close();
		return people;
	}
};
