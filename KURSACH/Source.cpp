#include <Windows.h>
#include <vector>

#include "Accounts.h"
#include "Students.h"
#include "Menus.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector <Account> vec_of_accounts;
	vec_of_accounts.reserve(getCountOfStructuresAccount(FILE_OF_ACCOUNTS));
	vector <Student> vec_of_students;
	vec_of_students.reserve(getCountOfStructuresStudent(FILE_OF_STUDENTS));
	readFileOfAccounts(vec_of_accounts);
	readFileOfStudents(vec_of_students);
	core(vec_of_accounts, vec_of_students);
	writeFileOfAccounts(vec_of_accounts);
	writeFileOfStudents(vec_of_students);
	system("pause");
	return 0;
}
