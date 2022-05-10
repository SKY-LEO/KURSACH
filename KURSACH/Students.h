#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

#include "Validations.h"//���������� ��������� �������� �� ������������ ����

using namespace std;

//��������� �������
struct Offsets
{
	bool oopip;//�����, true - �����, false - �������
	bool discrete_math;//��, true - �����, false - �������
	bool inad;//����, true - �����, false - �������
	bool history;//�������, true - �����, false - �������
	bool phys_culture;//����, true - �����, false - �������
	bool is_offsets_submited = true;//���� ��� ��������, ������� �� ��� ������ true - ������� (�� ���������), false - �� �������
};

//��������� ���������
struct Exams
{
	int oaip;//����, ������
	int math;//��, ������
	int english;//����, ������
	int physics;//������, ������
	double average_score;//������� ���� �� ��������
};

//��������� ��������
struct Student
{
	string FIO;//���
	string num_of_group;//����� ������
	Offsets offset;//������
	Exams exam;//��������
	bool is_budget_student;//����� ��������, true - ���������, false - ������� 
	bool is_social_work;//������� � ������������ ������, true - ��������, false - ����������
	double stipend = 0.;//������ ���������
	double base_stipend = 0.;//������ ������� ���������
};

const string FILE_OF_STUDENTS = "students.txt";//�������� ����� �� ����������

const int MIN_EXAM = 4;//����������� ���� �� �������
const int MAX_EXAM = 10;//������������ ���� �� �������
const bool MIN_OFFSET = false;//�������
const bool MAX_OFFSET = true;//�����
const double MIN_MARK_FOR_STIPEND = 5.;//����������� ������� ���� ��� ��������� ���������
const double MIN_MARK_FOR_HIGH_STIPEND = 9.;//����������� ������� ���� ��� ��������� ���������� ���������
const double COEFFICIENT_FOR_HIGH_STIPEND = 1.25;//����������� ��� ���������� ���������
const double COEFFICIENT_FOR_HIGHEST_STIPEND = 1.5;//����������� ��� ������������ ���������

//��� �������
const string SEPARATOR_STUDENT = "|-------+---------------------+--------------+-------+--------+--------+-------+--------+--------+------+--------+----------+------------+-------------+--------------+-------------|";
const string SEPARATOR_OFFSETS_EXAMS = "------------------------------------------|-----------------------------------";
const string OAIP = "����";
const string MATH = "��";
const string ENGLISH = "����";
const string PHYSICS = "������";
const string OOPIP = "�����";
const string DISCRETE_MATH = "��";
const string INAD = "����";
const string HISTORY = "���";
const string PHYS_CULTURE = "����";

//�������
void showStudents(vector <Student>& vec_of_students);//����� � ������� ������ ��� ���� ���������
void drawHeader();//����� � ������� ����� �������
void displayStudent(Student& temp_student, int i);//����� � ������� ������ �� ����� ��������
string tellIsPassOrFailOffset(bool offset);//������� bool offset true/false � �����/�������
string tellIsBudgetOrPaidEducation(bool is_budget);//������� bool is_budget true/false � ���������/�������
string tellIsActiveOrPassiveSocialWork(bool is_social_work);//������� bool is_social_work true/false � ��������/����������

void addStudent(vector <Student>& vec_of_students);//���������� ������ ��������
string enterFio(vector <Student>& vec_of_students);//������� ����� ���
bool isGoodFio(vector <Student>& vec_of_students, string fio);//�������� �� ������������ ���
void setFio(vector <Student>& vec_of_students, Student& temp_student);//���������� ��� ��������
void setNumOfGroup(Student& temp_student);//���������� ������ ������ ��������
void setFormOfEducation(Student& temp_student);//���������� ����� �������� ��������
void setActivityOfSocialWork(Student& temp_student);//���������� ������� � ������������ ������ ��������

void setOffsets(Student& temp_student);//���������� ������� ��������
void setOopip(Student& temp_student);//����� �� �����
void setDiscreteMath(Student& temp_student);//����� �� ��
void setInad(Student& temp_student);//����� �� ����
void setHistory(Student& temp_student);//����� �� �������
void setPhysCulture(Student& temp_student);//����� �� ����
void setIsOffsetsSubmited(Student& temp_student);//�����������, ��� �� ������ �������

void setExams(Student& temp_student);//���������� ��������� ��������
void setOaip(Student& temp_student);//������ �� ����
void setMath(Student& temp_student);//������ �� ��
void setEnglish(Student& temp_student);//������ �� ����
void setPhysics(Student& temp_student);//������ �� ������
void setAverageScore(Student& temp_student);//���������� �������� ����� �� ��������
int rateStudent(int min_range, int max_of_range, string subject);//�������, ������������� ������ �� ������������� ��������

void editStipends(vector <Student>& vec_of_students);//���������� ������� ��������� ��� �������������� ������ �������� ��� ������� ���������
void calculateStipends(vector <Student>& vec_of_students);//������ ���������
double calculateCoefficient(Student& student);//���������� ������������ ���������
double enterStipend();//���� ������� ���������
bool isGoodStipend(double stipend);//�������� �� ��������������� ���������

int indexOfVectorForChange(vector <Student>& vec_of_students);//����� �������� ��� ��������������
void deleteStudent(vector <Student>& vec_of_students);//�������� ���������� ��������

void editFormOfEducation(Student& temp_student);//�������������� ����� ��������
void editActivityOfSocialWork(Student& temp_student);//�������������� ������� � ������������ ������

void saveToMainVectorOfStudents(vector <Student>& vec_of_students, vector <Student>& vec_of_finded_students);//����� �� ��������� ��������� ����������� ����������, ��������������
																											 //� ��������, ���������� ������� �������������� ������
void searchByFio(vector <Student>& vec_of_students, vector <Student>& vec_of_finded_students);//����� �� ���
void searchByNumberOfGroup(vector <Student>& vec_of_students, vector <Student>& vec_of_finded_students);//����� �� ������ ������
void searchByAverageScore(vector <Student>& vec_of_students, vector <Student>& vec_of_finded_students);//����� �� ������� ����� �� a �� b
bool isGoodAverageScoreMin(double min);//����������� ������� ���� ������ ���� ������ ����������� ����������
bool isGoodAverageScoreMax(double max);//������������ ������� ���� ������ ���� ������ ���������� ���������� 
bool isMinLessMax(double min, double max);//����������� ������� ���� ������ ���� ������ �������������
void clearNotEmptyVector(vector<Student>& vec);//��� ����� ������ �������������� ������ ���� ��������

void readFileOfStudents(vector <Student>& vec_of_students);//������� ���������� ������� ������� �� �����
void writeFileOfStudents(vector <Student>& vec_of_students);//������� ������ � ���� ������ �� �������
int getCountOfStructuresStudent(string file_path);//����������� ���������� ������� � ����� ��� �������������� ����� � �������