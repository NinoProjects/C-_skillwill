#include <iostream>

using namespace std;

//Abstract class for academy

class AbstractAcademy{
    public:
        string Name;
        string Section;
        int NumOfStudents;
        int NumOfLectors;
        string Subjects;
        
        void getDescription(){
            cout << "Description of abstract academy" <<endl;
        }
    
};

//class of SkillWillAcademy

class SkillWillAcademy: public AbstractAcademy {
    public:
    
        //Overriding getDescription
        void getDescription (){
            cout << "Academy name: " << Name << endl;
            cout << "Number of students: " << NumOfStudents << endl;
            cout << "Number of Lectors: " << NumOfLectors << endl;
            cout << "Subject: " << Subjects <<endl;
        }
};


// Subject class Description
class SkillWillSubject{
    public:
        string Name;
        string Length;
        string StartingDate;
        
        virtual void lastLectureName(){
            cout << "last lecture name was Practical Lesson" << endl;
        }
        void getDescription() {
            cout << "This is a class of " << Name << " subject " << endl;
        }
    
};


//Abstract class of Lector
class AbstractLector {
    public:
        string FirstName;
        string LastName;
        string SubjectName;
        int Chapter;
        string Level;
        
        virtual void conductingLecture() = 0;
        void getDescription () {
            cout << "Description of a Lector, Chapter and Level" << endl;
        }
};


// class of Skillwill Lector 
class SkillWillLector: public AbstractLector {
    public:
        
        SkillWillSubject subject;
        SkillWillAcademy skillwill;
        void conductingLecture() {
            cout << "Lector is conducting a lecture" << endl;
        }
        
        // Overloading conductingLecture
        void conductingLecture(SkillWillSubject subject) {
            cout << FirstName << " " << LastName << " is conducting a " << subject.Name << " lecture on" << subject.StartingDate << endl;
        }
        
        void conductingLecture(string subjectName, string date) {
          cout << FirstName << " " << LastName << " is conducting a " << subjectName << " lecture in " << date << endl;
        }
        
        // Overriding getDescription
        
        void getDescription (){
            cout << "First name: " << FirstName << endl;
            cout << "Last name: " << LastName << endl;
            cout << "Subject teaching: " << SubjectName << endl;
            cout << "Chapter: " << Chapter << endl;
            cout << "Level: " << Level << endl;
        }
};


//Abstract class of Student
class AbstractStudent {
    public:
        string FirstName;
        string LastName;
        int Age;
        int QuizScore = 0;
        
        virtual void attendLecture() = 0;
        void studentScore(){
            cout << "This is a score Student is getting monthly in quiz" << endl;
        }
        void getDescription() {
            cout << "Description of a Student" << endl;
        }
        
        void updateQuizScore(string fullName, int quizScore) {
           QuizScore += quizScore;
           cout << fullName << "'s current score is " << QuizScore << endl;
       }
};


//class of SkillWill Student
class SkillWillStudent: public AbstractStudent {
    public:
    
        SkillWillSubject subject;
        SkillWillAcademy academy;
        SkillWillLector lector;
    
        void attendLecture(){
            cout << "Student is attending Lecture" << endl;
        }
        
        // Overloading attendLecture
        void attendLecture(string subjectName){
            cout << FirstName <<" " << LastName << " is attending a " << subjectName << " Lecture" << endl;
        } 
    
        // Overriding getDescription
        void getDescription() {
            cout << "First name: " << FirstName << endl;
            cout << "Last name: " << LastName << endl;
            cout << "Age: " << Age << endl;
            cout << "Section: " << academy.Section << endl;
            cout << "Subject: " << subject.Name << endl;
            cout << "Lector of subject: " << lector.FirstName << " " << lector.LastName <<endl;
        }
    
};



int main()
{
    SkillWillLector lector;
    lector.FirstName = "Aleksandre";
    lector.LastName = "Kutaladze";
    lector.SubjectName = "Basics of C++";
    lector.Chapter = 3;
    lector.Level = "Professional";
    
    lector.getDescription();
    
    lector.conductingLecture("python", "March 30th.");
    
    SkillWillStudent student1;
    student1.FirstName = "Nino";
    student1.LastName = "Ninoshvili";
    student1.Age = 23;
    student1.academy.Section = "C-section";
    
    student1.getDescription();
    
    
    student1.updateQuizScore("Nino Ninoshvili", 50);
    student1.updateQuizScore("Nino Ninoshvili", 80);
    
    student1.attendLecture();


    SkillWillSubject subject;
    subject.lastLectureName();
    
    

    return 0;
}




