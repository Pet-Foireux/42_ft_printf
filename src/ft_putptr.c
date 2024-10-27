/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:42:48 by mpapin            #+#    #+#             */
/*   Updated: 2024/09/17 14:42:48 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int    ft_print_pointer(unsigned long long addr, int fd)
{
    char    buffer[17];
    char    *hex;
    int        i;

    hex = "0123456789abcdef";
    if (addr == 0)
    {
        if (fd == 1)
            ft_putstr_fd("(nil)", 1);
        return (5);
    }
    i = 16;
    buffer[i] = '\0';
    i--;
    while (addr > 0)
    {
        buffer[i] = hex[addr % 16];
        addr = addr / 16;
        i--;
    }
    if (fd == 0)
        return (17 - i);
    ft_putstr_fd("0x", 1);
    return (ft_putstr_fd(&buffer[i + 1], 1) + 2);
}