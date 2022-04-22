#include <iostream>
#include <Windows.h>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

void StPeterburgsParadoxLog(long long bet, long long iterations)
{
	long long sum = 0;
	long long tails_counter, heads_counter;
	tails_counter = 0;
	heads_counter = 0;
	bool heads;
	vector<long long> wins;
	srand(time(NULL));
	for (long long i = 0; i < iterations; ++i)
	{
		heads = false;
		sum -= bet;
		long long win = 1;     // ������� � ���� ����� �������� ����������� ���������
		cout << "\n�������� " << i + 1 << ":\n";
		while (!heads)   // ���� �� ����� ���
		{
			if (rand() % 2 == 0)
			{
				win *= 2;
				tails_counter++;
				cout << "������ �����, ������� �������� �� " << win << endl;
			}
			else
			{
				heads = true;
				heads_counter++;
				cout << "����� ���, ������� �� �������� �������� " << win << endl;
			}
		}
		sum += win;
		wins.push_back(win - bet);
	}

	sort(wins.begin(), wins.end());
	double median = 0;
	if (iterations % 2 == 0)
	{
		median = (double)wins[iterations / 2 - 1];
		median += (double)wins[iterations / 2];
		median /= 2;
	}
	else
		median = (double)wins[iterations / 2];

	cout << "\n����� ������� �� " << iterations << " ��� ��������� " << sum << endl;
	cout << "\n����� ������ " << tails_counter << " ����� � " << heads_counter << " �����";
	cout << "���������� ������� ��������� " << sum / (double)iterations << endl;
	cout << "��������� �������� �������� ����� " << median << endl;
}

void StPeterburgsParadox(long long bet, long long iterations)
{
	long long sum = 0;
	bool heads;
	vector<long long> wins;
	srand(time(NULL));
	for (long long i = 0; i < iterations; ++i)
	{
		heads = false;
		sum -= bet;
		long long win = 1;     // ������� � ���� ����� �������� ����������� ���������
		while (!heads)   // ���� �� ����� ���
		{
			if (rand() % 2 == 0)
				win *= 2;
			else
				heads = true;
		}
		sum += win;
		wins.push_back(win - bet);
	}

	sort(wins.begin(), wins.end());
	double median = 0;
	if (iterations % 2 == 0)
	{
		median = (double)wins[iterations / 2 - 1];
		median += (double)wins[iterations / 2];
		median /= 2;
	}
	else
		median = (double)wins[iterations / 2];

	cout << "\n����� ������� �� " << iterations << " ��� ��������� " << sum << endl;
	cout << "���������� ������� ��������� " << sum / (double)iterations << endl;
	cout << "��������� �������� �������� ����� " << median << endl;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	long long bet, iterations;
	cout << "������� �������� ������: ";
	cin >> bet;
	cout << "������� �������� ���������� ��������: ";
	cin >> iterations;
	bool is_logged = false; // �������� �� true ��� ������ ��������� � ������������� ����������� ����������

	if (is_logged)
		StPeterburgsParadoxLog(bet, iterations);
	else
		for (int i = 0; i < 10; i++)
		{
			StPeterburgsParadox(bet, iterations);
			Sleep(1000);
		}
		
	return 0;
}
