/*2. Дан массив целых чисел (можно ввести значения элементов или задать
случайным образом). Пользуясь ДВУМЯ указателями, нужно поменять порядок
элементов массива на обратный.*/

#include <iostream>
#include <ctime>
#define NSIZE 10
#define MSIZE 15
using namespace std;
void randArr(int a[], int sizeArr) {
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
	cout << endl;
}
void sortArr(int a[], int sizeArr) {
	bool flag = true;
	int k = sizeArr - 1;
	while (k > 0)// к - левая граница подмассива
	{
		int endI = -1;
		for (int i = 0; i < k; i++)
			if (a[i] > a[i + 1]) {
				//Находим максимальный элемент в части массива от k до SIZE 
				int tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				endI = i;
			}
		k = endI;
	}
}
void main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	int aArr[NSIZE];
	int bArr[MSIZE];
	int cArr[NSIZE + MSIZE] = {};
	randArr(aArr, NSIZE);
	printArr(aArr, NSIZE);
	sortArr(aArr, NSIZE);
	cout << "Исходный массив А[n]:" << endl;
	printArr(aArr, NSIZE);



	randArr(bArr, MSIZE);
	printArr(bArr, MSIZE);
	sortArr(bArr, MSIZE);
	cout << "Исходный массив B[m]:" << endl;
	printArr(bArr, MSIZE);


	int *ptrA, *ptrB, *ptrC;
	ptrA = aArr;
	ptrB = bArr;
	ptrC = cArr;
	for (int i = 0; i < NSIZE + MSIZE; i++, ptrC++) {
		if (*ptrA < *ptrB) *ptrC = *ptrA++;
			else *ptrC = *ptrB++;
	}
	//sortArr(cArr, NSIZE + MSIZE);
	cout << endl << "Итоговый массив C[n+m]" << endl;
	printArr(cArr, NSIZE + MSIZE);
	system("pause");
}
