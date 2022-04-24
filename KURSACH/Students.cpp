#include "Students.h"

void showStudents(vector <Student>& vec_of_students)
{
	cout << endl;
	cout << SEPARATOR_STUDENT << endl;
	cout << "|" << setw(8) << "|" << setw(22) << "|" << setw(15) << "|" << setw(24) << "Зачеты" << setw(19) << "|"
		<< setw(22) << "Экзамены" << setw(14) << "|" << setw(13) << "|"<<setw(11)<<"|"<<setw(15)<<"|"<<setw(14)<<"|" << endl;
	cout << "|" << setw(4) << "№" << setw(4) << "|" << setw(12) << "ФИО" << setw(10) << "|" << setw(11) << "№ группы"
		<< setw(4) << "|" << SEPARATOR_OFFSETS_EXAMS << "|"
		<< setw(10) << "Ср. балл" << setw(3) << "|" << setw(8) << "Бюджет" << setw(3) << "|"
		<< setw(12) << "Активность" << setw(3) << "|" << setw(11) << "Стипендия" << setw(3) << "|" << endl;
	cout << "|" << setw(8) << "|" << setw(22) << "|" << setw(15) << "|" << setw(7) << "ОППиП" << setw(3) << "|" 
		<< setw(4) << "ДМ" << setw(3) << "|" << setw(6) << "ИнАД" << setw(3) << "|"
		<< setw(5) << "Ист" << setw(3) << "|" << setw(6) << "ФизК" << setw(3) << "|" << setw(6) << "ОАиП" << setw(3) << "|"
		<< setw(4) << "МА" << setw(3) << "|" << setw(6) << "ИнЯз" << setw(3) << "|" << setw(8) << "Физика" << setw(3) << "|"
		<< setw(13) << "|" << setw(11) << "|" << setw(15) << "|" << setw(14) << "|" << endl;
	/*cout << "|" << setw(4) << "№" << setw(4) << "|" << setw(12) << "ФИО" << setw(10) << "|" << setw(11) << "№ группы" << setw(4) << "|"
		<< setw(7) << "ОППиП" << setw(3) << "|" << setw(4) << "ДМ" << setw(3) << "|" << setw(6) << "ИнАД" << setw(3) << "|"
		<< setw(5) << "Ист" << setw(3) << "|" << setw(6) << "ФизК" << setw(3) << "|" << setw(6) << "ОАиП" << setw(3) << "|"
		<< setw(4) << "МА" << setw(3) << "|" << setw(6) << "ИнЯз" << setw(3) << "|" << setw(8) << "Физика" << setw(3) << "|"
		<< setw(10) << "Ср. балл" << setw(3) << "|" << setw(8) << "Бюджет" << setw(3) << "|"
		<< setw(12) << "Активность" << setw(3) << "|" << setw(11) << "Стипендия" << setw(3) << "|" << endl;*/
	cout << SEPARATOR_STUDENT << endl;
	for (unsigned int i = 0; i < vec_of_students.size(); i++)
	{
		cout << "|" << setw(4) << i + 1 << setw(4) << "|" << setw(21) << left << vec_of_students.at(i).FIO
			<< "|" << setw(14) << right << vec_of_students.at(i).num_of_group
			<< "|" << setw(9) << vec_of_students.at(i).offset.oopip << "|" << setw(6) << vec_of_students.at(i).offset.discrete_math
			<< "|" << setw(8) << vec_of_students.at(i).offset.inad << "|" << setw(7) << vec_of_students.at(i).offset.history
			<< "|" << setw(8) << vec_of_students.at(i).offset.phys_culture
			<< "|" << setw(8) << vec_of_students.at(i).exam.oaip << "|" << setw(6) << vec_of_students.at(i).exam.math
			<< "|" << setw(8) << vec_of_students.at(i).exam.english << "|" << setw(10) << vec_of_students.at(i).exam.physics
			<< "|" << setw(12) << vec_of_students.at(i).exam.average_score
			<< "|" << setw(10) << vec_of_students.at(i).is_budget_student << "|" << setw(14) << vec_of_students.at(i).is_social_work
			<< "|" << setw(13) << vec_of_students.at(i).stipend << "|" << endl;
		cout << SEPARATOR_STUDENT << endl;
	}
	cout << endl;
}

void calculateStipends(vector <Student>& vec_of_students)
{
	double coefficient;
	double base_stipend = enterBaseStipend();
	for (int i = 0; i < vec_of_students.size(); i++)
	{
		coefficient = calculateCoefficient(vec_of_students.at(i));
		vec_of_students.at(i).stipend = base_stipend * coefficient;
	}
}

double calculateCoefficient(Student& student)
{
	double coefficient = 0.;
	if (student.is_budget_student)
	{
		if (student.exam.average_score > 5.)
		{
			coefficient = 1.;
			if (student.exam.average_score || student.is_social_work)coefficient = 1.25;
			else if (student.exam.average_score >= 9. && student.is_social_work)coefficient = 1.5;
		}
	}
	return coefficient;
}

double enterBaseStipend()
{
	double base_stipend;
	while (true)
	{
		cout << "Введите базовую стипендию: ";
		base_stipend = correctInputDouble();
		if (isGoodStipend(base_stipend))
		{
			return base_stipend;
		}
		else
		{
			system("cls");
			cout << "Стипендия не может быть меньше 0! Повторите попытку." << endl;
		}
	}
}

bool isGoodStipend(double stipend)
{
	if (stipend < 0.)
	{
		return false;
	}
	return true;
}

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
			return false;
		}
	}
	return true;
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
	temp_student.exam.average_score = (temp_student.exam.oaip + temp_student.exam.math + temp_student.exam.english + temp_student.exam.physics) / 4.;
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
				fin >> temp_student.num_of_group;
				fin >> temp_student.offset.oopip >> temp_student.offset.discrete_math >> temp_student.offset.inad
					>> temp_student.offset.history >> temp_student.offset.phys_culture
					>> temp_student.exam.oaip >> temp_student.exam.math >> temp_student.exam.english
					>> temp_student.exam.physics >> temp_student.exam.average_score
					>> temp_student.is_budget_student >> temp_student.is_social_work >> temp_student.stipend;
				getline(fin, temp_student.FIO, '\n');
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
		fout << vec_of_students.at(i).num_of_group
			<< " " << vec_of_students.at(i).offset.oopip << " " << vec_of_students.at(i).offset.discrete_math
			<< " " << vec_of_students.at(i).offset.inad << " " << vec_of_students.at(i).offset.history
			<< " " << vec_of_students.at(i).offset.phys_culture
			<< " " << vec_of_students.at(i).exam.oaip << " " << vec_of_students.at(i).exam.math
			<< " " << vec_of_students.at(i).exam.english << " " << vec_of_students.at(i).exam.physics
			<< " " << vec_of_students.at(i).exam.average_score
			<< " " << vec_of_students.at(i).is_budget_student << " " << vec_of_students.at(i).is_social_work
			<< " " << vec_of_students.at(i).stipend << vec_of_students.at(i).FIO;
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