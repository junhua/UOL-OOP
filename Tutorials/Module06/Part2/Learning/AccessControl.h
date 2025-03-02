#ifndef ACCESSCONTROL_H
#define ACCESSCONTROL_H

#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>

class Student {
private:
    std::string studentId;
    std::string name;
    std::vector<double> grades;
    double gpa;
    bool active;
    
    void updateGPA();
    
protected:
    std::string getFormattedGPA() const;
    bool isActiveStudent() const;
    
public:
    Student(const std::string& id, const std::string& studentName);
    void addGrade(double grade);
    double getGPA() const;
    std::string getName() const;
    std::string getStudentId() const;
    bool isPassing() const;
    std::string getAcademicStanding() const;
    void deactivate();
};

class Course {
private:
    std::string courseCode;
    std::string courseName;
    std::vector<Student*> enrolledStudents;
    size_t maxCapacity;
    bool active;
    
    bool findStudent(const std::string& studentId) const;
    
protected:
    std::vector<Student*> getPassingStudents() const;
    double getClassAverage() const;
    
public:
    Course(const std::string& code, const std::string& name, size_t capacity);
    bool enrollStudent(Student* student);
    bool dropStudent(const std::string& studentId);
    size_t getEnrollmentCount() const;
    bool isFull() const;
    std::string getCourseInfo() const;
    void deactivate();
};

class Department {
private:
    std::string departmentName;
    std::vector<Course*> courses;
    double budget;
    bool active;
    
    Course* findCourse(const std::string& courseCode) const;
    
protected:
    bool allocateBudget(double amount);
    void deactivateAllCourses();
    
public:
    Department(const std::string& name, double initialBudget);
    bool addCourse(Course* course);
    bool removeCourse(const std::string& courseCode);
    std::string getDepartmentInfo() const;
    double getBudget() const;
    void deactivate();
};

#endif // ACCESSCONTROL_H
