7. 	Із заданого рядка символів вилучити слова, довжина яких менша, за вказану користувачем.

#include <iostream>
#include <string>
using namespace std;

string input_string();
string changing_the_string(string str);
void output_the_changed_string(string str_final);

string input_string()
{
	string str;
	cout << "Please, input the string: ";
	getline(cin, str);
	return str;
}

string changing_the_string(string str)
{
	int n;
	cout << "Please, input the number (n) and the words, that have letters less than n will be removed from the string: ";
	cin >> n;
	string str_final, word;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != *(strpbrk(str.c_str(), " ,.")))
		{
			word += str[i];
		}
		if (str[i] == *(strpbrk(str.c_str(), " ,.")) || (str[i] != *(strpbrk(str.c_str(), " ,.")) && (i == str.length() - 1)))
		{
			if (word.length() >= n)
			{
				str_final += word + " ";
				word = "";
			}
			else
			{
				word = "";
			}
		}
	}
	return str_final;
}

void output_the_changed_string(string str_final)
{
	cout << "The changed string is: " << str_final << endl;
}

int main()
{
	string str = input_string();
	string str_final = changing_the_string(str);
	output_the_changed_string(str_final);
	system("pause");
}
