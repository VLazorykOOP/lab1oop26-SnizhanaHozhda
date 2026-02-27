

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// ЗАДАЧА 1 - 6. Задано одновимірний масив А розміру N. Знайти кількість нульових елементів
void task1() {
    cout << "\n--- First task ---" << endl;
    int N;
    cout << " Input size Array N ";
    cin >> N;

    vector<int> A(N);
    cout << " Input Array A \n";
    for (int i = 0; i < N; i++) {
        cout << " A[ " << i << "] ";
        cin >> A[i];
    }
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

// ГОЛОВНА ФУНКЦІЯ
int main() {
    int choice;
    cout << "Select task (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        task1();
    }
    else if (choice == 2) {
        task2();
    }
    else {
        cout << "Wrong choice!" << endl;
    }

    return 0;
}