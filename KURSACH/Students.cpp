#include "Students.h"

void showStudents(vector <Student>& vec_of_students)
{
	cout << endl;
	cout << "№\t|" << "ФИО\t|" << "№ группы\t|" << "ООПиП\t|" << "ДМ\t|" << "ИнАД\t|" << "Ист\t|" << "ФизК\t|"
		<< "ОАиП\t|" << "МА\t|" << "ИнЯз\t|" << "Физика\t|" << "Бюджет\t|" << "Активность\t|" << endl;
	cout << SEPARATOR_STUDENT << endl;
	for (unsigned int i = 0; i < vec_of_students.size(); i++)
	{
		cout << i + 1 << "\t|" << vec_of_students.at(i).FIO << "\t|" << vec_of_students.at(i).num_of_group
			<< "\t|" << vec_of_students.at(i).offset.oopip << "\t|" << vec_of_students.at(i).offset.discrete_math
			<< "\t|" << vec_of_students.at(i).offset.inad << "\t|" << vec_of_students.at(i).offset.history
			<< "\t|" << vec_of_students.at(i).offset.phys_culture
			<< "\t|" << vec_of_students.at(i).exam.oaip << "\t|" << vec_of_students.at(i).exam.math
			<< "\t|" << vec_of_students.at(i).exam.english << "\t|" << vec_of_students.at(i).exam.physics
			<< "\t|" << vec_of_students.at(i).is_budget_student << "\t|" << vec_of_students.at(i).is_social_work 
			<< "\t|" << vec_of_students.at(i).average_score << "\t|" << vec_of_students.at(i).stipend << endl;
	}
	cout << SEPARATOR_STUDENT << endl;
	cout << endl;
}

void calculateStipends(vector <Student>& vec_of_students) {}



void searchStudents(vector <Student>& vec_of_students) {}

void addStudent(vector <Student>& vec_of_students)
{
	Student temp_student;
	string fio;
	while (true)
	{
		cout << "\nФИО: ";
		fio = enterStringWithoutNumbers();
		if (isGoodFio(vec_of_students, fio))
		{
			temp_student.FIO = fio;
			break;
		}
		else
		{
			system("cls");
			cout << "\nСтудент с таким ФИО уже существует! Введите другое.";
		}
	}
	cout << "\nНомер группы: ";
	temp_student.num_of_group = enterStringWithoutSpaces();
	setOffsets(temp_student);
	setExams(temp_student);
	cout << "\nФорма обучения (Платная - 0, Бюджетная - 1): ";
	temp_student.is_budget_student = enterNumberInRange(0, 1);
	cout << "\nУчастие в общественной работе (Неактивное - 0, Активное - 1): ";
	temp_student.is_social_work = enterNumberInRange(0, 1);
	vec_of_students.push_back(temp_student);
}

bool isGoodFio(vector <Student>& vec_of_students, string fio)
{
	for (unsigned int i = 0; i < vec_of_students.size(); i++)
	{
		if (fio == vec_of_students.at(i).FIO)
		{
			return 0;
		}
	}
	return 1;
}

void setOffsets(Student& temp_student)
{
	cout << "\nЗачеты (Не зачтено - " << MIN_OFFSET << ", Зачтено - " << MAX_OFFSET << ")" << endl;
	temp_student.offset.oopip = rateStudent(MIN_OFFSET, MAX_OFFSET, OOPIP);
	temp_student.offset.discrete_math = rateStudent(MIN_OFFSET, MAX_OFFSET, DISCRETE_MATH);
	temp_student.offset.inad = rateStudent(MIN_OFFSET, MAX_OFFSET, INAD);
	temp_student.offset.history = rateStudent(MIN_OFFSET, MAX_OFFSET, HISTORY);
	temp_student.offset.phys_culture = rateStudent(MIN_OFFSET, MAX_OFFSET, PHYS_CULTURE);
}

void setExams(Student& temp_student)
{
	cout << "\nЭкзамены (Минимальная оценка - " << MIN_EXAM << ", Максимальная оценка - " << MAX_EXAM << ")" << endl;
	temp_student.exam.oaip = rateStudent(MIN_EXAM, MAX_EXAM, OAIP);
	temp_student.exam.math = rateStudent(MIN_EXAM, MAX_EXAM, MATH);
	temp_student.exam.english = rateStudent(MIN_EXAM, MAX_EXAM, ENGLISH);
	temp_student.exam.physics = rateStudent(MIN_EXAM, MAX_EXAM, PHYSICS);
	temp_student.average_score = (temp_student.exam.oaip + temp_student.exam.math + temp_student.exam.english + temp_student.exam.physics) / 4.;
}

int rateStudent(int min_range, int max_of_range, string subject)
{
	cout << subject << ": ";
	return enterNumberInRange(min_range, max_of_range);
}

void editStudent(vector <Student>& vec_of_students) {}

void deleteStudent(vector <Student>& vec_of_students)
{
	int answer, index_for_delete;
	cout << "Какого студента вы хотите удалить?\n Отмена - 0" << endl;
	index_for_delete = indexOfVectorForChange(vec_of_students);
	if (index_for_delete != 0)
	{
		index_for_delete--;

		system("cls");
		cout << "Вы действительно хотите удалить студента " << vec_of_students.at(index_for_delete).FIO << "? \nДа - 1 \nНет - 0" << endl;
		answer = enterNumberInRange(0, 1);
		if (answer == 1)
		{
			vec_of_students.erase(vec_of_students.begin() + index_for_delete);
			cout << "Успешно удалён!" << endl;
			system("pause");
		}
	}
}

void readFileOfStudents(vector <Student>& vec_of_students)
{
	ifstream fin(FILE_OF_STUDENTS, ios::in);
	Student temp_student;
	if (!fin.is_open())
	{
		cout << "Файла со студентами не существует! Создан новый." << endl;
	}
	else
	{
		if (fin.peek() != EOF)
		{
			while (!fin.eof())
			{
				getline(fin, temp_student.FIO, '\0');
				temp_student.FIO += '\0';
				fin >> temp_student.num_of_group
					>> temp_student.offset.oopip >> temp_student.offset.discrete_math >> temp_student.offset.inad
					>> temp_student.offset.history >> temp_student.offset.phys_culture
					>> temp_student.exam.oaip >> temp_student.exam.math >> temp_student.exam.english >> temp_student.exam.physics
					>> temp_student.is_budget_student >> temp_student.is_social_work 
					>> temp_student.average_score >> temp_student.stipend;
				vec_of_students.push_back(temp_student);
			}
		}
		else
		{
			cout << "Файл пуст!" << endl;
		}
	}
	fin.close();
}

void writeFileOfStudents(vector <Student>& vec_of_students)
{
	ofstream fout(FILE_OF_STUDENTS, ios::out);
	for (unsigned int i = 0; i < vec_of_students.size(); i++)
	{
		fout << vec_of_students.at(i).FIO << " " << vec_of_students.at(i).num_of_group
			<< " " << vec_of_students.at(i).offset.oopip << " " << vec_of_students.at(i).offset.discrete_math
			<< " " << vec_of_students.at(i).offset.inad << " " << vec_of_students.at(i).offset.history
			<< " " << vec_of_students.at(i).offset.phys_culture
			<< " " << vec_of_students.at(i).exam.oaip << " " << vec_of_students.at(i).exam.math
			<< " " << vec_of_students.at(i).exam.english << " " << vec_of_students.at(i).exam.physics
			<< " " << vec_of_students.at(i).is_budget_student << " " << vec_of_students.at(i).is_social_work
			<< " " << vec_of_students.at(i).average_score << " " << vec_of_students.at(i).stipend;
		if (i < vec_of_students.size() - 1)
		{
			fout << endl;
		}
	}
	fout.close();
}

int indexOfVectorForChange(vector <Student>& vec_of_students)
{
	int size;
	size = vec_of_students.size();
	return enterNumberInRange(0, size);
}