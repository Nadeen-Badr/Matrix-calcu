#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include<iostream>
using namespace std;
template<typename T>
        class Matrix{
        private:
            int rows;
            int cols;
            T** elem;
        public:
            //prototype for default constracturs!!
            Matrix(){
                rows=0;
                cols=0;
            }
            //prototype for parmtarazed constructurs!!
            Matrix(int row,int col);
            //prototype copy constructors!
            Matrix(const Matrix&mat);
            //prototype for destructor!1
            ~Matrix();
            //prototype for operators overloading!!
            Matrix operator+(const Matrix& mat);
            Matrix operator-(const Matrix& mat);
            Matrix operator*(const Matrix& mat);
            //prototype for transpose function!!
            void transMatrix();
            //input operator!!
            friend istream& operator>>(istream& input,Matrix<T> &mat){
                for (int n=0;n<mat.rows;n++){
                    for(int m=0;m<mat.cols;m++){
                        input>>mat.elem[n][m];
                    }
                }
                return input;
            }
            friend ostream& operator<<(ostream& output,const Matrix<T>& mat){
                for(int i=0;i<mat.rows;i++){
                    for(int j=0;j<mat.cols;j++){
                        output<<mat.elem[i][j]<<"\t";
                    }
                    output<<"\n";
                }
                return output;
            }
        };


template<typename T>
        //parametrized constructors!!
        Matrix<T>::Matrix(int row,int col){
            rows=row;
            cols=col;
            elem=new T*[rows];
            for(int m=0;m<rows;m++){
                elem[m]=new T [cols];
            }
        }
        template<typename T>
                //copy constructors!!
                Matrix<T>::Matrix(const Matrix& mat){
                    rows=mat.rows;
                    cols=mat.cols;
                    elem=new T*[rows];
                    for(int m=0;m<rows;m++){
                        elem[m]=new T [cols];
                    }
                    for(int i=0;i<rows;i++){
                        for(int j=0;j<cols;j++){
                            elem[i][j]=mat.elem[i][j];
                        }
                    }
                }

                //operator plus
                // overloading the operator +
                template <typename T>
                        Matrix<T> Matrix<T>::operator+ (const Matrix<T>& mat)
                        {
                            Matrix Res(rows, cols);
                            if (rows == mat.rows && cols == mat.cols)
                            {
                                for (int i = 0; i < rows; i++)
                                {
                                    for (int j = 0; j < cols; j++)
                                        Res.elem[i][j] = 0;
                                }


                                for (int i = 0; i < rows; i++)
                                {
                                    for (int j = 0; j < cols; j++)
                                        Res.elem[i][j] = elem[i][j] + mat.elem[i][j];
                                }



                            }
                            else
                            {
                                cout << "Invalid add matrix" << endl;
                                for (int i = 0; i < Res.rows; i++)
                                {
                                    for (int j = 0; j < Res.cols; j++)
                                        Res.elem[i][j] = NULL;
                                }
                            }

                            return Res;
                        }
                        //operator sub
                        // overloading the operator -
                        template <class T>
                                Matrix<T> Matrix<T>::operator-(const Matrix<T>& mat)
                                {
                                    Matrix Res(rows, cols);
                                    if (rows == mat.rows && cols == mat.cols)
                                    {
                                        for (int i = 0; i < rows; i++)
                                        {
                                            for (int j = 0; j < cols; j++)
                                                Res.elem[i][j] = elem[i][j] - mat.elem[i][j];
                                        }
                                    }
                                    else
                                    {
                                        cout << "Invalid subtraction matrix" << endl;
                                        for (int i = 0; i < Res.rows; i++)
                                        {
                                            for (int j = 0; j < Res.cols; j++)
                                                Res.elem[i][j] = 0;
                                        }
                                    }
                                    return Res;
                                }
                                // overloading the operator *
                                //operator to multiply
                                template <class T>
                                        Matrix<T> Matrix<T>::operator* (const Matrix<T>& mat){
                                            Matrix Res(rows, mat.cols);
                                            if (cols != mat.rows)
                                            {
                                                cout << "Invalid multiplication matrix \n";
                                                for (int i = 0; i < Res.rows; i++)
                                                {
                                                    for (int j = 0; j < Res.cols; j++)
                                                        Res.elem[i][j] = NULL;
                                                }
                                            }
                                            else
                                            {
                                                for (int i = 0; i < rows; i++)
                                                {
                                                    for (int j = 0; j < mat.cols; j++)
                                                    {
                                                        Res.elem[i][j] = 0;
                                                        for (int k = 0; k < cols; k++)
                                                            Res.elem[i][j] += elem[i][k] * mat.elem[k][j];
                                                    }
                                                }
                                            }
                                            return Res;
                                        }
                                        template <class T>

                                                void Matrix<T>:: transMatrix(){
                                                    for(int i=0;i<rows;i++){
                                                        for(int j=0;j<cols;j++){
                                                            cout<<elem[j][i]<<"\t";
                                                        }
                                                        cout<<"\n";
                                                    }}
                                                    //Destructor!1
                                                    template < typename T >
                                                            Matrix<T>::~Matrix(){
                                                                for(int i=0;i<rows;i++){
                                                                    delete[]elem[i];
                                                                }
                                                                delete[]elem;
                                                            }
                                        #endif //ASS_MATRIX_H