#include <iostream>
#include <fstream>

using namespace std;
#define MAX_NUM_STU 20

// TASK1: Merge two files into a new file.
void mergeFile(const string ip_filename1, const string ip_filename2, const string op_filename){
    string temp;
    ifstream ifs1(ip_filename1);
    if (!ifs1){
        cerr << "Error: Cannot open " << ip_filename1 << endl;
        return;
    }

    ifstream ifs2(ip_filename2);
    if (!ifs2){
        cerr << "Error: Cannot open " << ip_filename2 << endl;
        return;
    }

    ofstream ofs(op_filename);
    if (!ofs){
        cerr << "Error: Cannot open " << op_filename << endl;
        return;
    }

    // copy file1
    while (!ifs1.eof()){
        getline(ifs1, temp);
        ofs << temp << endl;
    }
    ifs1.close();

    // copy file2
    while (!ifs2.eof()){
        getline(ifs2, temp);
        ofs << temp << endl;
    }
    ifs2.close();
    ofs.close();
    return;
}

// TASK2: Clean a given file and save it to a new file.
void cleanFile(const string ip_filename, const string op_filename){
    string name[MAX_NUM_STU], grade[MAX_NUM_STU], temp_name, temp_grade;
    char c;
    int i = 0, j = 0;

    ifstream ifs(ip_filename);
    if (!ifs){
        cerr << "Error: Cannot open " << ip_filename << endl;
        return;
    }
    
    ifs.get(c);
    while (!ifs.eof()){
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
            // letters
            temp_name += c;
        }
        else if (c >= '0' && c <= '9'){
            // numbers
            temp_grade += c;
        }
        else{
            if (temp_name.length() > 0){
                name[i] = temp_name;
                temp_name = "";
                i += 1;
            }
            if (temp_grade.length() > 0){
                grade[j] = temp_grade;
                temp_grade = "";
                j += 1;
            }
        }
        ifs.get(c);
    }
    ifs.close();

    // Output the clean file.
    ofstream ofs(op_filename);
    if (!ofs){
        cerr << "Error: Cannot open " << op_filename << endl;
        return;
    }

    for (int k=0; k<i; k++){
        ofs << name[k] << "\t" << grade[k] << endl;
    }
    ofs.close();
    return;
}

// TASK3: Analyze a file, that is, to find the two students who have got the lowest and the highest grade, respectively.
// If two or more students got the same lowest/highest grade, you only need to return the first-appeared ones.
void analyzeFile(const string filename, string &low_name, string &high_name, int &low_grade, int &high_grade){
    string name[MAX_NUM_STU];
    int grade[MAX_NUM_STU], i = 0;

    ifstream ifs(filename);
    if (!ifs){
        cerr << "Error: Cannot open " << filename << endl;
        return;
    }
    
    ifs >> name[i];
    ifs >> grade[i];
    while (!ifs.eof()){
        i += 1;
        ifs >> name[i];
        ifs >> grade[i];
    }
    ifs.close();

    low_name = name[0];
    low_grade = grade[0];
    high_name = name[0];
    high_grade = grade[0];
    for (int k=0; k<i; k++){
        if (low_grade > grade[k]){
            low_grade = grade[k];
            low_name = name[k];
        }
        if (high_grade < grade[k]){
            high_grade = grade[k];
            high_name = name[k];
        }
    }
    return;
}

// Display a given file.
void displayFile(const string filename){
    string temp;
    ifstream ifs(filename);
    if (!ifs){
        cerr << "Error: Cannot open " << filename << endl;
        return;
    }
    
    cout << filename << endl;
    while (!ifs.eof()){
        getline(ifs, temp);
        cout << temp << endl;
    }
    cout << endl;
    ifs.close();
    return;
}

int main(){
    string low_name, high_name;
    int low_grade = 0, high_grade = 0;

    displayFile("record1.txt");
    displayFile("record2.txt");

    mergeFile("record1.txt", "record2.txt", "record.txt");
    displayFile("record.txt");

    cleanFile("record.txt", "record_clean.txt");
    displayFile("record_clean.txt");

    analyzeFile("record_clean.txt", low_name, high_name, low_grade, high_grade);
    cout << low_name << " got the lowest grade: " << low_grade << endl;
    cout << high_name << " got the highest grade: " << high_grade << endl;
    return 0;
}