#include "Students.h"

void showStudents(vector <Student>& vec_of_students)
{
	cout << endl;
	cout << setw(4) << "�" << setw(4) << "|" << setw(12) << "���" << setw(10) << "|" << setw(11) << "� ������" << setw(4) << "|"
		<< setw(7) << "�����" << setw(3) << "|" << setw(4) << "��" << setw(3) << "|" << setw(6) << "����" << setw(3) << "|"
		<< setw(5) << "���" << setw(3) << "|" << setw(6) << "����" << setw(3) << "|" << setw(6) << "����" << setw(3) << "|"
		<< setw(4) << "��" << setw(3) << "|" << setw(6) << "����" << setw(3) << "|" << setw(8) << "������" << setw(3) << "|"
		<< setw(8) << "������" << setw(3) << "|" << "����������" << endl;
	cout << SEPARATOR_STUDENT << endl;
	for (unsigned int i = 0; i < vec_of_students.size(); i++)
	{
		cout << setw(4)<<i + 1 << setw(4) << "|"<<setw(22) << vec_of_students.at(i).FIO << "|"<<setw(14) << vec_of_students.at(i).num_of_group
			<< "|"<<setw(9) << vec_of_students.at(i).offset.oopip << "|"<<setw(6) << vec_of_students.at(i).offset.discrete_math
			<< "|"<<setw(8) << vec_of_students.at(i).offset.inad << "|"<<setw(7) << vec_of_students.at(i).offset.history
			<< "|"<<setw(8) << vec_of_students.at(i).offset.phys_culture
			<< "|"<<setw(8) << vec_of_students.at(i).exam.oaip << "|" << setw(6) << vec_of_students.at(i).exam.math
			<< "|" << setw(8) << vec_of_students.at(i).exam.english << "|" << setw(10) << vec_of_students.at(i).exam.physics
			<< "|" << setw(10) << vec_of_students.at(i).is_budget_student << "|" << setw(8) << vec_of_students.at(i).is_social_work
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
		cout << "\n���: ";
		fio = enterStringWithoutNumbers();
		if (isGoodFio(vec_of_students, fio))
		{
			temp_student.FIO = fio;
			break;
		}
		else
		{
			system("cls");
			cout << "\n������� � ����� ��� ��� ����������! ������� ������.";
		}
	}
	cout << "\n����� ������: ";
	temp_student.num_of_group = enterStringWithoutSpaces();
	setOffsets(temp_student);
	setExams(temp_student);
	cout << "\n����� �������� (������� - 0, ��������� - 1): ";
	temp_student.is_budget_student = enterNumberInRange(0, 1);
	cout << "\n������� � ������������ ������ (���������� - 0, �������� - 1): ";
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
	cout << "\n������ (�� ������� - " << MIN_OFFSET << ", ������� - " << MAX_OFFSET << ")" << endl;
	temp_student.offset.oopip = rateStudent(MIN_OFFSET, MAX_OFFSET, OOPIP);
	temp_student.offset.discrete_math = rateStudent(MIN_OFFSET, MAX_OFFSET, DISCRETE_MATH);
	temp_student.offset.inad = rateStudent(MIN_OFFSET, MAX_OFFSET, INAD);
	temp_student.offset.history = rateStudent(MIN_OFFSET, MAX_OFFSET, HISTORY);
	temp_student.offset.phys_culture = rateStudent(MIN_OFFSET, MAX_OFFSET, PHYS_CULTURE);
}

void setExams(Student& temp_student)
{
	cout << "\n�������� (����������� ������ - " << MIN_EXAM << ", ������������ ������ - " << MAX_EXAM << ")" << endl;
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
	cout << "������ �������� �� ������ �������?\n ������ - 0" << endl;
	index_for_delete = indexOfVectorForChange(vec_of_students);
	if (index_for_delete != 0)
	{
		index_for_delete--;

		system("cls");
		cout << "�� ������������� ������ ������� �������� " << vec_of_students.at(index_for_delete).FIO << "? \n�� - 1 \n��� - 0" << endl;
		answer = enterNumberInRange(0, 1);
		if (answer == 1)
		{
			vec_of_students.erase(vec_of_students.begin() + index_for_delete);
			cout << "������� �����!" << endl;
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
		cout << "����� �� ���������� �� ����������! ������ �����." << endl;
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
			cout << "���� ����!" << endl;
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