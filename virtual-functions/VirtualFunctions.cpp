#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <sstream>

class Person {
    public:
        string name;
        int age;
    
    public:
        virtual void getdata();
        virtual void putdata();
};

void Person::getdata() {
    cin >> name >> age;
}

void Person::putdata() {
    stringstream result;
    result << name << " ";
    result << age << " ";
    cout << result.str();
}

class Professor : public Person {
    public:
        int publications;
        int cur_id;
        void getdata();
        void putdata();
        static int id;
};
int Professor::id = 0;

class Student : public Person {
    public:
        vector<int> marks;
        int cur_id;
        void getdata();
        void putdata();
        int calculateMarks();
        static int id;
};
int Student::id = 0;

void Professor::getdata() {
    Person::getdata();
    cin >> publications;
    id = id + 1;
    cur_id = id;
}

void Professor::putdata() {
    Person::putdata();
    stringstream result;
    result << publications << " ";
    result << cur_id;
    cout << result.str() << endl;
}

void Student::getdata() {
    Person::getdata();
    for (int i = 0; i < 6; i++) {
        int mark;
        cin >> mark;
        marks.push_back(mark);
    }
    id = id + 1;
    cur_id = id;
}

void Student::putdata() {
    Person::putdata();
    stringstream result;
    result << calculateMarks() << " ";
    result << cur_id;
    cout << result.str() << endl;
}

int Student::calculateMarks() {
    int result = 0;
    for (int i = 0; i < marks.size(); i++) {
        result = result + marks[i];
    }
    return result;
}

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
