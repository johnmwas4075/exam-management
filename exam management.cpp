#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Exam
{
public:
    string name, examID, duration, maxmarks;

    Exam() {
        name = "";
        examID = "";
        duration = "";
        maxmarks = "";
    }

    void details() {
        cout << "Name of exam: ";
        cin >> name;
        cout << "Exam ID of exam: ";
        cin >> examID;
        cout << "Duration of exam: ";
        cin >> duration;
        cout << "Maximum marks of exam: ";
        cin >> maxmarks;
    }

    virtual string gradeExam(int marks) const { return 0; }
    virtual void displayDetails() const = 0;
    virtual ~Exam() {}
};

class Multiple : public Exam
{
public:
    int questions, marks, choice, grades;

    Multiple() {
        questions = 0;
        marks = 0;
        choice = 0;
        grades = 0;
    }

    void multipleDetails() {
        details();
        cout << "Number of questions: ";
        cin >> questions;
        cout << "Marks per question: ";
        cin >> marks;
        cout << "Choices per question: ";
        cin >> choice;
        cout << "Marks gotten: ";
        cin >> marks;
    }

        string gradeExam(int marks) const {
        if (marks >= 70) {
            return "A";
        } else if (marks >= 60 && marks < 70) {
            return "B";
        } else if (marks >= 50 && marks < 60) {
            return "C";
        } else if (marks >= 40 && marks < 50) {
            return "D";
        } else {
            return "F";
        }
    }


    void displayDetails() const  {
        cout << "Multiple Choice Exam Details:\n";
        cout << "Name: " << name <<endl;
		cout << " Exam ID: " << examID <<endl;
		cout << " Duration: " << duration << endl;
		cout << " Max Marks: " << maxmarks << endl;
        cout << " Questions: " << questions <<endl;
		cout << " Marks per question: " << marks <<endl;
		cout << " Choices per question: " << choice <<endl;
		cout << " Marks gotten: " << marks << endl;
		cout <<":::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    }

    ~Multiple() {}
};

class Essay : public Exam
{
public:
    int questions, marks, grades, topic;

    Essay() {
        questions = 0;
        marks = 0;
        grades = 0;
        topic = 0;
    }

    void essayDetails() {
        details();
        cout << "Number of questions: ";
        cin >> questions;
        cout << "Marks per question: ";
        cin >> marks;
        cout << "Marks gotten: ";
        cin >> grades;
        cout << "Topic of question: ";
        cin >> topic;
    }
    string gradeExam(int marks) const {
        if (marks >= 70) {
            return "A";
        } else if (marks >= 60 && marks < 70) {
            return "B";
        } else if (marks >= 50 && marks < 60) {
            return "C";
        } else if (marks >= 40 && marks < 50) {
            return "D";
        } else {
            return "F";
        }
    }

    void displayDetails() const {
        cout << "Essay Exam Details:\n";
        cout << "Name: " << name << endl;
		cout<<" Exam ID: " << examID << endl;
		cout<<" Duration: " << duration <<endl;
		cout<<" Max Marks: " << maxmarks << endl;
        cout<<"Questions: " << questions <<endl;
		cout<<" Marks per question: " << marks <<endl;
	    cout<<" Marks gotten: " << grades <<endl;
		cout<<" Topic: " << topic << endl;
        cout << "Grade: " << gradeExam(grades) << endl;
        cout<<":::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    }

    ~Essay() {}
};

void displayMultipleChoiceExams(const vector<Multiple*>& exams) {
    if (exams.empty()) {
        cout << "No multiple choice exams taken yet." << endl;
        return;
    }

    for (size_t i = 0; i < exams.size(); ++i) {
        exams[i]->displayDetails();
    }
}

void displayEssayExams(const vector<Essay*>& exams) {
    if (exams.empty()) {
        cout << "No essay exams taken yet." << endl;
        return;
    }

    for (size_t i = 0; i < exams.size(); ++i) {
        exams[i]->displayDetails();
    }
}

int main()
{
    vector<Multiple*> multipleChoiceExams;
    vector<Essay*> essayExams;
    Exam* exam = NULL;
    int choice;

    while (true) {
        cout << "1. Multiple choice" << endl;
        cout << "2. Essay" << endl;
        cout << "3. Display Multiple Choice Exams" << endl;
        cout << "4. Display Essay Exams" << endl;
        cout << "5. Exit" << endl;
        cout << "Input your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Multiple* multipleExam = new Multiple();
                multipleExam->multipleDetails();
                multipleChoiceExams.push_back(multipleExam);
                break;
            }
            case 2: {
                Essay* essayExam = new Essay();
                essayExam->essayDetails();
                essayExams.push_back(essayExam);
                break;
            }
            case 3: {
                displayMultipleChoiceExams(multipleChoiceExams);
                break;
            }
            case 4: {
                displayEssayExams(essayExams);
                break;
            }
            case 5: {
                for (size_t i = 0; i < multipleChoiceExams.size(); ++i) {
                    delete multipleChoiceExams[i];
                }
                for (size_t i = 0; i < essayExams.size(); ++i) {
                    delete essayExams[i];
                }
                return 0;
            }
            default: {
                cout << "Invalid choice!" << endl;
                break;
            }
        }
    }
    return 0;
}
