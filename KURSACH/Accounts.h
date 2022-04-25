#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Validations.h"
#include "Menus.h"
#include "sha256.h"
using namespace std;
const int NUMBER_OF_ATTEMPTS = 3;
const string FILE_OF_ACCOUNTS = "accounts.txt";
const string ADMIN_LOGIN = "ADMIN";
const string ADMIN_PASSWORD = "BSUIR";
const bool ADMIN_ROLE = 1;
const int ADMIN_ACCESS = 1;
const string SEPARATOR = "|-------+-----------------+--------------|";
const string SEPARATOR_ACCOUNT = "|-------+-----------------+--------------+----------|";
const int MAX_OF_RANGE_MENU_ADMIN = 6;
const int MAX_OF_RANGE_MENU_ADMIN_WITHOUT_ACCESS = 5;

struct Account
{
	string login;
	string salted_hash_password;
	string salt;
	bool role = false;
	int access = 0;
};

void showAccounts(vector <Account>& vec_of_accounts);
void showRequestsOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array);
void addAccount(vector <Account>& vec_of_accounts, bool is_from_admin = false);
void deleteAccount(vector <Account>& vec_of_accounts, int index_of_user);
int indexOfVectorForChange(vector <Account>& vec_of_accounts);
bool isGoodLogin(vector <Account>& vec_of_accounts, string login);
bool isPasswordEquals(vector <Account>& vec_of_accounts, string password, int index_of_user);
bool isLoginEquals(vector <Account>& vec_of_accounts, string login, int index_of_user);
int enterAccount(vector <Account>& vec_of_accounts);
int checkDataEquals(vector <Account>& vec_of_accounts, string login, string password);
int updateIndexOfUser(vector <Account>& vec_of_accounts, string login_of_user);
void changePassword(vector <Account>& vec_of_accounts, int index_of_user);
void confirmAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array);
void rejectAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array);
void fillVectorOfAccountsNeedAccess(vector <Account>& vec_of_accounts, vector <int>& array);
void createFirstAccount(vector <Account>& vec_of_accounts);
void readFileOfAccounts(vector <Account>& vec_of_accounts);
void writeFileOfAccounts(vector <Account>& vec_of_accounts);
void updateAccountAccess(vector <Account>& vec_of_accounts, int index_of_user);
void updateAccountRole(vector <Account>& vec_of_accounts, int index_of_user);
string tellIsUserOrAdminRole(bool role);
string tellIsActiveOrWaitOrBannedAccess(int access);