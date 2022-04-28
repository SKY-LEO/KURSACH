#include "Sorts.h"

//--------------------Accounts--------------------

void sortAccountsBy(vector <Account>& vec_of_accounts, bool (*comparisonFunction)(Account&, Account&))
{
	sort(vec_of_accounts.begin(), vec_of_accounts.end(), comparisonFunction);
}

bool mySortByAccessAscending(Account& acc_1, Account& acc_2)
{
	return acc_1.access < acc_2.access;
}

bool mySortByAccessDescending(Account& acc_1, Account& acc_2)
{
	return acc_1.access > acc_2.access;
}

bool mySortByRoleAscending(Account& acc_1, Account& acc_2)
{
	return acc_1.role < acc_2.role;
}

bool mySortByRoleDescending(Account& acc_1, Account& acc_2)
{
	return acc_1.role > acc_2.role;
}

bool mySortByLoginAscending(Account& acc_1, Account& acc_2)
{
	return acc_1.login < acc_2.login;
}

bool mySortByLoginDescending(Account& acc_1, Account& acc_2)
{
	return acc_1.login > acc_2.login;
}

//--------------------Students--------------------

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