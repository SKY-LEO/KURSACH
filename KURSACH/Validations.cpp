#include "Validations.h"

string enterStringWithoutSpaces()
{
	char symbol;
	string buffer;
	while ((symbol = _getch()) != '\r')//пока вводимый символ не равен сиволу переноса каретки(enter)
	{
		if (symbol == '\b')//backspace
		{
			if (!buffer.empty())
			{
				cout << "\b \b";
				buffer.erase(buffer.length() - 1);
			}
			continue;
		}
		if (symbol == ' ')
		{
			continue;
		}
		buffer += symbol;
		cout << symbol;
	}
	return buffer;
}

int enterNumberInRange(int min, int max)
{
	int number;
	while (true)
	{
		number = correctInputInt();
		if (number >= min && number <= max)
		{
			break;
		}
		else
		{
			cout << "¬ведите число в заданном промежутке!" << endl;
		}
	}
	return number;
}

int correctInputInt()
{
	int a;
	while (true)
	{
		cin >> a;
		if (cin.get() == '\n') {
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "ќшибка! ¬ведите целое число." << endl;
		}
	}
	return a;
}