#include <iostream>

#include "slau.h"

static sla::result calculate_result( sla::slau s );
static bool permuter( sla::slau& s );

/* Метод простой итерации */
sla::result sla::solution_methods::method_of_simple_iteration(slau s)
{
    result res = sla::result();

    if (s.get_matrix().determinant() == 0)
    {
        std::cout << "SLAU can not be calculated because determinant equal zero" << std::endl;
        return res;
    }

    if (s.get_matrix().is_diagonal())
    {
        res = calculate_result(s);    
        return res;
    }

    std::cout << "SLAU should be permuted" << std::endl;
    if (permuter(s))
    {
        s.print_slau();
        std::cout << "SLAU after permutation" << std::endl;
        res = calculate_result(s);
        
        return res;
    }

    std::cout << "SLAU can not be permuted and can not be calculated" << std::endl;
    return res;
}

static sla::result calculate_result(sla::slau s)
{
    double max_esp, sum, t;
    unsigned iter = 0, size = s.get_matrix().get_size();
    mth::vec x = mth::vec(size);
    sla::result res = sla::result();

    x.print_vector();
    do
    {
        mth::vec esps = mth::vec(size);

        max_esp = 0;
        for (unsigned i = 0; i < size; i++)
        {
            t = x[i];
            sum = 0;
            for (unsigned j = 0; j < size; j++)
                if (j != i)
                    sum += s.get_matrix()[i][j] * x[j];
            x[i] = (s.get_vector()[i] - sum) / s.get_matrix()[i][i];
            esps[i] = mth::abs(x[i] - t);
            if (esps[i] > max_esp)
                max_esp = esps[i];
        }
        iter++;
        res(iter, x, esps);
    } while (max_esp >= s.getEps());
    
    return res;
}

static bool permuter( sla::slau& s )
{
    unsigned n = s.get_matrix().get_size();
    bool is_swapped;

    for (unsigned i = 0; i < n; ++i) 
    {
        is_swapped = false;
        double sum = 0;
        for (unsigned j = 0; j < n; ++j) 
            if (i != j) 
                sum += mth::abs(s.get_matrix()[i][j]);

        if (mth::abs(s.get_matrix()[i][i]) < sum) 
        {
            for (unsigned k = i + 1; k < n; ++k) 
            {
                double k_sum = 0;
                for (unsigned j = 0; j < n; ++j) 
                    if (i != j) 
                        k_sum += mth::abs(s.get_matrix()[k][j]);

                if (mth::abs(s.get_matrix()[k][i]) > k_sum) 
                {
                    s.swap(i, k);
                    is_swapped = true;
                    break;
                }
            }

            if (!is_swapped)
                return false;
        }
    }

    return true;
}
