#include <iostream>

#include "slau.h"

/* Конструктор результата вычислений */
sla::result::result( unsigned iteration, mth::vec vector, mth::vec infelicity ) : iteration(iteration), vector(vector), infelicity(infelicity), is_succes(true)
{
}

/* Конструктор результата вычислений по умолчанию */
sla::result::result( void ) : iteration(), vector(), infelicity(0), is_succes(false)
{
}

unsigned sla::result::get_iteration( void )
{   
    return iteration;
}

mth::vec sla::result::get_vector( void )
{
    return vector;
}

mth::vec sla::result::get_infelicity( void )
{
    return infelicity;
}

bool sla::result::succes()
{
    return is_succes;
}

void sla::result::print_result( void )
{
    std::cout << "Iteration: " << iteration << std::endl;
    std::cout << "X:" << std::endl;
    vector.print_vector();
    std::cout << "Infelicity:" << std::endl;
    infelicity.print_vector();
}

void sla::result::operator()( unsigned i, mth::vec v, mth::vec esps )
{
    iteration = i;
    vector = v;
    infelicity = esps;
    is_succes = true;
    print_result();
}
