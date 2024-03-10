#include <iostream> 
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

void InputAndOutputArray(int sizeMax, vector<double>& A) {
    int size;
    do {
        cout << "Введіть розмір масиву (0 < розмір < " << sizeMax << "): ";
        cin >> size;
    } while (size <= 0 || size >= sizeMax);

    cout << "Введіть елементи масиву:\n";
    A.resize(size);
    for (int i = 0; i < size; i++) {
        cout << "A[" << i << "]: ";
        cin >> A[i];
    }

    cout << "Масив A:\n";
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int CountZeroElements(const vector<double>& A) {
    int count = 0;
    for (double elem : A) {
        if (elem == 0) {
            count++;
        }
    }
    return count;
}

int LastMaxNegativeIndex(const vector<double>& A, double T) {
    int lastMaxNegativeIndex = -1;
    double maxNegative = INT_MIN;
    bool foundT = false;

    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] == T) {
            foundT = true;
            break;
        }
        if (A[i] < 0 && abs(A[i]) > abs(maxNegative)) {
            maxNegative = A[i];
            lastMaxNegativeIndex = i;
        }
    }

    if (!foundT) {
        cout << "Елемент, що дорівнює T, не знайдено." << endl;
        return -1;
    }

    if (lastMaxNegativeIndex == -1) {
        cout << "В масиві немає від'ємних елементів." << endl;
    }

    return lastMaxNegativeIndex;
}

int main() {
    const int MAX_SIZE = 100;
    vector<double> A;
    double T;
    int choice;

    do {
        cout << "\n\nМеню:\n";
        cout << "1. Ввести масив та вивести його\n";
        cout << "2. Порахувати кількість нульових елементів в масиві\n";
        cout << "3. Знайти останній максимальний від'ємний елемент\n";
        cout << "4. Вийти з програми\n";
        cout << "Виберіть опцію: ";
        cin >> choice;

        switch (choice) {
        case 1:
            InputAndOutputArray(MAX_SIZE, A);
            break;
        case 2:
            cout << "Кількість нульових елементів в масиві: " << CountZeroElements(A) << endl;
            break;
        case 3:
            cout << "Введіть значення T: ";
            cin >> T;
            int lastIndex = LastMaxNegativeIndex(A, T);
            if (lastIndex != -1) {
                cout << "Номер останнього максимального від'ємного елемента: " << lastIndex << endl;
            }
            break;
        case 4:
            cout << "До побачення!\n";
            break;
        default:
            cout << "Некоректний вибір. Спробуйте ще раз.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
