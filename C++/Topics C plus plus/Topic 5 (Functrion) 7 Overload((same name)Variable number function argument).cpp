// ���������� �������
#include <iostream>
using namespace std;

void repchar();              // ���������
void repchar(char);
void repchar(char, int);

int main()
{
	repchar();
	repchar('=');
	repchar('+', 30);
	system("pause");
}

// ������� �� ����� 45 �������� '*'
void repchar()
{
	for (int j = 0; j < 45; j++)    // ����, ������������� 45 ��� ����� ������� '*'
		cout << '*';               
	cout << endl;
}
// ������� 45 �������� ��������
void repchar(char ch)
{
	for (int j = 0; j < 45; j++)    // ����, ������������� 45 ���
		cout << ch;                // ����� ��������� �������
	cout << endl;
}
// ������� �������� ������ �������� ����� ���
void repchar(char ch, int n)
{
	for (int j = 0; j < n; j++)     // ����, ������������� n ���
		cout << ch;                // ����� ��������� �������
	cout << endl;
}
