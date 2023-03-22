#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
const  int M = 20, N = 20;
void shakerSort(float arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; i++) {
            if (arr[i] < arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        swapped = false;
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] < arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        start++;
        end--;
    }
}


void get_mas1(int arr[], int& n, string filename) {
    ifstream file(filename);
    file >> n;
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {
            file >> arr[i];
        }
        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}

void show_mas1(int arr[], int n, string filename) {
    ofstream out(filename);
    for (int i = 0; i < n; i++) {
        out << arr[i] << " ";
    }
    cout << endl;
}
void show_mas3(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}
void get_mas2(int matrix[M][N], int& n, int& m, string filename) {
    ifstream file(filename);
    file >> m;
    file >> n;
    if (file.is_open()) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
            {
                file >> matrix[i][j];
            }

        }
        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}


void get_mas3(float arr[], int& n, string filename) {
    ifstream file(filename);
    file >> n;
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {
            file >> arr[i];
        }
        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}

void task1() {
    int n =0, t=0,fp=0;
    int* a = new int[n];
    get_mas1(a, n, "array_in_n.txt"); // передаем поток ifstream вместо имени файла
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0 && t == 0)
        {
            fp = a[i];
            t = 1;
        }
        else
        {
            if (a[i] % 2 == 0)
            {
                a[i] += fp;
            }
        }
    }
    show_mas1(a, n, "array_out_n.txt"); // передаем поток ofstream вместо имени файла
    delete[] a;
}

void task2() {

    int matrix[M][N]{};
    int Sum = 0, cols = 0, rows = 0,min_max= -2147483648;//-2 147 483 648 минимальное  значение типа int

    get_mas2(matrix, cols, rows, "matr_in_n.txt"); // передаем поток ifstream вместо имени файла
    ofstream out("matr_in_n.txt", ios::app);
    for (int i = 0; i < rows; i++)
    {
        int min = matrix[rows][0];
        for (int j = 0; j < cols; j++)
        {
            if (j == 0 || matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
            if (i == 0 || min > min_max)
            {
                min_max = min;
            }
        }

    }
    out << "Min max:" << min_max << endl;
    out.close();
}
void task3() {

    int n = 0;
    float* arr = new float[n];
    get_mas3(arr, n, "shaker.txt");
    cout << "Масив до сортування:" << endl;
    show_mas3(arr, n);
    shakerSort(arr, n);
    cout << "Масив після сортування:" << endl;
    show_mas3(arr, n);


}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int menu;
    do
    {
        cout << "Task number(0 for exit):";
        cin >> menu;
        switch (menu)
        { 
        case 1:
            task1();
            break; // Завдання 1
        case 2:
            task2();
            break; // Завдання 2
        case 3:
            task3();
            break; // Завдання 3

        }
    } while (menu);



    system("pause");
    return 0;
}