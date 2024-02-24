
#include "libft.h"
#include<stdio.h>

int main()
{
    int result = ft_atoi("123");

    if (result == 0) {
        printf("All tests passed!\n");
    } else {
        printf("Some tests failed.\n");
    }

    return result;
}

