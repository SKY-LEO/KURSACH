#include "Accounts.h"

void showAccounts(vector <Account>& vec_of_accounts)
{
	cout << endl;
	cout << SEPARATOR_ACCOUNT << endl;
	cout << "|" << setw(4) << "№" << setw(4) << "|" << setw(11) << "Логин" << setw(7) << "|" << setw(9) << "Роль" << setw(6) << "|"
		<< setw(8) << "Доступ" << setw(3) << "|" << endl;
	cout << SEPARATOR_ACCOUNT << endl;
	for (unsigned int i = 0; i < vec_of_accounts.size(); i++)
	{
		cout << "|" << setw(4) << i + 1 << setw(4) << "|" << setw(17) << left << vec_of_accounts.at(i).login << "|"
			<< setw(14) << right << tellIsUserOrAdminRole(vec_of_accounts.at(i).role) << "|"
			<< setw(9) << tellIsActiveOrWaitOrBannedAccess(vec_of_accounts.at(i).access) << setw(2) << "|" << endl;
		cout << SEPARATOR_ACCOUNT << endl;
	}
	cout << endl;
}

void showRequestsOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array)
{
	cout << endl;
	cout << "|" << setw(4) << "№" << setw(4) << "|" << setw(11) << "Логин" << setw(7) << "|"
		<< setw(9) << "Роль" << setw(6) << "|" << endl;
	cout << SEPARATOR << endl;
	for (unsigned int i = 0; i < array.size(); i++)
	{
		cout << "|" << setw(4) << i + 1 << setw(4) << "|" << setw(17) << left << vec_of_accounts.at(i).login << "|"
			<< setw(14) << right << tellIsUserOrAdminRole(vec_of_accounts.at(i).role) << "|" << endl;
	}
	cout << SEPARATOR << endl;
}

string tellIsUserOrAdminRole(bool role)
{
	if (role)
	{
		return "администратор";
	}
	return "пользователь";
}

string tellIsActiveOrWaitOrBannedAccess(int access)
{
	if (access == 1)
	{
		return "разрешен";
	}
	else if (access == 0)
	{
		return "запрос";
	}
	return "запрещен";
}

void addAccount(vector <Account>& vec_of_accounts, bool is_from_admin)
{
	Account temp_account;
	string login, password;
	while (true)
	{
		cout << "Логин: ";
		login = enterStringWithoutSpaces();
		if (isGoodLogin(vec_of_accounts, login))
		{
			temp_account.login = login;
			break;
		}
		else
		{
			system("cls");
			cout << "\nТакой логин уже существует! Введите другой.";
		}
	}
	cout << "\nПароль: ";
	password = enterStringWithoutSpaces();
	temp_account.salt = generateSalt(SALT_SIZE);
	temp_account.salted_hash_password = hashPassword(password, temp_account.salt);
	cout << "\nРоль (Пользователь - 0, Админ - 1): ";
	int role;
	role = enterNumberInRange(0, 1);
	temp_account.role = role;
	if (is_from_admin)
	{
		temp_account.access = 1;
		cout << "Учётная запись создана!" << endl;
		system("pause");
	}
	else
	{
		system("cls");
		cout << "Учётная запись создана! Ожидйте подтверждения администратором." << endl;
	}
	vec_of_accounts.push_back(temp_account);
}

void deleteAccount(vector <Account>& vec_of_accounts, int index_of_user)
{
	int answer, index_for_delete;
	cout << "Какой аккаунт вы хотите удалить?\n Отмена - 0" << endl;
	index_for_delete = indexOfVectorForChange(vec_of_accounts);
	if (index_for_delete != 0)
	{
		index_for_delete--;
		if (index_for_delete != index_of_user)
		{
			system("cls");
			cout << "Вы действительно хотите удалить аккаунт " << vec_of_accounts.at(index_for_delete).login << "? \nДа - 1 \nНет - 0" << endl;
			answer = enterNumberInRange(0, 1);
			if (answer == 1)
			{
				vec_of_accounts.erase(vec_of_accounts.begin() + index_for_delete);
				cout << "Успешно удалён!" << endl;
				system("pause");
			}
		}
		else
		{
			cout << "Нельзя удалить самого себя! Обратитесь к другому администратору." << endl;
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
		cout << "Осталось попыток: " << NUMBER_OF_ATTEMPTS - i << endl;
		cout << "Введите логин: ";
		login = enterStringWithoutSpaces();
		cout << "\nВведите пароль: ";
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
				cout << "Ваша учетная запись ещё не подтверждена администратором, доступ запрещён." << endl;
				return -1;
			}
			else
			{
				cout << "Ваша учетная запись заблокирована, доступ запрещён." << endl;
				return -2;
			}
		}
		else
		{
			cout << "Введён неверный логин или пароль! Повторите попытку." << endl;
		}
	}
	cout << "Доступ запрещён. Завершение работы..." << endl;
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
		cout << "Осталось попыток: " << NUMBER_OF_ATTEMPTS - i << endl;
		cout << "Введите текущий пароль: ";
		password = enterGoodPassword();
		if (isPasswordEquals(vec_of_accounts, password, index_of_user))
		{
			cout << "\nВведите новый пароль: ";
			password = enterStringWithoutSpaces();
			vec_of_accounts.at(index_of_user).salt = generateSalt(SALT_SIZE);
			vec_of_accounts.at(index_of_user).salted_hash_password = hashPassword(password, vec_of_accounts.at(index_of_user).salt);
			system("cls");
			cout << "\nПароль изменён успешно!" << endl;
			system("pause");
			break;
		}
		else
		{
			system("cls");
			cout << "Введён неверный пароль! Повторите попытку." << endl;
		}
	}
	system("cls");
}

int updateIndexOfUser(vector <Account>& vec_of_accounts, string login_of_user)
{
	for (unsigned int i = 0; i < vec_of_accounts.size(); i++)
	{
		if (login_of_user == vec_of_accounts.at(i).login)
		{
			return i;
		}
	}
	return -1;
}

void confirmAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array)
{
	int number;
	cout << "Выберите учётную запись, которую вы хотите подтвердить:" << endl;
	cout << " Назад - 0" << endl;
	number = enterNumberInRange(0, array.size());
	if (number != 0)
	{
		number--;
		vec_of_accounts.at(array.at(number)).access = 1;
		array.erase(array.begin() + number);
		system("cls");
		cout << "Учётная запись подтверждена." << endl;
		system("pause");
	}
}

void rejectAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array)
{
	int number;
	cout << "Выберите учётную запись, которой вы хотите заблокировать доступ:" << endl;
	cout << " Назад - 0" << endl;
	number = enterNumberInRange(0, array.size());
	if (number != 0)
	{
		number--;
		vec_of_accounts.at(array.at(number)).access = -1;
		array.erase(array.begin() + number);
		system("cls");
		cout << "Учётная запись заблокирована." << endl;
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
		cout << "Файла с учетными записями не существует! Создан новый с учётной записью администратора." << endl;
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
			cout << "Файл пуст! Создана учётная запись администратора." << endl;
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
	cout << "Какому аккаунту вы хотите изменить доступ?\n Отмена - 0" << endl;
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
			cout << "Нельзя изменить доступ самому себе! Обратитесь к другому администратору." << endl;
			system("pause");
		}
	}
}

void updateAccountRole(vector <Account>& vec_of_accounts, int index_of_user)
{
	cout << "Какому аккаунту вы хотите изменить роль?\n Отмена - 0" << endl;
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
			cout << "Нельзя изменить роль самому себе! Обратитесь к другому администратору." << endl;
			system("pause");
		}
	}
}
