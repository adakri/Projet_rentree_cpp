#include <ostream>
#include <iostream>
#include <string>
#include <vector>




#define debug std::cout<<"debug"<<std::endl;


template <typename T>
class Matrix{
    private:
        std::vector<T> _matrix;
        int _rows,_columns;
    public:
        Matrix(int,int);
        ~Matrix(){};
        void print_mat();
        void assign(int, T);
        Matrix& operator+=(const Matrix&);
        Matrix& operator*=(const Matrix&);


        //getters
        int get_size() const { return _rows*_columns; };
        int get_rows() const { return _columns; };
        int get_columns() const { return _columns; };
        std::vector<T> get_matrix() const {return _matrix;};


};

template<typename T>
Matrix<T>::Matrix(int n, int m): _rows(n), _columns(n)
{
    _matrix.resize(n*m);
}




template<typename T>
void Matrix<T>::print_mat()
{
    std::cout<<"Matrix of "<<this -> get_rows()<<"x"<<this -> get_columns()<<std::endl;;
    for(int i=0; i<this -> get_rows(); i++)
        {
            std::cout<<"[";
            for(int j=0; j<this -> get_rows(); j++)
            {
                std::cout<< this-> get_matrix()[j+this ->get_rows()*i];
            }
            std::cout<<"]"<<std::endl;
        }
}



template<typename T>
void Matrix<T>::assign(int index, T value)
{
    if(index >= this-> get_columns() * this-> get_rows() )
    {
        std::cout<<"This will cause a segmentation fault"<<std::endl;
        exit(0);
    }else{
        _matrix[index] = value;
        std::cout<<this->get_matrix()[index]<<std::endl;
    }
    debug
    this->print_mat();
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& m)
{
    //this -> print_mat();
    if(this-> get_columns() == m.get_rows())
    {
        //std::cout<<this-> get_matrix().size()<<m.get_matrix().size()<<std::endl;
        for(int i=0; i<m.get_rows(); i++)
        {
            for(int j=0; j<m.get_rows(); j++)
            {   
                //std::cout<<get_matrix()[j+m.get_rows()*i]<<m.get_matrix()[j+m.get_rows()*i]<<std::endl;
                _matrix[j+m.get_rows()*i] +=  + m.get_matrix()[j+m.get_rows()*i];
                //std::cout<<this-> get_matrix()[j+m.get_rows()*i]<<std::endl;
            }
        }
    }else{
        std::cout<<"Matrices are not compatible"<<std::endl;
        std::exit(0);
    }
    return *this;
} 

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& m)
{
    Matrix<T> product;
    if(this->get_columns() == m.get_rows())
    {
        product.resize(this-> get_columns() * this-> get_columns());
        for(int i=0; i<this-> get_columns(); i++)
        {
            for(int j=0; j<this-> get_columns(); j++)
            {
                int k=0;
                while(k< m.get_rows())
                {
                    product[i+_columns*j] += this-> get_matrix[i+_columns*k] + m[k+_columns*j];
                }

                _matrix[i+_columns*k] = product[i+_columns*j];
            }
        }
    }else{
        std::cout<<"Matrices are not compatible"<<std::endl;
        std::exit(0);
    }



    return *this;
} 


