#include "handler.h"

/* Обрабочик чтения СЛАУ из консоли */
void handler::console( void )
{
    unsigned n;
    double eps;
    bool is_running;

    is_running = true;
    while (is_running)
    {
        std::cout << "Input integer [1;20]: ";
        std::cin >> n;
        if (n > 0 && n <= 20)
            is_running = false;
        else
            std::cout << "Invalid size of SLAU";
    }

    is_running = true;
    while (is_running)
    {
        std::cout << "Input number greater then 0: ";
        std::cin >> eps;
        if (eps > 0)
            is_running = false;
        else
            std::cout << "Invalid epsylon";
    }

    double matrix[mth::MAX_SIZE][mth::MAX_SIZE];
    double vector[mth::MAX_SIZE];

    std::cout << "Input SLAU with compatible size:" << std::endl;
    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = 0; j < n; j++)
            std::cin >> matrix[i][j];
        std::cin >> vector[i];
    }

    sla::slau s = sla::slau(mth::matr(n, matrix), mth::vec(n, vector), eps);
    s.solution();
}
