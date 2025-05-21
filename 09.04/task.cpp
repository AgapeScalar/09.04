#include <iostream>
using namespace std;

class String {
private:
    char* str;
    int length;

    int getLength(const char* s) {
        int len = 0;
        while (s[len] != '\0') len++;
        return len;
    }

    void copy(char* dest, const char* src) {
        int i = 0;
        while (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

public:
    String() {
        length = 80;
        str = new char[length + 1];
        str[0] = '\0';
    }

    String(int size) {
        length = size;
        str = new char[length + 1];
        str[0] = '\0';
    }

    String(const char* input) {
        length = getLength(input);
        str = new char[length + 1];
        copy(str, input);
    }

    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        copy(str, other.str);
    }

    void input() {
        char buffer[1000];
        cout << "Enter string: ";
        cin.getline(buffer, 1000);
        length = getLength(buffer);
        delete[] str;
        str = new char[length + 1];
        copy(str, buffer);
    }

    void display() const {
        cout << "String: " << str << endl;
    }

    ~String() {
        delete[] str;
    }
};

class Array {
private:
    int* data;
    int size;

public:
    Array() {
        size = 0;
        data = nullptr;
    }

    Array(int s) {
        size = s;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = 0;
    }

    Array(const Array& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    void fill() {
        cout << "Enter " << size << " numbers:\n";
        for (int i = 0; i < size; i++)
            cin >> data[i];
    }

    void display() const {
        cout << "Array: ";
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    void resize(int newSize) {
        int* newData = new int[newSize];
        for (int i = 0; i < (newSize < size ? newSize : size); i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        size = newSize;
    }

    void sortArray() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }

    int min() const {
        if (size == 0) return 0;
        int minVal = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] < minVal)
                minVal = data[i];
        }
        return minVal;
    }

    int max() const {
        if (size == 0) return 0;
        int maxVal = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] > maxVal)
                maxVal = data[i];
        }
        return maxVal;
    }

    ~Array() {
        delete[] data;
    }
};

int main() {
    cout << "=== Task 1: String Class ===" << endl;

    String s1;
    s1.input();
    s1.display();

    String s2("Test string");
    s2.display();

    String s3 = s2; 
    cout << "Copied string: ";
    s3.display();

    cout << "\n=== Task 2: Array Class ===" << endl;

    Array a1(5); 
    a1.fill();
    cout << "Original array: ";
    a1.display();

    a1.sortArray();
    cout << "Sorted array: ";
    a1.display();

    cout << "Min: " << a1.min() << ", Max: " << a1.max() << endl;

    Array a2 = a1; 
    cout << "Copied array: ";
    a2.display();

    a2.resize(7);
    cout << "Resized copied array (size = 7): ";
    a2.display();

    return 0;
}
