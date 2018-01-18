/*1. Дан массив целых чисел (можно ввести значения элементов или задать
	случайным образом).Воспользовавшись указателями, поменяйте местами элементы
	массива с четными и нечетными индексами(т.е.те элементы массива, которые стоят
	на четных местах, поменяйте с элементами, которые стоят на нечетных местах).*/

#include <iostream>
#include <ctime>
#define SIZE 10
using namespace std;
void randArr (int a[], int sizeArr) {
	srand(time(0));
	int *ptr;
	ptr = a;
	for (int i = 0; i<sizeArr; i++, ptr++)
		*ptr = rand() % 21 - 10;
}
void printArr(int a[], int sizeArr) {
	int *ptr;
	ptr = a;
	for (int i = 0; i < sizeArr; i++, ptr++)
		cout << *ptr << " ";
}
void main()
{
	setlocale(LC_ALL, "rus");
	int myArr[SIZE];
	int *ptr;
	randArr(myArr, SIZE); // Инициализация массива случайными числами
	cout << "Исходный массив:" << endl; 
	printArr(myArr, SIZE);// Вывод массива
	cout << endl;
	ptr = myArr;
	for (int i = 0; i < SIZE; i+=2, ptr+=2) {
		int tmp = *ptr;
		*ptr = *(ptr + 1);
		*(ptr+1) = tmp;
	}
	cout << "Итоговый массив:" << endl;
	printArr(myArr, SIZE);// Вывод массива
	cout << endl;
	system("pause");
}
