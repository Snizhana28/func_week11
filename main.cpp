// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

/*Task 2. Write a function that determines the average
arithmetic of the elements of the array transferred to it.*/

#include <iostream>
#include <time.h>
using namespace std;
                                                                                        
double Average(int arr[], const uint32_t size)
{
	double result = 0;
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
		result += arr[i];
	}
	result /= size;
	cout << endl;
	return result;
}
int main()
{
	srand(time(0));
	const uint32_t size = 10;
	int arr[size];

	for (size_t i = 0; i < size; i++)
		arr[i] = rand() % 20;
	cout << "Result " << Average(arr, size);

	return 0;
}