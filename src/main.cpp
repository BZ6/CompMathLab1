#include <iostream>
#include <string>

#include "handler.h"

// const int n = 20;
// const double e = 0.01;

int main( void )
{
    // double m[mth::MAX_SIZE][mth::MAX_SIZE] = { 
    //     {2, 2, 10},
    //     {10, 1, 1},
    //     {2, 10, 1},
    // };
    // double v[mth::MAX_SIZE] = { 14, 12, 13 };
	// mth::matr a = mth::matr(n, m);
    // mth::vec b = mth::vec(n, v);
    // sla::slau s = sla::slau(a, b, e);
    
    //sla::slau s = sla::slau(n, e);
	
    /*Вывод начальных значений*/
	// std::cout << "Matrix a:" << std::endl;
    // a.print_matrix();
	// std::cout << "Vector b:" << std::endl;
	// b.print_vector();
	/*Вывод матрицы с переставленными строками*/
    // a.swap(0, 1);
    // a.swap(1, 2);
    // std::cout << "Matrix a" << std::endl;
    // a.print_matrix();
    /*Вывод определителя матрицы*/
	// std::cout << "Determinant a:" << std::endl;
    // a.print_determinant();
    // /*Вывод результата проверки на доминирование диагонали матрицы*/
	// std::cout << "Matrix a is diagonal:" << std::endl;
    // a.print_is_diagonal();

    /*Вывод СЛАУ*/
	// std::cout << "SLAU:" << std::endl;
    // s.print_slau();

    /*Вывод СЛАУ с переставленными строками*/
    // std::cout << "SLAU s:" << std::endl;
    // s.swap(0, 1);
    // s.swap(2, 1);
    // s.print_slau();

    /*Вывод после привидения СЛАУ к доминированию диагонали*/
	// std::cout << "SLAU s:" << std::endl;
    // permuter(s, 0);
    // std::cout << "SLAU s:" << std::endl;
    // s.print_slau();

    /*Выполнение метода простых итераций*/
    // std::cout << "Execute method of simple iteration for SLAU:" << std::endl;
    // sla::result res = sla::solution_methods::method_of_simple_iteration(s);

    // if (res.succes())
    // {
    //     /*Результат выполнения метода простых итераций*/
    //     std::cout << "result values after method of simple iteration for SLAU:" << std::endl;
    //     res.print_result();
    // }
    
    bool is_running = true;
    std::string message;

    while (is_running)
    {
        std::cout << "What do you want?" << std::endl << "file[0]/console[1]/random[2]/exit[3]" << std::endl;
        std::cin >> message;

        if (message == "0")
            handler::file();
        else if (message == "1")
            handler::console();
        else if (message == "2")
            handler::random();
        else if (message == "3")
        {
            is_running = false;
            std::cout << "Goodbye";
        }
        else
            std::cout << "Input only [0]/[1]/[2]/[3]!!!" << std::endl;
    }

    return 0;
}
