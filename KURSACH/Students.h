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
	bool is_offsets_submited = true;
};

struct Exams
{
	int oaip;
	int math;
	int english;
	int physics;
	double average_score;
};

struct Student
{
	string FIO;
	string num_of_group;
	Offsets offset;
	Exams exam;
	bool is_budget_student;
	bool is_social_work;
	double stipend = 0.;
	double base_stipend = 0.;
};

const int MIN_EXAM = 4;
const int MAX_EXAM = 10;
const int MIN_OFFSET = 0;
const int MAX_OFFSET = 1;
const double MIN_MARK_FOR_STIPEND = 5;
const double MIN_MARK_FOR_HIGH_STIPEND = 9;
const double COEFFICIENT_FOR_HIGH_STIPEND = 1.25;
const double COEFFICIENT_FOR_HIGHEST_STIPEND = 1.5;

const string SEPARATOR_STUDENT = "|-------+---------------------+--------------+-------+--------+--------+-------+--------+--------+------+--------+----------+------------+-------------+--------------+-------------|";
const string SEPARATOR_OFFSETS_EXAMS = "------------------------------------------|-----------------------------------";
const string FILE_OF_STUDENTS = "students.txt";
const string STUDENT_MENU_ADMIN = "Вы находитесь в меню работы со стипендиями.\n1) Расчет стипендии\n2) Поиск\n3) Сортировка\n4) Добавить студента\n5) Редактировать данные\n6) Удалить студента\n0) Назад";
const string STUDENT_MENU_USER = "Вы находитесь в меню работы со стипендиями.\n1) Расчет стипендии\n2) Поиск\n3) Сортировка\n0) Назад";
const string OAIP = "ОАиП";
const string MATH = "МА";
const string ENGLISH = "ИнЯз";
const string PHYSICS = "Физика";
const string OOPIP = "ООПиП";
const string DISCRETE_MATH = "ДМ";
const string INAD = "ИнАД";
const string HISTORY = "Ист";
const string PHYS_CULTURE = "ФизК";

void showStudents(vector <Student>& vec_of_students);
void drawHeader();
void displayStudent(Student& temp_student, int i);
void calculateStipends(vector <Student>& vec_of_students);
void addStudent(vector <Student>& vec_of_students);
bool isGoodFio(vector <Student>& vec_of_students, string fio);
void setFio(vector <Student>& vec_of_students, Student& temp_student);
string enterFio(vector <Student>& vec_of_students);
void setNumOfGroup(Student& temp_student);
void setFormOfEducation(Student& temp_student);
void setActivityOfSocialWork(Student& temp_student);
void setOffsets(Student& temp_student);
void setExams(Student& temp_student);
int rateStudent(int min_range, int max_of_range, string subject);
void deleteStudent(vector <Student>& vec_of_students);
int indexOfVectorForChange(vector <Student>& vec_of_students);
void writeFileOfStudents(vector <Student>& vec_of_students);
void readFileOfStudents(vector <Student>& vec_of_students);
void calculateStipends(vector <Student>& vec_of_students);
double calculateCoefficient(Student& student);
double enterStipend();
bool isGoodStipend(double stipend);
void editStipends(vector <Student>& vec_of_students);
string tellIsPassOrFailOffset(bool offset);
string tellIsBudgetOrPaidEducation(bool is_budget);
string tellIsActiveOrPassiveSocialWork(bool is_social_work);
void setAverageScore(Student& temp_student);
void setOaip(Student& temp_student);
void setMath(Student& temp_student);
void setEnglish(Student& temp_student);
void setPhysics(Student& temp_student);
void setOopip(Student& temp_student);
void setDiscreteMath(Student& temp_student);
void setInad(Student& temp_student);
void setHistory(Student& temp_student);
void setPhysCulture(Student& temp_student);
void setIsOffsetsSubmited(Student& temp_student);