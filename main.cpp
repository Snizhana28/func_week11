// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

/*Task 3. Write a function that determines the quantity
positive, negative and zero elements of what was transferred to her
array*/


#include <iostream>
#include <time.h>
using namespace std;

void output(int arr[], const int size)
{
	int result[3]{ 0, 0, 0 };
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
		if (arr[i] == 0) 
		{
			result[0]++;
		}
		if (arr[i] > 0) 
		{
			result[1]++;
		}
		if (arr[i] < 0) 
		{
			result[2]++;
		}
	}
	cout << "\n\nNumber = 0 --> " << result[0] << "\nNumber > 0 --> " << result[1] << "\nNumber < 0 --> " << result[2] << endl;
}
int main()
{
	srand(time(0));
	const uint32_t size = 10;
	int arr[size];
	for (size_t i = 0; i < size; i++)
		arr[i] = rand() % 20 - 5;

	output(arr, size);
	return 0;
}