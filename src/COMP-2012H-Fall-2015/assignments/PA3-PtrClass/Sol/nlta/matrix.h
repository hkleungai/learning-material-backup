#include <vector>

#ifndef MATRIX_H
#define MATRIX_H



using namespace std;


/**
 * @class Matrix
 * @brief This class represents and support calculation of Matrix
 */
class Matrix {
    public:
        /**
		 * @brief Create a zero matrix
		 * @param rows Number of row of matrix, must be positive number
		 * @param cols Number of col of matrix, must be positive number
		 * @remark if rows <= 0 or cols <= 0, a zero-sized matrix will be created
		 */
		explicit Matrix (int rows = 0, int cols = 0);

        ///Copy constructor
		Matrix(const Matrix& mt);

        ///Destructor
		~Matrix();



		/****************************************************************************
		 * Region Public Member Functions
		 ****************************************************************************/

        ///@brief Return number of row of matrix
		int rows() const;

		///@brief Return number of column of matrix
        int cols() const;

		/**
		 * @brief Get access (read/write) to element at specific position
		 * @param i The row of element
		 * @param j The column of element
		 * @return A reference variable to the element (i, j)
		 */
        double& el(int i, int j) const;


		/**
		 * @brief Assign a matrix to the current matrix
		 * @param op The matrix we want to assign
		 */
		void assign(const Matrix& op);

		/**
		 * @brief Multiply the current matrix with another matrix
		 * @param op The matrix we want to multiple with
         * @return	If the sizes of two matrices are valid, the multiplication result is returned
					Otherwise, a zero matrix of size (0, 0) is returned
		 */
        Matrix mul(const Matrix& op) const;

        ///@brief The return the transpose of the current Matrix
		Matrix transpose() const;

        /**
		 * @brief Return the inverse of the current matrix
		 * @return 	If the matrix is invertible, the resulting matrix is returned
		 * 			Otherwise, a zero matrix of size (0, 0) is returned
		 */
		Matrix inverse() const;

        /**
		 * @brief Return the determinant of the current matrix
		 * @return 	If the matrix is square and not zero-sized, the determinant is returned
		 * 			Otherwise, NaN value is returned
		 */
        double det() const;

		/**
		 * @brief Solve the equation Ax = b, with A is the current matrix
		 * @remarks	The solution will be represented in the form:
		 *				x = x0 + p1*h1 + p2*h2 + ... + pn*hn
		 *				x0, h1, h2, ..., hn are vectors
		 *				p1, p2, ..., pn are coefficient (any real number)
		 * @param b Vector b on the right-handed side of the equation
		 * @param bparam 	Result vector x0 in the solution
		 *					If there is no solution, bparam will be empty
		 * @param fparam	Collection of result vector h1, h2, ..., hn in the solution
		 * 					If there is no solution, fparam will be empty
		 */
		void solve(const vector<double>& b, vector<double>& bparam, vector< vector<double> >& fparam) const;

		/**
		 * @brief Find the eigenspace of the current matrix corresponding to eigenvalue v
		 * @remarks The eigenspace will be represented in the form:
		 *              x = p1*h1 + p2*h2 + ... + pn*hn
		 *              h1, h2, ..., hn are basis of the eigenspace
		 *              p1, p2, ..., pn are coefficient (any real number, but can't be
         *                  simultaneously zero)
		 * @param v The eigenvalue that we want to find corresponding eigenspace
		 * @return  A collection of basis h1, h2, ..., hn of the eigenspace, if the matrix
         *          is square and v is truly an eigenvalue
         *          Otherwise, an empty collection
		 */
		vector< vector<double> > eigenspace(double v) const;

        ///@brief Return the basis of the Null space of the current matrix
		vector< vector<double> > nullspace() const;

		///@brief Return the basis of the row space of the current matrix
		vector< vector<double> > rowspace() const;

		///@brief Return the basis of the column space of the current matrix
		vector< vector<double> > colspace() const;

		/****************************************************************************
		 * EndRegion Public Member Functions
		 ****************************************************************************/



		/**
		 * Assignment operator
		 * @remark 	Because there is pointer class members, we need to implement deep copy (content-copy)
					of these pointers
		 */
		Matrix& operator = (const Matrix& source);



    private:
		/**
		 * A dynamic 2D array that represents the elements of the matrix
		 * elm[i] = Array of row i of matrix
		 * elm[i][j] = Element (i, j) (row i, column j) of matrix
		 */
        double **elm;

		///Number of rows of matrix
        int r;

		///Number of columns of matrix
        int c;

		/*************************************************************
		 * Region Helper functions
		 *************************************************************/

		/**
		 * @brief Allocate a new all-zero, 2D array for the matrix and assign it to variable elm
		 * @param rows The number of rows of new matrix
		 * @param cols The number of columns of new matrix
		 */
		void allocate(int rows, int cols);

		/**
		 * @brief Clean up the content of pointer elm
		 */
		void clean();

        /**
		 * @brief Perform Row Reduce Algorithm on the current matrix
		 * @param submat	Pointer to the matrix which will also be transformed exactly according
							to the transformation applied to the main matrix
		 * @param detchange Pointer to a real number variable which is the multiplication difference_type
							between the determinant of the result matrix and the ones of the original matrix
								i.e. det(RREF(M)) = det(M) * detchange
							This variable is not applicable when matrix is not square and is zero-sized
		 * @return Pointer to a dynamic 2D array which is the Row-Reduce Echelon Form of the original matrix
		 */
		double** rowreduce(Matrix* submat, double *detchange) const;

		/*************************************************************
		 * EndRegion Helper functions
		 *************************************************************/
};



#endif
