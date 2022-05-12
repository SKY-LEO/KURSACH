#pragma once

#include <algorithm>
#include <vector>

#include "Accounts.h"//реализация функционала для модуля работы с учетными записями и авторизации в систему
#include "Students.h"//реализация функционала для модуля работы со студентами и стипендиями

void sortAccountsBy(vector <Account>& vec_of_accounts, bool (*comparisonFunction)(Account&, Account&));//сортировка аккаунтов
//компараторы
bool mySortByAccessAscending(Account& acc_1, Account& acc_2);
bool mySortByAccessDescending(Account& acc_1, Account& acc_2);
bool mySortByRoleAscending(Account& acc_1, Account& acc_2);
bool mySortByRoleDescending(Account& acc_1, Account& acc_2);
bool mySortByLoginAscending(Account& acc_1, Account& acc_2);
bool mySortByLoginDescending(Account& acc_1, Account& acc_2);

void sortStudentsBy(vector <Student>& vec_of_students, bool (*comparisonFunction)(Student&, Student&));//сортировка студентов
//компараторы
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
bool mySortByOaipAscending(Student& stu_1, Student& stu_2);
bool mySortByOaipDescending(Student& stu_1, Student& stu_2);
bool mySortByMathAscending(Student& stu_1, Student& stu_2);
bool mySortByMathDescending(Student& stu_1, Student& stu_2);
bool mySortByEnglishAscending(Student& stu_1, Student& stu_2);
bool mySortByEnglishDescending(Student& stu_1, Student& stu_2);
bool mySortByPhysicsAscending(Student& stu_1, Student& stu_2);
bool mySortByPhysicsDescending(Student& stu_1, Student& stu_2);