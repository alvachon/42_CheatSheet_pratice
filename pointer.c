/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:50:58 by alvachon          #+#    #+#             */
/*   Updated: 2022/12/11 13:40:39 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;
	int	*ptr;

	a = 1;
	b = a;
	ptr = &a;
	printf("\nint a = %d;\n", a);
	printf("int b = a (%d);\n\n", b);
	printf("int *ptr;\n");
	printf("ptr = &a;\n\n");
	printf("ptr's value: %2d\nptr's address: %p\n", *ptr, ptr);
	a = 42;
	printf("\nint a = %d;\n", a);
	printf("a's value: %2d\na's address: %p\n\n", a, &a);
	printf("ptr's value: %2d\nptr's address: %p\n\n", *ptr, ptr);
	printf("b's value: %2d\nb's address: %p\n\n", b, &b);
	printf("a's address: %p\n", &a);
	printf("ptr's address: %p\n", ptr);
	printf("b's address: %p\n", &b);
	printf("\nSize of ptr in bytes: %zu\n", sizeof(ptr));
	return (0);
}
