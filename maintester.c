#include "./LibftXen/libft.h"

int     main()
{
    int     *pouet;
    int     i;

    i = 0;
    pouet = NULL;
    pouet = ft_memalloc((sizeof(int) * 8), 0);
    while (i < 8)
        ft_printf("|%d", pouet[i++]);
    return (0);
}