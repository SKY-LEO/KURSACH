#pragma once
#include <iostream>
#include <vector>
#include "Validations.h"
#include "Menus.h"
#include "sha256.h"
using namespace std;
const string ACCOUNT_MENU_ADMIN = " �� ���������� � ���� ������ � �������� ��������.\n1) �����������\n2) �������\n3) �������� ������\n4) �������� ����\n5) ������� �������\n6) ������� �� ������";// ����� - 0";
//const string ACCOUNT_MENU_ADMIN_WITHOUT_ACCESS = " �� ���������� � ���� ������ � �������� ��������.\n �������� - 1 \n ������� - 2\n �������� ������ - 3\n �������� ���� - 4\n ����� - 0";
const string ACCOUNT_MENU_ADMIN_WITHOUT_ACCESS = " �� ���������� � ���� ������ � �������� ��������.\n1) �����������\n2) �������\n3) �������� ������\n4) �������� ����\n5) ������� �������\n0) �����";
const string MENU_OF_ACCESS = "\n1) ����������� ������\n2) ������������� ������\n0) �����";
const string MENU_OF_SORTS_ACCOUNTS = "����������� ��:\n1) ������\n2) ����\n3) �������\n0) �����";
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
