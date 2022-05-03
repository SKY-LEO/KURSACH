#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

#include "Validations.h"
#include "sha256.h"

using namespace std;

struct Account
{
	string login;
	string salted_hash_password;
	string salt;
	bool role = false;
	int access = 0;
};

const int NUMBER_OF_ATTEMPTS = 3;
const string FILE_OF_ACCOUNTS = "accounts.txt";

const bool ADMIN_ROLE = true;
const int ADMIN_ACCESS = 1;
const string ADMIN_LOGIN = "ADMIN";
const string ADMIN_PASSWORD = "BSUIR";
const string SEPARATOR = "|-------+-----------------+--------------|";
const string SEPARATOR_ACCOUNT = "|-------+-----------------+--------------+----------|";

void createFirstAccount(vector <Account>& vec_of_accounts);

void addAccount(vector <Account>& vec_of_accounts, bool is_from_admin = false);
string enterLogin(vector <Account>& vec_of_accounts);
bool isGoodLogin(vector <Account>& vec_of_accounts, string login);
void setLogin(vector <Account>& vec_of_accounts, Account& temp_account);
string enterPassword();
void setPassword(Account& temp_account);
void setSalt(Account& temp_account);
void setRole(Account& temp_account);

int enterAccount(vector <Account>& vec_of_accounts);
int checkDataEquals(vector <Account>& vec_of_accounts, string login, string password);
bool isLoginEquals(vector <Account>& vec_of_accounts, string login, int index_of_user);
bool isPasswordEquals(vector <Account>& vec_of_accounts, string password, int index_of_user);

void showAccounts(vector <Account>& vec_of_accounts);
string tellIsUserOrAdminRole(bool role);
string tellIsActiveOrWaitOrBannedAccess(int access);

int indexOfVectorForChange(vector <Account>& vec_of_accounts);
void deleteAccount(vector <Account>& vec_of_accounts, int index_of_user);
int updateIndexOfUser(vector <Account>& vec_of_accounts, string login_of_user);
void updateAccountAccess(vector <Account>& vec_of_accounts, int index_of_user);
void updateAccountRole(vector <Account>& vec_of_accounts, int index_of_user);
void changePassword(vector <Account>& vec_of_accounts, int index_of_user);

void showRequestsOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array);
void fillVectorOfAccountsNeedAccess(vector <Account>& vec_of_accounts, vector <int>& array);
void confirmAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array);
void rejectAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array);

void readFileOfAccounts(vector <Account>& vec_of_accounts);
void writeFileOfAccounts(vector <Account>& vec_of_accounts);
int getCountOfStructuresAccount(string file_path);