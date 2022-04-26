#include <iostream>
#include <Windows.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void StPeterburgsParadox_fast(long long iterations)
{
	long long sum = 0;
	bool heads;
	vector<long long> wins;
	srand(time(NULL));

	for (long long i = 0; i < iterations; ++i)
	{
		heads = false;
		long long win = 1;     // ������� � ���� ����� �������� ����������� ���������
		while (!heads)   // ���� �� ����� ���
		{
			if (rand() % 2 == 0)
				win *= 2;
			else
				heads = true;
		}
		sum += win;
		wins.push_back(win);
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

	cout.precision(10);
	cout << "\n����� ������� �� " << iterations << " ��� ��������� " << sum << endl;
	cout << "���������� ������� ��������� " << sum / (double)iterations << endl;
	cout << "��������� �������� �������� ����� " << median << endl;
}


void StPeterburgsParadox_fast(long long iterations, int limit)
{
	long long sum = 0;
	bool heads;
	vector<long long> wins;
	srand(time(NULL));

	for (long long i = 0; i < iterations; ++i)
	{
		heads = false;
		int tails_counter = 0;
		long long win = 1;     // ������� � ���� ����� �������� ����������� ���������
		while (!heads)   // ���� �� ����� ���
		{
			if (rand() % 2 == 0)
			{
				win *= 2;
				++tails_counter;
				if (tails_counter == limit)
					heads = true;
			}
			else
				heads = true;
		}
		sum += win;
		wins.push_back(win);
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

	cout.precision(10);
	cout << "\n����� ������� �� " << iterations << " ��� ��������� " << sum << endl;
	cout << "���������� ������� ��������� " << sum / (double)iterations << endl;
	cout << "��������� �������� �������� ����� " << median << endl;
}


void StPeterburgsParadox(long long iterations)
{
	long long sum = 0;
	bool heads;
	vector<long long> wins;
	srand(time(NULL));

	cout.precision(6);

	cout << "\n-------------------------------------------------------------\n";
	cout << "| ����� ���� | ����� | �������  | ����������� |    �����    |\n";
	cout << "|------------|-------|----------|-------------|-------------|\n";
	for (long long i = 0; i < iterations; ++i)
	{
		heads = false;
		int tails_counter = 0;
		long long win = 1;     // ������� � ���� ����� �������� ����������� ���������
		while (!heads)   // ���� �� ����� ���
		{
			if (rand() % 2 == 0)
			{
				win *= 2;
				++tails_counter;
			}
			else
				heads = true;
		}
		sum += win;
		wins.push_back(win);
		cout << "|" << setfill(' ') << setw(11) << i + 1 << " ";
		cout << "|" << setfill(' ') << setw(6) << tails_counter << " ";
		cout << "|" << setfill(' ') << setw(9) << win << " ";
		cout << "|" << setfill(' ') << setw(11) << (double)100 / win * 0.5 << "% ";
		cout << "|" << setfill(' ') << setw(12) << sum << " |\n";
		cout << "|------------|-------|----------|-------------|-------------|\n";
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

	cout.precision(10);
	cout << "\n����� ������� �� " << iterations << " ��� ��������� " << sum << endl;
	cout << "���������� ������� ��������� " << sum / (double)iterations << endl;
	cout << "��������� �������� �������� ����� " << median << endl;
}


void StPeterburgsParadox(long long iterations, int limit)
{
	long long sum = 0;
	bool heads;
	vector<long long> wins;
	srand(time(NULL));

	cout.precision(6);

	cout << "\n-------------------------------------------------------------\n";
	cout << "| ����� ���� | ����� | �������  | ����������� |    �����    |\n";
	cout << "|------------|-------|----------|-------------|-------------|\n";
	for (long long i = 0; i < iterations; ++i)
	{
		heads = false;
		int tails_counter = 0;
		long long win = 1;     // ������� � ���� ����� �������� ����������� ���������
		while (!heads)   // ���� �� ����� ���
		{
			if (rand() % 2 == 0)
			{
				win *= 2;
				++tails_counter;
				if (tails_counter == limit)
					heads = true;
			}
			else
				heads = true;
		}
		sum += win;
		wins.push_back(win);
		cout << "|" << setfill(' ') << setw(11) << i + 1 << " ";
		cout << "|" << setfill(' ') << setw(6) << tails_counter << " ";
		cout << "|" << setfill(' ') << setw(9) << win << " ";
		cout << "|" << setfill(' ') << setw(11) << (double)100 / win * 0.5 << "% ";
		cout << "|" << setfill(' ') << setw(12) << sum << " |\n";
		cout << "|------------|-------|----------|-------------|-------------|\n";
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

	cout.precision(10);
	cout << "\n����� ������� �� " << iterations << " ��� ��������� " << sum << endl;
	cout << "���������� ������� ��������� " << sum / (double)iterations << endl;
	cout << "��������� �������� �������� ����� " << median << endl;
}


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int flag = 1;

	while (flag)
	{
		long long iterations;
		cout << "������� �������� ���������� ��������: ";
		cin >> iterations;
		int limit;
		cout << "������� ����������� �� ���������� ������� � ����� (��� ���� ��� ����������� ������� 0): ";
		cin >> limit;
		int is_fast = 2;
		cout << "\n1. ������� ������������� (����� ������������ ����� ��������, �� �� ������� ������� ������������� ��������)";
		cout << "\n2. ��������� ������������� (������� ������� ������������� ��������, �� ����� ������������ ����� ��������)";
		cout << "\n������� ����� ������ ������: ";
		cin >> is_fast;

		if (is_fast == 1)
		{
			if (limit != 0)
				StPeterburgsParadox_fast(iterations, limit);
			else
				StPeterburgsParadox_fast(iterations);
		}
		else
		{
			if (limit != 0)
				StPeterburgsParadox(iterations, limit);
			else
				StPeterburgsParadox(iterations);
		}

		
		cout << "\n��� ����������� ������� 1, ��� ������ �� ��������� ������� 0: ";
		cin >> flag;
	}

	return 0;
}
