#include<conio.h>
#include<fstream>
#include<iomanip>
#include<Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#define N 1
using namespace std;



class People {
protected:
	string name, surname, last_name;
	int age;
public:
	virtual void show() = 0;
};

class Doctor : public People {

private:
	string profi;
	int cabinet;
public:
	Doctor()
	{
		name = ' ';
		surname = ' ';
		last_name = ' ';
		age = 0;
		profi = ' ';
		cabinet = 0;
	}

	void set_profi(string profi1)
	{
		profi = profi1;
	}
	string get_profi()
	{
		return profi;
	}

	void set_cabinet(int cabinet1)
	{
		cabinet = cabinet1;
	}
	int get_cabinet()
	{
		return cabinet;
	}

	void set_name(string name1)
	{
		name = name1;
	}
	string get_name()
	{
		return name;
	}

	void set_surname(string surname1)
	{
		surname = surname1;
	}
	string get_surname()
	{
		return surname;
	}

	void set_last_name(string last_name1)
	{
		last_name = last_name1;
	}
	string get_last_name()
	{
		return last_name;
	}

	void set_age(int age1)
	{
		age = age1;
	}
	int get_age()
	{
		return age;
	}

	void show()
	{
		cout << "Специализация врача:" << profi << endl;
		cout << "Кабинет:" << cabinet << endl;
		cout << "Имя:" << name << endl;
		cout << "Фамилия:" << surname << endl;
		cout << "Отчество:" << last_name << endl;
		cout << "Возраст врача:" << age << endl;
	}
};

ostream& operator << (ostream& z, Doctor& c) {
	return z << "=========================================\n"
		<< "Имя:\n" << c.get_name() << endl
		<< "Фамилия:\n" << c.get_surname() << endl
		<< "Отчество:\n" << c.get_last_name() << endl      //перегрузка оператора вывода
		<< "Возраст:\n" << c.get_age() << endl
		<< "Специализация врача:\n" << c.get_profi() << endl
		<< "Кабинет:\n" << c.get_cabinet() << endl;
}

class spravochnik
{
private:
	vector <Doctor> vector;

public:
	int check_int()
	{
		while (true)
		{
			int a;
			cin >> a;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Повторите попытку: ";
			}
			else
			{
				std::cin.ignore(32767, '\n');
				return a;
			}
		}
	}

	string check_string(string s)
	{
		int i = 0;
		string str;
		while (s[i])
		{
			if ((s[i] >= 97) && (s[i] <= 122))
				str = str + s[i];
			else
			{
				cout << "Повторите попытку : ";
				cin >> s;
				return check_string(s);
			}
			i++;
		}
		return str;
	}
	void create_doctor()
	{
		Doctor doctor;
		string name, surname, last_name;
		int age;
		string profi;
		int cabinet;
		int n;
		cout << " Введите количество врачей:" << endl;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << endl << "Имя:" << endl;
			cin >> name;
			check_string(name);
			cout << endl << "Фамилия:" << endl;
			cin >> surname;
			check_string(surname);
			cout << endl << "Отчество:" << endl;
			cin >> last_name;
			check_string(last_name);
			cout << endl << "Возраст:" << endl;
			age = check_int();
			cout << endl << "Специальность врача:" << endl;
			cin >> profi;
			check_string(profi);
			cout << endl << "Кабинет врача:" << endl;
			cabinet = check_int();

			doctor.set_name(name);
			doctor.set_surname(surname);
			doctor.set_last_name(last_name);
			doctor.set_age(age);
			doctor.set_profi(profi);
			doctor.set_cabinet(cabinet);

			this->vector.push_back(doctor);
		}
	}

	void Schitivanie_iz_fileF1() {

		vector.clear();

		ifstream ins("F1.txt");
		Doctor doctor;
		char r;
		string name;
		string surname;
		string last_name;
		int age;
		string profi;
		int cabinet;
		string age1;
		string cabinet1;

		int i = 0;
		int n = 0;
		int j = -1;
		while (1)
		{
			ins.get(r);
			if (r == '*') break;
			else
				ins.seekg(j, ins.cur);

			getline(ins, name, ',');
			doctor.set_name(name);

			getline(ins, surname, ',');
			doctor.set_surname(surname);

			getline(ins, last_name, ',');
			doctor.set_last_name(last_name);

			getline(ins, age1, ',');
			age = stoi(age1);
			doctor.set_age(age);


			getline(ins, profi, ',');
			doctor.set_profi(profi);

			getline(ins, cabinet1, ',');
			cabinet = stoi(cabinet1);
			doctor.set_cabinet(cabinet);

			vector.push_back(doctor);

		}
		ins.close();

	}

	void zapis_vrachei_v_fileF1() {
		ofstream fout("F1.txt");
		for (int i = 0; i < vector.size(); i++)
		{
			fout << this->vector[i].get_name() << ","
				<< this->vector[i].get_surname() << ","
				<< this->vector[i].get_last_name() << ","
				<< this->vector[i].get_age() << ","
				<< this->vector[i].get_profi() << ",";
			if (i == (vector.size() - 1)) fout << this->vector[i].get_cabinet() << ",*";
			else fout << this->vector[i].get_cabinet() << ",";
		}
		fout.close();
	}

	/*void schitivanie_vrachei_iz_file()
	{
		string str;
		ifstream fout("F1.txt", ios::in);
		while (!fout.eof())
		{
			getline(fout, str);
			cout << str << endl;
		}
		fout.close();
	}*/

	void show()
	{
		for (int i = 0; i < vector.size(); i++)
		{
			cout << vector[i];
		}
	}
	void search_doctor()
	{
		string name, surname, last_name;
		int n;
		cout << "Введите количество врачей о которых необходимо просмотреть информацию:" << endl;
		n = check_int();

		for (int i = 0; i < n; i++)
		{
			cout << endl << "Имя:" << endl;
			cin >> name;
			check_string(name);
			cout << endl << "Фамилия:" << endl;
			cin >> surname;
			check_string(surname);
			cout << endl << "Отчество:" << endl;
			cin >> last_name;
			check_string(last_name);
			for (int i = 0; i < vector.size(); i++)
			{
				if (((name == vector[i].get_name()) && surname == vector[i].get_surname()) && (last_name == vector[i].get_last_name()))
				{
					cout << vector[i];
				}
			}
		}
	}

};

class Patient :public People {
private:
	string diagnosis;
	int data_priema;
	int number;
public:

	Patient()
	{
		name = ' ';
		surname = ' ';
		last_name = ' ';
		age = 0;
		diagnosis = ' ';
		data_priema = 0;
		number = 0;

	}
	Patient(string name1, string surname1, string last_name1, int age1, string diagnosis1, int data_priema1, int number1)
	{
		name = name1;
		surname = surname1;
		last_name = last_name1;
		age = age1;
		diagnosis = diagnosis1;
		data_priema = data_priema1;
		number = number1;

	}
	void set_name(string name1)
	{
		name = name1;
	}
	string get_name()
	{
		return name;
	}

	void set_surname(string surname1)
	{
		surname = surname1;
	}
	string get_surname()
	{
		return surname;
	}

	void set_last_name(string last_name1)
	{
		last_name = last_name1;
	}
	string get_last_name()
	{
		return last_name;
	}

	void set_age(int age1)
	{
		this->age = age1;
	}
	int get_age()
	{
		return age;
	}

	void set_diagnosis(string diagnosis1)
	{
		diagnosis = diagnosis1;
	}
	string get_diagnosis()
	{
		return diagnosis;
	}

	void set_data_priema(int data_priema1)
	{
		data_priema = data_priema1;
	}
	int get_data_priema()
	{
		return data_priema;
	}

	void set_number(int number1)
	{
		this->number = number1;
	}
	int get_number()
	{
		return number;
	}

	void show()
	{
		cout << "Имя:" << name << endl;
		cout << "Фамилия:" << surname << endl;
		cout << "Отчество:" << last_name << endl;
		cout << "Возраст пциента" << age << endl;
		cout << "Диагноз:" << diagnosis << endl;
		cout << "Дата приёма:" << data_priema << endl;
		cout << "Номер пациента:" << number << endl;
	}
	friend ostream& operator<<(ostream& zange, const Patient& chimege);

};

ostream& operator << (ostream& zange, Patient& chimege) {
	return zange << "=========================================\n"
		<< "Имя:\n" << chimege.get_name() << endl
		<< "Фамилия:\n" << chimege.get_surname() << endl
		<< "Отчество:\n" << chimege.get_last_name() << endl
		<< "Возраст:\n" << chimege.get_age() << endl            //перегрузка оператора вывода
		<< "Диагноз:\n" << chimege.get_diagnosis() << endl
		<< "Дата приёма:\n" << chimege.get_data_priema() << endl
		<< "Номер пациента:\n" << chimege.get_number() << endl;
}

class Uchet
{
private:
	vector <Patient> vector1;

public:
	int check_int()
	{
		while (true)
		{
			int a;
			cin >> a;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Повторите попытку: ";
			}
			else
			{
				cin.ignore(32767, '\n');
				return a;
			}
		}
	}

	string check_string(string s)
	{
		int i = 0;
		string str;
		while (s[i])
		{
			if ((s[i] >= 97) && (s[i] <= 122))
				str = str + s[i];
			else
			{
				cout << "Повторите попытку : ";
				cin >> s;
				return check_string(s);
			}
			i++;
		}
		return str;
	}

	void Schitivanie_iz_fileF2() {

		vector1.clear();

		ifstream ins("F2.txt");
		Patient patient;
		char r;
		string name;
		string surname;
		string last_name;
		int age;
		string diagnosis;
		int data_priema;
		int number;
		string age1;
		string data_priema1;
		string number1;

		int i = 0;
		int n = 0;
		int j = -1;
		while (1)
		{
			ins.get(r);
			if (r == '*') break;
			else
				ins.seekg(j, ins.cur);

			getline(ins, name, ',');
			patient.set_name(name);

			getline(ins, surname, ',');
			patient.set_surname(surname);

			getline(ins, last_name, ',');
			patient.set_last_name(last_name);

			getline(ins, age1, ',');
			age = stoi(age1);
			patient.set_age(age);


			getline(ins, diagnosis, ',');
			patient.set_diagnosis(diagnosis);

			getline(ins, data_priema1, ',');
			data_priema = stoi(data_priema1);
			patient.set_data_priema(data_priema);

			getline(ins, number1, ',');
			number = stoi(number1);
			patient.set_number(number);

			vector1.push_back(patient);

		}
		ins.close();

	}

	void zapis_patientov_v_fileF2() {
		ofstream fout("F2.txt");
		for (int i = 0; i < vector1.size(); i++)
		{
			fout << this->vector1[i].get_name() << ","
				<< this->vector1[i].get_surname() << ","
				<< this->vector1[i].get_last_name() << ","
				<< this->vector1[i].get_age() << ","
				<< this->vector1[i].get_diagnosis() << ","
				<< this->vector1[i].get_data_priema() << ",";
			if (i == (vector1.size() - 1)) fout << this->vector1[i].get_number() << ",*";
			else fout << this->vector1[i].get_number() << ",";
		}
		fout.close();
	}

	void create_patient()
	{
		Patient patient;
		string name, surname, last_name;
		int age;
		string diagnosis;
		int data_priema, number;
		int n;
		cout << " Введите количество пациентов:" << endl;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cout << endl << "Имя:" << endl;
			cin >> name;
			check_string(name);
			cout << endl << "Фамилия:" << endl;
			cin >> surname;
			check_string(surname);
			cout << endl << "Отчество:" << endl;
			cin >> last_name;
			check_string(last_name);
			cout << endl << "Возраст:" << endl;
			age = check_int();
			cout << endl << "Диагноз:" << endl;
			cin >> diagnosis;
			check_string(diagnosis);
			cout << endl << "Дата приёма:" << endl;
			data_priema = check_int();
			cout << endl << "Номер пациента:" << endl;
			number = check_int();



			patient.set_name(name);
			patient.set_surname(surname);
			patient.set_last_name(last_name);
			patient.set_age(age);
			patient.set_diagnosis(diagnosis);
			patient.set_data_priema(data_priema);
			patient.set_number(number);

			this->vector1.push_back(patient);
		}
	}

	void show()
	{
		for (int i = 0; i < vector1.size(); i++)
		{
			cout << vector1[i];
		}
	}
	void search_patient()
	{
		string name, surname, last_name;
		int n;
		cout << "Введите количество пациентов о которых необходимо просмотреть информацию:" << endl;
		n = check_int();

		for (int i = 0; i < n; i++)
		{
			cout << endl << "Имя:" << endl;
			cin >> name;
			check_string(name);
			cout << endl << "Фамилия:" << endl;
			cin >> surname;
			check_string(surname);
			cout << endl << "Отчество:" << endl;
			cin >> last_name;
			check_string(last_name);
			for (int i = 0; i < vector1.size(); i++)
			{
				if (((name == vector1[i].get_name()) && surname == vector1[i].get_surname()) && (last_name == vector1[i].get_last_name()))
				{
					cout << vector1[i];
				}
			}
		}
	}

	void change()
	{
		string name, surname, last_name;
		string diagnosis;
		int data_priema, number;
		int t;
		cout << "Введите количество пациентов которым необходимо изменить информацию:" << endl;
		t = check_int();

		for (int i = 0; i < t; i++)
		{
			cout << endl << "Имя:" << endl;
			cin >> name;
			check_string(name);
			cout << endl << "Фамилия:" << endl;
			cin >> surname;
			check_string(surname);
			cout << endl << "Отчество:" << endl;
			cin >> last_name;
			check_string(last_name);
			for (int i = 0; i < vector1.size(); i++)
			{
				if (((name == vector1[i].get_name()) && surname == vector1[i].get_surname()) && (last_name == vector1[i].get_last_name()))
				{
					int n;
					cout << "Что вы хотите изменить?\n" << "1. Диагноз\n" << "2. Дата приёма\n" << "3. Номер пациента\n" << "0. Выход\n" << endl;
					do
					{
						n = check_int();

						switch (n)
						{
						case 3:
						{
							cout << "Введите новый номер пациента:" << endl;
							number = check_int();

							vector1[i].set_number(number);
							cout << vector1[i];
							zapis_patientov_v_fileF2();
							break;
						}
						case 2:
						{
							cout << "Введите обновлённую дату:" << endl;
							data_priema = check_int();

							vector1[i].set_data_priema(data_priema);
							cout << vector1[i];
							zapis_patientov_v_fileF2();
							break;
						}
						case 1:
						{
							cout << "Введите диагноз:" << endl;
							cin >> diagnosis;
							check_string(diagnosis);
							vector1[i].set_diagnosis(diagnosis);
							cout << vector1[i];
							zapis_patientov_v_fileF2();
							break;
						}
						case 0:
						{
							break;
						}
						}
					} while (n != 0);
				}
			}
		}
	}

	void delete_patient()
	{
		int s;
		int number;
		int n;
		cout << "Введите количество пациентов которых необходимо удалить из списков:" << endl;
		n = check_int();

		for (int i = 0; i < n; i++)
		{
			cout << endl << "Введите номер пациента которого необходимо удалить из списков:" << endl;
			number = check_int();

			for (int i = 0; i < vector1.size(); i++)
			{
				if (number == vector1[i].get_number())
				{
					s = i;
					vector1.erase(vector1.begin() + s);
				}
				for (int i = 0; i < vector1.size(); i++)
				{ 
					zapis_patientov_v_fileF2();
					/*cout << vector1[i];*/
				}
			}
		}
	}
};

bool Password();
bool Login();
bool Password1();
bool Login1();
bool Password2();
bool Login2();
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;

	do
	{

		cout << "Хотите зайти от имени 1-пациента, 2-доктора, 3-администрации медицинской клиники, 0-выход:" << endl;
		cin >> n;
		switch (n)
		{
		case 3:
		{
			while (!Login());
			while (!Password());
			int t;
			do
			{

				cout << "Хотите изменить информацию о 1. Врачах, 2. Пациентах, 0. Выход:" << endl;
				cin >> t;
				switch (t)
				{
				case 1:
				{
					spravochnik doctor_objekt;
					int q;
					do
					{

						cout << "1. Хотите добавить врача в справочник, 2. Хотите найти информацию о враче в справочнике, 0. Выход:" << endl;
						cin >> q;
						switch (q)
						{
						case 1:
						{
							doctor_objekt.Schitivanie_iz_fileF1();
							doctor_objekt.create_doctor();
							doctor_objekt.zapis_vrachei_v_fileF1();
							break;
						}
						case 2:
						{
							doctor_objekt.Schitivanie_iz_fileF1();
							doctor_objekt.search_doctor();
							break;
						}
						case 0:
						{
							break;
						}
						}
					} while (q != 0);
					break;
				}
				case 2:
				{
					Uchet patient_objekt;
					int m;
					do
					{

						cout << "1. Хотите добавить патиента в учёт, 2. Хотите найти информацию о патиенте, 3. Хотите изменить информацию о патиенте, 4. удалить патиента, 0. Выход:" << endl;
						cin >> m;
						switch (m)
						{
						case 1:
						{
							patient_objekt.Schitivanie_iz_fileF2();
							patient_objekt.create_patient();
							patient_objekt.zapis_patientov_v_fileF2();
							break;

						}
						case 2:
						{
							patient_objekt.Schitivanie_iz_fileF2();
							patient_objekt.search_patient();
							break;
						}
						case 3:
						{
							patient_objekt.Schitivanie_iz_fileF2();
							patient_objekt.change();
							patient_objekt.zapis_patientov_v_fileF2();
							break;
						}
						case 4:
						{
							patient_objekt.Schitivanie_iz_fileF2();
							patient_objekt.delete_patient();
							patient_objekt.zapis_patientov_v_fileF2();
							break;

						}
						case 0:
						{
							break;
						}
						}
					} while (m != 0);
				}
				case 0:
				{
					break;
				}
				}
			} while (t != 0);
			break;

		}
		case 2:
		{
			while (!Login1());
			while (!Password1());
			Uchet patient_objekt;
			int l;
			do
			{

				cout << "1. Хотите добавить патиента в учёт, 2. Хотите найти информацию о патиенте, 3. Хотите изменить информацию о патиенте, 4. удалить патиента, 0. Выход:" << endl;
				cin >> l;
				switch (l)
				{
				case 1:
				{
					patient_objekt.Schitivanie_iz_fileF2();
					patient_objekt.create_patient();
					patient_objekt.zapis_patientov_v_fileF2();
					break;

				}
				case 2:
				{
					patient_objekt.Schitivanie_iz_fileF2();
					patient_objekt.search_patient();
					break;
				}
				case 3:
				{
					patient_objekt.Schitivanie_iz_fileF2();
					patient_objekt.change();
					patient_objekt.zapis_patientov_v_fileF2();
					break;
				}
				case 4:
				{
					patient_objekt.Schitivanie_iz_fileF2();
					patient_objekt.delete_patient();
					patient_objekt.zapis_patientov_v_fileF2();
					break;

				}
				case 0:
				{
					break;
				}
				}
			} while (l != 0);
			break;
		}
		case 1:
		{
			while (!Login2());
			while (!Password2());
			spravochnik doctor_object;
			doctor_object.Schitivanie_iz_fileF1();
			doctor_object.search_doctor();
			doctor_object.zapis_vrachei_v_fileF1();
			break;


		}
		case 0:
		{
			break;
		}

		}
	} while (n != 0);

	return 0;
}

bool Password()
{
	char key;
	string password = "95010";
	string PWD;
	cout << "Введите пароль:" << endl;
	while ((key = _getch()) != 13)
	{
		PWD += key;
		cout << "#";
	}
	cout << endl;
	if (PWD != password)
		return false;
	else return true;
}

bool Login()
{
	string login = "administracia";
	string i;
	cout << "Введите логин:" << endl;
	cin >> i;
	cout << endl;
	if (i != login)
		return false;
	else return true;

}

bool Password1()
{
	char key;
	string password = "101001";
	string PWD;
	cout << "Введите пароль:" << endl;
	while ((key = _getch()) != 13)
	{
		PWD += key;
		cout << "$";
	}
	cout << endl;
	if (PWD != password)
		return false;
	else return true;
}

bool Login1()
{
	string login = "doctor";
	string i;
	cout << "Введите логин:" << endl;
	cin >> i;
	cout << endl;
	if (i != login)
		return false;
	else return true;
}

bool Password2()
{
	char key;
	string password = "950";
	string PWD;
	cout << "Введите пароль:" << endl;
	while ((key = _getch()) != 13)
	{
		PWD += key;
		cout << "?";
	}
	cout << endl;
	if (PWD != password)
		return false;
	else return true;
}

bool Login2()
{
	string login = "patient";
	string i;
	cout << "Введите логин:" << endl;
	cin >> i;
	cout << endl;
	if (i != login)
		return false;
	else return true;
}



