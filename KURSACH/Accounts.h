#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

#include "Validations.h"//реализация различных проверок на некорректный ввод
#include "sha256.h"//хэширование пароля

using namespace std;

//структура учетной записи
struct Account
{
	string login;//логин
	string salted_hash_password;//хэшированный с солью пароль  
	string salt;//соль для пароля
	bool role = false;//роль: true - админ, false - пользователь (по умолчанию)
	int access = 0;//доступ в систему: 1 - разрешен, 0 - ожидает подтверждения, в систему войти нельзя, -1 - заблокирован 
};

const int NUMBER_OF_ATTEMPTS = 3;//количество попыток при вводе пароля
const string FILE_OF_ACCOUNTS = "accounts.txt";//название файла с учетными записями

//при отсутствии файла с учетными записями создается новый, с аккаунтом админа с данными значениями
const bool ADMIN_ROLE = true;
const int ADMIN_ACCESS = 1;
const string ADMIN_LOGIN = "ADMIN";
const string ADMIN_PASSWORD = "BSUIR";

//для таблиц
const string SEPARATOR = "|-------+-----------------+--------------|";
const string SEPARATOR_ACCOUNT = "|-------+-----------------+--------------+----------|";

//функции
void createFirstAccount(vector <Account>& vec_of_accounts);//при отсутствии файла с учетными записями функция создает новый, с аккаунтом админа

void addAccount(vector <Account>& vec_of_accounts, bool is_from_admin = false);//создание нового аккаунта, если создается через меню админа,
																			   //то сразу разрешается доступ в систему (access = 1)
string enterLogin(vector <Account>& vec_of_accounts);//функция ввода логина
bool isGoodLogin(vector <Account>& vec_of_accounts, string login);//проверка на уникальность логина
void setLogin(vector <Account>& vec_of_accounts, Account& temp_account);//присвоение логина учетной записи
string enterPassword();//функция ввода пароля
void setPassword(Account& temp_account);//присвоение пароля учетной записи
void setSalt(Account& temp_account);//присвоение соли учетной записи
void setRole(Account& temp_account);//присвоение роли учетной записи

int enterAccount(vector <Account>& vec_of_accounts);//функция входа в аккаунт
int checkDataEquals(vector <Account>& vec_of_accounts, string login, string password);//проверка на совпадение логина и пароля с данными из файла
bool isLoginEquals(vector <Account>& vec_of_accounts, string login, int index_of_user);//проверка на совпадение логина с данными из файла
bool isPasswordEquals(vector <Account>& vec_of_accounts, string password, int index_of_user);//проверка на совпадение пароля с данными из файла

void showAccounts(vector <Account>& vec_of_accounts);//вывод в консоль данных обо всех аккаунтах 
string tellIsUserOrAdminRole(bool role);//перевод bool role true/false в администратор/пользователь
string tellIsActiveOrWaitOrBannedAccess(int access);//перевод int access 1/0/-1 в разрешен/ожидает/заблокирован

int indexOfVectorForChange(vector <Account>& vec_of_accounts);//выбор аккаунта для редактирования
void deleteAccount(vector <Account>& vec_of_accounts, int index_of_user);//удаление выбранного аккаунта
int updateIndexOfUser(vector <Account>& vec_of_accounts, string login_of_user);//обновление индекса текущего пользователя в векторе при сортировке
void updateAccountAccess(vector <Account>& vec_of_accounts, int index_of_user);//редактирование доступа выбранного аккаунта
void updateAccountRole(vector <Account>& vec_of_accounts, int index_of_user);//редактирование роли выбранного аккаунта
void changePassword(vector <Account>& vec_of_accounts, int index_of_user);//изменение пароля текущего пользователя

void showRequestsOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array);//вывод в консоль данных об аккаунтах, ожидающих подтверждения на доступ 
void fillVectorOfAccountsNeedAccess(vector <Account>& vec_of_accounts, vector <int>& array);//создание дополнительного вектора с индексами аккаунтов, 
																							//ожидающих подтверждения на доступ
void confirmAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array);//функция подтверждения запроса на доступ в систему
void rejectAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array);//функция отклонения запроса на доступ в систему

void readFileOfAccounts(vector <Account>& vec_of_accounts);//функция заполнения вектора данными из файла
void writeFileOfAccounts(vector <Account>& vec_of_accounts);//функция записи в файл данных из вектора
int getCountOfStructuresAccount(string file_path);//определение количества струтур в файле для резервирования места в векторе