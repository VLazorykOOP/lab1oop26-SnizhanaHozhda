

#include <iostream>
#include <vector>
#include <limits>
#include <fstream>

using namespace std;
void WriteArrayToFile(int N, double* arr, const char* fileName) {
    ofstream fout(fileName);
    if (!fout) return;
    fout << N << "\n";
    for (int i = 0; i < N; i++) fout << arr[i] << " ";
    fout.close();
}
// ЗАДАЧА 1 - 6. Задано одновимірний масив А розміру N. Знайти кількість нульових елементів
void task1() {
    ifstream inFile("input.txt");
    cout << "\n--- First task ---  " << endl;
    if (!inFile.is_open()) {
        cout << "Error: File not found!" << endl;
        return;
    }
    int N;
    if (!(inFile >> N)) return;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        inFile >> A[i]; 
    }
    inFile.close();
    int countzero = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) {
            countzero++;
        }
    }
    cout << " Count zero = " << countzero << endl;
    return ;
    
}

// ЗАДАЧА 2 - 6. Знайти номер останнього максимального значення серед від’ємних елементів,розташованих правіше елемента, рівного Т.

void task2() {
    cout << "\n--- Task 2 ---" << endl;
    int n, T;
    cout << "Input size: ";
    if (!(cin >> n)) return;

    vector<int> arr(n);
    cout << "Input elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Input T: ";
    cin >> T;

    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == T) {
            index = i;
            break;
        }
    }

    if (index == -1 || index == n - 1) {
        cout << "T not found or no elements after it" << endl;
        return;
    }

    int max_negative = numeric_limits<int>::min();
    int last_idex = -1;
    bool found = false;

    for (int i = index + 1; i < n; i++) {
        if (arr[i] < 0) {
            if (!found || arr[i] >= max_negative) {
                max_negative = arr[i];
                last_idex = i;
                found = true;
            }
        }
    }

    if (found) {
        cout << "Index: " << last_idex << " Value: " << max_negative << endl;
    }
    else {
        cout << "No negative elements after T" << endl;
    }
}
    
        //ЗАДАЧА 3 6. Задано масив дійсних чисел А(N), N<=200 Розробити програму,яка будує масив дійсних чисел В(N) 
        // за правилом bi є середніи арифметичним значенням чисел a1,a2,...an крім ai, i = 1,2,...n.

    void task3() {
    ifstream inFile("input.txt");

    cout << "\n--- Task3 ---" << endl;

    if (!inFile.is_open()) {
        cout << "POMYLKA: Fail ne znaydeno za vkazanym shlyahom!" << endl;
        system("pause");
        return;
    }

    int N;
    if (!(inFile >> N)) {
        cout << "POMYLKA: Fail porozhniy abo nevirnyy format!" << endl;
        return;
    }

    double* A = new double[N];
    double totalsum = 0;
    for (int i = 0; i < N; i++) {
        inFile >> A[i];
        totalsum += A[i];
    }
    inFile.close();

    double* B = new double[N];
    for (int i = 0; i < N; i++) {
        B[i] = (totalsum - A[i]) / (N - 1);
    }
    WriteArrayToFile(N, B, "output3.txt");
    
    cout << "Array B (calculated from file): ";
    for (int i = 0; i < N; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;
    return;

}



// ГОЛОВНА ФУНКЦІЯ
int main() {
    int choice;
    cout << "Select task (1,2 or 3): ";
    cin >> choice;

    if (choice == 1) {
        task1();
    }
    else if (choice == 2) {
        task2();
    }
    else if (choice == 3) {
        task3();
    }
    else {
        cout << "Wrong choice!" << endl;
    }

    return 0;
}