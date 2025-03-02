#include "AccessControl.h"
#include <iostream>
using namespace std;

// Student class implementation
void Student::updateGPA() {
    if (grades.empty()) {
        gpa = 0.0;
        return;
    }
    
    double sum = 0.0;
    for (double grade : grades) {
        sum += grade;
    }
    gpa = sum / grades.size();
}

string Student::getFormattedGPA() const {
    stringstream ss;
    ss << fixed << setprecision(2) << gpa;
    return ss.str();
}

bool Student::isActiveStudent() const {
    return active;
}

Student::Student(const string& id, const string& studentName)
    : studentId(id), name(studentName), gpa(0.0), active(true) {}

void Student::addGrade(double grade) {
    if (grade < 0.0 || grade > 100.0) {
        cout << "Error: Invalid grade value" << endl;
        return;
    }
    
    grades.push_back(grade);
    updateGPA();
}

double Student::getGPA() const {
    return gpa;
}

string Student::getName() const {
    return name;
}

string Student::getStudentId() const {
    return studentId;
}

bool Student::isPassing() const {
    return gpa >= 60.0;
}

string Student::getAcademicStanding() const {
    if (gpa >= 90.0) return "Excellent";
    if (gpa >= 80.0) return "Good";
    if (gpa >= 70.0) return "Satisfactory";
    if (gpa >= 60.0) return "Passing";
    return "Failing";
}

void Student::deactivate() {
    active = false;
}

// Course class implementation
bool Course::findStudent(const string& studentId) const {
    return any_of(enrolledStudents.begin(), enrolledStudents.end(),
                 [&](const Student* s) { 
                     return s->getStudentId() == studentId; 
                 });
}

vector<Student*> Course::getPassingStudents() const {
    vector<Student*> passing;
    copy_if(enrolledStudents.begin(), enrolledStudents.end(),
            back_inserter(passing),
            [](const Student* s) { return s->isPassing(); });
    return passing;
}

double Course::getClassAverage() const {
    if (enrolledStudents.empty()) return 0.0;
    
    double sum = 0.0;
    for (const Student* student : enrolledStudents) {
        sum += student->getGPA();
    }
    return sum / enrolledStudents.size();
}

Course::Course(const string& code, const string& name, size_t capacity)
    : courseCode(code), courseName(name), 
      maxCapacity(capacity), active(true) {}

bool Course::enrollStudent(Student* student) {
    if (!active) {
        cout << "Error: Course is not active" << endl;
        return false;
    }
    
    if (enrolledStudents.size() >= maxCapacity) {
        cout << "Error: Course is full" << endl;
        return false;
    }
    
    if (findStudent(student->getStudentId())) {
        cout << "Error: Student already enrolled" << endl;
        return false;
    }
    
    enrolledStudents.push_back(student);
    return true;
}

bool Course::dropStudent(const string& studentId) {
    auto it = find_if(enrolledStudents.begin(), enrolledStudents.end(),
                     [&](const Student* s) { 
                         return s->getStudentId() == studentId; 
                     });
    
    if (it == enrolledStudents.end()) {
        cout << "Error: Student not found" << endl;
        return false;
    }
    
    enrolledStudents.erase(it);
    return true;
}

size_t Course::getEnrollmentCount() const {
    return enrolledStudents.size();
}

bool Course::isFull() const {
    return enrolledStudents.size() >= maxCapacity;
}

string Course::getCourseInfo() const {
    stringstream ss;
    ss << "Course: " << courseCode << " - " << courseName << endl
       << "Enrollment: " << enrolledStudents.size() 
       << "/" << maxCapacity << endl
       << "Status: " << (active ? "Active" : "Inactive") << endl
       << "Class Average: " << fixed << setprecision(2) 
       << getClassAverage();
    return ss.str();
}

void Course::deactivate() {
    active = false;
}

// Department class implementation
Course* Department::findCourse(const string& courseCode) const {
    auto it = find_if(courses.begin(), courses.end(),
                     [&](const Course* c) { 
                         return c->getCourseInfo().find(courseCode) != string::npos; 
                     });
    return it != courses.end() ? *it : nullptr;
}

bool Department::allocateBudget(double amount) {
    if (amount > budget) {
        return false;
    }
    budget -= amount;
    return true;
}

void Department::deactivateAllCourses() {
    for (Course* course : courses) {
        course->deactivate();
    }
    active = false;
}

Department::Department(const string& name, double initialBudget)
    : departmentName(name), budget(initialBudget), active(true) {}

bool Department::addCourse(Course* course) {
    if (!active) {
        cout << "Error: Department is not active" << endl;
        return false;
    }
    
    if (findCourse(course->getCourseInfo())) {
        cout << "Error: Course already exists" << endl;
        return false;
    }
    
    courses.push_back(course);
    return true;
}

bool Department::removeCourse(const string& courseCode) {
    auto it = find_if(courses.begin(), courses.end(),
                     [&](const Course* c) { 
                         return c->getCourseInfo().find(courseCode) != string::npos; 
                     });
    
    if (it == courses.end()) {
        cout << "Error: Course not found" << endl;
        return false;
    }
    
    courses.erase(it);
    return true;
}

string Department::getDepartmentInfo() const {
    stringstream ss;
    ss << "Department: " << departmentName << endl
       << "Number of Courses: " << courses.size() << endl
       << "Budget Remaining: $" << fixed << setprecision(2) << budget << endl
       << "Status: " << (active ? "Active" : "Inactive");
    return ss.str();
}

double Department::getBudget() const {
    return budget;
}

void Department::deactivate() {
    deactivateAllCourses();
}

int main() {
    cout << "Access Control Demo" << endl;
    cout << "==================" << endl;
    
    // Create students
    Student alice("S001", "Alice Smith");
    Student bob("S002", "Bob Johnson");
    
    cout << "\nAdding grades for students:" << endl;
    cout << "-------------------------" << endl;
    
    alice.addGrade(95.0);
    alice.addGrade(87.5);
    alice.addGrade(92.0);
    
    bob.addGrade(78.0);
    bob.addGrade(85.0);
    bob.addGrade(80.0);
    
    cout << "Alice's GPA: " << alice.getGPA() << endl;
    cout << "Alice's Standing: " << alice.getAcademicStanding() << endl;
    cout << "Bob's GPA: " << bob.getGPA() << endl;
    cout << "Bob's Standing: " << bob.getAcademicStanding() << endl;
    
    // Create course
    Course programming("CS101", "Introduction to Programming", 30);
    
    cout << "\nEnrolling students in course:" << endl;
    cout << "---------------------------" << endl;
    
    programming.enrollStudent(&alice);
    programming.enrollStudent(&bob);
    
    cout << "\nCourse Information:" << endl;
    cout << programming.getCourseInfo() << endl;
    
    // Create department
    Department computerScience("Computer Science", 100000.0);
    
    cout << "\nAdding course to department:" << endl;
    cout << "--------------------------" << endl;
    
    computerScience.addCourse(&programming);
    
    cout << "\nDepartment Information:" << endl;
    cout << computerScience.getDepartmentInfo() << endl;
    
    // Test access control
    cout << "\nTesting access control:" << endl;
    cout << "---------------------" << endl;
    
    programming.enrollStudent(&alice);  // Should fail (already enrolled)
    computerScience.addCourse(&programming);  // Should fail (already exists)
    
    cout << "\nDeactivating department..." << endl;
    computerScience.deactivate();
    
    cout << "\nFinal Department Status:" << endl;
    cout << computerScience.getDepartmentInfo() << endl;
    
    return 0;
}
