// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

/*Task 1. Write overloaded functions (int, double,
char) to perform the following tasks:
■ Initialization of the square matrix;
■ Display of the matrix on the screen;
■ Determination of the maximum and minimum element
on the main diagonal of the matrix;
■ Sort items by ascending order separately for
of each row of the matrix.*/

#include <iostream>
#include <ctime>
using namespace std;

template<typename T>T Rand(char trigger = 'i')
{

    switch (trigger)
    {
        case 'i':
        {
            return rand() % 10;
        } break;
        case 'd':
        {
            return (1000 + rand() % 9999) * 0.1;
        } break;
        case 'c':
        {
            return 100 + rand() % 255;
        } break;
    }
}

template <typename T> void RandArray(T arr[][5], const uint32_t col, const uint32_t row) 
{
    char trigger = '0';
    if (typeid(arr[0][0]) == typeid(int))
    {
        trigger = 'i';
    }
    if (typeid(arr[0][0]) == typeid(double))
    {
        trigger = 'd';
    }
    if (typeid(arr[0][0]) == typeid(char))
    {
        trigger = 'c';
    }
    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            arr[i][j] = Rand<T>(trigger);
        }
    }
}
template <typename T>void PrintArray(T arr[][5], const uint32_t col, const uint32_t row) 
{
    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl << endl;
}
template <typename T>void MinMaxArray(T arr[][5], const uint32_t col, const uint32_t row) 
{
    if (typeid(arr[0][0]) == typeid(int))
    {
        int min = arr[0][0];
        int max = arr[0][0];
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                if (i == j) {
                    if (arr[i][j] > max) max = arr[i][j];
                    if (arr[i][j] < min) min = arr[i][j];
                }
            }
        }
        cout << "min = " << min << endl << "max = " << max << endl << endl;
    }
    if (typeid(arr[0][0]) == typeid(double))
    {  
        double min = arr[0][0];
        double max = arr[0][0];
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                if (i == j) {
                    if (arr[i][j] > max) max = arr[i][j];
                    if (arr[i][j] < min) min = arr[i][j];
                }
            }
        }
        cout << "min = " << min << endl << "max = " << max << endl << endl;
    }
    if (typeid(arr[0][0]) == typeid(char))
    {
        char min = arr[0][0];
        char max = arr[0][0];
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                if (i == j) {
                    if (arr[i][j] > max) max = arr[i][j];
                    if (arr[i][j] < min) min = arr[i][j];
                }
            }
        }
        cout << "min = " << min << endl << "max = " << max << endl << endl;
    }
    
}

template <typename T>void SortArray(T arr[][5], const uint32_t col, const uint32_t row) 
{
    
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < col;j++)
        {
            for (int k = col - 1;k > j;k--)
                if (arr[i][k - 1] > arr[i][k])
                {
                    if (typeid(arr[0][0]) == typeid(int)) {
                        int tmp = arr[i][k];
                        arr[i][k] = arr[i][k - 1];
                        arr[i][k - 1] = tmp;
                    }
                    if (typeid(arr[0][0]) == typeid(double)) {
                        double tmp = arr[i][k];
                        arr[i][k] = arr[i][k - 1];
                        arr[i][k - 1] = tmp;
                    }
                    if (typeid(arr[0][0]) == typeid(char)) {
                        char tmp = arr[i][k];
                        arr[i][k] = arr[i][k - 1];
                        arr[i][k - 1] = tmp;
                    }
                   
                }
            cout << arr[i][j] << "   ";
        }
        cout << '\n';
    }
    cout << endl;
}

int main()
{
    srand(time(0));
    const uint32_t size = 5;
    int arr_i[size][size];
    RandArray<int>(arr_i, size, size);    //initialization of the matrix
    PrintArray<int>(arr_i, size, size);   //matrix output
    MinMaxArray<int>(arr_i, size, size);  //min and max
    SortArray<int>(arr_i, size, size);    //sorting

    double arr_d[size][size];
    RandArray<double>(arr_d, size, size);
    PrintArray<double>(arr_d, size, size);
    MinMaxArray<double>(arr_d, size, size);
    SortArray<double>(arr_d, size, size);

    char arr_c[size][size];
    RandArray<char>(arr_c, size, size);
    PrintArray<char>(arr_c, size, size);
    MinMaxArray<char>(arr_c, size, size);
    SortArray<char>(arr_c, size, size);

    return 0;
}