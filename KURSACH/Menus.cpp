#include "Menus.h"

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
			flag = false;
		}
	}
}

int initialisation(vector <Account>& vec_of_accounts)
{
	cout << START_MENU << endl;
	int number = enterNumberInRange(0, MAX_OF_RANGE_START_MENU);
	system("cls");
	switch (number)
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
		return number;
	}
}

int user(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students, int index_of_user)
{
	bool flag = true;
	while (flag)
	{
		cout << MAIN_MENU_USER << endl;
		int number = enterNumberInRange(0, MAX_OF_RANGE_MAIN_MENU_USER);
		switch (number)
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
		int number = enterNumberInRange(0, MAX_OF_RANGE_MAIN_MENU_ADMIN);
		switch (number)
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
	int number;
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
		if (array.empty())
		{
			cout << MENU_OF_ACCOUNT_ADMIN_WITHOUT_ACCESS << endl;
			number = enterNumberInRange(0, MAX_OF_RANGE_MENU_ADMIN_WITHOUT_ACCESS);
		}
		else
		{
			cout << MENU_OF_ACCOUNT_ADMIN << "(Новых запросов: " << array.size() << ")\n0) Назад" << endl;
			number = enterNumberInRange(0, MAX_OF_RANGE_MENU_ADMIN);
		}
		switch (number)
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

void workWithAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array)
{
	bool flag = true;
	int number;
	while (flag)
	{
		if (!array.empty())
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

void workWithStudents(vector <Student>& vec_of_students, bool is_admin)
{
	int number;
	bool flag = true;
	while (flag)
	{
		system("cls");
		showStudents(vec_of_students);
		if (is_admin)
		{
			cout << STUDENT_MENU_ADMIN << endl;
			number = enterNumberInRange(0, MAX_OF_RANGE_MENU_OF_STUDENTS_ADMIN);
		}
		else
		{
			cout << STUDENT_MENU_USER << endl;
			number = enterNumberInRange(0, MAX_OF_RANGE_MENU_OF_STUDENTS_USER);
		}
		switch (number)
		{
		case 1:
			calculateStipends(vec_of_students);
			break;
		case 2:
			system("cls");
			searchStudents(vec_of_students, is_admin);
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

void editStudent(vector <Student>& vec_of_students)
{
	bool flag = true;
	cout << "Какого студента вы хотите отредактировать?\nНазад - 0" << endl;
	int index_for_change = indexOfVectorForChange(vec_of_students);
	if (index_for_change == 0)return;
	else index_for_change--;
	while (flag)
	{
		system("cls");
		drawHeader();
		displayStudent(vec_of_students.at(index_for_change), index_for_change);
		cout << endl;
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

void searchStudents(vector <Student>& vec_of_students, bool is_admin)
{
	int number;
	bool flag = true;
	vector <Student> vec_of_finded_students;
	while (flag)
	{
		system("cls");
		if (!vec_of_finded_students.empty())
		{
			showStudents(vec_of_finded_students);
			if (is_admin)
			{
				cout << MENU_OF_SEARCH_STUDENTS_ADMIN << endl;
				number = enterNumberInRange(0, MAX_OF_RANGE_MENU_OF_SEARCH_STUDENTS_ADMIN);
			}
			else
			{
				cout << MENU_OF_SEARCH_STUDENTS_USER << endl;
				number = enterNumberInRange(0, MAX_OF_RANGE_MENU_OF_SEARCH_STUDENTS_USER);
			}
		}
		else
		{
			cout << MENU_OF_SEARCH_STUDENTS_ONLY_SEARCHES << endl;
			number = enterNumberInRange(0, MAX_OF_RANGE_MENU_OF_SEARCH_STUDENTS_ONLY_SEARCHES);
		}
		switch (number)
		{
		case 1:
			saveToMainVectorOfStudents(vec_of_students, vec_of_finded_students);
			searchByFio(vec_of_students, vec_of_finded_students);
			break;
		case 2:
			saveToMainVectorOfStudents(vec_of_students, vec_of_finded_students);
			searchByNumberOfGroup(vec_of_students, vec_of_finded_students);
			break;
		case 3:
			saveToMainVectorOfStudents(vec_of_students, vec_of_finded_students);
			searchByAverageScore(vec_of_students, vec_of_finded_students);
			break;
		case 4:
			sortStudents(vec_of_finded_students);
			break;
		case 5:
			editStudent(vec_of_finded_students);
			break;
		case 6:
			deleteStudent(vec_of_finded_students);
			break;
		case 0:
			saveToMainVectorOfStudents(vec_of_students, vec_of_finded_students);
			flag = false;
			break;
		default:
			cout << ERROR_MESSAGE << endl;
		}
	}
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