#include "User.cpp"
using namespace std;


class Admin : public User
{
private:

	string Number;

public:
	Admin() : User()
	{
		cout << "Введите номер телефона: ";
		cin >> Number;
	}

	Admin(string name, string password, string number) : User(name, password)
	{
		Number = number;
	}

	string GetNumber()
	{
		return Number;
	}
	void SetNumber(string number)
	{
		Number = number;
	}



	static void input(vector<Admin>& people)
	{
		ofstream out("Admin.txt");
		if (!out) {
			cerr << "Ошибка открытия файла для записи!" << std::endl;
			return;
		}
		for (const auto& person : people) {
			out << person.Name << '\n' << person.Password << '\n' << person.Number << '\n';
		}
		out.close();
	}


	static vector<Admin> output() {
		vector<Admin> people;
		ifstream in("Admin.txt");
		if (!in) {
			return people;
		}

		while (in.peek() != EOF) {
			Admin person("", "", "");
			getline(in, person.Name);
			in >> person.Password;
			in.ignore();
			getline(in, person.Number);
			people.push_back(person);
		}

		in.close();
		return people;
	}
};

