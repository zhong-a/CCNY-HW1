#include "hw1.h"
#include <iostream>
#include <cctype>

// Put your functions/prototype here if you need to 

using namespace std;

//Swap Helper Function for Question 5
void swap(int a, int b) {
    int holder = a;
    a = b;
    b = holder;
}

// Question 1
// Loop from 1 - 30
void fizzBuzz() {
	//TODO
    for (int i = 0; i <= 30; i++) {
        cout << i << ' ';
        if (i % 3 == 0) {
            cout << "Fizz";
        }
        if (i % 5 == 0) {
            cout << "Buzz";
        }
        cout << endl;
    }
}

// Question 2
// Keeps taking in inputs until "99" is entered, and then printLargeSmall() is called
// Cannot store inputs, only check for changes to smallest and largets
void findLargeSmall() {
	//TODO
    int smallest = 0;
    int largest = 0;
    int holder;
    cin >> holder;
    while (holder != 99) {
        cin >> holder;
        if (holder > largest) {
            largest = holder;
        }
        if (holder < smallest) {
            smallest = holder;
        }
    }
    printLargeSmall(largest, smallest);
}

// Question 3
// User adds alphabet letters to ar until a non-alphabet letter is entered or size reaches MAX_SIZE
//precondition: size is ar.size() + 1
void fillArray(char ar[], size_t& size) {
	//TODO
    /*if (size == MAXSIZE) {
        return;
    }
    char out[size];
    for (int i = 0; i < size - 1; i++) {
        out[i] = ar[i];
    }

    char in;
    cin >> in;
    if (!isalpha(in)) {
        return;
    }
    out[size - 1] = in;
    size = (size_t)(size++);
    fillArray(out, size);*/
    char in;
    while (size != MAXSIZE) {
        cin >> in;
        if (!isalpha(in)) {
            return;
        }
        ar[size] = in;
        size++;
    }
}

// Question 4
// lower case letters are 97 - 122 inclusive on ASCII Table
// Use can only enter lower-case alphabet chars, need to keep track of occurences
char highestOccurrences(const char ar[], const size_t size) {
	//TODO
    assert(size <= MAXSIZE);
    int occurences[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < size; i++) {
        occurences[(int)ar[i] - 97]++;
    }
    
    char charMax = 'a';
    int occMax = 0;
    for (int i = 0; i < 26; i++) {
        if (occurences[i] > occMax) {
            charMax = i + 97;
            occMax = occurences[i];
        }
    }
    return charMax;
}

void printLargeSmall(const int large, const int small) {
	cout << "The largest is " << large << endl;
	cout << "The smallest is " << small << endl;
}

// Question 5
void shiftAr(char ar[], const size_t size, const int numShift) {
	//TODO
    /*int shift = numShift % size;
    for (int i = 0; i < size - shift; i++) {
        swap(ar[i], ar[i + shift]);
        printAr(ar, size);
    }*/
    /*for (int i = size - shift - 1; i < size; i++) {
        swap(ar[i], ar[i - shift]);
        printAr(ar, size);
    }*/
    /*for (int i = size - shift - 1; i < size; i++) {
        for (int j = i; j > 0; j--) {
            swap(ar[j], ar[j - 1]);
        }
    }*/
    
    /*for (int i = 0; i < shift; i++) {
        for (int j = size - 1; j >= 0; j--) {
            if (j == 0) {
                swap(ar[0], ar[size-1]);
            }
            else {
                swap(ar[j], ar[j-1]);
            }
            printAr(ar, size);
        }
    }*/
    int shift = numShift;
    
    if (numShift > 0)
    {
        shift = numShift % size;
    }
    else
    {
        int temp = abs(numShift) % size;
        shift = size - temp;
    }
    
    for (int i = 0; i < shift; i++)
    {
        for (int j = size - 1; j > 0; j--)
        {
            swap(ar[j], ar[j - 1]);
            printAr(ar, size);
        }
    }
}

// Question 6
char* merge(const char ar1[], const size_t n1, const char ar2[], const size_t n2) {
	//TODO
    //const size_t size = n1 + n2;
    char ar3[n1 + n2];
    int in1, in2 = 0;
    if (n1 == 0) { //ar1 empty
        for (int i = 0; i < n2; i++) {
            ar3[i] = ar2[i];
        }
        return ar3;
    }
    if (n2 == 0) { //ar2 is empty
        for (int i = 0; i < n1; i ++) {
            ar3[i] = ar2[i];
        }
        return ar3;
    }
    for (int in3 = 0; in3 < n1 + n2 - 1; in3++) {
        if (in1 == n1) {
            ar3[in3] = ar2[in2];
            in2++;
        }
        else if (in2 == n2) {
            ar3[in3] = ar1[in1];
            in1++;
        }
        else {
            if (ar1[in1] <= ar2[in2]) {
                ar3[in3] = ar1[in1];
                in1++;
            }
            else {
                ar3[in3] = ar2[in2];
                in2++;
            }
        }
    }
    return ar3;
}

void printAr(const char ar[], const size_t size) {
	for(size_t i = 0; i < size; i++)
		cout << ar[i];
	cout << endl;
}
