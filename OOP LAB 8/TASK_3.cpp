#include <string>
using namespace std;

class Student 
{
private:
    string name;
    int grades[3];

public:
    Student(string n, int g1, int g2, int g3) : name(n) 
{
        grades[0] = g1;
        grades[1] = g2;
        grades[2] = g3;
    }

    friend class Teacher;
    friend double calculateAverageGrade(Student& student);
};

class Teacher 
{
public:
    void displayGrades(Student& student) 
{
        cout << "Grades for " << student.name << ": "
             << student.grades[0] << ", "
             << student.grades[1] << ", "
             << student.grades[2] << endl;
    }

    void updateGrade(Student& student, int index, int newGrade) {
        if (index >= 0 && index < 3) 
{
            student.grades[index] = newGrade;
        }
    }
};

double calculateAverageGrade(Student& student)
 {
    return (student.grades[0] + student.grades[1] + student.grades[2]) / 3.0;
}

int main()
 {
    Student student("Asad Ahmed", 85, 90, 78);
    Teacher teacher; 
    teacher.displayGrades(student);
    cout << "Average grade: " << calculateAverageGrade(student) << endl;
    teacher.updateGrade(student, 1, 95);
    teacher.displayGrades(student);
    cout << "New average grade: " << calculateAverageGrade(student) << endl;
}