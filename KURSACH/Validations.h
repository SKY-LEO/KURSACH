#pragma once

#include <iostream>
#include <conio.h>

using namespace std;

int enterNumberInRange(int min, int max);//ввод значения в заданном диапазоне 
int correctInputInt();//проверка вводимого значения на целочисленное число
double correctInputDouble();//проверка вводимого значения на дробное число 
string enterGoodPassword();//замена символов пароля на звездочки
string enterStringWithoutSpaces();//ввод строки без пробелов
string enterStringWithoutNumbers();//ввод строки без чисел
string enterStringWithoutSpacesAndSpecialSym();//ввод строки, состоящей только из букв и цифр
