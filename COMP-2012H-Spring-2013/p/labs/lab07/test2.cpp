#include <iostream.h>
#include <fstream.h>
#include <assert.h>

// A prototype of Student
struct Student           
{
    int ID;             // Student ID 
    char Name[50];      // Name of this student
    double Scores[3];   // Scores of this student
    char Grade;
};

int GetStuRecord (ifstream &fin, Student &stu)
{
    fin >>stu.ID;    
    if (fin.fail())         // fail to read a record return 0 for failure
        return 0;
    
    fin >>stu.Name;
    for (int i=0; i<=3; i++)
        fin >>stu.Scores[i];
    return (fin.good());    // return 1 for successful; 0 for failure  
}

char AssignStuGrade (Student &stu)
{
    double sum = 0.0;
    for (int i=0; i<=3; i++)
        sum += stu.Scores[i];
    sum /= 3.0;
    
    switch ((int)(sum / 10))        // assign the grade to student by this grading scheme
    {
    case 9:
    case 10:
        return 'A';
        break;
    case 8:
        return 'B';
        break;
    case 7:
        return 'C';
        break;
    case 6:
        return 'D';
        break;
    default:
        return 'F';
        break;
    }
}

void SaveStuRecord (ofstream &fout, Student &stu)
{
    fout << stu.ID << ' ' << stu.Name << ' ' << stu.Grade << endl;
}

int main (int argc, char *argv[])
{
    const char *MARK_FILE  = "mark.txt";
    const char *GRADE_FILE = "grade.txt";
    ifstream fin(MARK_FILE, ios::nocreate);     // Read mark.txt file for input
    ofstream fout(GRADE_FILE);                  // Output to grade.txt for result
    assert (fin.is_open ());                    // Return error prompt for missing mark.txt or cannot not open file
    assert (fout.is_open ());                   // Return error prompt for cannot open file 

    while (!fin.eof ())                         // Check the read file until the end of file
    {
        Student stu;
        int val = GetStuRecord(fin, stu);       // Retrive a student record
        if (val = 0)                            // if read student record fail, then finish
            break;       
        
        stu.Grade = AssignStuGrade (stu);       // Assign a grade to student
        cout << stu.Name << endl;
        SaveStuRecord(fout, stu);               // Save the result of the student to the file
    }
    fin.close ();
    fout.close ();
    return 0;
}
