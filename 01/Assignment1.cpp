#include <iostream>
#include <string>

using namespace std;

struct Student{
    int rollNo;
    string name;
    float sgpa;
};

class StudentManager{
private:
    Student students[20];
    int size;

public:
    StudentManager(int n){
        size = n;
    }

    void getData(){
        for (int i = 0; i < size; i++){
            cout << "Enter details for student " << i + 1 << ":\n";
            cout << "Roll No: ";
            cin >> students[i].rollNo;
            cout << "Name: ";
            cin.ignore();
            getline(cin, students[i].name);
            cout << "SGPA: ";
            cin >> students[i].sgpa;
            cout << "\n";
        }
    }

    void displayData(){
        cout << "------------------------------------------------------------\n";
        cout << "Roll No\t\tName\t\tSGPA\n";
        cout << "------------------------------------------------------------\n";
        for (int i = 0; i < size; i++){
            cout << students[i].rollNo << "\t\t" << students[i].name << "\t\t" << students[i].sgpa << "\n";
        }
        cout << "------------------------------------------------------------\n";
    }

    // Sort by Roll No
    void bubbleSort(){
        for (int i = 0; i < size - 1; i++){
            for (int j = 0; j < size - i - 1; j++){
                if (students[j].rollNo > students[j + 1].rollNo){
                    swap(students[j], students[j + 1]);
                }
            }
        }
    }

    // Sort By Name
    void insertionSort(){
        for (int i = 1; i < size; i++){
            int j = i;
            while (j > 0 && students[j].name < students[j - 1].name){
                swap(students[j], students[j - 1]);
                j = j - 1;
            }
        }
    }

    // Sort by SGPA
    void quickSort(int low, int high){
        if (low > high){
            return;
        }

        int s = low;
        int e = high;
        int m = s + (e - s) / 2;
        int pivot = students[m].sgpa;

        while (s <= e){
            while (students[s].sgpa < pivot){
                s++;
            }

            while (students[e].sgpa > pivot){
                e--;
            }

            if (s <= e){
                swap(students[s], students[e]);
                s++;
                e--;
            }
        }

        quickSort(low, e);
        quickSort(s, high);
    }

    // Search by SGPA
    void searchBySGPA(double sgpa){
        cout << "------------------------------------------------------------\n";
        cout << "Roll No\t\tName\t\tSGPA\n";
        cout << "------------------------------------------------------------\n";
        for (int i = 0; i < size; i++){
            if (students[i].sgpa == sgpa){
                cout << students[i].rollNo << "\t\t" << students[i].name << "\t\t" << students[i].sgpa << "\n";
            }
        }
        cout << "------------------------------------------------------------\n";
    }

    // Search By Name
    bool binarySearch(string nameToSearch){
        int left = 0, right = size - 1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (students[mid].name == nameToSearch){
                return true;
            }
            if (students[mid].name < nameToSearch){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return false;
    }
};

int main(){
    int n;
    cout << "Enter the count of students in the database (Maximum 15):";
    cin >> n;

    StudentManager manager(n);
    manager.getData();
    string choice;

    do{
        cout << "\n\n";
        cout << "Choose an operation: " << endl;
        cout << "1. Sort students by roll number (Bubble Sort)" << endl;
        cout << "2. Sort students by alphabetically (Insertion Sort)" << endl;
        cout << "3. Sort students by SGPA (Quick Sort)" << endl;
        cout << "4. Search for a student by SGPA" << endl;
        cout << "5. Search students by name (Binary Search)" << endl;
        cout << "6. Display Data" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        int targetRollNo;
        string nameToSearch;

        switch (stoi(choice)){
        case 1:
            manager.bubbleSort();
            break;
        case 2:
            manager.insertionSort();
            break;
        case 3:
            manager.quickSort(0, n - 1);
            break;
        case 4:
            cout << "Enter the SGPA to search: ";
            cin >> targetRollNo;
            manager.searchBySGPA(targetRollNo);
            break;
        case 5:
            cout << "Enter the name to search: ";   
            cin >> nameToSearch;
            if (manager.binarySearch(nameToSearch))
            {
                cout << "\nStudent found!" << endl;
            }
            else
            {
                cout << "\nStudent not found!" << endl;
            }
            break;
        case 6:
            manager.displayData();
            break;
        default:
            cout << "Invalid choice. Please enter a valid option (1-5)." << endl;
        }

    } while (choice != "7");

    return 0;
}