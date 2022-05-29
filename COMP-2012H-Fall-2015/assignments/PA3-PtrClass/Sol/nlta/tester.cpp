#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

#include "matrix.h"



using namespace std;


ifstream fin("input.txt");
ofstream fout("output.txt");



void PrintMatrix(const Matrix& mt, string title) {
    fout << title << "=" << endl;

    for (int i = 0; i < mt.rows(); ++i) {
        fout << "   ";

        for (int j = 0; j < mt.cols(); ++j)
            fout << setprecision(3) << mt.el(i, j) << " ";

        fout << endl;
    }

    fout << endl;
}



void PrintVector(const vector<double>& v) {
    fout << "[";

    for (int i = 0; i < v.size(); ++i)
        if (i == v.size() - 1)
            fout << v[i] << "]";
        else
            fout << v[i] << " ";
}



int main() {
    Matrix mt[10];
    vector<double> b;
    int r, c, nmat;

    fin >> nmat;

    for (int k = 0; k < nmat; ++k) {
        fin >> r >> c;

        mt[k] = Matrix(r, c);
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                fin >> mt[k].el(i, j);

        PrintMatrix(mt[k], string("Mat") + char('0' + k));
    }

    fout << "------------------------------------" << endl << endl;

    int ncmd;
    char cmd, bs;
    double dd;
    string info;
    Matrix res;
    vector<double> bparam;
    vector< vector<double> > fparams;

    fin >> ncmd;

    for (int k = 0; k < ncmd; ++k) {
        fin >> cmd;

        switch (cmd) {
            case 'A':
                fin >> r >> c;

                mt[c].assign(mt[r]);
                PrintMatrix(mt[c], string("Mat(") + char('0' + r) + string("->") + char('0' + c) + ")");

                break;
            case 'M':
                fin >> r >> c;

                res = mt[r].mul(mt[c]);
                PrintMatrix(res, string("Mat") + char('0' + r) + string("*Mat") + char('0' + c));

                break;
            case 'T':
                fin >> r;

                res = mt[r].transpose();
                PrintMatrix(res, string("(Mat") + char('0' + r) + string(")^T"));

                break;
            case 'I':
                fin >> r;

                res = mt[r].inverse();
                PrintMatrix(res, string("(Mat") + char('0' + r) + string(")^-1"));

                break;
            case 'D':
                fin >> r;

                fout << "det(Mat" << char('0' + r) << ")=" << setprecision(3) << mt[r].det() << endl;
                fout << endl;

                break;
            case 'S':
                fin >> r >> c;
                b.clear();

                double d;

                for (int i = 0; i < c; ++i) {
                    fin >> d;
                    b.push_back(d);
                }

                mt[r].solve(b, bparam, fparams);

                fout << "Solving Mat" << char('0' + r) << "*X=";
                PrintVector(b);
                fout << ":" << endl;

                if (bparam.size() == 0 && fparams.size() == 0)
                    fout << "   No solution!" << endl;
                else {
                    fout << "   Basic param: ";
                    PrintVector(bparam);
                    fout << endl;

                    fout << "   Free params: ";

                    for (int i = 0; i < fparams.size(); ++i) {
                        fout << endl << "      ";
                        PrintVector(fparams[i]);
                    }

                    if (fparams.size() == 0)
                        fout << "None";

                    fout << endl << endl;
                }

                break;
            case 'E':
                fin >> r >> dd;
                fparams = mt[r].eigenspace(dd);

                if (fparams.size() == 0)
                    fout << "For Mat[" << r << "], no eigenspace at " << setprecision(3)
                        << dd << " because " << dd << " is not an eigenvalue" << endl << endl;
                else {
                    fout << "Basis of eigenspace of Mat[" << r << "] corresponding to eigenvalue "
                        << setprecision(3) << dd << ":";

                    for (int i = 0; i < fparams.size(); ++i) {
                        fout << endl << "     ";
                        PrintVector(fparams[i]);
                    }

                    fout << endl << endl;
                }

                break;
            case 'B':
                fin >> r >> bs;

                switch (bs) {
                    case 'N':
                    case 'n':
                        fparams = mt[r].nullspace();
                        info = "Null";
                        break;
                    case 'R':
                    case 'r':
                        fparams = mt[r].rowspace();
                        info = "Row";
                        break;
                    case 'C':
                    case 'c':
                        fparams = mt[r].colspace();
                        info = "Column";
                        break;
                }

                fout << "Basis of " << info << " space of Mat[" << r << "] is: ";

                for (int i = 0; i < fparams.size(); ++i) {
                    fout << endl << "     ";
                    PrintVector(fparams[i]);
                }

                fout << endl << endl;

                break;
        }
    }
	
	fin.close();
	fout.close();
	
	return 0;
}

