#include<iostream>
using namespace std;

#define tab "\t"

int** CreateArr(int m, int n);
void FillRand(int** arr, int m, int n);
void Print(int** arr, const int m, const int n);
void Clear(int** arr, int m);
void push_col_back(int** arr, const int m, int& n);
void push_col_front(int** arr, const int m, int& n);
void insert_col(int** arr, const int m, int& n, int numPos);
void pop_col_back(int**& arr, const int m, int& n);
void pop_col_front(int** arr, const int m, int& n);
void erase_col(int**& arr, const int m, int& n, int numPos);

void main()
{
	setlocale(LC_ALL, "");
	int m;       // Количество строк
	int n;       // Количество столбцов
	int numMenu; // Меню выбора задания
	int numPos;  // Номер позиции в массиве
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество элементов строки (столбцов): "; cin >> n;
	system("cls");
	int** arr = CreateArr(m, n);
	FillRand(arr, m, n);
	Print(arr, m, n);
	do
	{
		cout << endl;
		cout << "Выберите номер задания: что Вы хотите сделать с массивом:" << endl;
		cout << "1.Добавить колонку заполненную '0' в конец  двумерного массива " << endl;
		cout << "2.Добавить колонку заполненную '0' в начало двумерного массива" << endl;
		cout << "3.Добавить колонку заполненную '0' в двумерный массив по указанному индексу" << endl;
		cout << "4.Удалить  колонку с конца двумерного массива" << endl;
		cout << "5.Удалить  колонку с начала двумерного массива" << endl;
		cout << "6.Удалить  колонку из двумерного массива по указанному индексу" << endl;
		cout << "0.Выход" << endl;
		cin >> numMenu;

		switch (numMenu)
		{
		case 0:
			break;
		case 1:
			system("cls");
			push_col_back(arr, m, n);
			Print(arr, m, n);
			break;
		case 2:
			system("cls");
			push_col_front(arr, m, n);
			Print(arr, m, n);
			break;
		case 3:
			cout << "Введите номер колонки для вставки: "; cin >> numPos;
			if (numPos > n)
			{
				cout << "ОШИБКА - Не верный номер!!!";
				continue;
			}
			system("cls");
			insert_col(arr, m, n, numPos);
			Print(arr, m, n);
			break;
		case 4:
			system("cls");
			pop_col_back(arr, m, n);
			Print(arr, m, n);
			break;
		case 5:
			system("cls");
			pop_col_front(arr, m, n);
			Print(arr, m, n);
			break;
		case 6:
			cout << "Введите номер колонки для удаления: "; cin >> numPos;
			if (numPos > n)
			{
				cout << "ОШИБКА - Не верный номер!!!";
				continue;
			}
			system("cls");
			erase_col(arr, m, n, numPos);
			Print(arr, m, n);
			break;
		default:
			cout << "ERROR - Нет такого номера задания!!!" << endl;
			break;
		}
	} while (numMenu != 0);
	Clear(arr, m);
}
//--------------------------------------------------------------------------
// Создаем массив указателей, и сохраняем его адрес в указатель на указатель
int** CreateArr(int m, int n)
{
	int** arr = new int* [m] {};
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	return arr;
}
//--------------------------------------------------------------------------
// Заполняем двумерный динамический массив случайными числами
void FillRand(int** arr, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
//--------------------------------------------------------------------------
// Вывод двумерного динамического массива
void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}
//--------------------------------------------------------------------------
// Удаление исходного динамического массива
void Clear(int** arr, int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
//--------------------------------------------------------------------------
// Добавить колонку заполненную '0' в конец двумерного массива
void push_col_back(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}
//--------------------------------------------------------------------------
// Добавить колонку заполненную '0' в начало двумерного массива
void push_col_front(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}
//--------------------------------------------------------------------------
// Добавить колонку заполненную '0' в двумерный массив по указанному индексу"
void insert_col(int** arr, const int m, int& n, int numPos)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			(j < numPos ? buffer[j] : buffer[j + 1]) = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}
//--------------------------------------------------------------------------
// Удалить колонку с конца двумерного массива
void pop_col_back(int**& arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n - 1]{};
		for (int j = 0; j < n - 1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n--;
}
//--------------------------------------------------------------------------
// Удалить колонку с начала двумерного массива
void pop_col_front(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n - 1]{};
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n--;
}
//--------------------------------------------------------------------------
// Удалить колонку из двумерного массива по указанному индексу
void erase_col(int**& arr, const int m, int& n, int numPos)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n - 1]{};
		for (int j = 0; j < n; j++)
		{
			buffer[j] = j < numPos ? arr[i][j] : arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n--;
}