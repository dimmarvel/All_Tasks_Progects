// sstrchar.cpp
// ������ � �������� � ������
#include <iostream>
#include <string>
using namespace std;
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL,"Rus");
	char charray[80];
	string word;

	cout << "������� �����: ";
	cin >> word;
	int wlen = word.length();     // ����� ������
	cout << "�� ������ �������: ";
	for (int j = 0; j < wlen; j++)
		cout << word.at(j);        // ��� ����� �������� �� ����� �� ������� ������
		// cout << word [ j ];        // � ��� �������� �� �����

	word.copy(charray, wlen, 0); // �������� ������ � ������
	charray[wlen] = 0;
	cout << "\n������ ��������: " << charray << endl;
	system("pause");
	return 0;
}
