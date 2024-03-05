#include <iostream>

#ifndef __handler_h_
#define __handler_h_

#include "slau.h"

namespace handler{
    /* Обрабочик чтения СЛАУ из файла */
    void file( void );

    /* Обрабочик чтения СЛАУ из консолb */
    void console( void );

    /* Обрабочик случайного заполнения СЛАУ */
    void random( void );
}

#endif//__handler_h_
