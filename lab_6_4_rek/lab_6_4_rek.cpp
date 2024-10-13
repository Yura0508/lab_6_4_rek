// lab_6_4_rek.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;


void Create(int* b, const int size, const int Low, const int High, int i) {
    b[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1) {
        Create(b, size, Low, High, i + 1);
    }
}


void Print(const int* b, const int size, int i) {
    cout << setw(4) << b[i];
    if (i < size - 1) {
        Print(b, size, i + 1);
    }
    else {
        cout << endl;
    }
}


int Max(int* a, const int size, int i, int max, int& index) {
    if (i == 0) {
        max = a[0];
        index = 0;
    }

    if (a[i] > max) {
        max = a[i];
        index = i;
    }

    if (i < size - 1) {
        return Max(a, size, i + 1, max, index);
    }
    else {
        return max;
    }
}


int ProductBetweenZeros(int* a, const int size, int firstZeroIndex = -1, int secondZeroIndex = -1, int i = 0) {
    if (i >= size) {
        if (firstZeroIndex != -1 && secondZeroIndex != -1 && secondZeroIndex > firstZeroIndex + 1) {
            int product = 1;
            for (int j = firstZeroIndex + 1; j < secondZeroIndex; ++j) {
                product *= a[j];
            }
            return product;
        }
        return 0; 
    }
    if (a[i] == 0) {
        if (firstZeroIndex == -1) {
            firstZeroIndex = i; 
        }
        else if (secondZeroIndex == -1) {
            secondZeroIndex = i; 
        }
    }
    return ProductBetweenZeros(a, size, firstZeroIndex, secondZeroIndex, i + 1);
}


void AddOddIndexed(int* a, const int size, int* newArray, int& index, int i) {
    if (i < size) {
        if (i % 2 != 0) {
            newArray[index++] = a[i];
        }
        AddOddIndexed(a, size, newArray, index, i + 1);
    }
}
void AddEvenIndexed(int* a, const int size, int* newArray, int& index, int i) {
    if (i < size) {
        if (i % 2 == 0) {
            newArray[index++] = a[i];
        }
        AddEvenIndexed(a, size, newArray, index, i + 1);
    }
}
int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    int n;
    cout << " n (size): ";
    cin >> n;
    if (n <= 0) {
        cout << "NaN" << endl;
        return 1;
    }
    int* b = new int[n];
    const int Low = 0;
    const int High = 10;

    Create(b, n, Low, High, 0);
    cout << "massif b:" << endl;
    Print(b, n, 0);

    int maxIndex;
    int maxValue = Max(b, n, 0, b[0], maxIndex);
    cout << "max b[" << maxIndex << "]: " << maxValue << endl;

    int product = ProductBetweenZeros(b, n);
    cout << "product: " << product << endl;
 
    int* separatedArray = new int[n];
    int index = 0;

    AddOddIndexed(b, n, separatedArray, index, 0);
    AddEvenIndexed(b, n, separatedArray, index, 0);
    cout << "now massif:" << endl;
    Print(separatedArray, index, 0);

    delete[] b;
    delete[] separatedArray;
    return 0;
}
