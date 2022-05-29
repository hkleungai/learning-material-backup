/**
 * This file contains implementation of the class Matrix
 */

#include <vector>
#include <cstring>
#include <cstddef>
#include <cmath>
#include <cstdlib>

#include "matrix.h"



///The precision used in comparison of 2 real numbers
const double EPS = 1e-7;



/************************************************************
 * Region Constructor & Destructor
 ************************************************************/
Matrix::Matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        rows = 0;
        cols = 0;
    }

    allocate(rows, cols);
}



Matrix::Matrix(const Matrix& mt) {
    allocate(mt.r, mt.c);

    for (int i = 0; i < r; ++i) {
        memcpy(elm[i], mt.elm[i], c * sizeof(double));
    }
}



Matrix::~Matrix() {
    clean();
}
/************************************************************
 * EndRegion Constructor & Destructor
 ************************************************************/



/**************************************************************
 * Region Public Member Functions
 **************************************************************/

int Matrix::rows() const {
    return r;
}



int Matrix::cols() const {
    return c;
}



double& Matrix::el(int i, int j) const {
    return elm[i][j];
}



void Matrix::assign(const Matrix& op) {
    if (r != op.r || c != op.c) {
        clean();
        allocate(op.r, op.c);
    }

    for (int i = 0; i < r; ++i) {
        memcpy(elm[i], op.elm[i], c * sizeof(double));
    }
}



Matrix Matrix::mul(const Matrix& op) const {
    if (c != op.r) {
        return Matrix(0, 0);
    }

    Matrix res(r, op.c);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < op.c; ++j) {
            res.el(i, j) = 0;

            for (int k = 0; k < c; ++k) {
                res.el(i, j) += elm[i][k] * op.el(k, j);
            }
        }

    return res;
}



Matrix Matrix::transpose() const {
    Matrix res(c, r);

    for (int i = 0; i < c; ++i)
        for (int j = 0; j < r; ++j) {
            res.el(i, j) = elm[j][i];
        }

    return res;
}



Matrix Matrix::inverse() const {
    if (r == 0 || c == 0 || r != c) {
        return Matrix(0, 0);
    }

    Matrix res(r, r);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < r; ++j) {
            res.elm[i][j] = (i == j ? 1 : 0);
        }

    double **tmp = rowreduce(&res, NULL);

    bool isIdentity = true;

    for (int i = 0; i < r && isIdentity; ++i)
        for (int j = 0; j < r && isIdentity; ++j)
            if (i == j && abs(tmp[i][j] - 1) >= EPS) {    //This is DOUBLE, so use EPS to deduce != operator
                isIdentity = false;
            } else if (i != j && abs(tmp[i][j] - 0) >= EPS) {
                isIdentity = false;
            }

    if (!isIdentity) {
        return Matrix(0, 0);
    } else {
        return res;
    }
}



double Matrix::det() const {
    if (r == 0 || c == 0 || r != c) {
        return NAN;
    }

    double det = 1;
    double **res = rowreduce(NULL, &det);

    for (int i = 0; i < r; ++i) {
        det *= res[i][i];
    }

    return det;
}



void Matrix::solve(const vector<double>& b, vector<double>& bparam, vector< vector<double> >& fparam) const {
    bparam.clear();
    fparam.clear();

    if (r == 0 || c == 0 || b.size() != r) {
        return;
    }

    Matrix mb(r, 1);

    for (int i = 0; i < r; ++i) {
        mb.elm[i][0] = b[i];
    }

    double **rref = rowreduce(&mb, NULL);
    int j, k;

    //Check no solution case
    for (int i = r - 1; i >= 0; --i) {
        j = 0;
        while (j < c && abs(rref[i][j] - 0) < EPS) {
            ++j;
        }

        //Last column of matrix [A|b] is NOT pivot column => No solution
        if (j == c && abs(mb.elm[i][0] - 0) >= EPS) {
            return;
        }
    }

    //Prepare necessary memory needed to store results: basic parameter (bvar) and free paramters (fvar)
    bparam = vector<double>(c, 0);

    //This matrix stores all possible free parameter vectors, some of them can be zero (will be eliminated later);
    Matrix mf(c, c);

    for (int i = 0; i < c; ++i) {
        memset(mf.elm[i], 0, c * sizeof(double));
    }

    int stopRow;

    for (int i = 0; i < r; ++i) {
        j = 0;
        while (j < c && abs(rref[i][j] - 0) < EPS) {
            ++j;
        }

        if (j == c) {
            stopRow = i;
            break;
        }

        k = j;

        bparam[k] = mb.elm[i][0];

        for (j = k + 1; j < c; ++j)
            if (abs(rref[i][j] - 0) >= EPS) {
                mf.elm[j][k] = -rref[i][j];
                mf.elm[j][j] = 1;
            }
    }

    //This is the case that all variable are free variables, so the solution space is R^c
    if (stopRow == 0) {
        for (int i = 0; i < c; ++i) {
            mf.elm[i][i] = 1;
        }
    }

    bool found;

    for (int i = 0; i < c; ++i) {
        found = false;

        for (j = 0; j < c; ++j)
            if (abs(mf.elm[i][j] - 0) >= EPS) {
                found = true;
                break;
            }

        if (found) {
            fparam.push_back(vector<double>(mf.elm[i], mf.elm[i] + c));
        }
    }
}



vector< vector<double> > Matrix::eigenspace(double v) const {
    if (r == 0 || c == 0 || r != c) {
        return vector< vector<double> >();
    }

    Matrix mt(*this);

    for (int i = 0; i < c; ++i) {
        mt.el(i, i) -= v;
    }

    vector<double> bparam;
    vector< vector<double> > fparams;
    vector<double> ZERO(c, 0);

    mt.solve(ZERO, bparam, fparams);

    return fparams;
}



vector< vector<double> > Matrix::nullspace() const {
    if (r == 0 || c == 0) {
        return vector< vector<double> >();
    }

    vector<double> bparam;
    vector< vector<double> > fparams;
    vector<double> ZERO(r, 0);

    solve(ZERO, bparam, fparams);

    if (fparams.size() == 0) {  //The Null space is zero-space
        fparams.push_back(bparam); //bparams in this case must be vector zero
    }

    return fparams;
}



vector< vector<double> > Matrix::rowspace() const {
    if (r == 0 || c == 0) {
        return vector< vector<double> >();
    }

    double** mat = rowreduce(NULL, NULL);

    vector< vector<double> > res;
    bool isZeroRow;

    for (int i = 0; i < r; ++i) {
        isZeroRow = true;

        for (int j = 0; j < c; ++j) {
            if (abs(mat[i][j] - 0) > EPS) {
                isZeroRow = false;
                break;
            }
        }

        if (isZeroRow) {
            break;
        } else {
            res.push_back(vector<double>(mat[i], mat[i] + c));
        }
    }

    if (res.size() == 0) {
        res.push_back(vector<double>(c, 0));
    }

    return res;
}



vector< vector<double> > Matrix::colspace() const {
    if (r == 0 || c == 0) {
        return vector< vector<double> >();
    }

    double** mat = rowreduce(NULL, NULL);
    vector< vector<double> > res;
    vector<double> b(r, 0);

    int k = 0;
    for (int i = 0; i < r; ++i) {
        while (k < c && abs(mat[i][k] - 1) > EPS) {
            ++k;
        }

        if (k == c) {
            break;
        }

        for (int j = 0; j < r; ++j) {
            b[j] = elm[j][k];
        }

        res.push_back(b);
    }

    if (res.size() == 0) {
        res.push_back(vector<double>(c, 0));
    }

    return res;
}

/**************************************************************
 * EndRegion Public Member Functions
 **************************************************************/



/*************************************************************
 * Region Operators
 *************************************************************/

///Assignment Operator
Matrix& Matrix::operator=(const Matrix& source) {
    //VERY IMPORTANT: Check for self assignment
    if (this == &source) {
        return *this;
    }

    assign(source);

    return *this;
}

/*************************************************************
 * EndRegion Operators
 *************************************************************/



/*************************************************************
 * Region Helper functions
 *************************************************************/

void Matrix::allocate(int rows, int cols) {
    r = rows;
    c = cols;

    elm = new double*[r];

    for (int i = 0; i < r; ++i) {
        elm[i] = new double[c];
    }
}



void Matrix::clean() {
    for (int i = 0; i < r; ++i) {
        delete [] elm[i];
    }

    delete [] elm;
}



double** Matrix::rowreduce(Matrix* submat, double *detchange) const {
    double **res = new double*[r];

    for (int i = 0; i < r; ++i) {
        res[i] = new double[c];
        memcpy(res[i], elm[i], c * sizeof(double));
    }

    bool found;
    int curRow = 0;
    double *tmp;
    double factor;

    //Phase 1: Forward Elimination -> Row Echelon Form
    for (int j = 0; j < c; ++j) {
        found = false;

        for (int i = curRow; i < r; ++i)
            if (abs(res[i][j] - 0) >= EPS) {    //This is DOUBLE type, so use EPS to deduce for != operator
                found = true;

                //Do not swap if currently at curRow
                if (i == curRow) {
                    break;
                }

                tmp = res[i];
                res[i] = res[curRow];
                res[curRow] = tmp;

                //Also do Row Interchange on submat, if provided

                if (submat != NULL) {
                    tmp = submat->elm[i];
                    submat->elm[i] = submat->elm[curRow];
                    submat->elm[curRow] = tmp;
                }

                ////Update detchange, if provided
                if (detchange != NULL) {
                    (*detchange) *= -1;
                }

                break;
            }

        if (!found)
            continue;

        for (int i = curRow + 1; i < r; ++i)
            if (abs(res[i][j] - 0) >= EPS) {
                factor = res[i][j] / -res[curRow][j];

                for (int k = c - 1; k >= j; --k) {
                    res[i][k] += (res[curRow][k] * factor);
                }

                //Also do Row Replacement on submat, if provided
                //No change in detchange
                if (submat != NULL) {
                    for (int k = submat->c - 1; k >= 0; --k) {
                        submat->elm[i][k] += (submat->elm[curRow][k] * factor);
                    }
                }
            }

        ++curRow;
    }

    //Phase 2: Backward Elimination -> Reduced Row Echelon Form
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (abs(res[i][j] - 0) >= EPS) {
                factor = res[i][j];

                for (int k = c - 1; k >= j; --k) {
                    res[i][k] /= factor;
                }

                //Also do Row Scaling on submat, if provided
                if (submat != NULL) {
                    for (int k = submat->c - 1; k >= 0; --k) {
                        submat->elm[i][k] /= factor;
                    }
                }

                //Update detchange, it provided
                if (detchange != NULL) {
                    (*detchange) *= factor;
                }

                break;
            }

    for (int i = r - 1; i > 0; --i) {
        int j = 0;
        while (j < c && abs(res[i][j] - 0) < EPS) {     //This is DOUBLE type, so use EPS to deduce for == operator
            ++j;
        }

        if (j == c) {
            continue;
        }

        for (int k = i - 1; k >= 0; --k) {
            factor = -res[k][j];

            for (int t = c - 1; t >= j; --t) {
                res[k][t] += (res[i][t] * factor);
            }

            //Also do Row Replacement on submat, if provided
            //No change in detchange
            if (submat != NULL) {
                for (int t = submat->c - 1; t >= 0; --t) {
                    submat->elm[k][t] += (submat->elm[i][t] * factor);
                }
            }
        }
    }

    return res;
}

/*************************************************************
 * EndRegion Helper functions
 *************************************************************/
