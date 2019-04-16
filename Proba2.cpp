#include <iostream>
#include"String.h"
using namespace std;

const int n = 300;

int GetLength();
void Array(char*, const char*,int&);
void CodeWord(char* oldarray, const char*, int&);

int main()
{
	char* oldarray = new char[n];
	cout << "Please, enter your array: " << endl;
	cin.getline(oldarray, 300);
	const char* code = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	int n = GetLength();
	Array(oldarray, code,n);
	 CodeWord(oldarray, code, n);
	
	system("pause");
	return 0;
}
int GetLength()
{
	int n;
	cout << "Please, enter length of your word ";
	cin >> n;
	if (n < 0)
	{
		cout << "Invalid number!!! Enter other value";
	}
	return n;
}
void Array(char* oldarray, const char* code, int& n)
{
	char* pword = strpbrk(oldarray, code);
	while (pword)
	{
		int len = strspn(pword, code);
		if (len == n)
		{
			CodeWord(oldarray, code, n);
		}
		pword += len;
		pword = strpbrk(pword, code);

	}
}
void CodeWord(char* oldarray, const char* code, int&n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < strlen(code); j++)
		{
			if (oldarray[i] == code[j] && j < strlen(code) / 2)
			{
				oldarray[i] = j;
				cout << "[" << strlen(code) / 2 - j << "]";
			}
			else if (oldarray[i] == code[j] && j > strlen(code) / 2)
			{
				oldarray[i] = j;
				cout << "[" << strlen(code) - j << "]";
			}
		}
	}
}
