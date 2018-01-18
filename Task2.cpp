/*2. Дан массив целых чисел (можно ввести значения элементов или задать
случайным образом). Пользуясь ДВУМЯ указателями, нужно поменять порядок
элементов массива на обратный.*/

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
	int *ptrBegin, *ptrEnd;
	randArr(myArr, SIZE); // Инициализация массива случайными числами
	cout << "Исходный массив:" << endl; 
	printArr(myArr, SIZE);// Вывод массива
	cout << endl;
	ptrBegin = myArr;
	ptrEnd = myArr + SIZE - 1;
	for (int i = 0; i < SIZE/2; i++, ptrBegin++, ptrEnd--) {
		int tmp = *ptrBegin;
		*ptrBegin = *ptrEnd;
		*ptrEnd = tmp;
		//printArr(myArr, SIZE);
		//cout << endl;
	}
	cout << "Итоговый массив:" << endl;
	printArr(myArr, SIZE);// Вывод массива
	cout << endl;
	system("pause");
}
