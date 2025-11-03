#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct student {
    string name;
    int roll_no;
    float cgpa;
};

class cstudent {
    struct student s[20];
    int n;

    int partition(int low, int high) {
        float pivot = s[high].cgpa;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (s[j].cgpa < pivot) {
                i++;
                swap(s[i], s[j]);
            }
        }
        swap(s[i + 1], s[high]);
        return i + 1;
    }

    void quick_sort_recursive(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quick_sort_recursive(low, pi - 1);
            quick_sort_recursive(pi + 1, high);
        }
    }

public:
    void insert(int n) {
        for (int i = 0; i < n; i++) {
            cout << "Enter student's name" << endl;
            cin >> s[i].name;
            cout << "Enter student's roll_no" << endl;
            cin >> s[i].roll_no;
            cout << "Enter student's cgpa" << endl;
            cin >> s[i].cgpa;
        }
        this->n = n; // Store the number of students internally
    }

    void display_data(int n) {
        for (int i = 0; i < n; i++) {
            cout << "name: " << s[i].name << endl;
            cout << "roll_no: " << s[i].roll_no << endl;
            cout << "cgpa: " << s[i].cgpa << endl;
        }
    }

    void linear_search(float key, int n) {
        int i = 0, flag = 0;
        while (i < n) {
            if (s[i].cgpa == key) {
                cout << "roll number: " << s[i].roll_no << " name: " << s[i].name << endl;
                flag = 1;
            }
            i++;
        }
        if (flag == 0) cout << "no record found" << endl;
    }

    void bubble_sort(int n) {
        for (int pass = 0; pass < n; pass++) {
            for (int i = 0; i < n - pass - 1; i++) {
                if (s[i + 1].roll_no < s[i].roll_no) {
                    swap(s[i + 1], s[i]);
                }
            }
        }
    }

    void insertion_sort(int n) {
        for (int i = 1; i < n; i++) {
            student key = s[i];
            int prev = i - 1;
            while (prev >= 0 && s[prev].name > key.name) {
                s[prev + 1] = s[prev];
                prev--;
            }
            s[prev + 1] = key;
        }
    }

    void binary_search(int n) {
        string key;
        cout << "Enter a name whose details you want to access" << endl;
        cin >> key;
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (s[mid].name == key) {
                cout << "result found at position: " << mid << endl;
                cout << s[mid].name << " " << s[mid].roll_no << " " << s[mid].cgpa << endl;
                return;
            }
            else if (s[mid].name < key) {
                start = mid + 1;
            }
            else end = mid - 1;
        }
        cout << "No student with name '" << key << "' found." << endl;
    }

    void quick_sort(int n) {
        quick_sort_recursive(0, n - 1);
    }
};

int main() {
    cstudent obj;
    int n;
    cout << "Enter number of students: " << endl;
    cin >> n;
    while (n > 20 || n < 0) {
        cout << "Enter value within 0 to 20 range" << endl;
        cin >> n;
    }

    cout << "Enter data of students please" << endl;
    obj.insert(n);

    int i = 1;
    while (i > 0) {
        int choice;
        cout << "\nEnter your choice:\n1.bubble sort\n2.insertion sort\n3.quick sort\n4.linear search\n5.binary search\n6.display\n7.quit" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            obj.bubble_sort(n);
            obj.display_data(n);
            break;
        case 2:
            obj.insertion_sort(n);
            obj.display_data(n);
            break;
        case 3:
            obj.quick_sort(n);
            obj.display_data(n);
            break;
        case 4: {
            float key;
            cout << "Enter a cgpa you want to match" << endl;
            cin >> key;
            obj.linear_search(key, n);
            break;
        }
        case 5:
            obj.binary_search(n);
            break;
        case 6:
            obj.display_data(n);
            break;
        case 7:
            i = 0;
            cout << "You are logging out" << endl;
            return 0;
        default:
            cout << "Enter correct choice please" << endl;
            break;
        }
        i++;
    }
    return 0;
}
