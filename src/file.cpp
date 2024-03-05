#include <fstream>

#include "handler.h"

/* Обрабочик чтения СЛАУ из файла */
void handler::file( void )
{
    unsigned n;
    double eps;
    std::string filename;
    std::ifstream in;

    std::cout << "Input file name: ";
    std::cin >> filename;
    in.open(filename);
    if (!in.is_open())
    {
        std::cout << "Can not open" << std::endl;
        in.close();
        return;
    }

    in >> n;
    if (n <= 0 || n > 20)
    {
        in.close();
        std::cout << "Invalid size of SLAU in file";
        return;
    }

    in >> eps;
    if (eps <= 0)
    {
        in.close();
        std::cout << "Invalid epsylon in file";
        return;
    }
    
    double matrix[mth::MAX_SIZE][mth::MAX_SIZE];
    double vector[mth::MAX_SIZE];

    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = 0; j < n; j++)
            in >> matrix[i][j];
        in >> vector[i];
    }

    in.close();
    sla::slau s = sla::slau(mth::matr(n, matrix), mth::vec(n, vector), eps);
    s.solution();
}
