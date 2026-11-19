#include <iostream>
#include <string>

/**
 * Inheritance Hierarchy:
 *   Person (Base Class)
 *     └── Student (Derived from Person -> Single Inheritance)
 *           └── GraduateStudent (Derived from Student -> Multilevel Inheritance)
 */
class Person {
protected:
    std::string name_;
    int age_;

public:
    Person(const std::string& name = "Satinderpal Singh Chaney", int age = 20)
        : name_(name), age_(age) {}

    void displayPersonDetails() const {
        std::cout << "----- PERSON DETAILS -----\n";
        std::cout << "Name: " << name_ << "\n";
        std::cout << "Age: " << age_ << "\n";
    }
};

// Single Inheritance: Student derives publicly from Person
class Student : public Person {
protected:
    std::string studentId_;
    std::string course_;

public:
    Student(const std::string& name = "Satinderpal Singh Chaney",
            int age = 20,
            const std::string& studentId = "E26B00S2034",
            const std::string& course = "Computer Science Engineering")
        : Person(name, age), studentId_(studentId), course_(course) {}

    void displayStudentDetails() const {
        std::cout << "----- STUDENT DETAILS -----\n";
        std::cout << "Name: " << name_ << "\n";
        std::cout << "Student ID: " << studentId_ << "\n";
        std::cout << "Course: " << course_ << "\n";
    }
};

// Multilevel Inheritance: GraduateStudent derives publicly from Student (which derives from Person)
class GraduateStudent : public Student {
private:
    std::string researchTopic_;
    std::string supervisor_;

public:
    GraduateStudent(const std::string& name = "Satinderpal Singh Chaney",
                    int age = 20,
                    const std::string& studentId = "E26B00S2034",
                    const std::string& course = "Computer Science Engineering",
                    const std::string& researchTopic = "Artificial Intelligence",
                    const std::string& supervisor = "Computer Science Department")
        : Student(name, age, studentId, course),
          researchTopic_(researchTopic),
          supervisor_(supervisor) {}

    void displayGraduateStudentDetails() const {
        std::cout << "----- GRADUATE STUDENT DETAILS -----\n";
        std::cout << "Name: " << name_ << "\n";
        std::cout << "Student ID: " << studentId_ << "\n";
        std::cout << "Course: " << course_ << "\n";
        std::cout << "Research Topic: " << researchTopic_ << "\n";
        std::cout << "Supervisor: " << supervisor_ << "\n";
    }
};

int main() {
    std::cout << "----- INHERITANCE DEMONSTRATION -----\n";
    std::cout << "Student Name: Satinderpal Singh Chaney\n";
    std::cout << "Roll Number: E26B00S2034 ";

    // Person object
    Person person("Satinderpal Singh Chaney", 20);
    person.displayPersonDetails();

    // Single Inheritance object: Person -> Student
    Student student("Satinderpal Singh Chaney", 20, "E26B00S2034", "Computer Science Engineering");
    student.displayStudentDetails();

    // Multilevel Inheritance object: Person -> Student -> GraduateStudent
    GraduateStudent gradStudent("Satinderpal Singh Chaney",
                                20,
                                "E26B00S2034",
                                "Computer Science Engineering",
                                "Artificial Intelligence",
                                "Computer Science Department");
    gradStudent.displayGraduateStudentDetails();

    std::cout << "Single Inheritance Demonstrated!\n";
    std::cout << "Multilevel Inheritance Demonstrated!\n";
    std::cout << "Program executed successfully.\n";

    return 0;
}
