/*4. Даны два массива: А[n] и B[m]. Необходимо создать третий массив, в котором
нужно собрать:
• Общие элементы двух массивов;
• Элементы массива A, которые не включаются в B;*/

#include <iostream>
#include <ctime>
#define NSIZE 33
#define MSIZE 12
using namespace std;
void randArr(int a[], int sizeArr);
void printArr(int a[], int sizeArr);
void sortArr(int a[], int sizeArr);

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int aArr[NSIZE];
	int bArr[MSIZE];
	int cArr[NSIZE + MSIZE] = {};
	//Генерация сортированного массива  А[n]:
	//(Инициализируем случайными числами, потом сортируем)
	{
		randArr(aArr, NSIZE);
		sortArr(aArr, NSIZE);
		cout << "Исходный массив А[n]:" << endl;
		printArr(aArr, NSIZE);
	}
	//Генерация сортированного массива  B[m]:
	{randArr(bArr, MSIZE);
	sortArr(bArr, MSIZE);
	cout << "Исходный массив B[m]:" << endl;
	printArr(bArr, MSIZE); }
	
	int *ptrA, *ptrB, *ptrC;
	ptrA = aArr;
	ptrB = bArr;
	ptrC = cArr;
	for (int i = 0; i < (MSIZE + NSIZE); i++, ptrC++) {  //
		if (ptrB-1 < &bArr[MSIZE-1] && ptrA-1 < &aArr[NSIZE-1]) {//если ptrB не вышел за пределы В, и ptrA не вышел за пределы А
			if (*ptrA <= *ptrB)	{
				*ptrC = *ptrA++;
				continue;
			}
			else {
				*ptrC = *ptrB++;
				continue;
			}
		}
		if (ptrB > &bArr[MSIZE - 1] && ptrA - 1 < &aArr[NSIZE - 1])//если ptrB вышел за пределы В, а ptrA  не вышел за пределы А
			*ptrC = *ptrA++;
		if (ptrA > &aArr[NSIZE - 1] && ptrB - 1 < &bArr[MSIZE - 1])
			*ptrC = *ptrB++;
	}
	cout << endl << "Итоговый массив C[n+m]" << endl;
	printArr(cArr, NSIZE + MSIZE);
	system("pause");
}


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
	while (k > 0 && flag)// к - левая граница подмассива
	{
		int endI = -1;
		flag = false;
		for (int i = 0; i < k; i++)
			if (a[i] > a[i + 1]) {
				//Находим максимальный элемент в части массива от k до SIZE 
				int tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				flag = true;
				endI = i;
			}
		k = endI;
	}
}
