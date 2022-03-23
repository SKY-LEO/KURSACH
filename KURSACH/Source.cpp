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
#include <conio.h>

//----hash----
#include "sha256.h"
//----hash----

using namespace std;

const string ADMIN_LOGIN = "ADMIN";
const string ADMIN_PASSWORD = "BSUIR";
const bool ADMIN_ROLE = 1;
//const bool ADMIN_ACCESS = 1;
const int ADMIN_ACCESS = 1;

const string FILE_OF_ACCOUNTS = "accounts.txt";
const string FILE_OF_STUDENTS = "students.txt";
const int NUMBER_OF_SYMBOLS = 20;
const int NUMBER_OF_ATTEMPTS = 3;

const string SEPARATOR = "------------------------------------------------";

//const string MAIN_MENU_ADMIN = "\n ��������� - 1\n ������ � �������� �������� - 2\n ������� ������ - 3\n ����� - 0";
const string MAIN_MENU_ADMIN = "\n1) ���������\n2) ������ � �������� ��������\n3) ������� ������\n0) �����";
//const string ACCOUNT_MENU_ADMIN = " �� ���������� � ���� ������ � �������� ��������.\n �������� - 1\n ������� - 2\n �������� ������ - 3\n �������� ���� - 4\n ������� �� ������ - 5\n ����� - 0";
//const string ACCOUNT_MENU_ADMIN = " �� ���������� � ���� ������ � �������� ��������.\n ������� - 1\n �������� ������ - 2\n �������� ���� - 3\n ������� �� ������ - 4\n ����� - 0";
const string ACCOUNT_MENU_ADMIN = " �� ���������� � ���� ������ � �������� ��������.\n1) �������\n2) �������� ������\n3) �������� ����\n4) ������� �� ������";// ����� - 0";
//const string ACCOUNT_MENU_ADMIN_WITHOUT_ACCESS = " �� ���������� � ���� ������ � �������� ��������.\n �������� - 1 \n ������� - 2\n �������� ������ - 3\n �������� ���� - 4\n ����� - 0";
const string ACCOUNT_MENU_ADMIN_WITHOUT_ACCESS = " �� ���������� � ���� ������ � �������� ��������.\n1) �������\n2) �������� ������\n3) �������� ����\n0) �����";
//const string ACCOUNT_MENU_ADMIN_WITHOUT_ACCESS = " �� ���������� � ���� ������ � �������� ��������.\n ������� - 1\n �������� ������ - 2\n �������� ���� - 3\n ����� - 0";
//const string MAIN_MENU_USER = "\n ��������� - 1\n ������� ������ - 2\n ����� - 0";
const string MAIN_MENU_USER = "\n1) ���������\n2) ������� ������\n0) �����";
//const string START_MENU = "\n ����� � ������������ ������� ������ - 1\n ������� ����� ������� ������ - 2\n ���������� ������ - 0";
const string START_MENU = "\n1) ����� � ������������ ������� ������\n2) ������� ����� ������� ������\n0) ���������� ������";
const string MENU_OF_ACCESS = "\n1) ����������� ������\n2) ������������� ������\n0) �����";
const int MAX_OF_RANGE_MENU_ADMIN = 4;
const int MAX_OF_RANGE_MENU_ADMIN_WITHOUT_ACCESS = 3;
const int MAX_OF_RANGE_MAIN_MENU_ADMIN = 3;
const int MAX_OF_RANGE_MAIN_MENU_USER = 2;
const int MAX_OF_START_MENU = 2;
const int MAX_OF_RANGE_MENU_ACCESS = 2;
//const string ACCESS[3] = { "������ �������� �� ������ �������� ������?", "�� ������������� ������ �������� ������ ����� ��������?", "������ �������!" };
//const string ROLE[3] = { "������ �������� �� ������ �������� ����?", "�� ������������� ������ �������� ���� ����� ��������?", "�������� �������!" };
//const string DELETE_ACCOUNT[3] = { "����� ������� �� ������ �������?", "�� ������������� ������ ������� ���� �������?", "����� �������!" };


struct Account
{
	string login;
	string salted_hash_password;
	string salt;
	bool role = false;//
	//bool access = false;
	int access = 0;
};

struct Student
{
	string login;
	string password;
	bool role = false;
};

/*typedef void(*ToFunction)(vector <Account>& vec_of_accounts, int index_for_change);
void updateAccountAccess(vector <Account>& vec_of_accounts, int index_for_change);
void updateAccountRole(vector <Account>& vec_of_accounts, int index_for_change);
void deleteAccount(vector <Account>& vec_of_accounts, int index_for_delete);
void doSomethingWithAccount(vector <Account>& vec_of_accounts, const string* message, ToFunction function);*/


void showAccounts(vector <Account>& vec_of_accounts);
void addAccount(vector <Account>& vec_of_accounts);
void deleteAccount(vector <Account>& vec_of_accounts, int index_of_user);
//void updateAccount(vector <Account>& vec_of_accounts);
void core(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students);
void readFileOfAccounts(vector <Account>& vec_of_accounts);
void readFileOfStudents(vector <Student>& vec_of_students);
void writeFileOfAccounts(vector <Account>& vec_of_accounts);
void writeFileOfStudents(vector <Student>& vec_of_students);
int getCountOfStructures(string file_path);
int correctInputInt();
//int menu(vector <Account>& vec_of_accounts, string message, int max_of_range);
//int chooseMenu(string message, int max_of_range);
int initialisation(vector <Account>& vec_of_accounts);
int enterAccount(vector <Account>& vec_of_accounts);
int checkDataEquals(vector <Account>& vec_of_accounts, string login, string password);
string hashPassword(string password, string salt);
string enterGoodPassword();
string enterStringWithoutSpaces();
bool isGoodLogin(vector <Account>& vec_of_accounts, string login);
void createFirstAccount(vector <Account>& vec_of_accounts);
int enterNumberInRange(int min, int max);
void confirmAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array);
int user(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students, int index_of_user);
int admin(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students, int index_of_user);
void workWithStudents(vector <Student>& vec_of_students);
void changePassword(vector <Account>& vec_of_accounts, int index_of_user);
void workWithAccounts(vector <Account>& vec_of_accounts, int index_of_user);
bool isPasswordEquals(vector <Account>& vec_of_accounts, string password, int index_of_user);
bool isLoginEquals(vector <Account>& vec_of_accounts, string login, int index_of_user);
void fillVectorOfAccountsNeedAccess(vector <Account>& vec_of_accounts, vector <int>& array);
void updateAccountRole(vector <Account>& vec_of_accounts, int index_of_user);
void updateAccountAccess(vector <Account>& vec_of_accounts, int index_of_user);
int IndexOfAccountForChange(vector <Account>& vec_of_accounts);

void workWithAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array);

void rejectAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array);

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
	cout << "������������, �����! ����������, �������� ����� ����:" << endl;
	cout << START_MENU << endl;
	int item = enterNumberInRange(0, MAX_OF_START_MENU);
	system("cls");
	switch (item)
	{
	case 1: return enterAccount(vec_of_accounts);
	case 2: addAccount(vec_of_accounts);
		return initialisation(vec_of_accounts);
	case 0: return -2;
	default: return item;
	}
}

int enterAccount(vector <Account>& vec_of_accounts)
{
	string login, password;
	int index;
	for (int i = 0; i < NUMBER_OF_ATTEMPTS; i++)
	{
		cout << "�������� �������: " << NUMBER_OF_ATTEMPTS - i << endl;
		cout << "������� �����: ";
		login = enterStringWithoutSpaces();
		cout << "\n������� ������: ";
		password = enterGoodPassword();
		index = checkDataEquals(vec_of_accounts, login, password);
		if (index >= 0)
		{
			if (vec_of_accounts.at(index).access == 1)
			{
				return index;//vec_of_accounts.at(index).role;
			}
			else if (vec_of_accounts.at(index).access == 0)
			{
				system("cls");
				cout << "\n���� ������� ������ ��� �� ������������ ���������������, ������ ��������." << endl;
				return -1;
			}
			else//access = -1
			{
				system("cls");
				cout << "\n���� ������� ������ �������������, ������ ��������." << endl;
				return -2;
			}
		}
		else
		{
			system("cls");
			cout << "����� �������� ����� ��� ������! ��������� �������." << endl;
			//system("pause");//
		}
		//system("cls");
	}
	cout << "������ ��������. ���������� ������..." << endl;
	return -2;
}

string enterGoodPassword()
{
	int count = 0;
	char symbol;
	string password;
	while ((symbol = _getch()) != '\r')//���� �������� ������ �� ����� ������ �������� �������(enter)
	{
		if (symbol == '\b')//backspace
		{
			if (count != 0)
			{
				cout << '\b' << ' ' << '\b';
				password.erase(password.length() - 1);
				count--;
			}
			continue;
		}
		count++;
		password += symbol;
		cout << '*';
	}
	return password;
}

string enterStringWithoutSpaces()
{
	//cout << "������� ����� �������, ����� �������." << endl;
	int count = 0;
	char symbol;
	string buffer;
	while ((symbol = _getch()) != '\r')//���� �������� ������ �� ����� ������ �������� �������(enter)
	{
		if (symbol == '\b')//backspace
		{
			if (count != 0)
			{
				cout << '\b' << ' ' << '\b';
				buffer.erase(buffer.length() - 1);
				count--;
			}
			continue;
		}
		if (symbol == ' ')
		{
			continue;
		}
		count++;
		buffer += symbol;
		cout << symbol;
	}
	return buffer;
}

string hashPassword(string password, string salt)
{
	return sha256(sha256(password + salt) + sha256(password));
}

bool isGoodLogin(vector <Account>& vec_of_accounts, string login)
{
	for (unsigned int i = 0; i < vec_of_accounts.size(); i++)
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
	int code, index_of_user;
	bool flag = true;
	while (flag)
	{
		index_of_user = initialisation(vec_of_accounts);
		if (index_of_user > -1)//���� �� ��� ������
		{
			code = vec_of_accounts.at(index_of_user).role;
		}
		else
		{
			code = index_of_user;
		}
		switch (code)
		{
		case 0: system("cls");
			user(vec_of_accounts, vec_of_students, index_of_user);
			break;
		case 1: system("cls");
			admin(vec_of_accounts, vec_of_students, index_of_user);
			break;
		case -1:
			break;
		default:
			flag = false;//return;
		}
	}
}

int user(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students, int index_of_user)
{
	bool flag = true;
	while (flag)
	{
		cout << MAIN_MENU_USER << endl;
		int item = enterNumberInRange(0, MAX_OF_RANGE_MAIN_MENU_USER);//chooseMenu(message, max_of_range);
		switch (item)
		{
		case 1:system("cls");
			workWithStudents(vec_of_students);
			break;
		case 2:system("cls");
			changePassword(vec_of_accounts, index_of_user);
			break;
		case 0: flag = false;
			break;
		}
	}
	system("cls");
	return 0;
}

int admin(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students, int index_of_user)
{
	bool flag = true;
	while (flag)
	{
		cout << MAIN_MENU_ADMIN << endl;
		int item = enterNumberInRange(0, MAX_OF_RANGE_MAIN_MENU_ADMIN);
		switch (item)
		{
		case 1: system("cls");
			workWithStudents(vec_of_students);
			break;
		case 2: system("cls");
			workWithAccounts(vec_of_accounts, index_of_user);
			break;
		case 3: system("cls");
			changePassword(vec_of_accounts, index_of_user);
			break;
		case 0: flag = false;
			break;
		}
	}
	system("cls");
	return 0;
}

void changePassword(vector <Account>& vec_of_accounts, int index_of_user)
{
	string password;
	for (int i = 0; i < NUMBER_OF_ATTEMPTS; i++)
	{
		cout << "�������� �������: " << NUMBER_OF_ATTEMPTS - i << endl;
		cout << "������� ������� ������: ";
		password = enterGoodPassword();
		if (isPasswordEquals(vec_of_accounts, password, index_of_user))
		{
			cout << "\n������� ����� ������: ";
			password = enterStringWithoutSpaces();
			vec_of_accounts.at(index_of_user).salt = generateSalt(SALT_SIZE);
			vec_of_accounts.at(index_of_user).salted_hash_password = hashPassword(password, vec_of_accounts.at(index_of_user).salt);
			system("cls");
			cout << "\n������ ������ �������!" << endl;
			system("pause");
			break;
		}
		else
		{
			system("cls");
			cout << "����� �������� ������! ��������� �������." << endl;
		}
	}
	system("cls");
}

bool isPasswordEquals(vector <Account>& vec_of_accounts, string password, int index_of_user)
{
	return vec_of_accounts.at(index_of_user).salted_hash_password == hashPassword(password, vec_of_accounts.at(index_of_user).salt);
}

bool isLoginEquals(vector <Account>& vec_of_accounts, string login, int index_of_user)
{
	return vec_of_accounts.at(index_of_user).login == login;
}

int checkDataEquals(vector <Account>& vec_of_accounts, string login, string password)
{
	for (unsigned int index = 0; index < vec_of_accounts.size(); index++)
	{
		if (isLoginEquals(vec_of_accounts, login, index) && isPasswordEquals(vec_of_accounts, password, index))
		{
			return index;
		}
	}
	return -1;
}

void workWithAccounts(vector <Account>& vec_of_accounts, int index_of_user)
{
	bool flag = true, update_access = true;
	int item, size_of_array;
	vector <int> array;
	while (flag)
	{
		showAccounts(vec_of_accounts);
		if (update_access)//���� ������ ������� ��� ������� � ������� ��� ������ ������, �� ���� �������� ������ ���������, ��������� �������������
		{
			fillVectorOfAccountsNeedAccess(vec_of_accounts, array);
			update_access = !update_access;
		}
		size_of_array = array.size();
		if (size_of_array == 0)
		{
			cout << ACCOUNT_MENU_ADMIN_WITHOUT_ACCESS << endl;
			item = enterNumberInRange(0, MAX_OF_RANGE_MENU_ADMIN_WITHOUT_ACCESS);
		}
		else
		{
			cout << ACCOUNT_MENU_ADMIN << "(����� ��������: " << size_of_array << ")\n0) �����" << endl;
			item = enterNumberInRange(0, MAX_OF_RANGE_MENU_ADMIN);
		}
		switch (item)
		{
			//case 1:system("cls");
				//showAccounts(vec_of_accounts);
				//break;
		case 1:
			deleteAccount(vec_of_accounts, index_of_user);
			/*cout << "����� ������� �� ������ �������?\n ������ - 0" << endl;
			int index_for_delete = IndexOfAccountForChange(vec_of_accounts);
			if (index_for_delete != 0)
			{


				if (isChangebable(index_for_delete, index_of_user))
				{
					deleteAccount(vec_of_accounts, index_for_delete);
				}
				else
				{
					cout << "������ ������� ������ ����!" << endl;
				}
			}*/
			update_access = true;
			system("cls");
			break;
		case 2:
			updateAccountAccess(vec_of_accounts, index_of_user);
			//update_access = true;
			system("cls");
			break;
		case 3:
			updateAccountRole(vec_of_accounts, index_of_user);
			system("cls");
			break;
		case 4:
			system("cls");
			//confirmAccessOfAccounts(vec_of_accounts, array);
			workWithAccessOfAccounts(vec_of_accounts, array);
			system("cls");
			break;
		case 0: flag = false;
			break;
		}
	}
	system("cls");
}

void workWithStudents(vector <Student>& vec_of_students)
{

}

void workWithAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array)
{
	bool flag = true;
	int number;
	while (flag)
	{
		if (array.size() != 0)
		{
			cout << endl;
			cout << "�\t|" << "�����\t|" << "����\t|" << endl;
			cout << SEPARATOR << endl;
			for (unsigned int i = 0; i < array.size(); i++)
			{
				cout << i + 1 << "\t|" << vec_of_accounts.at(array.at(i)).login << "\t|"
					<< vec_of_accounts.at(array.at(i)).role << "\t|" << endl;
			}
			cout << SEPARATOR << endl;
			cout << MENU_OF_ACCESS << endl;
			//cout << " ����� - 0" << endl;
			number = enterNumberInRange(0, MAX_OF_RANGE_MENU_ACCESS);
			switch (number)
			{
			case 1: confirmAccessOfAccounts(vec_of_accounts, array);
				system("cls");
				break;
			case 2: rejectAccessOfAccounts(vec_of_accounts, array);
				system("cls");
				break;
			default: flag = false;
			}
		}
		else
		{
			flag = false;
		}
	}
}

void confirmAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array)
{
	/*bool flag = true;
	int number;
	while (flag)
	{
		if (array.size() != 0)
		{
			cout << "�������� ������� ������, ������� �� ������ �����������:" << endl;
			cout << endl;
			cout << "�\t|" << "�����\t|" << "����\t|" << endl;
			cout << SEPARATOR << endl;
			for (unsigned int i = 0; i < array.size(); i++)
			{
				cout << i + 1 << "\t|" << vec_of_accounts.at(array.at(i)).login << "\t|"
					<< vec_of_accounts.at(array.at(i)).role << "\t|" << endl;
			}
			cout << SEPARATOR << endl;
			cout << endl;
			//cout << "1)����������� ������\n2)������� ������� ������\n0) �����" << endl;
			cout << " ����� - 0" << endl;
			number = enterNumberInRange(0, array.size());
			if (number != 0)
			{
				number--;
				//vec_of_accounts.at(array.at(number)).access = true;
				vec_of_accounts.at(array.at(number)).access = 1;
				array.erase(array.begin() + number);
				system("cls");
				cout << "������� ������ ������������." << endl;
				system("pause");
			}
			else
			{
				flag = false;
			}
		}
		else
		{
			flag = false;
		}
	}*/
	int number;
	cout << "�������� ������� ������, ������� �� ������ �����������:" << endl;
	cout << " ����� - 0" << endl;
	number = enterNumberInRange(0, array.size());
	if (number != 0)
	{
		number--;
		//vec_of_accounts.at(array.at(number)).access = true;
		vec_of_accounts.at(array.at(number)).access = 1;
		array.erase(array.begin() + number);
		system("cls");
		cout << "������� ������ ������������." << endl;
		system("pause");
	}
}
void rejectAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array)
{
	int number;
	cout << "�������� ������� ������, ������� �� ������ ������������� ������:" << endl;
	cout << " ����� - 0" << endl;
	number = enterNumberInRange(0, array.size());
	if (number != 0)
	{
		number--;
		//vec_of_accounts.at(array.at(number)).access = true;
		vec_of_accounts.at(array.at(number)).access = -1;
		array.erase(array.begin() + number);
		system("cls");
		cout << "������� ������ �������������." << endl;
		system("pause");
	}
}

void fillVectorOfAccountsNeedAccess(vector <Account>& vec_of_accounts, vector <int>& array)
{
	array.clear();
	for (unsigned int i = 0; i < vec_of_accounts.size(); i++)
	{
		if (vec_of_accounts.at(i).access == 0)
		{
			array.push_back(i);
		}
	}
}

void addAccount(vector <Account>& vec_of_accounts)
{
	Account temp_account;
	string login, password;
	while (true)
	{
		cout << "\n�����: ";
		login = enterStringWithoutSpaces();//�������� �� �������
		if (isGoodLogin(vec_of_accounts, login))
		{
			temp_account.login = login;
			break;
		}
		else
		{
			system("cls");
			cout << "\n����� ����� ��� ����������! ������� ������.";
		}
	}
	cout << "\n������: ";
	password = enterStringWithoutSpaces();
	temp_account.salt = generateSalt(SALT_SIZE);
	temp_account.salted_hash_password = hashPassword(password, temp_account.salt);
	cout << "\n���� (������������ - 0, ����� - 1): ";
	int role;
	role = enterNumberInRange(0, 1);//cin >> temp_account.role;
	temp_account.role = role;
	vec_of_accounts.push_back(temp_account);
	system("cls");
	cout << "������� ������ �������! ������� ������������� ���������������." << endl;
}

void showAccounts(vector <Account>& vec_of_accounts)
{
	cout << endl;
	cout << "�\t|" << "�����\t|" << "����\t|" << "������\t|" << endl;
	cout << SEPARATOR << endl;
	for (unsigned int i = 0; i < vec_of_accounts.size(); i++)
	{
		cout << i + 1 << "\t|" << vec_of_accounts.at(i).login << "\t|" << vec_of_accounts.at(i).role << "\t|"
			<< vec_of_accounts.at(i).access << "\t|" << endl;
	}
	cout << SEPARATOR << endl;
	cout << endl;
}

void deleteAccount(vector <Account>& vec_of_accounts, int index_of_user)
{
	//int size,
	int answer, index_for_delete;
	cout << "����� ������� �� ������ �������?\n ������ - 0" << endl;
	index_for_delete = IndexOfAccountForChange(vec_of_accounts);
	if (index_for_delete != 0)
	{
		index_for_delete--;
		if (index_for_delete != index_of_user)
		{
			system("cls");
			cout << "�� ������������� ������ ������� ���� �������? \n�� - 1 \n��� - 0" << endl;
			answer = enterNumberInRange(0, 1);
			if (answer == 1)
			{
				vec_of_accounts.erase(vec_of_accounts.begin() + index_for_delete);
			}
		}
		else
		{
			cout << "������ ������� ������ ����! ���������� � ������� ��������������." << endl;
			system("pause");
		}
	}
}


/*void deleteAccount(vector <Account>& vec_of_accounts, int index_for_delete)
{
	int answer;
	index_for_delete--;
	system("cls");
	cout << "�� ������������� ������ ������� ���� �������? \n�� - 1 \n��� - 0" << endl;
	answer = enterNumberInRange(0, 1);
	if (answer == 1)
	{
		vec_of_accounts.erase(vec_of_accounts.begin() + index_for_delete);
	}
}*/

int enterNumberInRange(int min, int max)
{
	int number;
	while (true)
	{
		number = correctInputInt();
		if (number >= min && number <= max)
		{
			break;
		}
		else
		{
			cout << "������� ����� � �������� ����������!" << endl;
		}
	}
	return number;
}

void createFirstAccount(vector <Account>& vec_of_accounts)
{
	ifstream fin(FILE_OF_ACCOUNTS, ios::in);
	Account temp_account;
	temp_account.login = ADMIN_LOGIN;
	temp_account.salt = generateSalt(SALT_SIZE);
	temp_account.salted_hash_password = hashPassword(ADMIN_PASSWORD, temp_account.salt);
	temp_account.role = ADMIN_ROLE;
	temp_account.access = ADMIN_ACCESS;
	vec_of_accounts.push_back(temp_account);
	writeFileOfAccounts(vec_of_accounts);
	fin.close();
}

void readFileOfAccounts(vector <Account>& vec_of_accounts)
{
	ifstream fin(FILE_OF_ACCOUNTS, ios::in);
	Account temp_account;
	if (!fin.is_open())
	{
		cout << "����� � �������� �������� �� ����������! ������ ����� � ������� ������� ��������������." << endl;
		createFirstAccount(vec_of_accounts);
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
			cout << "���� ����! ������� ������� ������ ��������������." << endl;
			createFirstAccount(vec_of_accounts);
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
	fin.close();
}

void writeFileOfAccounts(vector <Account>& vec_of_accounts)
{
	ofstream fout(FILE_OF_ACCOUNTS, ios::out);
	for (unsigned int i = 0; i < vec_of_accounts.size(); i++)
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
	for (unsigned int i = 0; i < vec_of_students.size(); i++)
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
			cout << "������! ������� ����� �����." << endl;
		}
	}
	return a;
}

int IndexOfAccountForChange(vector <Account>& vec_of_accounts)
{
	int index_for_change, size;
	size = vec_of_accounts.size();
	return index_for_change = enterNumberInRange(0, size);
}

void updateAccountAccess(vector <Account>& vec_of_accounts, int index_of_user)
{
	cout << "������ �������� �� ������ �������� ������?\n ������ - 0" << endl;
	int index_for_change = IndexOfAccountForChange(vec_of_accounts);
	if (index_for_change != 0)
	{
		index_for_change--;
		if (index_for_change != index_of_user)
		{
			//vec_of_accounts.at(index_for_change).access = !vec_of_accounts.at(index_for_change).access;
			if (vec_of_accounts.at(index_for_change).access == 1)
			{
				vec_of_accounts.at(index_for_change).access = -1;
			}
			else
			{
				vec_of_accounts.at(index_for_change).access = 1;
			}
		}
		else
		{
			cout << "������ �������� ������ ������ ����! ���������� � ������� ��������������." << endl;
			system("pause");
		}
	}
}

//bool isChangebable(int index_for_change, int index_of_user)
//{
	//return index_for_change - 1 != index_of_user;
//}

void updateAccountRole(vector <Account>& vec_of_accounts, int index_of_user)
{
	cout << "������ �������� �� ������ �������� ����?\n ������ - 0" << endl;
	int index_for_change = IndexOfAccountForChange(vec_of_accounts);
	if (index_for_change != 0)
	{
		index_for_change--;
		if (index_for_change != index_of_user)
		{
			vec_of_accounts.at(index_for_change).role = !vec_of_accounts.at(index_for_change).role;
		}
		else
		{
			cout << "������ �������� ���� ������ ����! ���������� � ������� ��������������." << endl;
			system("pause");
		}
	}
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