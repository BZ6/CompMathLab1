#include <fstream>

#ifndef __mth_h_
#define __mth_h_

namespace mth {
    const unsigned MAX_SIZE = 20;

    class vec;
    class matr;

    static double abs( double number );

    class matr {
    private:
        double matrix[MAX_SIZE][MAX_SIZE];
        unsigned size;

    public:
        /* Конструктор с размером матрицы */
        matr( unsigned number );

        /* Конструктор по умолчанию */
        matr( void );

        /* Конструктор по матрице */
        matr( matr& m );

        /* Конструктор с размером матрицы и данными */
        matr( unsigned number, double m[MAX_SIZE][MAX_SIZE] );

        /* Конструктор с размером матрицы и данными вводимыми из стандартного потока ввода консоли */
        matr( unsigned number, bool flag );

        /* Конструктор с размером матрицы и данными вводимыми из стандартного потока ввода файла */
        matr( unsigned number, std::ifstream in );

        /* Обнуление матрицы */
        void null_matrix( void );

        /* Вывод матрицы на экран */
        void print_matrix( void );

        /* Перестановка строк матрицы */
        void swap( unsigned i, unsigned j );

        unsigned get_size( void );

        vec& operator[]( unsigned i );

    private:
        /* Определитель матрицы 3x3 */
        static double matr_determ3x3( double A11, double A12, double A13,
                                    double A21, double A22, double A23,
                                    double A31, double A32, double A33 )
        {
            return A11 * A22 * A33 - A11 * A23 * A32 - A12 * A21 * A33 + 
                    A12 * A23 * A31 + A13 * A21 * A32 - A13 * A22 * A31;
        }

        /* Определитель матрицы 2x2 */
        static double matr_determ2x2( double A11, double A12,
                                    double A21, double A22 )
        {
            return A11 * A22 - A12 * A21;
        }

        /* Определитель матрицы NxN */
        static double matr_determNxN( double M[MAX_SIZE][MAX_SIZE], unsigned N )
        {
            unsigned c;
            double det = 0, s = 1;
            double b[MAX_SIZE][MAX_SIZE];
            unsigned i, j;
            unsigned m, n;

            if (N == 1) return M[0][0];
            if (N == 2) return matr_determ2x2(M[0][0], M[0][1],
                                            M[1][0], M[1][1]);
            if (N == 2) return matr_determ3x3(M[0][0], M[0][1], M[0][2],
                                            M[1][0], M[1][1], M[1][2],
                                            M[2][0], M[2][1], M[2][2]);

            det = 0;
            for (c = 0; c < N; c++)
            {
                m = 0;
                n = 0;
                for (i = 0; i < N; i++)
                    for(j = 0; j < N; j++)
                    {
                        b[i][j] = 0;
                        if (i != 0 && j != c)
                        {
                            b[m][n] = M[i][j];
                            if (n < N-2)
                                n++;
                            else
                            {
                                n = 0;
                                m++;
                            }
                        }
                    }
                det = det + s * (M[0][c] * matr_determNxN(b,N-1));
                s = (-1) * s;
            }

            return (det);
        }

        /* Определитель матрицы NxN методом Гаусса */
        static double matr_determNxNG( double M[MAX_SIZE][MAX_SIZE], unsigned N )
        {
            unsigned i, j, k, x, y, max_row, max_col;
            double kf, Det = 1;

            for (i = 0; i < N; i++)
            {
                /* Look for maximum matrix element */
                max_row = max_col = i;
                for (y = i; y < N; y++)    
                    for (x = i; x < N; x++)
                        if (abs(M[y][x]) > abs(M[max_row][max_col]))
                            max_col = x, max_row = y;
                /* Look for zero on diagonale of matrix */
                if (M[max_row][max_col] == 0)
                {
                    Det = 0;
                    break;
                }
                /* Swap rows */
                if (max_row != i)
                {
                    for (x = i; x < N; x++)
                    {
                        double tmp = M[i][x];

                        M[i][x] = M[max_row][x];
                        M[max_row][x] = tmp;
                    }
                    Det = -Det;
                }
                /* Swap Columns */
                if (max_col != i)
                {
                    for (y = 0; y < N; y++)
                    {
                        double tmp = M[y][i];

                        M[y][i] = M[y][max_col];
                        M[y][max_col] = tmp;
                    }
                    Det = -Det;
                }
                /* Subtrack from every row i row multiplied by A[j][i] / A[i][i] */
                for (j = i + 1; j < N; j++)    
                {
                    kf = M[j][i] / M[i][i];
                    M[j][i] = 0;
                    for (k = i + 1; k < N; k++)
                        M[j][k] -= M[i][k] * kf;
                }
                Det *= M[i][i];   
            }

            return Det;
        }

    public:
        /* Проверка на доминирование диагонали матрицы */
        bool is_diagonal( void );

        /* Вывод результата проверки на доминирование диагонали матрицы на экран */
        void print_is_diagonal( void );

        /* Определитель данной матрицы */
        double determinant( void );

        /* Вывод определителя матрицы на экран */
        void print_determinant( void );

        void init_random( void );
    };

    class vec {
    private:
        double vector[MAX_SIZE];
        unsigned size;

    public:
        /* Конструктор с размером вектора */
        vec( unsigned number );

        /* Конструктор по умолчанию */
        vec( void );

        /* Конструктор по вектору */
        vec( vec& v );

        /* Конструктор с размером вектора и данными */
        vec( unsigned number, double v[MAX_SIZE] );

        /* Конструктор с размером вектора и данными вводимыми из стандартного потока ввода консоли */
        vec( unsigned number, bool flag );

        /* Конструктор с размером вектора и данными вводимыми из стандартного потока ввода файла */
        vec( unsigned number, std::ifstream in );

        /*Обнуление вектора*/
        void null_vector( void );

        /*Вывод вектора на экран*/
        void print_vector( void );

        /* Перестановка компонент вектора */
        void swap( unsigned i, unsigned j );

        unsigned get_size( void );
        
        double& operator[]( unsigned i );

        void init_random( void );
    };

        /* Модуль числа */
    static double abs( double number ) 
    {
        if (number < 0) 
            number = -number;

        return number;
    }
}

#endif//__mth_h_
