#pragma once

#include <iostream>
#include <vector>

#include "Accounts.h"
#include "Students.h"
#include "Sorts.h"
#include "Validations.h"

using namespace std;

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

const string START_MENU = "Здравствуйте, гость! Пожалуйста, выберите пункт меню:\n1) Войти в существующую учётную запись\n2) Создать новую учётную запись\n0) Завершение работы";
const string MAIN_MENU_ADMIN = "Вы находитесь в главном меню администратора.\n1) Модуль работы со стипендиями\n2) Модуль работы с учётными записями\n3) Сменить пароль\n0) Выход";
const string MAIN_MENU_USER = "Вы находитесь в главном меню пользователя.\n1) Модуль работы со стипендиями\n2) Сменить пароль\n0) Выход";
const string MENU_OF_ACCOUNT_ADMIN = "Вы находитесь в меню работы с учётными записями.\n1) Сортировать\n2) Удалить\n3) Изменить доступ\n4) Изменить роль\n5) Создать аккаунт\n6) Запросы на доступ";
const string MENU_OF_ACCOUNT_ADMIN_WITHOUT_ACCESS = "Вы находитесь в меню работы с учётными записями.\n1) Сортировать\n2) Удалить\n3) Изменить доступ\n4) Изменить роль\n5) Создать аккаунт\n0) Назад";
const string MENU_OF_ACCESS = "Вы находитесь в меню работы с заявками на доступ к системе.\n1) Подтвердить доступ\n2) Заблокировать доступ\n0) Назад";
const string MENU_OF_SORTS_ACCOUNTS = "Вы находитесь в меню сортировки учётных записей.\nСортировать по:\n1) Логину\n2) Роли\n3) Доступу\n0) Назад";
const string MENU_OF_SORTS_STUDENTS = "Вы находитесь в меню сортировки студентов.\nСортировать по:\n1) Фамилии\n2) Номеру группы\n3) Среднему баллу\n4) Стипендии\n5) Сдаче зачетов\n6) Сдаче экзаменов\n7) Форме обучения\n8) Участию в общественной работе\n0) Назад";
const string MENU_OF_ASCENDING_DESCENDING = "Упорядочить по:\n1) Возрастанию\n2) Убыванию";
const string STUDENT_MENU_ADMIN = "Вы находитесь в меню работы со стипендиями.\n1) Расчет стипендии\n2) Поиск\n3) Сортировка\n4) Добавить студента\n5) Редактировать данные\n6) Удалить студента\n0) Назад";
const string STUDENT_MENU_USER = "Вы находитесь в меню работы со стипендиями.\n1) Расчет стипендии\n2) Поиск\n3) Сортировка\n0) Назад";
const string MENU_OF_STUDENTS_OFFSETS = "Вы находитесь в меню выбора зачета.\nВыберите предмет:\n1) ООПиП\n2) ДМ\n3) ИнАД\n4) Ист\n5) ФизК\n0) Назад";
const string MENU_OF_STUDENTS_EXAMS = "Вы находитесь в меню выбора экзамена.\nВыберите предмет:\n1) ОАиП\n2) МА\n3) ИнЯз\n4) Физика\n0) Назад";
const string MENU_OF_EDIT_STUDENT = "Вы находитесь в меню редактирования студентов.\nОтредактировать: \n1) ФИО\n2) Номер группы\n3) Зачеты\n4) Экзамены\n5) Форму обучения\n6) Участие в общественной работе\n0) Назад";
const string MENU_OF_SEARCH_STUDENTS_ADMIN = "Вы находитесь в меню поиска студентов.\n1) Искать по ФИО\n2) Искать по номеру группы\n3) Искать по среднему баллу\n4) Отсортировать результат\n5) Редактировать данные\n6) Удалить студента\n0) Назад";
const string MENU_OF_SEARCH_STUDENTS_USER = "Вы находитесь в меню поиска студентов.\n1) Искать по ФИО\n2) Искать по номеру группы\n3) Искать по среднему баллу\n4) Отсортировать результат\n0) Назад";
const string MENU_OF_SEARCH_STUDENTS_ONLY_SEARCHES = "Вы находитесь в меню поиска студентов.\n1) Искать по ФИО\n2) Искать по номеру группы\n3) Искать по среднему баллу\n0) Назад";
const string ERROR_MESSAGE = "Ошибка!";

void core(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students);
int initialisation(vector <Account>& vec_of_accounts);
int user(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students, int index_of_user);
int admin(vector <Account>& vec_of_accounts, vector <Student>& vec_of_students, int index_of_user);

void workWithAccounts(vector <Account>& vec_of_accounts, int& index_of_user);
void workWithAccessOfAccounts(vector <Account>& vec_of_accounts, vector <int>& array);
void sortAccounts(vector <Account>& vec_of_accounts);

void workWithStudents(vector <Student>& vec_of_students, bool is_admin);
void sortStudents(vector <Student>& vec_of_students);
void sortStudentOffsets(vector <Student>& vec_of_students);
void sortStudentExams(vector <Student>& vec_of_students);
void editStudent(vector <Student>& vec_of_students);
void editOffsets(Student& temp_student);
void editExams(Student& temp_student);
void searchStudents(vector <Student>& vec_of_students, bool is_admin);

bool isAscending();