/*
Задание 2
Создайте класс Array (или используйте ранее созданный вами).
Класс Array – это класс динамического массива.
Размер массива может быть передан в качестве параметра или задан с помощью вызова функции-члена.+
Класс должен позволять заполнять массив значениями,+
отображать содержимое массива,+
изменять размер массива,+
сортировать массив,+
определять минимальное и максимальное значение. +
Класс должен содержать набор конструкторов (конструктор копирования обязателен), деструктор.+
*/
#include <iostream>
#include <time.h>
using namespace std;
class Array
{
	int N;
	int* array;
public:
	Array();// конструктор по умолчанию
	explicit Array(int n);// конструктор с параметром
	Array(const Array& Ar); // конструктор копирования
	~Array();
	void Clear();//деструктор
	void Print();
	void SetRnd(int min, int max);
	void Input(); // вводим ручками
	Array& operator = (const Array& Ar);
	void QuicksSort(int left, int right); //сортировать массив
	int MaxPosInArray(const Array& Ar);
	int MinPosInArray(const Array& Ar);
	void QuicksSort() { QuicksSort(0, N); }
	int operator[](int i) const;
	int& operator[](int i);
};

Array::Array()// конструктор по умолчанию
{
	N = 0;
	array = nullptr;
}
Array::Array(int n)// конструктор с параметром
{
	N = n;
	array = new int [n] {0};
}
Array::Array(const Array& Ar) : Array(Ar.N)// конструктор копирования
{
	copy(Ar.array, Ar.array + N, array);
}
Array::~Array()
{
	Clear();
}
void Array::Clear() //деструктор
{
	N = 0;
	delete[] array;
	array = nullptr;
}
void Array::Print()
{
	for (size_t i = 0; i < N; i++)
		cout << array[i] << "\t";
	cout << endl;
}
void Array::SetRnd(int min, int max)
{
	if (min > max)swap(min, max);
	for (size_t i = 0; i < N; i++)
		array[i] = min + rand() % (max - min + 1);
}
void Array::Input()
{
	for (size_t i = 0; i < N; i++)
	{
		cout << "array[" << i << "]=";
		cin >> array[i];
	}
}
Array& Array::operator=(const Array& Ar)
{
	if (&Ar != this)
	{
		Clear();
		N = Ar.N;
		array = new int[Ar.N];
		copy(Ar.array, Ar.array + N, array);
	}
	return *this;
}
void Array::QuicksSort(int left, int right)
{
	int i = left, j = right - 1;
	int m = array[i + (j - i) / 2]; // використовувати саме так
	while (i <= j) {
		while (array[i] < m)i++;
		while (array[j] > m)j--;
		if (i <= j) {
			swap(array[i], array[j]);
			i++;
			j--;
		}
	}
	if (left < j) QuicksSort(left, j + 1);
	if (i < right) QuicksSort(i, right);
}
int Array::MaxPosInArray(const Array& Ar)
{
	int pmax = 0;
	for (size_t i = 1; i < N; i++)
		if (Ar.array[i] > Ar.array[pmax])
			pmax = i;
	return pmax;
}
int Array::MinPosInArray(const Array& Ar)
{
	int pmin = 0;
	for (size_t i = 1; i < N; i++)
		if (Ar.array[i] < Ar.array[pmin])
			pmin = i;
	return pmin;
}
int Array::operator[](int i) const
{
	if (i >= 0 && i < N)
		return array[i];
	exit(1);
}
int& Array::operator[](int i)
{
	if (i >= 0 && i < N)
		return array[i];
	exit(1);
}

int main()
{
	srand(time(0));
	Array mas(5);
	cout << "Array mas(5): \n";
	mas.Print();
	cout << "\nmas.SetRnd(-5, 5): \n";
	mas.SetRnd(-5, 5);
	//mas.Input();
	mas.Print();
	cout << "\nArray mas2 = mas: \n";
	Array mas2 = mas;
	mas2.Print();
	cout << "\nmas2.QuicksSort() :\n";
	mas2.QuicksSort();
	mas2.Print();
	cout << "\nPOSITION of the maximum value in the array(mas2) : " << endl;
	cout << mas2.MaxPosInArray(mas2) << endl;
	cout << "maximum VALUE in array(mas2) : " << endl;
	cout << mas2[mas2.MaxPosInArray(mas2)]<<"\n\n";
	cout << "POSITION of the minimum value in the array(mas2) : " << endl;
	cout << mas2.MinPosInArray(mas2) << endl;
	cout << "minimum VALUE in array(mas2) : " << endl;
	cout << mas2[mas2.MinPosInArray(mas2)] << "\n\n";

	cout << "\nThe End!\n";
}