#ifndef ACCESSCONTROL_H
#define ACCESSCONTROL_H

#include <string>
#include <vector>

// TODO: Implement Student class
// - Use appropriate access specifiers
// - Demonstrate public interface
// - Hide implementation details
class Student {
private:
    // TODO: Add private member variables
    // - Student ID
    // - Name
    // - Grades
    
protected:
    // TODO: Add protected member variables
    // - Grade calculation helpers
    // - Status tracking
    
public:
    // TODO: Implement constructor
    // - Initialize student data
    Student(const std::string& id, const std::string& name);
    
    // TODO: Implement grade management
    // - Add new grade
    // - Calculate average
    void addGrade(double grade);
    double getAverage() const;
    
    // TODO: Implement status checks
    // - Check passing status
    // - Get academic standing
    bool isPassing() const;
    std::string getStanding() const;
    
    // TODO: Implement info display
    // - Format student details
    std::string getInfo() const;
};

// TODO: Implement Course class
// - Use appropriate access specifiers
// - Manage student enrollment
class Course {
private:
    // TODO: Add private member variables
    // - Course code
    // - Course name
    // - Student list
    // - Maximum capacity
    
protected:
    // TODO: Add protected member variables
    // - Enrollment helpers
    // - Statistics tracking
    
public:
    // TODO: Implement constructor
    // - Initialize course data
    Course(const std::string& code, const std::string& name, int capacity);
    
    // TODO: Implement enrollment management
    // - Add student
    // - Remove student
    // - Check enrollment status
    bool enrollStudent(Student* student);
    bool dropStudent(const std::string& studentId);
    bool isEnrolled(const std::string& studentId) const;
    
    // TODO: Implement course info
    // - Get enrollment count
    // - Check capacity
    // - Format course details
    int getEnrollmentCount() const;
    bool isFull() const;
    std::string getCourseInfo() const;
};

// TODO: Implement Department class
// - Use appropriate access specifiers
// - Manage courses and faculty
class Department {
private:
    // TODO: Add private member variables
    // - Department name
    // - Course list
    // - Faculty list
    // - Budget allocation
    
protected:
    // TODO: Add protected member variables
    // - Resource management helpers
    // - Department statistics
    
public:
    // TODO: Implement constructor
    // - Initialize department
    Department(const std::string& name);
    
    // TODO: Implement course management
    // - Add course
    // - Remove course
    // - Find course
    bool addCourse(Course* course);
    bool removeCourse(const std::string& courseCode);
    Course* findCourse(const std::string& courseCode);
    
    // TODO: Implement department operations
    // - Calculate total enrollment
    // - Generate department report
    // - Check resource utilization
    int getTotalEnrollment() const;
    std::string generateReport() const;
    double getResourceUtilization() const;
};

#endif // ACCESSCONTROL_H
