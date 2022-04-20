#pragma once
#include <iostream>
#include <vector>
#include "Validations.h"
#include "Menus.h"
#include "sha256.h"
using namespace std;
const string ACCOUNT_MENU_ADMIN = " Вы находитесь в меню работы с учётными записями.\n1) Сортировать\n2) Удалить\n3) Изменить доступ\n4) Изменить роль\n5) Создать аккаунт\n6) Запросы на доступ";// Выход - 0";
//const string ACCOUNT_MENU_ADMIN_WITHOUT_ACCESS = " Вы находитесь в меню работы с учётными записями.\n Просмотр - 1 \n Удалить - 2\n Изменить доступ - 3\n Изменить роль - 4\n Выход - 0";
const string ACCOUNT_MENU_ADMIN_WITHOUT_ACCESS = " Вы находитесь в меню работы с учётными записями.\n1) Сортировать\n2) Удалить\n3) Изменить доступ\n4) Изменить роль\n5) Создать аккаунт\n0) Назад";
const string MENU_OF_ACCESS = "\n1) Подтвердить доступ\n2) Заблокировать доступ\n0) Назад";
const string MENU_OF_SORTS_ACCOUNTS = "Сортировать по:\n1) Логину\n2) Роли\n3) Доступу\n0) Назад";
const string SEPARATOR = "------------------------------------------------";
const int MAX_OF_RANGE_MENU_ADMIN = 6;
const int MAX_OF_RANGE_MENU_ADMIN_WITHOUT_ACCESS = 5;

struct Account
{
	string login;
	string salted_hash_password;
	string salt;
	bool role = false;//
	//bool access = false;
	int access = 0;
};

void showAccounts(vector <Account>& vec_of_accounts);
void addAccount(vector <Account>& vec_of_accounts, bool is_from_admin = false);
void deleteAccount(vector <Account>& vec_of_accounts, int index_of_user);
int IndexOfAccountForChange(vector <Account>& vec_of_accounts);
bool isGoodLogin(vector <Account>& vec_of_accounts, string login);
