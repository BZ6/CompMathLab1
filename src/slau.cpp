#include <iostream>

#include "slau.h"

/* Конструктор СЛАУ */
sla::slau::slau( mth::matr matrix, mth::vec vector, double eps ) : matrix(matrix), vector(vector), eps(eps), is_empty(false)
{
}

// TODO доделать!!!!!
/* Конструктор СЛАУ внутри через потоки ввода */
sla::slau::slau( unsigned number, double eps, bool is_file ) : matrix(number, is_file), vector(number, is_file), eps(eps), is_empty(false)
{
}

/* Конструктор СЛАУ рандомный */
sla::slau::slau( unsigned number, double eps ) : matrix(number), vector(number), eps(eps), is_empty(false) 
{
    this->init_random();
}

/* Конструктор СЛАУ по количеству строк */
sla::slau::slau( unsigned number ) : matrix(number), vector(number), is_empty(true)
{
}

/* Вывод СЛАУ на экран */
void sla::slau::print_slau( void )
{
    for (unsigned i = 0; i < matrix.get_size(); i++)
    {
        for (unsigned j = 0; j < matrix.get_size(); j++)
            std::cout << matrix[i][j] << "	";
        std::cout << vector[i] << std::endl;
    }
}

/* Перестановка строк СЛАУ */
void sla::slau::swap( unsigned i, unsigned j )
{
    matrix.swap(i, j);
    vector.swap(i, j);
}

/* Решатор СЛАУ (можно выбрать: method_of_simple_iteration) */
sla::result sla::slau::solution( std::string name_of_method )
{
    if (name_of_method == "method_of_simple_iteration")
        return solution_methods::method_of_simple_iteration(*this);
    else
        return result();
}


mth::matr sla::slau::get_matrix( void )
{
    return matrix;
}

mth::vec sla::slau::get_vector( void )
{
    return vector;
}

double sla::slau::getEps( void )
{
    return eps;
}

bool sla::slau::empty( void )
{
    return is_empty;
}

void sla::slau::init_random( void )
{
    matrix.init_random();
    vector.init_random();
}

void sla::slau::solution( void )
{
    /*Вывод СЛАУ*/
	std::cout << "SLAU:" << std::endl;
    print_slau();

    // Тут пока что только один метод, поэтому без выбора
    /*Выполнение метода простых итераций*/
    std::cout << "Execute method of simple iteration for SLAU:" << std::endl;
    sla::result res = sla::solution_methods::method_of_simple_iteration(*this);
    if (res.succes())
    {
        /*Результат выполнения метода простых итераций*/
        std::cout << "result values after method of simple iteration for SLAU:" << std::endl;
        res.print_result();
    }
}
