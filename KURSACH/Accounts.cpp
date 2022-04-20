#include "Accounts.h"

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

void addAccount(vector <Account>& vec_of_accounts, bool is_from_admin)
{
	Account temp_account;
	string login, password;
	while (true)
	{
		cout << "\n�����: ";
		login = enterStringWithoutSpaces();
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
	if (is_from_admin)
	{
		temp_account.access = 1;
		cout << "������� ������ �������!" << endl;
		system("pause");
	}
	else
	{
		system("cls");
		cout << "������� ������ �������! ������� ������������� ���������������." << endl;
	}
	vec_of_accounts.push_back(temp_account);
}

void deleteAccount(vector <Account>& vec_of_accounts, int index_of_user)
{
	int answer, index_for_delete;
	cout << "����� ������� �� ������ �������?\n ������ - 0" << endl;
	index_for_delete = indexOfVectorForChange(vec_of_accounts);
	if (index_for_delete != 0)
	{
		index_for_delete--;
		if (index_for_delete != index_of_user)
		{
			system("cls");
			cout << "�� ������������� ������ ������� ������� " << vec_of_accounts.at(index_for_delete).login << "? \n�� - 1 \n��� - 0" << endl;
			answer = enterNumberInRange(0, 1);
			if (answer == 1)
			{
				vec_of_accounts.erase(vec_of_accounts.begin() + index_for_delete);
				cout << "������� �����!" << endl;
				system("pause");
			}
		}
		else
		{
			cout << "������ ������� ������ ����! ���������� � ������� ��������������." << endl;
			system("pause");
		}
	}
}

int indexOfVectorForChange(vector <Account>& vec_of_accounts)
{
	int size;
	size = vec_of_accounts.size();
	return enterNumberInRange(0, size);
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

bool isPasswordEquals(vector <Account>& vec_of_accounts, string password, int index_of_user)
{
	return vec_of_accounts.at(index_of_user).salted_hash_password == hashPassword(password, vec_of_accounts.at(index_of_user).salt);
}

bool isLoginEquals(vector <Account>& vec_of_accounts, string login, int index_of_user)
{
	return vec_of_accounts.at(index_of_user).login == login;
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
		system("cls");
		if (index >= 0)
		{
			if (vec_of_accounts.at(index).access == 1)
			{
				return index;
			}
			else if (vec_of_accounts.at(index).access == 0)
			{
				cout << "\n���� ������� ������ ��� �� ������������ ���������������, ������ ��������." << endl;
				return -1;
			}
			else
			{
				cout << "\n���� ������� ������ �������������, ������ ��������." << endl;
				return -2;
			}
		}
		else
		{
			cout << "����� �������� ����� ��� ������! ��������� �������." << endl;
		}
	}
	cout << "������ ��������. ���������� ������..." << endl;
	return -2;
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

int updateIndexOfUser(vector <Account>& vec_of_accounts, string login_of_user)
{
	for (int i = 0; i < vec_of_accounts.size(); i++)
	{
		if (login_of_user == vec_of_accounts.at(i).login)
		{
			return i;
		}
	}
}

void confirmAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array)
{
	int number;
	cout << "�������� ������� ������, ������� �� ������ �����������:" << endl;
	cout << " ����� - 0" << endl;
	number = enterNumberInRange(0, array.size());
	if (number != 0)
	{
		number--;
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

void updateAccountAccess(vector <Account>& vec_of_accounts, int index_of_user)
{
	cout << "������ �������� �� ������ �������� ������?\n ������ - 0" << endl;
	int index_for_change = indexOfVectorForChange(vec_of_accounts);
	if (index_for_change != 0)
	{
		index_for_change--;
		if (index_for_change != index_of_user)
		{
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

void updateAccountRole(vector <Account>& vec_of_accounts, int index_of_user)
{
	cout << "������ �������� �� ������ �������� ����?\n ������ - 0" << endl;
	int index_for_change = indexOfVectorForChange(vec_of_accounts);
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
