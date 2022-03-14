/*
23. ���������� ��������� ������� ���������
��� ������� ��������� ���������� ���������� ���������� ���������� ���� : ����� ������, �.�.�.��������,
����� ��������(������� / ���������), ������ �� ���� ���������(����� / �������), ������ �� 4 ���������,
������� ������� � ������������ ������ : 1 � �������� �������, 0 � ���������.
�������������� ������� : ���������� ��������� ��� ��������� - �����������.
��� ���� : ���������(������� 9, 10) � ������������� �������� 50 % ��������, � ������ ��������� � 25 % .
�������� �� ������� ������, ������ ��� ���� 5, ��������� �� ��������.������� ������ ��������� �������� � ����������.
����� ��� ���� ��������� ������� : ����������� ����������� ��� ����� � �������, ���������� �������������� � ���������� ������������(��.����� �������� � �������������� ����������� � �������� ������ � ���� �������� ��������������.�������).
*/

#include <Windows.h>

#include <vector>
#include <fstream>
#include <iostream>
#include <string>

//----hash----
#include "sha256.h"
//----hash----

using namespace std;

const string ADMIN_LOGIN = "ADMIN";
const string ADMIN_PASSWORD = "BSUIR";
const bool ADMIN_ROLE = 1;
const bool ADMIN_ACCESS = 1;

const string FILE_OF_ACCOUNTS = "accounts.txt";
const string FILE_OF_STUDENTS = "students.txt";
const int NUMBER_OF_SYMBOLS = 20;
const int NUMBER_OF_ATTEMPTS = 3;

const string MENU_ADMIN = "\n �������� �������� - 1\n ������� ������� - 2\n �������� ������ �������� - 3\n ������� �� ������ � ������� - 4\n ����� - 0";
const string MENU_USER = "\n �������� �������� - 1\n ������� ������� - 2\n ����� - 0";
const string START_MENU = "\n ����� � ������������ ������� ������ - 1\n ������� ����� ������� ������ - 2\n ���������� ������ - 0";
const int MAX_OF_RANGE_ADMIN = 4;
const int MAX_OF_RANGE_USER = 2;
const int MAX_OF_START_MENU = 2;

struct Account
{
	string login;
	string salted_hash_password;
	string salt;
	bool role = 0;//
	bool access = 0;
};

struct Student
{
	string login;
	string password;
	bool role = 0;
};

void showAccounts(vector <Account>& vec_of_accounts);
void addAccount(vector <Account>& vec_of_accounts);
void deleteAccount(vector <Account>& vec_of_accounts);
void updateAccount(vector <Account>& vec_of_accounts);
void core(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students);
void readFileOfAccounts(vector <Account>& vec_of_accounts);
void readFileOfStudents(vector <Student>& vec_of_students);
void writeFileOfAccounts(vector <Account>& vec_of_accounts);
void writeFileOfStudents(vector <Student>& vec_of_students);
int getCountOfStructures(string file_path);
int correctInputInt();
int menu(vector <Account>& vec_of_accounts, string message, int max_of_range);
int chooseMenu(string message, int max_of_range);
int initialisation(vector <Account>& vec_of_accounts);
int enterAccount(vector <Account>& vec_of_accounts);
int checkDataEquals(vector <Account>& vec_of_accounts, string login, string password);
string hashPassword(string password, string salt);
bool isGoodLogin(vector <Account>& vec_of_accounts, string login);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector <Account> vec_of_accounts;//(getCountOfStructures(FILE_OF_ACCOUNTS));
	vec_of_accounts.reserve(getCountOfStructures(FILE_OF_ACCOUNTS));
	vector <Student> vec_of_students;//(getCountOfStructures(FILE_OF_STUDENTS));
	vec_of_students.reserve(getCountOfStructures(FILE_OF_STUDENTS));
	readFileOfAccounts(vec_of_accounts);
	readFileOfStudents(vec_of_students);
	core(vec_of_accounts, vec_of_students);
	writeFileOfAccounts(vec_of_accounts);
	writeFileOfStudents(vec_of_students);
	system("pause");
	return 0;
}

int initialisation(vector <Account>& vec_of_accounts)
{
	int item = chooseMenu(START_MENU, MAX_OF_START_MENU);
	switch (item)
	{
	case 1:
		return enterAccount(vec_of_accounts);
	case 2: addAccount(vec_of_accounts);
		return initialisation(vec_of_accounts);
	case 0: return -1;
	}
}

int enterAccount(vector <Account>& vec_of_accounts)
{
	string login, password;
	int index;
	for (int i = 0; i < NUMBER_OF_ATTEMPTS; i++)
	{
		cout << "�������� " << NUMBER_OF_ATTEMPTS - i << " �������" << endl;
		cout << "������� �����: ";
		cin >> login;//��������
		cout << "\n������� ������: ";
		cin >> password;//��������
		index = checkDataEquals(vec_of_accounts, login, password);
		if (index >= 0)
		{
			return vec_of_accounts.at(index).role;
		}
	}
	return -1;
}

int checkDataEquals(vector <Account>& vec_of_accounts, string login, string password)
{
	for (int i = 0; i < vec_of_accounts.size(); i++)
	{
		if (login == vec_of_accounts.at(i).login &&
			vec_of_accounts.at(i).salted_hash_password == hashPassword(password, vec_of_accounts.at(i).salt))
		{
			return i;
		}
	}
	return 0;
}

string hashPassword(string password, string salt)
{
	return sha256(sha256(password + salt) + sha256(password));
}

bool isGoodLogin(vector <Account>& vec_of_accounts, string login)
{
	for (int i = 0; i < vec_of_accounts.size(); i++)
	{
		if (login == vec_of_accounts.at(i).login)
		{
			return 0;
		}
	}
	return 1;
}

void core(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students)
{

	bool flag = true;
	while (flag)
	{
		int code = initialisation(vec_of_accounts);
		switch (code)
		{
		case 0: menu(vec_of_accounts, MENU_USER, MAX_OF_RANGE_USER);
			break;
		case 1: menu(vec_of_accounts, MENU_ADMIN, MAX_OF_RANGE_ADMIN);
			break;
		case -1: flag = false;//return;
			break;
		}
	}
}


int menu(vector <Account>& vec_of_accounts, string message, int max_of_range)
{
	bool flag = true;
	while (flag)
	{
		int item = chooseMenu(message, max_of_range);
		switch (item)
		{
		case 1: showAccounts(vec_of_accounts);
			break;
		case 2: deleteAccount(vec_of_accounts);
			break;
		case 3: updateAccount(vec_of_accounts);
			break;
		case 0: flag = false;
			break;
		}
	}
	return 0;
}

int chooseMenu(string message, int max_of_range)
{
	int item;
	do
	{
		cout << message << endl;
		item = correctInputInt();//����� ��� ��������
	} while (item > max_of_range || item < 0);
	return item;
}

void addAccount(vector <Account>& vec_of_accounts)
{
	Account temp_account;
	string password;
	string login;
	/*int n = 0, i = 1;
	do
	{
		printf("������� ������� ������� �� ������ ��������?: ");
		n = correctInputInt();
	} while (n < 1);
	do
	{*/
	cout << "\n�����:" << endl;
	cin >> login;//��������
	if (isGoodLogin(vec_of_accounts, login))
	{
		temp_account.login = login;
	}
	else {
		cout << "����� ����� ��� ����������!" << endl;
	}//��������
	cout << "\n������:" << endl;
	cin >> password;//��������
	temp_account.salt = generateSalt(SALT_SIZE);
	temp_account.salted_hash_password = hashPassword(password, temp_account.salt);
	cout << "\n���� (0 - ������������, 1 - �����):" << endl;
	cin >> temp_account.role;
	vec_of_accounts.push_back(temp_account);
	//i++;
	//} while (i < n + 1);
	ofstream fout(FILE_OF_ACCOUNTS, ios::out);
	for (int i = 0; i < vec_of_accounts.size(); i++)
	{
		fout << vec_of_accounts.at(i).login << " " << vec_of_accounts.at(i).salted_hash_password << " "
			<< vec_of_accounts.at(i).salt << " " << vec_of_accounts.at(i).role << " " << vec_of_accounts.at(i).access;
		if (i < vec_of_accounts.size() - 1)
		{
			fout << endl;
		}
	}
	fout.close();
}

void showAccounts(vector <Account>& vec_of_accounts)
{
	for (int i = 0; i < vec_of_accounts.size(); i++)
	{
		cout << vec_of_accounts.at(i).login << " " << vec_of_accounts.at(i).salted_hash_password << " " << vec_of_accounts.at(i).role;
		if (i < vec_of_accounts.size() - 1)
		{
			cout << endl;
		}
	}
}

void deleteAccount(vector <Account>& vec_of_accounts)
{
	int size = vec_of_accounts.size();
	//cout << size << endl;
	int index_for_delete = 0;
	do
	{
		cout << "����� ������� �� ������ �������?" << endl;
		index_for_delete = correctInputInt();
		index_for_delete--;
	} while (index_for_delete > size);
	vec_of_accounts.erase(vec_of_accounts.begin() + index_for_delete);
	cout << "����� �������!" << endl;
	writeFileOfAccounts(vec_of_accounts);
}

void readFileOfAccounts(vector <Account>& vec_of_accounts)
{
	ifstream fin(FILE_OF_ACCOUNTS, ios::in);
	Account temp_account;
	if (!fin.is_open())
	{
		cout << "����� � �������� �������� �� ����������! ������ ����� � ������� ������� ��������������." << endl;
		temp_account.login = ADMIN_LOGIN;
		temp_account.salt = generateSalt(SALT_SIZE);
		temp_account.salted_hash_password = hashPassword(ADMIN_PASSWORD, temp_account.salt);
		temp_account.role = ADMIN_ROLE;
		temp_account.access = ADMIN_ACCESS;
		vec_of_accounts.push_back(temp_account);
		writeFileOfAccounts(vec_of_accounts);
	}
	else
	{
		if (fin.peek() != EOF)
		{
			while (!fin.eof())
			{
				fin >> temp_account.login >> temp_account.salted_hash_password >> temp_account.salt >> temp_account.role
					>> temp_account.access;
				vec_of_accounts.push_back(temp_account);
			}
		}
		else
		{
			cout << "���� ����!" << endl;
		}
	}
	fin.close();
}

void readFileOfStudents(vector <Student>& vec_of_students)
{
	ifstream fin(FILE_OF_STUDENTS, ios::in);
	Student temp_student;
	if (!fin.is_open())
	{
		cout << "����� �� ���������� �� ����������! ������ �����." << endl;
		temp_student.login = ADMIN_LOGIN;
		temp_student.password = ADMIN_PASSWORD;
		temp_student.role = ADMIN_ROLE;
		vec_of_students.push_back(temp_student);
		writeFileOfStudents(vec_of_students);
	}
	else
	{
		if (fin.peek() != EOF)
		{
			while (!fin.eof())
			{
				fin >> temp_student.login >> temp_student.password >> temp_student.role;
				vec_of_students.push_back(temp_student);
			}
		}
		else
		{
			cout << "���� ����!" << endl;
		}
	}
	//delete & temp_student;//���� ��?
	fin.close();
}

void writeFileOfAccounts(vector <Account>& vec_of_accounts)
{
	ofstream fout(FILE_OF_ACCOUNTS, ios::out);
	for (int i = 0; i < vec_of_accounts.size(); i++)
	{
		fout << vec_of_accounts.at(i).login << " " << vec_of_accounts.at(i).salted_hash_password << " " << vec_of_accounts.at(i).salt
			<< " " << vec_of_accounts.at(i).role << " " << vec_of_accounts.at(i).access;
		if (i < vec_of_accounts.size() - 1)
		{
			fout << endl;
		}
	}
	fout.close();
}

void writeFileOfStudents(vector <Student>& vec_of_students)
{
	ofstream fout(FILE_OF_STUDENTS, ios::out);
	for (int i = 0; i < vec_of_students.size(); i++)
	{
		fout << vec_of_students.at(i).login << " " << vec_of_students.at(i).password << " " << vec_of_students.at(i).role;
		if (i < vec_of_students.size() - 1)
		{
			fout << endl;
		}
	}
	fout.close();
}

int correctInputInt()
{
	int a;
	while (true)
	{
		cin >> a;
		if (cin.get() == '\n') {
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "������!\n" << "���������� �����!" << endl;
		}
	}
	return a;
}

void updateAccount(vector <Account>& vec_of_accounts)
{
	int index;
	string password;
	cout << "������� ������:" << endl;
	cin >> index;
	index--;
	cout << "\n�����:" << endl;
	cin >> vec_of_accounts.at(index).login;
	cout << "\n������:" << endl;
	cin >> password;
	vec_of_accounts.at(index).salt = generateSalt(SALT_SIZE);
	vec_of_accounts.at(index).salted_hash_password = hashPassword(password, vec_of_accounts.at(index).salt);
	cout << "\n����(0 - ������������, 1 - �����):" << endl;
	cin >> vec_of_accounts.at(index).role;
}

int getCountOfStructures(string file_path)
{
	ifstream file(file_path, ios::in);
	int number_of_strings = 0;
	if (file.is_open())
	{
		while (file.ignore(256, '\n'))
		{
			number_of_strings++;
		}
	}
	file.close();
	return number_of_strings;
}