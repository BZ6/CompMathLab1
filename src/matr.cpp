#include <cstdlib>
#include <iostream>

#include "mth.h"

/* Конструктор с размером матрицы */
mth::matr::matr( unsigned number ) : size(number) 
{
    null_matrix();
}

/* Конструктор по умолчанию */
mth::matr::matr( void ) : matr(3)
{
}

/* Конструктор по матрице */
mth::matr::matr( matr& m ) : matr(m.size)
{
    for (unsigned i = 0; i < this->size; i++)
        for (unsigned j = 0; j < this->size; j++)
            this->matrix[i][j] = m.matrix[i][j];
}

/* Конструктор с размером матрицы и данными */
mth::matr::matr( unsigned number, double m[MAX_SIZE][MAX_SIZE] ) : matr(number)
{
    for (unsigned i = 0; i < this->size; i++)
        for (unsigned j = 0; j < this->size; j++)
            this->matrix[i][j] = m[i][j];
}

/* Конструктор с размером матрицы и данными вводимыми из стандартного потока ввода консоли */
mth::matr::matr( unsigned number, bool flag ) : matr(number) 
{
    for (unsigned i = 0; i < this->size; i++)
        for (unsigned j = 0; j < this->size; j++)
            std::cin >> this->matrix[i][j];
}

/* Конструктор с размером матрицы и данными вводимыми из стандартного потока ввода файла */
mth::matr::matr( unsigned number, std::ifstream in ) : matr(number) 
{
    for (unsigned i = 0; i < this->size; i++)
        for (unsigned j = 0; j < this->size; j++)
            in >> this->matrix[i][j];
}

/* Обнуление матрицы */
void mth::matr::null_matrix( void )
{
    for (unsigned i = 0; i < this->size; i++)
        for (unsigned j = 0; j < this->size; j++)
            this->matrix[i][j] = 0;
}

/* Вывод матрицы на экран */
void mth::matr::print_matrix( void )
{
    for (unsigned i = 0; i < this->size; i++)
    {
        for (unsigned j = 0; j < this->size; j++)
            std::cout << this->matrix[i][j] << "	";
        std::cout << std::endl;
    }
}

/* Перестановка строк матрицы */
void mth::matr::swap( unsigned i, unsigned j )
{
    double tmp;

    for (unsigned k = 0; k < this->size; k++)
    {
        tmp = this->matrix[i][k];
        this->matrix[i][k] = this->matrix[j][k];
        this->matrix[j][k] = tmp;
    }
}

unsigned mth::matr::get_size( void )
{
    return size;
}

/* Определитель данной матрицы */
double mth::matr::determinant( void )
{
    //return matr_determNxN(matrix, size);
    return matr_determNxNG(matrix, size);
}

/* Вывод определителя матрицы на экран */
void mth::matr::print_determinant( void )
{
    std::cout << determinant() << std::endl;
}

/* Проверка на доминирование диагонали матрицы */
bool mth::matr::is_diagonal( void )
{
    unsigned i, j, k = 1;
    double sum = 0;

    for (i = 0; i < size; i++)
    {
        sum = 0;
        for (j = 0; j < size;j++)
            sum += abs(matrix[i][j]);

        sum -= abs(matrix[i][i]);
        if (sum >= abs(matrix[i][i]))
            k = 0;
    }

    return (k == 1);
}

/* Вывод результата проверки на доминирование диагонали матрицы на экран */
void mth::matr::print_is_diagonal( void )
{
    if (is_diagonal())
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
}

mth::vec& mth::matr::operator[]( unsigned i)
{
    return vec(size, matrix[i]);
}

void mth::matr::init_random( void )
{
    for (unsigned i = 0; i < this->size; i++)
        for (unsigned j = 0; j < this->size; j++)
            this->matrix[i][j] = rand();
}
