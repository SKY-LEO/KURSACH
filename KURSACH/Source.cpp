#include <Windows.h>
#include <vector>

#include "Accounts.h"//реализация функционала для модуля работы с учетными записями и авторизации в систему
#include "Students.h"//реализация функционала для модуля работы со студентами и стипендиями
#include "Menus.h"//реализация различных меню

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector <Account> vec_of_accounts;//вектор учетных записей
	vec_of_accounts.reserve(getCountOfStructuresAccount(FILE_OF_ACCOUNTS));
	vector <Student> vec_of_students;//вектор студентов
	vec_of_students.reserve(getCountOfStructuresStudent(FILE_OF_STUDENTS));
	readFileOfAccounts(vec_of_accounts);
	readFileOfStudents(vec_of_students);
	core(vec_of_accounts, vec_of_students);
	writeFileOfAccounts(vec_of_accounts);
	writeFileOfStudents(vec_of_students);
	system("pause");
	return 0;
}
