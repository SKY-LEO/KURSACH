#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include "Validations.h"
#include "Menus.h"

using namespace std;

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
	double average_score;
	double stipend = 0.;
};

const int MIN_EXAM = 4;
const int MAX_EXAM = 10;
const int MIN_OFFSET = 0;
const int MAX_OFFSET = 1;

const string SEPARATOR_STUDENT = "------------------------------------------------";
const string FILE_OF_STUDENTS = "students.txt";
const string STUDENT_MENU_ADMIN = "\n1) ������ ���������\n2) �����\n3) ����������\n4) �������� ��������\n5) ������������� ������\n6) ������� ��������\n0) �����";
const string STUDENT_MENU_USER = "\n1) ������ ���������\n2) �����\n3) ����������\n0) �����";
const string OAIP = "����";
const string MATH = "��";
const string ENGLISH = "����";
const string PHYSICS = "������";
const string OOPIP = "�����";
const string DISCRETE_MATH = "��";
const string INAD = "����";
const string HISTORY = "���";
const string PHYS_CULTURE = "����";

void showStudents(vector <Student>& vec_of_students);
void calculateStipends(vector <Student>& vec_of_students);
void searchStudents(vector <Student>& vec_of_students);
void addStudent(vector <Student>& vec_of_students);
bool isGoodFio(vector <Student>& vec_of_students, string fio);
void setOffsets(Student& temp_student);
void setExams(Student& temp_student);
int rateStudent(int min_range, int max_of_range, string subject);
void editStudent(vector <Student>& vec_of_students);
void deleteStudent(vector <Student>& vec_of_students);
int indexOfVectorForChange(vector <Student>& vec_of_students);
void writeFileOfStudents(vector <Student>& vec_of_students);
void readFileOfStudents(vector <Student>& vec_of_students);

