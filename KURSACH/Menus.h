#pragma once

#include <iostream>
#include <vector>

#include "Accounts.h"//���������� ����������� ��� ������ ������ � �������� �������� � ����������� � �������
#include "Students.h"//���������� ����������� ��� ������ ������ �� ���������� � �����������
#include "Sorts.h"//���������� ����������
#include "Validations.h"//���������� ��������� �������� �� ������������ ����

using namespace std;

//��������� ��� ����������� ������������� ���������� ������ � ��������� ����
const int MAX_OF_RANGE_START_MENU = 2;
const int MAX_OF_RANGE_MAIN_MENU_USER = 2;
const int MAX_OF_RANGE_MAIN_MENU_ADMIN = 3;
const int MAX_OF_RANGE_MENU_ADMIN = 6;
const int MAX_OF_RANGE_MENU_ADMIN_WITHOUT_ACCESS = 5;
const int MAX_OF_RANGE_MENU_ACCESS = 2;
const int MAX_OF_RANGE_MENU_OF_SORTS_ACCOUNTS = 3;
const int MAX_OF_RANGE_MENU_OF_STUDENTS_ADMIN = 6;
const int MAX_OF_RANGE_MENU_OF_STUDENTS_USER = 3;
const int MAX_OF_RANGE_MENU_OF_SORTS_STUDENTS = 8;
const int MAX_OF_RANGE_MENU_OF_ASCENDING_DESCENDING = 2;
const int MAX_OF_RANGE_MENU_OF_STUDENTS_OFFSETS = 5;
const int MAX_OF_RANGE_MENU_OF_STUDENTS_EXAMS = 4;
const int MAX_OF_RANGE_MENU_OF_EDIT_STUDENT = 6;
const int MAX_OF_RANGE_MENU_OF_SEARCH_STUDENTS_ADMIN = 6;
const int MAX_OF_RANGE_MENU_OF_SEARCH_STUDENTS_USER = 4;
const int MAX_OF_RANGE_MENU_OF_SEARCH_STUDENTS_ONLY_SEARCHES = 3;

//��������� ��������� ��� ��������� ����
const string START_MENU = "������������, �����! ����������, �������� ����� ����:\n1) ����� � ������������ ������� ������\n2) ������� ����� ������� ������\n0) ���������� ������";
const string MAIN_MENU_USER = "�� ���������� � ������� ���� ������������.\n1) ������ ������ �� �����������\n2) ������� ������\n0) �����";
const string MAIN_MENU_ADMIN = "�� ���������� � ������� ���� ��������������.\n1) ������ ������ �� �����������\n2) ������ ������ � �������� ��������\n3) ������� ������\n0) �����";
const string MENU_OF_ACCOUNT_ADMIN = "�� ���������� � ���� ������ � �������� ��������.\n1) �����������\n2) �������\n3) �������� ������\n4) �������� ����\n5) ������� �������\n6) ������� �� ������";
const string MENU_OF_ACCOUNT_ADMIN_WITHOUT_ACCESS = "�� ���������� � ���� ������ � �������� ��������.\n1) �����������\n2) �������\n3) �������� ������\n4) �������� ����\n5) ������� �������\n0) �����";
const string MENU_OF_ACCESS = "�� ���������� � ���� ������ � �������� �� ������ � �������.\n1) ����������� ������\n2) ������������� ������\n0) �����";
const string MENU_OF_SORTS_ACCOUNTS = "�� ���������� � ���� ���������� ������� �������.\n����������� ��:\n1) ������\n2) ����\n3) �������\n0) �����";
const string STUDENT_MENU_ADMIN = "�� ���������� � ���� ������ �� �����������.\n1) ������ ���������\n2) �����\n3) ����������\n4) �������� ��������\n5) ������������� ������\n6) ������� ��������\n0) �����";
const string STUDENT_MENU_USER = "�� ���������� � ���� ������ �� �����������.\n1) ������ ���������\n2) �����\n3) ����������\n0) �����";
const string MENU_OF_SORTS_STUDENTS = "�� ���������� � ���� ���������� ���������.\n����������� ��:\n1) ���\n2) ������ ������\n3) �������� �����\n4) ���������\n5) ����� �������\n6) ����� ���������\n7) ����� ��������\n8) ������� � ������������ ������\n0) �����";
const string MENU_OF_ASCENDING_DESCENDING = "����������� ��:\n1) �����������\n2) ��������";
const string MENU_OF_STUDENTS_OFFSETS = "�� ���������� � ���� ������ ������.\n�������� �������:\n1) �����\n2) ��\n3) ����\n4) ���\n5) ����\n0) �����";
const string MENU_OF_STUDENTS_EXAMS = "�� ���������� � ���� ������ ��������.\n�������� �������:\n1) ����\n2) ��\n3) ����\n4) ������\n0) �����";
const string MENU_OF_EDIT_STUDENT = "�� ���������� � ���� �������������� ���������.\n���������������: \n1) ���\n2) ����� ������\n3) ������\n4) ��������\n5) ����� ��������\n6) ������� � ������������ ������\n0) �����";
const string MENU_OF_SEARCH_STUDENTS_ADMIN = "�� ���������� � ���� ������ ���������.\n1) ������ �� ���\n2) ������ �� ������ ������\n3) ������ �� �������� �����\n4) ������������� ���������\n5) ������������� ������\n6) ������� ��������\n0) �����";
const string MENU_OF_SEARCH_STUDENTS_USER = "�� ���������� � ���� ������ ���������.\n1) ������ �� ���\n2) ������ �� ������ ������\n3) ������ �� �������� �����\n4) ������������� ���������\n0) �����";
const string MENU_OF_SEARCH_STUDENTS_ONLY_SEARCHES = "�� ���������� � ���� ������ ���������.\n1) ������ �� ���\n2) ������ �� ������ ������\n3) ������ �� �������� �����\n0) �����";
const string ERROR_MESSAGE = "������!";

//�������
void core(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students);//������� �������
int initialisation(vector <Account>& vec_of_accounts);//������� ���� START_MENU, ��� ���������� ���� � �������, �������� ������ ��������, ���������� ������
int user(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students, int index_of_user);//������� ���� MAIN_MENU_USER
int admin(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students, int index_of_user);//������� ���� MAIN_MENU_ADMIN

void workWithAccounts(vector <Account>& vec_of_accounts, int& index_of_user);//������� � ���� ������ ������ � ����������, ���� ������� �� ���� ������������ 
void workWithAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array);//������� ���� MENU_OF_ACCESS ��� ������ � ��������� �� ������ � �������
void sortAccounts(vector <Account>& vec_of_accounts);//������� ���� MENU_OF_SORTS_ACCOUNTS ��� ������ ����������

void workWithStudents(vector <Student>& vec_of_students, bool is_admin);//������� � ���� ������ ������ �� ����������, ���� ������� �� ���� ������������ 
void sortStudents(vector <Student>& vec_of_students);//������� ���� MENU_OF_SORTS_STUDENTS ��� ������ ����������
void sortStudentOffsets(vector <Student>& vec_of_students);//������� ������� MENU_OF_STUDENTS_OFFSETS ���� MENU_OF_SORTS_STUDENTS ��� ������ ������, �� �������� ���� �������������
void sortStudentExams(vector <Student>& vec_of_students);//������� ������� MENU_OF_STUDENTS_EXAMS ���� MENU_OF_SORTS_STUDENTS ��� ������ ��������, �� �������� ���� �������������
void editStudent(vector <Student>& vec_of_students);//������� ���� MENU_OF_EDIT_STUDENT ��� �������������� ������ ��������
void editOffsets(Student& temp_student);//������� ������� ���� MENU_OF_EDIT_STUDENT ��� �������������� ������� ��������
void editExams(Student& temp_student);//������� ������� ���� MENU_OF_EDIT_STUDENT ��� �������������� ��������� ��������
void searchStudents(vector <Student>& vec_of_students, bool is_admin);//������� ���� ��� ������ ��������� �� ��������� ����, ���� ������� �� ���� ������������

bool isAscending();//������� ���� MENU_OF_ASCENDING_DESCENDING ��� ����������� ���������� �� ����������� ��� ��������