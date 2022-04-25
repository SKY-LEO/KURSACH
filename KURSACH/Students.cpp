#include "Students.h"

void showStudents(vector <Student>& vec_of_students)
{
	
	if (vec_of_students.size() != 0)
	{
		drawHeader();
		for (unsigned int i = 0; i < vec_of_students.size(); i++)
		{
			displayStudent(vec_of_students.at(i), i);
		}
	}
	else
	{
		cout << "Нет ни одного студента! Создайте первого" << endl;
	}
	cout << endl;
}

void drawHeader()
{
	cout << endl;
	cout << SEPARATOR_STUDENT << endl;
	cout << "|" << setw(8) << "|" << setw(22) << "|" << setw(15) << "|" << setw(24) << "Зачеты" << setw(19) << "|"
		<< setw(22) << "Экзамены" << setw(14) << "|" << setw(13) << "|" << setw(14) << "|" << setw(15) << "|" << setw(14) << "|" << endl;
	cout << "|" << setw(4) << "№" << setw(4) << "|" << setw(12) << "ФИО" << setw(10) << "|" << setw(11) << "№ группы"
		<< setw(4) << "|" << SEPARATOR_OFFSETS_EXAMS << "|"
		<< setw(10) << "Ср. балл" << setw(3) << "|" << setw(12) << "Форма обуч." << setw(2) << "|"
		<< setw(12) << "Соц. работа" << setw(3) << "|" << setw(11) << "Стипендия" << setw(3) << "|" << endl;
	cout << "|" << setw(8) << "|" << setw(22) << "|" << setw(15) << "|" << setw(6) << "ОППиП" << setw(2) << "|"
		<< setw(5) << "ДМ" << setw(4) << "|" << setw(6) << "ИнАД" << setw(3) << "|"
		<< setw(5) << "Ист" << setw(3) << "|" << setw(6) << "ФизК" << setw(3) << "|" << setw(6) << "ОАиП" << setw(3) << "|"
		<< setw(4) << "МА" << setw(3) << "|" << setw(6) << "ИнЯз" << setw(3) << "|" << setw(8) << "Физика" << setw(3) << "|"
		<< setw(13) << "|" << setw(14) << "|" << setw(15) << "|" << setw(14) << "|" << endl;
	cout << SEPARATOR_STUDENT << endl;
}

void displayStudent(Student& temp_student, int i)
{
	cout << "|" << setw(4) << i + 1 << setw(4) << "|" << setw(21) << left << temp_student.FIO
		<< "|" << setw(14) << right << temp_student.num_of_group
		<< "|" << setw(7) << tellIsPassOrFailOffset(temp_student.offset.oopip)
		<< "|" << setw(8) << tellIsPassOrFailOffset(temp_student.offset.discrete_math)
		<< "|" << setw(8) << tellIsPassOrFailOffset(temp_student.offset.inad)
		<< "|" << setw(7) << tellIsPassOrFailOffset(temp_student.offset.history)
		<< "|" << setw(8) << tellIsPassOrFailOffset(temp_student.offset.phys_culture)
		<< "|" << setw(8) << temp_student.exam.oaip << "|" << setw(6) << temp_student.exam.math
		<< "|" << setw(8) << temp_student.exam.english << "|" << setw(10) << temp_student.exam.physics
		<< "|" << setw(12) << temp_student.exam.average_score
		<< "|" << setw(11) << tellIsBudgetOrPaidEducation(temp_student.is_budget_student) << setw(3)
		<< "|" << setw(12) << tellIsActiveOrPassiveSocialWork(temp_student.is_social_work) << setw(3)
		<< "|" << setw(13) << temp_student.stipend << "|" << endl;
	cout << SEPARATOR_STUDENT << endl;
}

string tellIsPassOrFailOffset(bool offset)
{
	if (offset)
	{
		return "зачет";
	}
	return "незачет";
}

string tellIsBudgetOrPaidEducation(bool is_budget)
{
	if (is_budget)
	{
		return "бюджетная";
	}
	return "платная";
}

string tellIsActiveOrPassiveSocialWork(bool is_social_work)
{
	if (is_social_work)
	{
		return "активная";
	}
	return "неактивная";
}

void calculateStipends(vector <Student>& vec_of_students)
{
	double coefficient;
	double base_stipend = enterStipend();
	for (int i = 0; i < vec_of_students.size(); i++)
	{
		coefficient = calculateCoefficient(vec_of_students.at(i));
		vec_of_students.at(i).stipend = base_stipend * coefficient;
		vec_of_students.at(i).base_stipend = base_stipend;
	}
}

void editStipends(vector <Student>& vec_of_students)
{
	double coefficient;
	for (int i = 0; i < vec_of_students.size(); i++)
	{
		coefficient = calculateCoefficient(vec_of_students.at(i));
		vec_of_students.at(i).stipend = vec_of_students.at(i).base_stipend * coefficient;
	}
}

double calculateCoefficient(Student& student)
{
	double coefficient = 0.;
	if (student.is_budget_student)
	{
		if (student.offset.is_offsets_submited)
		{
			if (student.exam.average_score > 5.)
			{
				coefficient = 1.;
				if (student.exam.average_score >= 9. && student.is_social_work)coefficient = 1.5;
				else if (student.exam.average_score >= 9. || student.is_social_work)coefficient = 1.25;
			}
		}
	}
	return coefficient;
}

double enterStipend()
{
	double base_stipend;
	while (true)
	{
		cout << "Введите значение стипендии: ";
		base_stipend = correctInputDouble();
		if (isGoodStipend(base_stipend))
		{
			return base_stipend;
		}
	}
}

bool isGoodStipend(double stipend)
{
	if (stipend < 0.)
	{
		system("cls");
		cout << "Стипендия не может быть меньше 0! Повторите попытку." << endl;
		return false;
	}
	return true;
}

void addStudent(vector <Student>& vec_of_students)
{
	char code;
	Student temp_student;
	do
	{
		setFio(vec_of_students, temp_student);
		setNumOfGroup(temp_student);
		setOffsets(temp_student);
		setExams(temp_student);
		setFormOfEducation(temp_student);
		setActivityOfSocialWork(temp_student);
		vec_of_students.push_back(temp_student);
		cout << "\nВы хотите добавить ещё одного студента?(Д/Н)" << endl;
		code = (char)_getch();
	} while (code == 'Д' || code == 'д');
}

void setFio(vector <Student>& vec_of_students, Student& temp_student)
{
	temp_student.FIO = enterFio(vec_of_students);
}

string enterFio(vector <Student>& vec_of_students)
{
	string fio;
	while (true)
	{
		cout << "ФИО: ";
		fio = enterStringWithoutNumbers();
		if (isGoodFio(vec_of_students, fio))
		{
			return fio;
		}
	}
}

void setNumOfGroup(Student& temp_student)
{
	cout << "\nНомер группы: ";
	temp_student.num_of_group = enterStringWithoutSpacesAndSpecialSym();
}

void setFormOfEducation(Student& temp_student)
{
	cout << "\nФорма обучения (Платная - 0, Бюджетная - 1): ";
	temp_student.is_budget_student = enterNumberInRange(0, 1);
}

void setActivityOfSocialWork(Student& temp_student)
{
	cout << "Участие в общественной работе (Неактивное - 0, Активное - 1): ";
	temp_student.is_social_work = enterNumberInRange(0, 1);
}

bool isGoodFio(vector <Student>& vec_of_students, string fio)
{
	for (unsigned int i = 0; i < vec_of_students.size(); i++)
	{
		if (fio == vec_of_students.at(i).FIO)
		{
			system("cls");
			cout << "\nСтудент с таким ФИО уже существует! Введите другое." << endl;;
			return false;
		}
	}
	return true;
}

void setOffsets(Student& temp_student)
{
	cout << "\n\nЗачеты (Не зачтено - " << MIN_OFFSET << ", Зачтено - " << MAX_OFFSET << ")" << endl;
	setOopip(temp_student);
	setDiscreteMath(temp_student);
	setInad(temp_student);
	setHistory(temp_student);
	setPhysCulture(temp_student);
	setIsOffsetsSubmited(temp_student);
}

void setOopip(Student& temp_student)
{
	temp_student.offset.oopip = rateStudent(MIN_OFFSET, MAX_OFFSET, OOPIP);
}

void setDiscreteMath(Student& temp_student)
{
	temp_student.offset.discrete_math = rateStudent(MIN_OFFSET, MAX_OFFSET, DISCRETE_MATH);
}

void setInad(Student& temp_student)
{
	temp_student.offset.inad = rateStudent(MIN_OFFSET, MAX_OFFSET, INAD);
}

void setHistory(Student& temp_student)
{
	temp_student.offset.history = rateStudent(MIN_OFFSET, MAX_OFFSET, HISTORY);
}

void setPhysCulture(Student& temp_student)
{
	temp_student.offset.phys_culture = rateStudent(MIN_OFFSET, MAX_OFFSET, PHYS_CULTURE);
}

void setIsOffsetsSubmited(Student& temp_student)
{
	bool is_offsets_submited = true;
	if (!temp_student.offset.oopip)is_offsets_submited = false;
	else if (!temp_student.offset.discrete_math)is_offsets_submited = false;
	else if (!temp_student.offset.inad)is_offsets_submited = false;
	else if (!temp_student.offset.history)is_offsets_submited = false;
	else if (!temp_student.offset.phys_culture)is_offsets_submited = false;
	temp_student.offset.is_offsets_submited = is_offsets_submited;
}

void setExams(Student& temp_student)
{
	cout << "\nЭкзамены (Минимальная оценка - " << MIN_EXAM << ", Максимальная оценка - " << MAX_EXAM << ")" << endl;
	setOaip(temp_student);
	setMath(temp_student);
	setEnglish(temp_student);
	setPhysics(temp_student);
	setAverageScore(temp_student);
}

void setOaip(Student& temp_student)
{
	temp_student.exam.oaip = rateStudent(MIN_EXAM, MAX_EXAM, OAIP);
}

void setMath(Student& temp_student)
{
	temp_student.exam.math = rateStudent(MIN_EXAM, MAX_EXAM, MATH);
}

void setEnglish(Student& temp_student)
{
	temp_student.exam.english = rateStudent(MIN_EXAM, MAX_EXAM, ENGLISH);
}

void setPhysics(Student& temp_student)
{
	temp_student.exam.physics = rateStudent(MIN_EXAM, MAX_EXAM, PHYSICS);
}

void setAverageScore(Student& temp_student)
{
	temp_student.exam.average_score = (temp_student.exam.oaip + temp_student.exam.math + temp_student.exam.english + temp_student.exam.physics) / 4.;
}

int rateStudent(int min_range, int max_of_range, string subject)
{
	cout << subject << ": ";
	return enterNumberInRange(min_range, max_of_range);
}

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
					>> temp_student.offset.history >> temp_student.offset.phys_culture >> temp_student.offset.is_offsets_submited
					>> temp_student.exam.oaip >> temp_student.exam.math >> temp_student.exam.english
					>> temp_student.exam.physics >> temp_student.exam.average_score
					>> temp_student.is_budget_student >> temp_student.is_social_work >> temp_student.stipend
					>> temp_student.base_stipend;
				getline(fin, temp_student.FIO, '\n');
				vec_of_students.push_back(temp_student);
			}
		}
		else
		{
			cout << "Файл со студентами пуст!" << endl;
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
			<< " " << vec_of_students.at(i).offset.phys_culture << " " << vec_of_students.at(i).offset.is_offsets_submited
			<< " " << vec_of_students.at(i).exam.oaip << " " << vec_of_students.at(i).exam.math
			<< " " << vec_of_students.at(i).exam.english << " " << vec_of_students.at(i).exam.physics
			<< " " << vec_of_students.at(i).exam.average_score
			<< " " << vec_of_students.at(i).is_budget_student << " " << vec_of_students.at(i).is_social_work
			<< " " << vec_of_students.at(i).stipend << " " << vec_of_students.at(i).base_stipend << vec_of_students.at(i).FIO;
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