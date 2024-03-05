#include <string>

#ifndef __slau_h_
#define __slau_h_

#include "mth.h"

namespace sla {
    class result;
    class slau;

    namespace solution_methods {
        /* Метод простой итерации */
        result method_of_simple_iteration(slau s);
    }
    

    class result {
    private:
        unsigned iteration;
        mth::vec 
            vector,
            infelicity;
        bool is_succes;
        
    public:
        /* Конструктор результата вычислений */
        result( unsigned iteration, mth::vec vector, mth::vec infelicity );

        /* Конструктор результата вычислений по умолчанию */
        result( void );

        unsigned get_iteration( void );
        mth::vec get_vector( void );
        mth::vec get_infelicity( void );
        bool succes();
        void print_result( void );
        
        void operator()( unsigned i, mth::vec v, mth::vec esps );
    };

    class slau {
    private:
        mth::matr matrix;
        mth::vec vector;
        double eps;
        bool is_empty;

    public:
        /* Конструктор СЛАУ */
        slau( mth::matr matrix, mth::vec vector, double eps );

        /* Конструктор СЛАУ внутри через потоки ввода */
        slau( unsigned number, double eps, bool is_file );

        /* Конструктор СЛАУ рандомный */
        slau( unsigned number, double eps );

        /* Конструктор СЛАУ по умолчанию */
        slau( unsigned number );

        /* Вывод СЛАУ на экран */
        void print_slau( void );

        /* Перестановка строк СЛАУ */
        void swap( unsigned i, unsigned j );

        /* Решатор СЛАУ (можно выбрать: method_of_simple_iteration) */
        result solution( std::string name_of_method );

        mth::matr get_matrix( void );
        mth::vec get_vector( void );
        double getEps( void );
        bool empty( void );

        void init_random( void );

        void solution( void );
    }; 
}

#endif//__slau_h_
