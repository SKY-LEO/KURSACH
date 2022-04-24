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
			cout << "Введите число в заданном промежутке!" << endl;
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
			cout << "Ошибка! Введите целое число." << endl;
		}
	}
	return a;
}

double correctInputDouble()
{
	double a;
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
			cout << "Ошибка! Введите число." << endl;
		}
	}
	return a;
}

string enterGoodPassword()
{
	char symbol;
	string password;
	while ((symbol = _getch()) != '\r')//пока вводимый символ не равен сиволу переноса каретки(enter)
	{
		if (symbol == '\b')//backspace
		{
			if (!password.empty())
			{
				cout << '\b' << ' ' << '\b';
				password.erase(password.length() - 1);
			}
			continue;
		}
		password += symbol;
		cout << '*';
	}
	return password;
}

string enterStringWithoutNumbers()
{
	char symbol;
	string buffer;
	while ((symbol = _getch()) != '\r')
	{
		if (symbol == '\b')
		{
			if (!buffer.empty())
			{
				cout << "\b \b";
				buffer.erase(buffer.size() - 1);
			}
			continue;
		}
		if (!((symbol >= 'а' && symbol <= 'я') || (symbol >= 'А' && symbol <= 'Я') || symbol == ' ' || symbol == '.'))
		{
			continue;
		}
		else if ((!buffer.empty() && symbol == ' ' && buffer.at(buffer.size() - 1) == ' ') || (buffer.empty() && symbol == ' '))
		{
			continue;
		}
		buffer += symbol;
		cout << symbol;
	}
	return buffer;
}