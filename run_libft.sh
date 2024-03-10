#!/bin/bash
rm test_printf.out
make -C ft_printf
cc -Wall -Werror -Wextra -o test_printf.out test_printf.c -L./ft_printf/libft -lft -L./ft_printf -lftprintf
make fclean -C ft_printf
./test_printf.out
