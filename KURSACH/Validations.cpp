#include "Validations.h"

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
	while (true)//пока вводимый символ не равен сиволу переноса каретки(enter)
	{
		symbol = (char)_getch();
		if (symbol == '\r')
		{
			if (password.empty())
			{
				cout << "Строка пуста! Повторите ввод." << endl;
				continue;
			}
			break;
		}
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

string enterStringWithoutSpaces()
{
	char symbol;
	string buffer;
	while (true)//пока вводимый символ не равен сиволу переноса каретки(enter)
	{
		symbol = (char)_getch();
		if (symbol == '\r')
		{
			if (buffer.empty())
			{
				cout << "Строка пуста! Повторите ввод." << endl;
				continue;
			}
			break;
		}
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

string enterStringWithoutNumbers()
{
	char symbol;
	string buffer;
	while (true)
	{
		symbol = (char)_getch();
		if (symbol == '\r')
		{
			if (buffer.empty())
			{
				cout << "Строка пуста! Повторите ввод." << endl;
				continue;
			}
			if (buffer.at(buffer.size() - 1) == ' ')
			{
				cout << "\b \b";
				buffer.erase(buffer.size() - 1);
			}
			break;
		}
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

string enterStringWithoutSpacesAndSpecialSym()
{
	char symbol;
	string buffer;
	while (true)//пока вводимый символ не равен сиволу переноса каретки(enter)
	{
		symbol = (char)_getch();
		if (symbol == '\r')
		{
			if (buffer.empty())
			{
				cout << "Строка пуста! Повторите ввод." << endl;
				continue;
			}
			break;
		}
		if (symbol == '\b')//backspace
		{
			if (!buffer.empty())
			{
				cout << "\b \b";
				buffer.erase(buffer.length() - 1);
			}
			continue;
		}
		if (!((symbol >= 'а' && symbol <= 'я') || (symbol >= 'А' && symbol <= 'Я') || (symbol >= '0' && symbol <= '9')))
		{
			continue;
		}
		buffer += symbol;
		cout << symbol;
	}
	return buffer;
}