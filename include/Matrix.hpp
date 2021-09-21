#include <ostream>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Matrix{
    private:
        std::vector<T> _matrix;
        int _rows,_columns;
    public:
        Matrix(int,int);
        ~Matrix(){};
        Matrix& operator+(const Matrix&);
        Matrix& operator*(const Matrix&);


        //getters
        int get_size(){ return _rows*_columns; };
        int get_rows(){ return _columns; };
        int get_columns(){ return _columns; };
        std::vector<T> get_matrix() {return _matrix;};


};

template<typename T>
Matrix<T>::Matrix(int n, int m): _rows(n), _columns(n)
{
    _matrix.resize(n*m);
}


template<typename T>
Matrix<T>& Matrix<T>::operator+(const Matrix<T>& m)
{
    Matrix<T> sum;
    sum.resize(_rows*_columns);
    for(int i=0; i<_rows; i++)
    {
        for(int j=0; j<_columns; j++)
        {
            sum[i+_columns*j] = this-> get_matrix[i+_columns*j] + m[i+_columns*j];
        }
    }
    return sum;
} 

template<typename T>
Matrix<T>& Matrix<T>::operator*(const Matrix<T>& m)
{
    Matrix<T> product;
    if(this->get_columns() == m.get_rows())
    {
        product.resize(_rows*_columns);
        for(int i=0; i<_rows; i++)
        {
            for(int j=0; j<_columns; j++)
            {
                int k=0;
                while(k< m.get_rows())
                {
                    product[i+_columns*j] += this-> get_matrix[i+_columns*k] + m[k+_columns*j];
                }
                
            }
        }
    }else{
        std::cout<<"Matrices are not compatible"<<std::endl;
        std::exit(0);
    }



    return product;
} 


