#include<stdio.h>
int main()
{
	int Array[] = { 5,7,9,10,8,10,14,19,98,56,199,-9,-45 };
	int temp = Array[0];
	for (int i = 0; i < (sizeof(Array) / sizeof(Array[0]))-1; i++)
	{
		if (Array[i] < Array[i + 1]) temp = Array[i + 1];
	}
	printf("gia tri lon nhat cua mang: %d\r\n", temp);
	temp = 0;
	for (int i = 0; i < (sizeof(Array) / sizeof(Array[0]))-1; i++)
	{
		if (Array[i] > Array[i + 1]) temp = Array[i + 1];
	}
	printf("gia tri be nhat cua mang: %d\r\n", temp);
	return 0;
}