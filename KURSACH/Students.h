#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

#include "Validations.h"//реализация различных проверок на некорректный ввод

using namespace std;

//структура зачетов
struct Offsets
{
	bool oopip;//ООПиП, true - зачет, false - незачет
	bool discrete_math;//ДМ, true - зачет, false - незачет
	bool inad;//ИнАД, true - зачет, false - незачет
	bool history;//История, true - зачет, false - незачет
	bool phys_culture;//ФизК, true - зачет, false - незачет
	bool is_offsets_submited = true;//поле для проверки, зачтены ли все зачеты true - зачтены (по умолчанию), false - не зачтены
};

//структура экзаменов
struct Exams
{
	int oaip;//ОАиП, оценка
	int math;//МА, оценка
	int english;//ИнЯз, оценка
	int physics;//Физика, оценка
	double average_score;//средний балл за экзамены
};

//структура студента
struct Student
{
	string FIO;//ФИО
	string num_of_group;//номер группы
	Offsets offset;//зачеты
	Exams exam;//экзамены
	bool is_budget_student;//форма обучения, true - бюджетная, false - платная 
	bool is_social_work;//участие в общественной работе, true - активное, false - неактивное
	double stipend = 0.;//размер стипендии
	double base_stipend = 0.;//размер базовой стипендии
};

const string FILE_OF_STUDENTS = "students.txt";//название файла со студентами

const int MIN_EXAM = 4;//минимальный балл за экзамен
const int MAX_EXAM = 10;//максимальный балл за экзамен
const bool MIN_OFFSET = false;//незачет
const bool MAX_OFFSET = true;//зачет
const double MIN_MARK_FOR_STIPEND = 5.;//минимальный средний балл для получения стипендии
const double MIN_MARK_FOR_HIGH_STIPEND = 9.;//минимальный средний балл для получения повышенной стипендии
const double COEFFICIENT_FOR_HIGH_STIPEND = 1.25;//коэффициент для повышенной стипендии
const double COEFFICIENT_FOR_HIGHEST_STIPEND = 1.5;//коэффициент для максимальной стипендии

//для таблицы
const string SEPARATOR_STUDENT = "|-------+---------------------+--------------+-------+--------+--------+-------+--------+--------+------+--------+----------+------------+-------------+--------------+-------------|";
const string SEPARATOR_OFFSETS_EXAMS = "------------------------------------------|-----------------------------------";
const string OAIP = "ОАиП";
const string MATH = "МА";
const string ENGLISH = "ИнЯз";
const string PHYSICS = "Физика";
const string OOPIP = "ООПиП";
const string DISCRETE_MATH = "ДМ";
const string INAD = "ИнАД";
const string HISTORY = "Ист";
const string PHYS_CULTURE = "ФизК";

//функции
void showStudents(vector <Student>& vec_of_students);//вывод в консоль данных обо всех студентах
void drawHeader();//вывод в консоль шапки таблицы
void displayStudent(Student& temp_student, int i);//вывод в консоль данных об одном студенте
string tellIsPassOrFailOffset(bool offset);//перевод bool offset true/false в зачет/незачет
string tellIsBudgetOrPaidEducation(bool is_budget);//перевод bool is_budget true/false в бюджетная/платная
string tellIsActiveOrPassiveSocialWork(bool is_social_work);//перевод bool is_social_work true/false в активная/неактивная

void addStudent(vector <Student>& vec_of_students);//добавление нового студента
string enterFio(vector <Student>& vec_of_students);//функция ввода ФИО
bool isGoodFio(vector <Student>& vec_of_students, string fio);//проверка на уникальность ФИО
void setFio(vector <Student>& vec_of_students, Student& temp_student);//присвоение ФИО студенту
void setNumOfGroup(Student& temp_student);//присвоение номера группы студенту
void setFormOfEducation(Student& temp_student);//присвоение формы обучения студенту
void setActivityOfSocialWork(Student& temp_student);//присвоение участия в общественной работе студенту

void setOffsets(Student& temp_student);//присвоение зачетов студенту
void setOopip(Student& temp_student);//зачет по ООПиП
void setDiscreteMath(Student& temp_student);//зачет по ДМ
void setInad(Student& temp_student);//зачет по ИнАд
void setHistory(Student& temp_student);//зачет по Истории
void setPhysCulture(Student& temp_student);//зачет по ФизК
void setIsOffsetsSubmited(Student& temp_student);//определение, все ли зачеты зачтены

void setExams(Student& temp_student);//присвоение экзаменов студенту
void setOaip(Student& temp_student);//оценка по ОАиП
void setMath(Student& temp_student);//оценка по МА
void setEnglish(Student& temp_student);//оценка по ИнЯз
void setPhysics(Student& temp_student);//оценка по Физике
void setAverageScore(Student& temp_student);//вычисление среднего балла за экзамены
int rateStudent(int min_range, int max_of_range, string subject);//функция, запрашивающая оценку по определенному предмету

void editStipends(vector <Student>& vec_of_students);//обновление размера стипендии при редактировании данных студента или базовой стипендии
void calculateStipends(vector <Student>& vec_of_students);//расчет стипендии
double calculateCoefficient(Student& student);//вычисление коэффициента стипендии
double enterStipend();//ввод базовой стипендии
bool isGoodStipend(double stipend);//проверка на положительность стипендии

int indexOfVectorForChange(vector <Student>& vec_of_students);//выбор студента для редактирования
void deleteStudent(vector <Student>& vec_of_students);//удаление выбранного студента

void editFormOfEducation(Student& temp_student);//редактирование формы обучения
void editActivityOfSocialWork(Student& temp_student);//редактирование участия в общественной работе

void saveToMainVectorOfStudents(vector <Student>& vec_of_students, vector <Student>& vec_of_finded_students);//чтобы по найденным студентам реализовать сортировку, редактирование
																											 //и удаление, необходимо создать дополнительный вектор
void searchByFio(vector <Student>& vec_of_students, vector <Student>& vec_of_finded_students);//поиск по ФИО
void searchByNumberOfGroup(vector <Student>& vec_of_students, vector <Student>& vec_of_finded_students);//поиск по номеру группы
void searchByAverageScore(vector <Student>& vec_of_students, vector <Student>& vec_of_finded_students);//поиск по средему баллу от a до b
bool isGoodAverageScoreMin(double min);//минимальный средний балл должен быть меньше максимально возможного
bool isGoodAverageScoreMax(double max);//максимальный средний балл должен быть больше минимально возможного 
bool isMinLessMax(double min, double max);//минимальный средний балл должен быть меньше максимального
void clearNotEmptyVector(vector<Student>& vec);//при новом поиске дополнительный вектор надо очистить

void readFileOfStudents(vector <Student>& vec_of_students);//функция заполнения вектора данными из файла
void writeFileOfStudents(vector <Student>& vec_of_students);//функция записи в файл данных из вектора
int getCountOfStructuresStudent(string file_path);//определение количества струтур в файле для резервирования места в векторе