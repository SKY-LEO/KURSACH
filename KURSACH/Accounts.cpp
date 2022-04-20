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
	index_for_delete = IndexOfAccountForChange(vec_of_accounts);
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

int IndexOfAccountForChange(vector <Account>& vec_of_accounts)
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
