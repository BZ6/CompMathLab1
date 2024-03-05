#include <cstdlib>
#include <iostream>

#include "mth.h"

/* Конструктор с размером Вектора */
mth::vec::vec( unsigned number ) : size(number) 
{
    null_vector();
}

/* Конструктор по умолчанию */
mth::vec::vec( void ) : vec(3) 
{
}

/* Конструктор по вектору */
mth::vec::vec( vec& v ) : vec(v.size)
{
    for (unsigned j = 0; j < size; j++)
		this->vector[j] = v.vector[j];
}

/* Конструктор с размером вектора и данными */
mth::vec::vec( unsigned number, double v[MAX_SIZE] ) : vec(number)
{
    for (unsigned j = 0; j < size; j++)
		vector[j] = v[j];
}

/* Конструктор с размером вектора и данными вводимыми из стандартного потока ввода консоли */
mth::vec::vec( unsigned number, bool flag ) : vec(number) 
{
    for (unsigned j = 0; j < size; j++)
        std::cin >> vector[j];
}

/* Конструктор с размером вектора и данными вводимыми из стандартного потока ввода файла */
mth::vec::vec( unsigned number, std::ifstream in ) : vec(number)
{
    for (unsigned j = 0; j < size; j++)
        in >> vector[j];
}

/*Обнуление вектора*/
void mth::vec::null_vector( void ) 
{
    for (unsigned j = 0; j < size; j++)
		vector[j] = 0;
}

/*Вывод вектора на экран*/
void mth::vec::print_vector( void ) 
{
    for (unsigned j = 0; j < size; j++)
		std::cout << vector[j] << "    ";
    std::cout << std::endl;
}

/* Перестановка компонент вектора */
void mth::vec::swap( unsigned i, unsigned j )
{
    double tmp;

    tmp = vector[i];
    vector[i] = vector[j];
    vector[j] = tmp;
}

unsigned mth::vec::get_size( void )
{
    return size;
}

double& mth::vec::operator[]( unsigned i )
{
    return vector[i];
}

void mth::vec::init_random( void )
{
    for (unsigned j = 0; j < size; j++)
		vector[j] = rand();
}
