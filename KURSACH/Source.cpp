/*
23. ���������� ��������� ������� ���������
��� ������� ��������� ���������� ���������� ���������� ���������� ���� : ����� ������, �.�.�.��������,
����� ��������(������� / ���������), ������ �� ���� ���������(����� / �������), ������ �� 4 ���������,
������� ������� � ������������ ������ : 1 � �������� �������, 0 � ���������.
�������������� ������� : ���������� ��������� ��� ��������� - �����������.
��� ���� : ���������(������� 9, 10) � ������������� �������� 50 % ��������, � ������ ��������� � 25 % .
�������� �� ������� ������, ������ ��� ���� 5, ��������� �� ��������.������� ������ ��������� �������� � ����������.
����� ��� ���� ��������� ������� : ����������� ����������� ��� ����� � �������, ���������� �������������� � ���������� ������������(��.����� �������� � �������������� ����������� � �������� ������ � ���� �������� ��������������.�������).
*/

#include <Windows.h>

#include <vector>
//#include <fstream>//����� ������
#include <iostream>//����� ������
//#include <string>//����� ������
//#include <conio.h>//����� ������
#include <algorithm>//����� ������

//----hash----
//#include "sha256.h"//����� ������
//----hash----
#include "Accounts.h"
#include "Students.h"
#include "Validations.h"//����� ������
//#include "Menus.h"
//template <class To>
//using namespace std;//����� ������

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

//const string MAIN_MENU_ADMIN = "\n ��������� - 1\n ������ � �������� �������� - 2\n ������� ������ - 3\n ����� - 0";
const string MAIN_MENU_ADMIN = "�� ���������� � ������� ���� ��������������.\n1) ���������\n2) ������ � �������� ��������\n3) ������� ������\n0) �����";
//const string ACCOUNT_MENU_ADMIN = " �� ���������� � ���� ������ � �������� ��������.\n �������� - 1\n ������� - 2\n �������� ������ - 3\n �������� ���� - 4\n ������� �� ������ - 5\n ����� - 0";
//const string ACCOUNT_MENU_ADMIN = " �� ���������� � ���� ������ � �������� ��������.\n ������� - 1\n �������� ������ - 2\n �������� ���� - 3\n ������� �� ������ - 4\n ����� - 0";
//const string ACCOUNT_MENU_ADMIN_WITHOUT_ACCESS = " �� ���������� � ���� ������ � �������� ��������.\n ������� - 1\n �������� ������ - 2\n �������� ���� - 3\n ����� - 0";
//const string MAIN_MENU_USER = "\n ��������� - 1\n ������� ������ - 2\n ����� - 0";
const string MAIN_MENU_USER = "�� ���������� � ������� ���� ������������.\n1) ���������\n2) ������� ������\n0) �����";
//const string START_MENU = "\n ����� � ������������ ������� ������ - 1\n ������� ����� ������� ������ - 2\n ���������� ������ - 0";
const string START_MENU = "������������, �����! ����������, �������� ����� ����:\n1) ����� � ������������ ������� ������\n2) ������� ����� ������� ������\n0) ���������� ������";
//const string STUDENT_MENU_ADMIN = "\n1) ������ ���������\n2) �����\n3) ����������\n4) �������� ��������\n5) ������������� ������\n6) ������� ��������\n0) �����";
//const string STUDENT_MENU_USER = "\n1) ������ ���������\n2) �����\n3) ����������\n0) �����";
const string MENU_OF_ASCENDING_DESCENDING = "����������� ��:\n1) �����������\n2) ��������";
const string ERROR_MESSAGE = "������!";

const string ACCOUNT_MENU_ADMIN = "�� ���������� � ���� ������ � �������� ��������.\n1) �����������\n2) �������\n3) �������� ������\n4) �������� ����\n5) ������� �������\n6) ������� �� ������";// ����� - 0";
//const string ACCOUNT_MENU_ADMIN_WITHOUT_ACCESS = " �� ���������� � ���� ������ � �������� ��������.\n �������� - 1 \n ������� - 2\n �������� ������ - 3\n �������� ���� - 4\n ����� - 0";
const string ACCOUNT_MENU_ADMIN_WITHOUT_ACCESS = " �� ���������� � ���� ������ � �������� ��������.\n1) �����������\n2) �������\n3) �������� ������\n4) �������� ����\n5) ������� �������\n0) �����";
const string MENU_OF_ACCESS = "�� ���������� � ���� ������ � �������� �� ������ � �������.\n1) ����������� ������\n2) ������������� ������\n0) �����";
const string MENU_OF_SORTS_ACCOUNTS = "�� ���������� � ���� ���������� ������� �������.\n����������� ��:\n1) ������\n2) ����\n3) �������\n0) �����";
const string MENU_OF_SORTS_STUDENTS = "�� ���������� � ���� ���������� ���������.\n����������� ��:\n1) �������\n2) ������ ������\n3) �������� �����\n4) ���������\n5) ����� �������\n6) ����� ���������\n7) ����� ��������\n8) ������� � ������������ ������\n0) �����";
const string MENU_OF_STUDENTS_OFFSETS = "�� ���������� � ���� ������ ������.\n�������� �������:\n1) �����\n2) ��\n3) ����\n4) ���\n5) ����\n0) �����";
const string MENU_OF_STUDENTS_EXAMS = "�� ���������� � ���� ������ ��������.\n�������� �������:\n1) ����\n2) ��\n3) ����\n4) ������\n0) �����";
const string MENU_OF_EDIT_STUDENT = "�� ���������� � ���� �������������� ���������.\n���������������: \n1) ���\n2) ����� ������\n3) ������\n4) ��������\n5) ����� ��������\n6) ������� � ������������ ������\n0) �����";
const string MENU_OF_SEARCH_STUDENTS = "�� ���������� � ���� ������ ���������.\n������ ��:\n1) ���\n2) ������ ������\n3) ���������\n0) �����";
const int MAX_OF_RANGE_MAIN_MENU_ADMIN = 3;
const int MAX_OF_RANGE_MAIN_MENU_USER = 2;
const int MAX_OF_START_MENU = 2;
const int MAX_OF_RANGE_MENU_ACCESS = 2;
const int MAX_OF_RANGE_MENU_OF_SORTS_ACCOUNTS = 3;
const int MAX_OF_RANGE_MENU_OF_ASCENDING_DESCENDING = 2;
const int MAX_OF_STUDENT_MENU_ADMIN = 6;
const int MAX_OF_STUDENT_MENU_USER = 3;
const int MAX_OF_RANGE_MENU_OF_SORTS_STUDENTS = 8;
const int MAX_OF_RANGE_MENU_OF_STUDENTS_OFFSETS = 5;
const int MAX_OF_RANGE_MENU_OF_STUDENTS_EXAMS = 4;
const int MAX_OF_RANGE_MENU_OF_EDIT_STUDENT = 6;
const int MAX_OF_RANGE_MENU_OF_SEARCH_STUDENTS = 3;

void core(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students);
int getCountOfStructures(string file_path);
int initialisation(vector <Account>& vec_of_accounts);
int user(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students, int index_of_user);
int admin(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students, int index_of_user);
void workWithStudents(vector <Student>& vec_of_students, bool is_admin);
void workWithAccounts(vector <Account>& vec_of_accounts, int& index_of_user);
void workWithAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array);

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
void sortStudentsBy(vector <Student>& vec_of_students, bool (*comparisonFunction)(Student&, Student&));
bool mySortBySurnameAscending(Student& stu_1, Student& stu_2);
bool mySortBySurnameDescending(Student& stu_1, Student& stu_2);
bool mySortByGroupNumberAscending(Student& stu_1, Student& stu_2);
bool mySortByGroupNumberDescending(Student& stu_1, Student& stu_2);
bool mySortByAverageScoreAscending(Student& stu_1, Student& stu_2);
bool mySortByAverageScoreDescending(Student& stu_1, Student& stu_2);
bool mySortByStipendAscending(Student& stu_1, Student& stu_2);
bool mySortByStipendDescending(Student& stu_1, Student& stu_2);
bool mySortByFormOfEducationAscending(Student& stu_1, Student& stu_2);
bool mySortByFormOfEducationDescending(Student& stu_1, Student& stu_2);
bool mySortBySocialWorkAscending(Student& stu_1, Student& stu_2);
bool mySortBySocialWorkDescending(Student& stu_1, Student& stu_2);

void sortStudents(vector <Student>& vec_of_students);
void sortStudentOffsets(vector <Student>& vec_of_students);
bool mySortByOopipAscending(Student& stu_1, Student& stu_2);
bool mySortByOopipDescending(Student& stu_1, Student& stu_2);
bool mySortByDiscreteMathAscending(Student& stu_1, Student& stu_2);
bool mySortByDiscreteMathDescending(Student& stu_1, Student& stu_2);
bool mySortByInadAscending(Student& stu_1, Student& stu_2);
bool mySortByInadDescending(Student& stu_1, Student& stu_2);
bool mySortByHistoryAscending(Student& stu_1, Student& stu_2);
bool mySortByHistoryDescending(Student& stu_1, Student& stu_2);
bool mySortByPhysCultureAscending(Student& stu_1, Student& stu_2);
bool mySortByPhysCultureDescending(Student& stu_1, Student& stu_2);
void sortStudentExams(vector <Student>& vec_of_students);
bool mySortByOaipAscending(Student& stu_1, Student& stu_2);
bool mySortByOaipDescending(Student& stu_1, Student& stu_2);
bool mySortByMathAscending(Student& stu_1, Student& stu_2);
bool mySortByMathDescending(Student& stu_1, Student& stu_2);
bool mySortByEnglishAscending(Student& stu_1, Student& stu_2);
bool mySortByEnglishDescending(Student& stu_1, Student& stu_2);
bool mySortByPhysicsAscending(Student& stu_1, Student& stu_2);
bool mySortByPhysicsDescending(Student& stu_1, Student& stu_2);
void editStudent(vector <Student>& vec_of_students);
void editExams(Student& temp_student);
void editOffsets(Student& temp_student);
void editFormOfEducation(Student& temp_student);
void searchStudents(vector <Student>& vec_of_students);
void searchByStipend(vector <Student>& vec_of_students);
void searchByFio(vector <Student>& vec_of_students);
void searchByNumberOfGroup(vector <Student>& vec_of_students);
void editActivityOfSocialWork(Student& temp_student);

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
	default:
		cout << ERROR_MESSAGE << endl;
		return item;
	}
}

void core(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students)
{
	int code, index_of_user;
	bool flag = true;
	while (flag)
	{
		index_of_user = initialisation(vec_of_accounts);
		if (index_of_user > -1)//���� �� ��� ������
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
			flag = false;
		}
	}
}

int user(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students, int index_of_user)
{
	bool flag = true;
	while (flag)
	{
		cout << MAIN_MENU_USER << endl;
		int item = enterNumberInRange(0, MAX_OF_RANGE_MAIN_MENU_USER);
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
		default:
			cout << ERROR_MESSAGE << endl;
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
		default:
			cout << ERROR_MESSAGE << endl;
		}
	}
	system("cls");
	return 0;
}

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
		if (update_access)//���� ������ ������� ��� ������� � ������� ��� ������ ������, �� ���� �������� ������ ���������, ��������� �������������
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
			cout << ACCOUNT_MENU_ADMIN << "(����� ��������: " << size_of_array << ")\n0) �����" << endl;
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
		default:
			cout << ERROR_MESSAGE << endl;
		}
	}
	system("cls");
}

void workWithStudents(vector <Student>& vec_of_students, bool is_admin)
{
	//cout << "������������, �����! ����������, �������� ����� ����:" << endl;
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
			system("cls");
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
		default:
			cout << ERROR_MESSAGE << endl;
		}
	}
	system("cls");
}

void searchStudents(vector <Student>& vec_of_students)
{
	int number;
	bool flag = true;
	while (flag)
	{
		cout << MENU_OF_SEARCH_STUDENTS << endl;
		number = enterNumberInRange(0, MAX_OF_RANGE_MENU_OF_SEARCH_STUDENTS);
		switch (number)
		{
		case 1:
			searchByFio(vec_of_students);
			break;
		case 2:
			searchByNumberOfGroup(vec_of_students);
			break;
		case 3:
			searchByStipend(vec_of_students);
			break;
		case 0:
			flag = false;
			break;
		default:
			cout << ERROR_MESSAGE << endl;
		}
	}
}

void searchByFio(vector <Student>& vec_of_students)
{
	cout << "���: ";
	string fio = enterStringWithoutNumbers();
	system("cls");
	drawHeader();
	int k = 0;
	for (unsigned int i = 0; i < vec_of_students.size(); i++)
	{
		if (vec_of_students.at(i).FIO == fio)
		{
			displayStudent(vec_of_students.at(i), k++);
		}
	}
	if (k == 0)
	{
		cout << setw(99) << "������ �� �������..." << endl;
		cout << SEPARATOR_STUDENT << endl;
	}
	cout << endl;
}

void searchByNumberOfGroup(vector <Student>& vec_of_students)
{
	cout << "����� ������: ";
	string num_of_group = enterStringWithoutSpacesAndSpecialSym();
	system("cls");
	drawHeader();
	int k = 0;
	for (unsigned int i = 0; i < vec_of_students.size(); i++)
	{
		if (vec_of_students.at(i).num_of_group == num_of_group)
		{
			displayStudent(vec_of_students.at(i), k++);
		}
	}
	if (k == 0)
	{
		cout << setw(99) << "������ �� �������..." << endl;
		cout << SEPARATOR_STUDENT << endl;
	}
	cout << endl;
}

void searchByStipend(vector <Student>& vec_of_students)
{
	double stipend = enterStipend();
	system("cls");
	drawHeader();
	int k = 0;
	for (unsigned int i = 0; i < vec_of_students.size(); i++)
	{
		if (vec_of_students.at(i).stipend == stipend)
		{
			displayStudent(vec_of_students.at(i), k++);
		}
	}
	if (k == 0)
	{
		cout << setw(99) << "������ �� �������..." << endl;
		cout << SEPARATOR_STUDENT << endl;
	}
	cout << endl;
}

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
	default:
		cout << ERROR_MESSAGE << endl;
	}
}

void editStudent(vector <Student>& vec_of_students)
{
	bool flag = true;
	cout << "������ �������� �� ������ ���������������?\n����� - 0" << endl;
	int index_for_change = indexOfVectorForChange(vec_of_students);
	if (index_for_change == 0)return;
	else index_for_change--;
	while (flag)
	{
		system("cls");
		showStudents(vec_of_students);
		cout << "������ ������� " << vec_of_students.at(index_for_change).FIO << endl;
		cout << MENU_OF_EDIT_STUDENT << endl;
		int number = enterNumberInRange(0, MAX_OF_RANGE_MENU_OF_EDIT_STUDENT);
		switch (number)
		{
		case 1:
			setFio(vec_of_students, vec_of_students.at(index_for_change));
			break;
		case 2:
			setNumOfGroup(vec_of_students.at(index_for_change));
			break;
		case 3:
			editOffsets(vec_of_students.at(index_for_change));
			setIsOffsetsSubmited(vec_of_students.at(index_for_change));
			editStipends(vec_of_students);
			break;
		case 4:
			editExams(vec_of_students.at(index_for_change));
			setAverageScore(vec_of_students.at(index_for_change));
			editStipends(vec_of_students);
			break;
		case 5:
			editFormOfEducation(vec_of_students.at(index_for_change));
			editStipends(vec_of_students);
			break;
		case 6:
			editActivityOfSocialWork(vec_of_students.at(index_for_change));
			editStipends(vec_of_students);
			break;
		case 0:
			flag = false;
			break;
		default:
			cout << ERROR_MESSAGE << endl;
		}
	}
}

void editFormOfEducation(Student& temp_student)
{
	temp_student.is_budget_student = !temp_student.is_budget_student;
}

void editActivityOfSocialWork(Student& temp_student)
{
	temp_student.is_social_work = !temp_student.is_social_work;
}

void editOffsets(Student& temp_student)
{
	cout << MENU_OF_STUDENTS_OFFSETS << endl;
	int number = enterNumberInRange(0, MAX_OF_RANGE_MENU_OF_STUDENTS_OFFSETS);
	switch (number)
	{
	case 1:
		temp_student.offset.oopip = !temp_student.offset.oopip;
		break;
	case 2:
		temp_student.offset.discrete_math = !temp_student.offset.discrete_math;
		break;
	case 3:
		temp_student.offset.inad = !temp_student.offset.inad;
		break;
	case 4:
		temp_student.offset.history = !temp_student.offset.history;
		break;
	case 5:
		temp_student.offset.phys_culture = !temp_student.offset.phys_culture;
		break;
	case 0:
		break;
	default:
		cout << ERROR_MESSAGE << endl;
	}
}

void editExams(Student& temp_student)
{
	cout << MENU_OF_STUDENTS_EXAMS << endl;
	int number = enterNumberInRange(0, MAX_OF_RANGE_MENU_OF_STUDENTS_EXAMS);
	switch (number)
	{
	case 1:
		setOaip(temp_student);
		break;
	case 2:
		setMath(temp_student);
		break;
	case 3:
		setEnglish(temp_student);
		break;
	case 4:
		setPhysics(temp_student);
		break;
	case 0:
		break;
	default:
		cout << ERROR_MESSAGE << endl;
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
	default:
		cout << ERROR_MESSAGE << endl;
	}
}

void sortStudentOffsets(vector <Student>& vec_of_students)
{
	int number;
	cout << MENU_OF_STUDENTS_OFFSETS << endl;
	number = enterNumberInRange(0, MAX_OF_RANGE_MENU_OF_STUDENTS_OFFSETS);
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
	default:
		cout << ERROR_MESSAGE << endl;
	}
}

void sortStudentExams(vector <Student>& vec_of_students)
{
	int number;
	cout << MENU_OF_STUDENTS_EXAMS << endl;
	number = enterNumberInRange(0, MAX_OF_RANGE_MENU_OF_STUDENTS_EXAMS);
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
	default:
		cout << ERROR_MESSAGE << endl;
	}
}

void sortStudentsBy(vector <Student>& vec_of_students, bool (*comparisonFunction)(Student&, Student&))
{
	sort(vec_of_students.begin(), vec_of_students.end(), comparisonFunction);
}

bool mySortBySurnameAscending(Student& stu_1, Student& stu_2)
{
	return stu_1.FIO < stu_2.FIO;
}

bool mySortBySurnameDescending(Student& stu_1, Student& stu_2)
{
	return stu_1.FIO > stu_2.FIO;
}

bool mySortByGroupNumberAscending(Student& stu_1, Student& stu_2)
{
	return stoi(stu_1.num_of_group) < stoi(stu_2.num_of_group);
}

bool mySortByGroupNumberDescending(Student& stu_1, Student& stu_2)
{
	return stoi(stu_1.num_of_group) > stoi(stu_2.num_of_group);
}

bool mySortByAverageScoreAscending(Student& stu_1, Student& stu_2)
{
	return stu_1.exam.average_score < stu_2.exam.average_score;
}

bool mySortByAverageScoreDescending(Student& stu_1, Student& stu_2)
{
	return stu_1.exam.average_score > stu_2.exam.average_score;
}

bool mySortByStipendAscending(Student& stu_1, Student& stu_2)
{
	return stu_1.stipend < stu_2.stipend;
}

bool mySortByStipendDescending(Student& stu_1, Student& stu_2)
{
	return stu_1.stipend > stu_2.stipend;
}

bool mySortByFormOfEducationAscending(Student& stu_1, Student& stu_2)
{
	return stu_1.is_budget_student < stu_2.is_budget_student;
}

bool mySortByFormOfEducationDescending(Student& stu_1, Student& stu_2)
{
	return stu_1.is_budget_student > stu_2.is_budget_student;
}

bool mySortBySocialWorkAscending(Student& stu_1, Student& stu_2)
{
	return stu_1.is_social_work < stu_2.is_social_work;
}

bool mySortBySocialWorkDescending(Student& stu_1, Student& stu_2)
{
	return stu_1.is_social_work > stu_2.is_social_work;
}

bool mySortByOopipAscending(Student& stu_1, Student& stu_2)
{
	return stu_1.offset.oopip < stu_2.offset.oopip;
}

bool mySortByOopipDescending(Student& stu_1, Student& stu_2)
{
	return stu_1.offset.oopip > stu_2.offset.oopip;
}

bool mySortByDiscreteMathAscending(Student& stu_1, Student& stu_2)
{
	return stu_1.offset.discrete_math < stu_2.offset.discrete_math;
}

bool mySortByDiscreteMathDescending(Student& stu_1, Student& stu_2)
{
	return stu_1.offset.discrete_math > stu_2.offset.discrete_math;
}

bool mySortByInadAscending(Student& stu_1, Student& stu_2)
{
	return stu_1.offset.inad < stu_2.offset.inad;
}

bool mySortByInadDescending(Student& stu_1, Student& stu_2)
{
	return stu_1.offset.inad > stu_2.offset.inad;
}

bool mySortByHistoryAscending(Student& stu_1, Student& stu_2)
{
	return stu_1.offset.history < stu_2.offset.history;
}

bool mySortByHistoryDescending(Student& stu_1, Student& stu_2)
{
	return stu_1.offset.history > stu_2.offset.history;
}

bool mySortByPhysCultureAscending(Student& stu_1, Student& stu_2)
{
	return stu_1.offset.phys_culture < stu_2.offset.phys_culture;
}

bool mySortByPhysCultureDescending(Student& stu_1, Student& stu_2)
{
	return stu_1.offset.phys_culture > stu_2.offset.phys_culture;
}

bool mySortByOaipAscending(Student& stu_1, Student& stu_2)
{
	return stu_1.exam.oaip < stu_2.exam.oaip;
}

bool mySortByOaipDescending(Student& stu_1, Student& stu_2)
{
	return stu_1.exam.oaip > stu_2.exam.oaip;
}

bool mySortByMathAscending(Student& stu_1, Student& stu_2)
{
	return stu_1.exam.math < stu_2.exam.math;
}

bool mySortByMathDescending(Student& stu_1, Student& stu_2)
{
	return stu_1.exam.math > stu_2.exam.math;
}

bool mySortByEnglishAscending(Student& stu_1, Student& stu_2)
{
	return stu_1.exam.english < stu_2.exam.english;
}

bool mySortByEnglishDescending(Student& stu_1, Student& stu_2)
{
	return stu_1.exam.english > stu_2.exam.english;
}

bool mySortByPhysicsAscending(Student& stu_1, Student& stu_2)
{
	return stu_1.exam.physics < stu_2.exam.physics;
}

bool mySortByPhysicsDescending(Student& stu_1, Student& stu_2)
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
			showRequestsOfAccounts(vec_of_accounts, array);
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