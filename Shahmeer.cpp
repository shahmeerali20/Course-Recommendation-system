#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Course {
    string niche;
    string name;
    string link;
};

vector<Course> courses = {
    {"web development", "The Complete Web Developer Course", "https://www.udemy.com/course/the-complete-web-developer-course-2/"},
    {"data science", "Data Science and Machine Learning Bootcamp", "https://www.udemy.com/course/python-for-data-science-and-machine-learning-bootcamp/"},
    {"graphic design", "Graphic Design Masterclass", "https://www.udemy.com/course/graphic-design-masterclass-everything-you-need-to-know/"},
    {"cybersecurity", "The Complete Cyber Security Course", "https://www.udemy.com/course/the-complete-internet-security-privacy-course-volume-1/"},
    {"digital marketing", "The Complete Digital Marketing Guide", "https://www.udemy.com/course/learn-digital-marketing-course/"}
};

Course recommendCourse(string niche) {
    transform(niche.begin(), niche.end(), niche.begin(), ::tolower);
    for (const auto& course : courses) {
        string courseNiche = course.niche;
        transform(courseNiche.begin(), courseNiche.end(), courseNiche.begin(), ::tolower);
        if (courseNiche == niche) {
            return course;
        }
    }
    return {niche, "No course found", "#"};
}

void clearScreen() {
    system("cls");
}

bool isValidEmail(const string& email) {
    return email.find('@') != string::npos;
}

int main() {
    string name, niche, email;
    int age;
    char confirm;
    
    do {
        clearScreen();
        cout << "Welcome to Course Recommender!\n";
        cout << "---------------------------------\n";
        cout << "Enter your name: ";
        getline(cin, name);
        
        cout << "Enter your age: ";
        while (!(cin >> age)) {
            cout << "Invalid input. Please enter a number for age: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();
        
        do {
            cout << "Enter your email: ";
            getline(cin, email);
            if (!isValidEmail(email)) {
                cout << "Invalid email format. Please include '@' in your email.\n";
            }
        } while (!isValidEmail(email));
        
        cout << "Enter your niche (e.g., Web Development, Data Science, etc.): ";
        getline(cin, niche);
        
        Course recommended = recommendCourse(niche);
        
        clearScreen();
        cout << "\nHello " << name << "! Based on your interest in " << niche << ", we recommend:\n";
        cout << "Your Details:\n";
        cout << "---------------------------------\n";
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Email: " << email << "\n";
        cout << "Niche: " << niche << "\n";
        
        if (recommended.name == "No course found") {
            cout << "Sorry, no course found for the given niche. Please try again.\n";
        } else {
            cout << "Course: " << recommended.name << "\n";
            cout << "Link: " << recommended.link << "\n\n";
        }
        
        cout << "\nWould you like to enter details again? (y/n): ";
        cin >> confirm;
        cin.ignore();
        
    } while (confirm == 'y' || confirm == 'Y');
    
    cout << "\nThank you for using Course Recommender!\n";
    return 0;
}
