#include "handler.h"

/* Обрабочик случайного заполнения СЛАУ */
void handler::random( void )
{
    unsigned n;
    double eps;
    bool is_running;

    is_running = true;
    while (is_running)
    {
        std::cout << "Input integer size [1;20]: ";
        std::cin >> n;
        if (n > 0 && n <= 20)
            is_running = false;
        else
            std::cout << "Invalid size of SLAU" << std::endl;
    }

    is_running = true;
    while (is_running)
    {
        std::cout << "Input epsylon number greater then 0: ";
        std::cin >> eps;
        if (eps > 0)
            is_running = false;
        else
            std::cout << "Invalid epsylon" << std::endl;
    }
    
    sla::slau s = sla::slau(n, eps);
    s.solution();
}
