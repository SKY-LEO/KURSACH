/*
23. Разработка программы расчета стипендии
Для расчета стипендии необходимо обработать информацию следующего вида : номер группы, Ф.И.О.студента,
форма обучения(платная / бюджетная), зачеты по пяти предметам(зачет / незачет), оценки по 4 предметам,
признак участия в общественной работе : 1 – активное участие, 0 – неучастие.
Индивидуальное задание : рассчитать стипендию для студентов - бюджетников.
При этом : отличники(отметки 9, 10) и общественники получают 50 % надбавку, а просто отличники – 25 % .
Студенты со средним баллом, равным или ниже 5, стипендию не получают.Базовый размер стипендии вводится с клавиатуры.
Общее для всех вариантов задание : реализовать авторизацию для входа в систему, функционал администратора и функционал пользователя(см.более подробно в функциональных требованиях к курсовой работе в ТРПО Курсовое проектирование.Пособие).
*/

#include <Windows.h>

#include <vector>
//#include <fstream>//потом убрать
#include <iostream>//потом убрать
//#include <string>//потом убрать
//#include <conio.h>//потом убрать
#include <algorithm>//потом убрать

//----hash----
//#include "sha256.h"//потом убрать
//----hash----
#include "Accounts.h"
#include "Students.h"
#include "Validations.h"//потом убрать
//#include "Menus.h"
//template <class To>
//using namespace std;//потом убрать

//const string ADMIN_LOGIN = "ADMIN";
//const string ADMIN_PASSWORD = "BSUIR";
//const bool ADMIN_ROLE = 1;
//const bool ADMIN_ACCESS = 1;
//const int ADMIN_ACCESS = 1;

//const string FILE_OF_ACCOUNTS = "accounts.txt";
//const string FILE_OF_STUDENTS = "students.txt";
//const int NUMBER_OF_SYMBOLS = 20;
//const int NUMBER_OF_ATTEMPTS = 3;

//const string SEPARATOR = "------------------------------------------------";

//const string MAIN_MENU_ADMIN = "\n Стипендии - 1\n Работа с учётными записями - 2\n Сменить пароль - 3\n Выход - 0";
const string MAIN_MENU_ADMIN = "\n1) Стипендии\n2) Работа с учётными записями\n3) Сменить пароль\n0) Выход";
//const string ACCOUNT_MENU_ADMIN = " Вы находитесь в меню работы с учётными записями.\n Просмотр - 1\n Удалить - 2\n Изменить доступ - 3\n Изменить роль - 4\n Запросы на доступ - 5\n Выход - 0";
//const string ACCOUNT_MENU_ADMIN = " Вы находитесь в меню работы с учётными записями.\n Удалить - 1\n Изменить доступ - 2\n Изменить роль - 3\n Запросы на доступ - 4\n Выход - 0";
//const string ACCOUNT_MENU_ADMIN_WITHOUT_ACCESS = " Вы находитесь в меню работы с учётными записями.\n Удалить - 1\n Изменить доступ - 2\n Изменить роль - 3\n Выход - 0";
//const string MAIN_MENU_USER = "\n Стипендии - 1\n Сменить пароль - 2\n Выход - 0";
const string MAIN_MENU_USER = "\n1) Стипендии\n2) Сменить пароль\n0) Выход";
//const string START_MENU = "\n Войти в существующую учётную запись - 1\n Создать новую учётную запись - 2\n Завершение работы - 0";
const string START_MENU = "\n1) Войти в существующую учётную запись\n2) Создать новую учётную запись\n0) Завершение работы";
//const string STUDENT_MENU_ADMIN = "\n1) Расчет стипендии\n2) Поиск\n3) Сортировка\n4) Добавить студента\n5) Редактировать данные\n6) Удалить студента\n0) Назад";
//const string STUDENT_MENU_USER = "\n1) Расчет стипендии\n2) Поиск\n3) Сортировка\n0) Назад";
const string MENU_OF_ASCENDING_DESCENDING = "Упорядочить по:\n1) Возрастанию\n2) Убыванию";
const string ERROR_MESSAGE = "Ошибка!";
/*const string OAIP = "ОАиП";
const string MATH = "МА";
const string ENGLISH = "ИнЯз";
const string PHYSICS = "Физика";
const string OOPIP = "ООПиП";
const string DISCRETE_MATH = "ДМ";
const string INAD = "ИнАД";
const string HISTORY = "Ист";
const string PHYS_CULTURE = "ФизК";*/
/*
const string ACCOUNT_MENU_ADMIN = " Вы находитесь в меню работы с учётными записями.\n1) Сортировать\n2) Удалить\n3) Изменить доступ\n4) Изменить роль\n5) Создать аккаунт\n6) Запросы на доступ";// Выход - 0";
//const string ACCOUNT_MENU_ADMIN_WITHOUT_ACCESS = " Вы находитесь в меню работы с учётными записями.\n Просмотр - 1 \n Удалить - 2\n Изменить доступ - 3\n Изменить роль - 4\n Выход - 0";
const string ACCOUNT_MENU_ADMIN_WITHOUT_ACCESS = " Вы находитесь в меню работы с учётными записями.\n1) Сортировать\n2) Удалить\n3) Изменить доступ\n4) Изменить роль\n5) Создать аккаунт\n0) Назад";
const string MENU_OF_ACCESS = "\n1) Подтвердить доступ\n2) Заблокировать доступ\n0) Назад";
const string MENU_OF_SORTS_ACCOUNTS = "Сортировать по:\n1) Логину\n2) Роли\n3) Доступу\n0) Назад";
const int MAX_OF_RANGE_MENU_ADMIN = 6;
const int MAX_OF_RANGE_MENU_ADMIN_WITHOUT_ACCESS = 5;
*/
const string ACCOUNT_MENU_ADMIN = " Вы находитесь в меню работы с учётными записями.\n1) Сортировать\n2) Удалить\n3) Изменить доступ\n4) Изменить роль\n5) Создать аккаунт\n6) Запросы на доступ";// Выход - 0";
//const string ACCOUNT_MENU_ADMIN_WITHOUT_ACCESS = " Вы находитесь в меню работы с учётными записями.\n Просмотр - 1 \n Удалить - 2\n Изменить доступ - 3\n Изменить роль - 4\n Выход - 0";
const string ACCOUNT_MENU_ADMIN_WITHOUT_ACCESS = " Вы находитесь в меню работы с учётными записями.\n1) Сортировать\n2) Удалить\n3) Изменить доступ\n4) Изменить роль\n5) Создать аккаунт\n0) Назад";
const string MENU_OF_ACCESS = "\n1) Подтвердить доступ\n2) Заблокировать доступ\n0) Назад";
const string MENU_OF_SORTS_ACCOUNTS = "Сортировать по:\n1) Логину\n2) Роли\n3) Доступу\n0) Назад";
const string MENU_OF_SORTS_STUDENTS = "Сортировать по:\n1) Фамилии\n2) Номеру группы\n3) Среднему баллу\n4) Стипендии\n5) Сдаче зачетов\n6) Сдаче экзаменов\n7) Форме обучения\n8) Участию в общественной работе\n0) Назад";
const string MENU_OF_SORTS_STUDENTS_OFFSETS = "Выберите предмет:\n1) ООПиП\n2) ДМ\n3) ИнАД\n4) Ист\n5) ФизК\n0) Назад";
const string MENU_OF_SORTS_STUDENTS_EXAMS = "Выберите предмет:\n1) ОАиП\n2) МА\n3) ИнЯз\n4) Физика\n0) Назад";
const int MAX_OF_RANGE_MAIN_MENU_ADMIN = 3;
const int MAX_OF_RANGE_MAIN_MENU_USER = 2;
const int MAX_OF_START_MENU = 2;
const int MAX_OF_RANGE_MENU_ACCESS = 2;
const int MAX_OF_RANGE_MENU_OF_SORTS_ACCOUNTS = 3;
const int MAX_OF_RANGE_MENU_OF_ASCENDING_DESCENDING = 2;
const int MAX_OF_STUDENT_MENU_ADMIN = 6;
const int MAX_OF_STUDENT_MENU_USER = 3;
const int MAX_OF_RANGE_MENU_OF_SORTS_STUDENTS = 8;
const int MAX_OF_RANGE_MENU_OF_SORTS_STUDENTS_OFFSETS = 5;
const int MAX_OF_RANGE_MENU_OF_SORTS_STUDENTS_EXAMS = 4;
/*const int MIN_EXAM = 4;
const int MAX_EXAM = 10;
const int MIN_OFFSET = 0;
const int MAX_OFFSET = 1;
*/
//const string ACCESS[3] = { "Какому аккаунту вы хотите изменить доступ?", "Вы действительно хотите изменить доступ этому аккаунту?", "Изменён успешно!" };
//const string ROLE[3] = { "Какому аккаунту вы хотите изменить роль?", "Вы действительно хотите изменить роль этому аккаунту?", "Изменена успешно!" };
//const string DELETE_ACCOUNT[3] = { "Какой аккаунт вы хотите удалить?", "Вы действительно хотите удалить этот аккаунт?", "Удалён успешно!" };


/*struct Account
{
	string login;
	string salted_hash_password;
	string salt;
	bool role = false;//
	//bool access = false;
	int access = 0;
};*/
/*
struct Offsets
{
	bool oopip;
	bool discrete_math;
	bool inad;
	bool history;
	bool phys_culture;
};

struct Exams
{
	int oaip;
	int math;
	int english;
	int physics;
};

struct Student
{
	string FIO;
	string num_of_group;
	Offsets offset;
	Exams exam;
	bool is_budget_student;
	bool is_social_work;
};
*/

/*typedef void(*ToFunction)(vector <Account>& vec_of_accounts, int index_for_change);
void updateAccountAccess(vector <Account>& vec_of_accounts, int index_for_change);
void updateAccountRole(vector <Account>& vec_of_accounts, int index_for_change);
void deleteAccount(vector <Account>& vec_of_accounts, int index_for_delete);
void doSomethingWithAccount(vector <Account>& vec_of_accounts, const string* message, ToFunction function);*/


//void showAccounts(vector <Account>& vec_of_accounts);
//void addAccount(vector <Account>& vec_of_accounts, bool is_from_admin = false);
//void deleteAccount(vector <Account>& vec_of_accounts, int index_of_user);

//void updateAccount(vector <Account>& vec_of_accounts);
void core(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students);
//void readFileOfAccounts(vector <Account>& vec_of_accounts);
//void readFileOfStudents(vector <Student>& vec_of_students);
//void writeFileOfAccounts(vector <Account>& vec_of_accounts);
//void writeFileOfStudents(vector <Student>& vec_of_students);
int getCountOfStructures(string file_path);
//int correctInputInt();
//int menu(vector <Account>& vec_of_accounts, string message, int max_of_range);
//int chooseMenu(string message, int max_of_range);
int initialisation(vector <Account>& vec_of_accounts);
//int enterAccount(vector <Account>& vec_of_accounts);
//int checkDataEquals(vector <Account>& vec_of_accounts, string login, string password);
//string hashPassword(string password, string salt);
//string enterGoodPassword();
//string enterStringWithoutSpaces();
//bool isGoodLogin(vector <Account>& vec_of_accounts, string login);
//void createFirstAccount(vector <Account>& vec_of_accounts);
//int enterNumberInRange(int min, int max);
//void confirmAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array);
int user(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students, int index_of_user);
int admin(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students, int index_of_user);
void workWithStudents(vector <Student>& vec_of_students, bool is_admin);
//void changePassword(vector <Account>& vec_of_accounts, int index_of_user);
void workWithAccounts(vector <Account>& vec_of_accounts, int& index_of_user);
//bool isPasswordEquals(vector <Account>& vec_of_accounts, string password, int index_of_user);
//bool isLoginEquals(vector <Account>& vec_of_accounts, string login, int index_of_user);
//void fillVectorOfAccountsNeedAccess(vector <Account>& vec_of_accounts, vector <int>& array);
//void updateAccountRole(vector <Account>& vec_of_accounts, int index_of_user);
//void updateAccountAccess(vector <Account>& vec_of_accounts, int index_of_user);
//int indexOfVectorForChange(vector <Account>& vec_of_accounts);
//int updateIndexOfUser(vector <Account>& vec_of_accounts, string login_of_user);

void workWithAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array);

//void rejectAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array);
void sortAccountsBy(vector <Account>& vec_of_accounts, bool (*comparisonFunction)(Account, Account));
bool mySortByAccessAscending(Account acc_1, Account acc_2);
bool mySortByAccessDescending(Account acc_1, Account acc_2);
bool mySortByRoleAscending(Account acc_1, Account acc_2);
bool mySortByRoleDescending(Account acc_1, Account acc_2);
bool mySortByLoginAscending(Account acc_1, Account acc_2);
bool mySortByLoginDescending(Account acc_1, Account acc_2);
void sortAccounts(vector <Account>& vec_of_accounts);
bool isAscending();

void sortStudents(vector <Student>& vec_of_students);
void sortStudentsBy(vector <Student>& vec_of_students, bool (*comparisonFunction)(Student, Student));
bool mySortBySurnameAscending(Student stu_1, Student stu_2);
bool mySortBySurnameDescending(Student stu_1, Student stu_2);
bool mySortByGroupNumberAscending(Student stu_1, Student stu_2);
bool mySortByGroupNumberDescending(Student stu_1, Student stu_2);
bool mySortByAverageScoreAscending(Student stu_1, Student stu_2);
bool mySortByAverageScoreDescending(Student stu_1, Student stu_2);
bool mySortByStipendAscending(Student stu_1, Student stu_2);
bool mySortByStipendDescending(Student stu_1, Student stu_2);
bool mySortByFormOfEducationAscending(Student stu_1, Student stu_2);
bool mySortByFormOfEducationDescending(Student stu_1, Student stu_2);
bool mySortBySocialWorkAscending(Student stu_1, Student stu_2);
bool mySortBySocialWorkDescending(Student stu_1, Student stu_2);
//bool mySortByAscending(Student stu_1, Student stu_2, string Student::* x);
//bool mySortByDescending(Student stu_1, Student stu_2, string Student::* x);
void sortStudents(vector <Student>& vec_of_students);
void sortStudentOffsets(vector <Student>& vec_of_students);
bool mySortByOopipAscending(Student stu_1, Student stu_2);
bool mySortByOopipDescending(Student stu_1, Student stu_2);
bool mySortByDiscreteMathAscending(Student stu_1, Student stu_2);
bool mySortByDiscreteMathDescending(Student stu_1, Student stu_2);
bool mySortByInadAscending(Student stu_1, Student stu_2);
bool mySortByInadDescending(Student stu_1, Student stu_2);
bool mySortByHistoryAscending(Student stu_1, Student stu_2);
bool mySortByHistoryDescending(Student stu_1, Student stu_2);
bool mySortByPhysCultureAscending(Student stu_1, Student stu_2);
bool mySortByPhysCultureDescending(Student stu_1, Student stu_2);
void sortStudentExams(vector <Student>& vec_of_students);
bool mySortByOaipAscending(Student stu_1, Student stu_2);
bool mySortByOaipDescending(Student stu_1, Student stu_2);
bool mySortByMathAscending(Student stu_1, Student stu_2);
bool mySortByMathDescending(Student stu_1, Student stu_2);
bool mySortByEnglishAscending(Student stu_1, Student stu_2);
bool mySortByEnglishDescending(Student stu_1, Student stu_2);
bool mySortByPhysicsAscending(Student stu_1, Student stu_2);
bool mySortByPhysicsDescending(Student stu_1, Student stu_2);
//void sortStudentsBy(vector <Student>& vec_of_students, bool (*comparisonFunction)(Student, Student, string Student::* x));

//void showStudents(vector <Student>& vec_of_students);
//void calculateStipends(vector <Student>& vec_of_students);
//void sortStudents(vector <Student>& vec_of_students);
//void searchStudents(vector <Student>& vec_of_students);
//void addStudent(vector <Student>& vec_of_students);
//void editStudent(vector <Student>& vec_of_students);
//void deleteStudent(vector <Student>& vec_of_students);
//int indexOfVectorForChange(vector <Student>& vec_of_students);
//bool isGoodFio(vector <Student>& vec_of_students, string fio);
//string enterStringWithoutNumbers();
//void setOffsets(Student& temp_student);
//void setExams(Student& temp_student);
//int rateStudent(int min_range, int max_of_range, string subject);

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
	cout << "Здравствуйте, гость! Пожалуйста, выберите пункт меню:" << endl;
	cout << START_MENU << endl;
	int item = enterNumberInRange(0, MAX_OF_START_MENU);
	system("cls");
	switch (item)
	{
	case 1:
		return enterAccount(vec_of_accounts);
	case 2:
		addAccount(vec_of_accounts);
		return initialisation(vec_of_accounts);
	case 0:
		return -2;
	default: cout << ERROR_MESSAGE << endl;
		return item;
	}
}

/*int enterAccount(vector <Account>& vec_of_accounts)
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
				cout << "\nВаша учетная запись ещё не подтверждена администратором, доступ запрещён." << endl;
				return -1;
			}
			else
			{
				cout << "\nВаша учетная запись заблокирована, доступ запрещён." << endl;
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
}*/

/*string enterGoodPassword()
{
	char symbol;
	string password;
	while ((symbol = _getch()) != '\r')//пока вводимый символ не равен сиволу переноса каретки(enter)
	{
		if (symbol == '\b')//backspace
		{
			if (!password.empty())
			{
				cout << '\b' << ' ' << '\b';
				password.erase(password.length() - 1);
			}
			continue;
		}
		password += symbol;
		cout << '*';
	}
	return password;
}*/

/*string enterStringWithoutSpaces()
{
	char symbol;
	string buffer;
	while ((symbol = _getch()) != '\r')//пока вводимый символ не равен сиволу переноса каретки(enter)
	{
		if (symbol == '\b')//backspace
		{
			if (!buffer.empty())
			{
				cout << "\b \b";
				buffer.erase(buffer.length() - 1);
			}
			continue;
		}
		if (symbol == ' ')
		{
			continue;
		}
		buffer += symbol;
		cout << symbol;
	}
	return buffer;
}*/

/*string hashPassword(string password, string salt)
{
	return sha256(sha256(password + salt) + sha256(password));
}*/

/*bool isGoodLogin(vector <Account>& vec_of_accounts, string login)
{
	for (unsigned int i = 0; i < vec_of_accounts.size(); i++)
	{
		if (login == vec_of_accounts.at(i).login)
		{
			return 0;
		}
	}
	return 1;
}*/

void core(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students)
{
	int code, index_of_user;
	bool flag = true;
	while (flag)
	{
		index_of_user = initialisation(vec_of_accounts);
		if (index_of_user > -1)//если не код ошибки
		{
			code = vec_of_accounts.at(index_of_user).role;
		}
		else
		{
			code = index_of_user;
		}
		switch (code)
		{
		case 0:
			system("cls");
			user(vec_of_accounts, vec_of_students, index_of_user);
			break;
		case 1:
			system("cls");
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
		case 1:
			system("cls");
			workWithStudents(vec_of_students, false);
			break;
		case 2:
			system("cls");
			changePassword(vec_of_accounts, index_of_user);
			break;
		case 0:
			flag = false;
			break;
		default: cout << ERROR_MESSAGE << endl;
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
		case 1:
			system("cls");
			workWithStudents(vec_of_students, true);
			break;
		case 2:
			system("cls");
			workWithAccounts(vec_of_accounts, index_of_user);
			break;
		case 3:
			system("cls");
			changePassword(vec_of_accounts, index_of_user);
			break;
		case 0:
			flag = false;
			break;
		default: cout << ERROR_MESSAGE << endl;
		}
	}
	system("cls");
	return 0;
}

/*void changePassword(vector <Account>& vec_of_accounts, int index_of_user)
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
}*/

/*bool isPasswordEquals(vector <Account>& vec_of_accounts, string password, int index_of_user)
{
	return vec_of_accounts.at(index_of_user).salted_hash_password == hashPassword(password, vec_of_accounts.at(index_of_user).salt);
}

bool isLoginEquals(vector <Account>& vec_of_accounts, string login, int index_of_user)
{
	return vec_of_accounts.at(index_of_user).login == login;
}*/

/*int checkDataEquals(vector <Account>& vec_of_accounts, string login, string password)
{
	for (unsigned int index = 0; index < vec_of_accounts.size(); index++)
	{
		if (isLoginEquals(vec_of_accounts, login, index) && isPasswordEquals(vec_of_accounts, password, index))
		{
			return index;
		}
	}
	return -1;
}*/

void workWithAccounts(vector <Account>& vec_of_accounts, int& index_of_user)
{
	string login_of_user = vec_of_accounts.at(index_of_user).login;
	bool flag = true, update_access = true;
	int item, size_of_array;
	vector <int> array;
	while (flag)
	{
		system("cls");
		showAccounts(vec_of_accounts);
		if (update_access)//если удален аккаунт без доступа к системе или изменён доступ, то надо обновить массив аккаунтов, требующих подтверждения
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
			cout << ACCOUNT_MENU_ADMIN << "(Новых запросов: " << size_of_array << ")\n0) Назад" << endl;
			item = enterNumberInRange(0, MAX_OF_RANGE_MENU_ADMIN);
		}
		switch (item)
		{
		case 1:
			system("cls");
			sortAccounts(vec_of_accounts);
			index_of_user = updateIndexOfUser(vec_of_accounts, login_of_user);
			update_access = true;
			break;
		case 2:
			deleteAccount(vec_of_accounts, index_of_user);
			update_access = true;
			break;
		case 3:
			updateAccountAccess(vec_of_accounts, index_of_user);
			update_access = true;
			break;
		case 4:
			updateAccountRole(vec_of_accounts, index_of_user);
			break;
		case 5:
			system("cls");
			addAccount(vec_of_accounts, true);
			break;
		case 6:
			system("cls");
			workWithAccessOfAccounts(vec_of_accounts, array);
			break;
		case 0: flag = false;
			break;
		default: cout << ERROR_MESSAGE << endl;
		}
	}
	system("cls");
}

/*int updateIndexOfUser(vector <Account>& vec_of_accounts, string login_of_user)
{
	for (int i = 0; i < vec_of_accounts.size(); i++)
	{
		if (login_of_user == vec_of_accounts.at(i).login)
		{
			return i;
		}
	}
}*/

void workWithStudents(vector <Student>& vec_of_students, bool is_admin)
{
	//cout << "Здравствуйте, гость! Пожалуйста, выберите пункт меню:" << endl;
	int item;
	bool flag = true;
	while (flag)
	{
		system("cls");
		showStudents(vec_of_students);
		if (is_admin)
		{
			cout << STUDENT_MENU_ADMIN << endl;
			item = enterNumberInRange(0, MAX_OF_STUDENT_MENU_ADMIN);
		}
		else
		{
			cout << STUDENT_MENU_USER << endl;
			item = enterNumberInRange(0, MAX_OF_STUDENT_MENU_USER);
		}
		switch (item)
		{
		case 1:
			calculateStipends(vec_of_students);
			break;
		case 2:
			searchStudents(vec_of_students);
			break;
		case 3:
			system("cls");
			sortStudents(vec_of_students);
			break;
		case 4:
			system("cls");
			addStudent(vec_of_students);
			break;
		case 5:
			editStudent(vec_of_students);
			break;
		case 6:
			deleteStudent(vec_of_students);
			break;
		case 0:
			flag = false;
			break;
		default: cout << ERROR_MESSAGE << endl;
		}
	}
	system("cls");
}

/*void showStudents(vector <Student>& vec_of_students)
{
	cout << endl;
	cout << "№\t|" << "ФИО\t|" << "№ группы\t|" << "ООПиП\t|" << "ДМ\t|" << "ИнАД\t|" << "Ист\t|" << "ФизК\t|"
		<< "ОАиП\t|" << "МА\t|" << "ИнЯз\t|" << "Физика\t|" << "Бюджет\t|" << "Активность\t|" << endl;
	cout << SEPARATOR << endl;
	for (unsigned int i = 0; i < vec_of_students.size(); i++)
	{
		cout << i + 1 << "\t|" << vec_of_students.at(i).FIO << "\t|" << vec_of_students.at(i).num_of_group
			<< "\t|" << vec_of_students.at(i).offset.oopip << "\t|" << vec_of_students.at(i).offset.discrete_math
			<< "\t|" << vec_of_students.at(i).offset.inad << "\t|" << vec_of_students.at(i).offset.history
			<< "\t|" << vec_of_students.at(i).offset.phys_culture
			<< "\t|" << vec_of_students.at(i).exam.oaip << "\t|" << vec_of_students.at(i).exam.math
			<< "\t|" << vec_of_students.at(i).exam.english << "\t|" << vec_of_students.at(i).exam.physics
			<< "\t|" << vec_of_students.at(i).is_budget_student << "\t|" << vec_of_students.at(i).is_social_work << endl;
	}
	cout << SEPARATOR << endl;
	cout << endl;
}*/
/*
void calculateStipends(vector <Student>& vec_of_students) {}

void sortStudents(vector <Student>& vec_of_students) {}

void searchStudents(vector <Student>& vec_of_students) {}

void addStudent(vector <Student>& vec_of_students)
{
	Student temp_student;
	string fio;
	while (true)
	{
		cout << "\nФИО: ";
		fio = enterStringWithoutNumbers();
		if (isGoodFio(vec_of_students, fio))
		{
			temp_student.FIO = fio;
			break;
		}
		else
		{
			system("cls");
			cout << "\nСтудент с таким ФИО уже существует! Введите другое.";
		}
	}
	cout << "\nНомер группы: ";
	temp_student.num_of_group = enterStringWithoutSpaces();
	setOffsets(temp_student);
	setExams(temp_student);
	cout << "\nФорма обучения (Платная - 0, Бюджетная - 1): ";
	temp_student.is_budget_student = enterNumberInRange(0, 1);
	cout << "\nУчастие в общественной работе (Неактивное - 0, Активное - 1): ";
	temp_student.is_social_work = enterNumberInRange(0, 1);
	vec_of_students.push_back(temp_student);
}
*/
/*bool isGoodFio(vector <Student>& vec_of_students, string fio)
{
	for (unsigned int i = 0; i < vec_of_students.size(); i++)
	{
		if (fio == vec_of_students.at(i).FIO)
		{
			return 0;
		}
	}
	return 1;
}*/

/*string enterStringWithoutNumbers()
{
	char symbol;
	string buffer;
	while ((symbol = _getch()) != '\r')
	{
		if (symbol == '\b')
		{
			if (!buffer.empty())
			{
				cout << "\b \b";
				buffer.erase(buffer.size() - 1);
			}
			continue;
		}
		if (!((symbol >= 'а' && symbol <= 'я') || (symbol >= 'А' && symbol <= 'Я') || symbol == ' ' || symbol == '.'))
		{
			continue;
		}
		else if ((!buffer.empty() && symbol == ' ' && buffer.at(buffer.size() - 1) == ' ') || (buffer.empty() && symbol == ' '))
		{
			continue;
		}
		buffer += symbol;
		cout << symbol;
	}
	buffer += '\0';
	return buffer;
}*/
/*
void setOffsets(Student& temp_student)
{
	cout << "\nЗачеты (Не зачтено - " << MIN_OFFSET << ", Зачтено - " << MAX_OFFSET << ")" << endl;
	temp_student.offset.oopip = rateStudent(MIN_OFFSET, MAX_OFFSET, OOPIP);
	temp_student.offset.discrete_math = rateStudent(MIN_OFFSET, MAX_OFFSET, DISCRETE_MATH);
	temp_student.offset.inad = rateStudent(MIN_OFFSET, MAX_OFFSET, INAD);
	temp_student.offset.history = rateStudent(MIN_OFFSET, MAX_OFFSET, HISTORY);
	temp_student.offset.phys_culture = rateStudent(MIN_OFFSET, MAX_OFFSET, PHYS_CULTURE);
}

void setExams(Student& temp_student)
{
	cout << "\nЭкзамены (Минимальная оценка - " << MIN_EXAM << ", Максимальная оценка - " << MAX_EXAM << ")" << endl;
	temp_student.exam.oaip = rateStudent(MIN_EXAM, MAX_EXAM, OAIP);
	temp_student.exam.math = rateStudent(MIN_EXAM, MAX_EXAM, MATH);
	temp_student.exam.english = rateStudent(MIN_EXAM, MAX_EXAM, ENGLISH);
	temp_student.exam.physics = rateStudent(MIN_EXAM, MAX_EXAM, PHYSICS);
}

int rateStudent(int min_range, int max_of_range, string subject)
{
	cout << subject << ": ";
	return enterNumberInRange(min_range, max_of_range);
}

void editStudent(vector <Student>& vec_of_students) {}

void deleteStudent(vector <Student>& vec_of_students)
{
	int answer, index_for_delete;
	cout << "Какого студента вы хотите удалить?\n Отмена - 0" << endl;
	index_for_delete = indexOfVectorForChange(vec_of_students);
	if (index_for_delete != 0)
	{
		index_for_delete--;

		system("cls");
		cout << "Вы действительно хотите удалить студента " << vec_of_students.at(index_for_delete).FIO << "? \nДа - 1 \nНет - 0" << endl;
		answer = enterNumberInRange(0, 1);
		if (answer == 1)
		{
			vec_of_students.erase(vec_of_students.begin() + index_for_delete);
			cout << "Успешно удалён!" << endl;
			system("pause");
		}
	}
}

int indexOfVectorForChange(vector <Student>& vec_of_students)
{
	int size;
	size = vec_of_students.size();
	return enterNumberInRange(0, size);
}
*/
void sortAccounts(vector <Account>& vec_of_accounts)
{
	int number;
	cout << MENU_OF_SORTS_ACCOUNTS << endl;
	number = enterNumberInRange(0, MAX_OF_RANGE_MENU_OF_SORTS_ACCOUNTS);
	switch (number)
	{
	case 1:
		if (isAscending())sortAccountsBy(vec_of_accounts, mySortByLoginAscending);
		else sortAccountsBy(vec_of_accounts, mySortByLoginDescending);
		break;
	case 2:
		if (isAscending())sortAccountsBy(vec_of_accounts, mySortByRoleAscending);
		else sortAccountsBy(vec_of_accounts, mySortByRoleDescending);
		break;
	case 3:
		if (isAscending())sortAccountsBy(vec_of_accounts, mySortByAccessAscending);
		else sortAccountsBy(vec_of_accounts, mySortByAccessDescending);
		break;
	case 0:
		break;
	default: cout << ERROR_MESSAGE << endl;
	}
}

void sortStudents(vector <Student>& vec_of_students)
{
	int number;
	cout << MENU_OF_SORTS_STUDENTS << endl;
	number = enterNumberInRange(0, MAX_OF_RANGE_MENU_OF_SORTS_STUDENTS);
	switch (number)
	{
	case 1:
		if (isAscending())sortStudentsBy(vec_of_students, mySortBySurnameAscending);
		else sortStudentsBy(vec_of_students, mySortBySurnameDescending);
		break;
	case 2:
		if (isAscending())sortStudentsBy(vec_of_students, mySortByGroupNumberAscending);
		else sortStudentsBy(vec_of_students, mySortByGroupNumberDescending);
		break;
	case 3:
		if (isAscending())sortStudentsBy(vec_of_students, mySortByAverageScoreAscending);
		else sortStudentsBy(vec_of_students, mySortByAverageScoreDescending);
		break;
	case 4:
		if (isAscending())sortStudentsBy(vec_of_students, mySortByStipendAscending);
		else sortStudentsBy(vec_of_students, mySortByStipendDescending);
		break;
	case 5:
		sortStudentOffsets(vec_of_students);
		break;
	case 6:
		sortStudentExams(vec_of_students);
		break;
	case 7:
		if (isAscending())sortStudentsBy(vec_of_students, mySortByFormOfEducationAscending);
		else sortStudentsBy(vec_of_students, mySortByFormOfEducationAscending);
		break;
	case 8:
		if (isAscending())sortStudentsBy(vec_of_students, mySortBySocialWorkAscending);
		else sortStudentsBy(vec_of_students, mySortBySocialWorkAscending);
		break;
	case 0:
		break;
	default: cout << ERROR_MESSAGE << endl;
	}
}

void sortStudentOffsets(vector <Student>& vec_of_students)
{
	int number;
	cout << MENU_OF_SORTS_STUDENTS_OFFSETS << endl;
	number = enterNumberInRange(0, MAX_OF_RANGE_MENU_OF_SORTS_STUDENTS_OFFSETS);
	switch (number)
	{
	case 1:
		if (isAscending())sortStudentsBy(vec_of_students, mySortByOopipAscending);
		else sortStudentsBy(vec_of_students, mySortByOopipDescending);
		break;
	case 2:
		if (isAscending())sortStudentsBy(vec_of_students, mySortByDiscreteMathAscending);
		else sortStudentsBy(vec_of_students, mySortByDiscreteMathDescending);
		break;
	case 3:
		if (isAscending())sortStudentsBy(vec_of_students, mySortByInadAscending);
		else sortStudentsBy(vec_of_students, mySortByInadDescending);
		break;
	case 4:
		if (isAscending())sortStudentsBy(vec_of_students, mySortByHistoryAscending);
		else sortStudentsBy(vec_of_students, mySortByHistoryDescending);
		break;
	case 5:
		if (isAscending())sortStudentsBy(vec_of_students, mySortByPhysCultureAscending);
		else sortStudentsBy(vec_of_students, mySortByPhysCultureDescending);
		break;
	case 0:
		break;
	default: cout << ERROR_MESSAGE << endl;
	}
}

void sortStudentExams(vector <Student>& vec_of_students)
{
	int number;
	cout << MENU_OF_SORTS_STUDENTS_EXAMS << endl;
	number = enterNumberInRange(0, MAX_OF_RANGE_MENU_OF_SORTS_STUDENTS_EXAMS);
	switch (number)
	{
	case 1:
		if (isAscending())sortStudentsBy(vec_of_students, mySortByOaipAscending);
		else sortStudentsBy(vec_of_students, mySortByOaipDescending);
		break;
	case 2:
		if (isAscending())sortStudentsBy(vec_of_students, mySortByMathAscending);
		else sortStudentsBy(vec_of_students, mySortByMathDescending);
		break;
	case 3:
		if (isAscending())sortStudentsBy(vec_of_students, mySortByEnglishAscending);
		else sortStudentsBy(vec_of_students, mySortByEnglishDescending);
		break;
	case 4:
		if (isAscending())sortStudentsBy(vec_of_students, mySortByPhysicsAscending);
		else sortStudentsBy(vec_of_students, mySortByPhysicsDescending);
		break;
	case 0:
		break;
	default: cout << ERROR_MESSAGE << endl;
	}
}

void sortStudentsBy(vector <Student>& vec_of_students, bool (*comparisonFunction)(Student, Student))
{
	sort(vec_of_students.begin(), vec_of_students.end(), comparisonFunction);
}

bool mySortBySurnameAscending(Student stu_1, Student stu_2)
{
	return stu_1.FIO < stu_2.FIO;
}

bool mySortBySurnameDescending(Student stu_1, Student stu_2)
{
	return stu_1.FIO > stu_2.FIO;
}

bool mySortByGroupNumberAscending(Student stu_1, Student stu_2)
{
	return stoi(stu_1.num_of_group) < stoi(stu_2.num_of_group);
}

bool mySortByGroupNumberDescending(Student stu_1, Student stu_2)
{
	return stoi(stu_1.num_of_group) > stoi(stu_2.num_of_group);
}

bool mySortByAverageScoreAscending(Student stu_1, Student stu_2)
{
	return stu_1.exam.average_score < stu_2.exam.average_score;
}

bool mySortByAverageScoreDescending(Student stu_1, Student stu_2)
{
	return stu_1.exam.average_score > stu_2.exam.average_score;
}

bool mySortByStipendAscending(Student stu_1, Student stu_2)
{
	return stu_1.stipend < stu_2.stipend;
}

bool mySortByStipendDescending(Student stu_1, Student stu_2)
{
	return stu_1.stipend > stu_2.stipend;
}

bool mySortByFormOfEducationAscending(Student stu_1, Student stu_2)
{
	return stu_1.is_budget_student < stu_2.is_budget_student;
}

bool mySortByFormOfEducationDescending(Student stu_1, Student stu_2)
{
	return stu_1.is_budget_student > stu_2.is_budget_student;
}

bool mySortBySocialWorkAscending(Student stu_1, Student stu_2)
{
	return stu_1.is_social_work < stu_2.is_social_work;
}

bool mySortBySocialWorkDescending(Student stu_1, Student stu_2)
{
	return stu_1.is_social_work > stu_2.is_social_work;
}

bool mySortByOopipAscending(Student stu_1, Student stu_2)
{
	return stu_1.offset.oopip < stu_2.offset.oopip;
}

bool mySortByOopipDescending(Student stu_1, Student stu_2)
{
	return stu_1.offset.oopip > stu_2.offset.oopip;
}

bool mySortByDiscreteMathAscending(Student stu_1, Student stu_2)
{
	return stu_1.offset.discrete_math < stu_2.offset.discrete_math;
}

bool mySortByDiscreteMathDescending(Student stu_1, Student stu_2)
{
	return stu_1.offset.discrete_math > stu_2.offset.discrete_math;
}

bool mySortByInadAscending(Student stu_1, Student stu_2)
{
	return stu_1.offset.inad < stu_2.offset.inad;
}

bool mySortByInadDescending(Student stu_1, Student stu_2)
{
	return stu_1.offset.inad > stu_2.offset.inad;
}

bool mySortByHistoryAscending(Student stu_1, Student stu_2)
{
	return stu_1.offset.history < stu_2.offset.history;
}

bool mySortByHistoryDescending(Student stu_1, Student stu_2)
{
	return stu_1.offset.history > stu_2.offset.history;
}

bool mySortByPhysCultureAscending(Student stu_1, Student stu_2)
{
	return stu_1.offset.phys_culture < stu_2.offset.phys_culture;
}

bool mySortByPhysCultureDescending(Student stu_1, Student stu_2)
{
	return stu_1.offset.phys_culture > stu_2.offset.phys_culture;
}

bool mySortByOaipAscending(Student stu_1, Student stu_2)
{
	return stu_1.exam.oaip < stu_2.exam.oaip;
}

bool mySortByOaipDescending(Student stu_1, Student stu_2)
{
	return stu_1.exam.oaip > stu_2.exam.oaip;
}

bool mySortByMathAscending(Student stu_1, Student stu_2)
{
	return stu_1.exam.math < stu_2.exam.math;
}

bool mySortByMathDescending(Student stu_1, Student stu_2)
{
	return stu_1.exam.math > stu_2.exam.math;
}

bool mySortByEnglishAscending(Student stu_1, Student stu_2)
{
	return stu_1.exam.english < stu_2.exam.english;
}

bool mySortByEnglishDescending(Student stu_1, Student stu_2)
{
	return stu_1.exam.english > stu_2.exam.english;
}

bool mySortByPhysicsAscending(Student stu_1, Student stu_2)
{
	return stu_1.exam.physics < stu_2.exam.physics;
}

bool mySortByPhysicsDescending(Student stu_1, Student stu_2)
{
	return stu_1.exam.physics > stu_2.exam.physics;
}

bool isAscending()
{
	int number;
	cout << MENU_OF_ASCENDING_DESCENDING << endl;
	number = enterNumberInRange(1, MAX_OF_RANGE_MENU_OF_ASCENDING_DESCENDING);
	switch (number)
	{
	case 1:
		return true;
	case 2:
		return false;
	default:
		cout << ERROR_MESSAGE << endl;
		return false;
	}
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
			cout << "№\t|" << "Логин\t|" << "Роль\t|" << endl;
			cout << SEPARATOR << endl;
			for (unsigned int i = 0; i < array.size(); i++)
			{
				cout << i + 1 << "\t|" << vec_of_accounts.at(array.at(i)).login << "\t|"
					<< vec_of_accounts.at(array.at(i)).role << "\t|" << endl;
			}
			cout << SEPARATOR << endl;
			cout << MENU_OF_ACCESS << endl;
			number = enterNumberInRange(0, MAX_OF_RANGE_MENU_ACCESS);
			switch (number)
			{
			case 1:
				confirmAccessOfAccounts(vec_of_accounts, array);
				system("cls");
				break;
			case 2:
				rejectAccessOfAccounts(vec_of_accounts, array);
				system("cls");
				break;
			case 0:
				flag = false;
				break;
			default:
				cout << ERROR_MESSAGE << endl;
			}
		}
		else
		{
			flag = false;
		}
	}
}
/*
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
}*/
/*
void addAccount(vector <Account>& vec_of_accounts, bool is_from_admin)
{
	Account temp_account;
	string login, password;
	while (true)
	{
		cout << "\nЛогин: ";
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
	role = enterNumberInRange(0, 1);//cin >> temp_account.role;
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

void showAccounts(vector <Account>& vec_of_accounts)
{
	cout << endl;
	cout << "№\t|" << "Логин\t|" << "Роль\t|" << "Доступ\t|" << endl;
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
}*/

/*int enterNumberInRange(int min, int max)
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
			cout << "Введите число в заданном промежутке!" << endl;
		}
	}
	return number;
}*/

/*void createFirstAccount(vector <Account>& vec_of_accounts)
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
}*/

/*void readFileOfAccounts(vector <Account>& vec_of_accounts)
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
}*/
/*
void readFileOfStudents(vector <Student>& vec_of_students)
{
	ifstream fin(FILE_OF_STUDENTS, ios::in);
	Student temp_student;
	if (!fin.is_open())
	{
		cout << "Файла со студентами не существует! Создан новый." << endl;
	}
	else
	{
		if (fin.peek() != EOF)
		{
			while (!fin.eof())
			{
				getline(fin,temp_student.FIO, '\0');
				temp_student.FIO += '\0';
				fin >> temp_student.num_of_group
					>> temp_student.offset.oopip >> temp_student.offset.discrete_math >> temp_student.offset.inad
					>> temp_student.offset.history >> temp_student.offset.phys_culture
					>> temp_student.exam.oaip >> temp_student.exam.math >> temp_student.exam.english >> temp_student.exam.physics
					>> temp_student.is_budget_student >> temp_student.is_social_work;
				vec_of_students.push_back(temp_student);
			}
		}
		else
		{
			cout << "Файл пуст!" << endl;
		}
	}
	fin.close();
}
*/
/*void writeFileOfAccounts(vector <Account>& vec_of_accounts)
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
}*/
/*
void writeFileOfStudents(vector <Student>& vec_of_students)
{
	ofstream fout(FILE_OF_STUDENTS, ios::out);
	for (unsigned int i = 0; i < vec_of_students.size(); i++)
	{
		fout << vec_of_students.at(i).FIO << " " << vec_of_students.at(i).num_of_group
			<< " " << vec_of_students.at(i).offset.oopip << " " << vec_of_students.at(i).offset.discrete_math
			<< " " << vec_of_students.at(i).offset.inad << " " << vec_of_students.at(i).offset.history
			<< " " << vec_of_students.at(i).offset.phys_culture
			<< " " << vec_of_students.at(i).exam.oaip << " " << vec_of_students.at(i).exam.math
			<< " " << vec_of_students.at(i).exam.english << " " << vec_of_students.at(i).exam.physics
			<< " " << vec_of_students.at(i).is_budget_student << " " << vec_of_students.at(i).is_social_work;
		if (i < vec_of_students.size() - 1)
		{
			fout << endl;
		}
	}
	fout.close();
}
*/
/*int correctInputInt()
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
			cout << "Ошибка! Введите целое число." << endl;
		}
	}
	return a;
}*/

/*int indexOfVectorForChange(vector <Account>& vec_of_accounts)
{
	int size;
	size = vec_of_accounts.size();
	return enterNumberInRange(0, size);
}*/
/*
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
}*/

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

void sortAccountsBy(vector <Account>& vec_of_accounts, bool (*comparisonFunction)(Account, Account))
{
	sort(vec_of_accounts.begin(), vec_of_accounts.end(), comparisonFunction);
}

bool mySortByAccessAscending(Account acc_1, Account acc_2)
{
	return acc_1.access < acc_2.access;
}

bool mySortByAccessDescending(Account acc_1, Account acc_2)
{
	return acc_1.access > acc_2.access;
}

bool mySortByRoleAscending(Account acc_1, Account acc_2)
{
	return acc_1.role < acc_2.role;
}

bool mySortByRoleDescending(Account acc_1, Account acc_2)
{
	return acc_1.role > acc_2.role;
}

bool mySortByLoginAscending(Account acc_1, Account acc_2)
{
	return acc_1.login < acc_2.login;
}

bool mySortByLoginDescending(Account acc_1, Account acc_2)
{
	return acc_1.login > acc_2.login;
}