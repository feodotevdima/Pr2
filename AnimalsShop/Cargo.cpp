#include "User.cpp"
using namespace std;


class Cargo : public User
{
private:

	string Number;

public:
	Cargo() : User()
	{
		cout << "Введите номер телефона: ";
		cin >> Number;
	}

	Cargo(string name, string password, string number) : User(name, password)
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



	static void input(vector<Cargo>& people)
	{
		ofstream out("Cargo.txt");
		if (!out) {
			cerr << "Ошибка открытия файла для записи!" << std::endl;
			return;
		}
		for (const auto& person : people) {
			out << person.Name << '\n' << person.Password << '\n' << person.Number << '\n';
		}
		out.close();
	}


	static vector<Cargo> output() {
		vector<Cargo> people;
		ifstream in("Cargo.txt");
		if (!in) {
			return people;
		}

		while (in.peek() != EOF) {
			Cargo person("", "", "");
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
