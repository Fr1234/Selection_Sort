#include <stdio.h>
#include <stdlib.h>
#include<time.h>
/// <summary>
/// 製造亂數放入陣列中
/// </summary>
/// <param name="array"></param>
/// <param name="array_length"></param>
void PutRandomNumberInArray(int* array, int* array_length) {
	//srand(time(NULL));
	for (int i = 0; i < *array_length; i++) {
		array[i] = rand() % *array_length + 1;
		//for (int j = 0; j < i; j++) {
		//	if (array[i] == array[j])  //比較值是否已經存在
		//	{
		//		/*i--;
		//		break;*/
		//		j = 0;
		//		array[i] = rand() % *array_length + 1;
		//	}
		////	/*while (array[i] == array[j])
		////	{
		////		j = 0;
		////		array[i] = rand() % *array_length + 1;
		////	}*/
		//}
	}
	

}
/// <summary>
/// 印出陣列裡的數字
/// </summary>
/// <param name="array"></param>
/// <param name="array_length"></param>
void Print(int *array, int *array_length) {

	for (int i = 0; i < *array_length; i++) {
		printf("%d ", *(array + i));
	}
	printf("\n");
}
/// <summary>
/// 交換兩個位置的值
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
void Swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
/// <summary>
/// Selection Sort
/// </summary>
/// <param name="array"></param>
/// <param name="array_length"></param>
void Selection_Sort(int *array, int *array_length) {
	int  min;
	for (int i = 0; i < (*array_length-1); i++) {
		min = i;
		for (int j = i + 1; j < *array_length; j++) {
			if (*(array + j) < *(array + min)) {
				min = j;
			}
			
		}
		if (i!=min) {
			Swap(&array[i], &array[min]);//為了不要自己跟自己還要swap一次
		}
		

	}
	//if ((*array + 0) < (*array + 2)) {
	//	Swap(&array[0], &array[2]);
	//}
	//printf("%d\n", *(array + min ));

}
/// <summary>
/// 主程式
/// </summary>
/// <returns></returns>
int main() {
	//int a = 10, b = 20;
	int A[] = { 0,10,40,5,16,1 };

	int B[100000];
	int  array_lengthB= sizeof(B) / sizeof(B[0]);
	int  array_length = sizeof(A) / sizeof(A[0]);
	clock_t start_time, end_time;
	printf("array_length=%d\n", array_length);
	Print(&A, &array_length);
	Selection_Sort(&A, &array_length);
	Print(&A, &array_length);
	PutRandomNumberInArray(&B, &array_lengthB);
	Print(&B, &array_lengthB);
	printf("\n亂數印完\n");
	start_time = clock(); /* mircosecond */
	Selection_Sort(&B, &array_lengthB);
	end_time = clock();
	//Print(&B, &array_lengthB);
	/* CLOCKS_PER_SEC is defined at time.h */
	float total_time = (float)(end_time - start_time) / CLOCKS_PER_SEC;

	printf("做完Selection_Sort Time : %f sec \n", total_time);
	//Swap(&a, &b);
	//printf("a=%d,b=%d", a, b);
}