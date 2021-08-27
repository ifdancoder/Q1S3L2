#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <string>
#include <algorithm>
#include <fstream>
#include "TextReader.h"

using namespace std;

template<class A>
void Swap(A& a, A& b) {
    A tmp = move(a);
    a = move(b);
    b = move(tmp);
}

template<class A>
void SortPointers(vector<A*>& vect) {
    bool f = true;
    while (f) {
        f = false;
        for (size_t i = 0; i < vect.size() - 1; i++) {
            if (*vect[i] > *vect[i + 1]) {
                f = true;
                swap(vect[i], vect[i + 1]);
            }
        }
    }
}

int main()
{
    srand(time(0));
    { // #1
        cout << "Ex 1:" << endl;
        int a, b;

        cout << "Input a, b (a b): ";
        cin >> a >> b;
        cout << "a: " << a << ", b: " << b << endl;
        cout << "Swapping..." << endl;

        Swap(a, b);

        cout << "a: " << a << ", b: " << b << endl << endl;
    }
   
    { // #2
        cout << "Ex 2:" << endl;
        vector<int*> a;

        cout << "Before sorting: ";
        for (size_t i = 0; i < 10; i++) {
            int* b = new int(rand() % 100 - 50);
            a.push_back(b);
            cout << *b << ' ';
        }
        cout << endl;

        SortPointers(a);

        cout << "After sorting: ";
        for (size_t i = 0; i < a.size(); cout << *a[i] << ' ', i++);

        cout << endl << endl;
    }

    { // #3
        cout << "Ex 3:" << endl;
        TextReader txtrdr("text.txt");
        txtrdr.TimerVowelCounter(VowelCountIfFind);
        txtrdr.TimerVowelCounter(VowelCountIfFor);
        txtrdr.TimerVowelCounter(VowelForFind);
        txtrdr.TimerVowelCounter(VowelForFor);
    }
    return 0;
}