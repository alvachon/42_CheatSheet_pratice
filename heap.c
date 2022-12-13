/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:13:00 by alvachon          #+#    #+#             */
/*   Updated: 2022/12/12 21:55:54 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_struct
{
	int		i;
	float	pi;
	char	a;
}	t_struct
;

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node
;

void	malloc_int_value(void)
{
	int	*ptr_one;

	ptr_one = (int *)malloc(sizeof(int));
	if (ptr_one == 0)
		printf("ERROR: Out of memory\n");
	*ptr_one = 25;
	printf("Integer :%d\n", *ptr_one);
	free(ptr_one);
    printf("Integer is freed\n\n");
}

void	malloc_t_struct(void)
{
	t_struct	*ptr_one;

	ptr_one = (t_struct *)malloc(sizeof(t_struct));
	if (ptr_one == 0)
		printf("ERROR: Out of memory\n");
	(*ptr_one).i = 10;
	(*ptr_one).pi = 3.14;
	(*ptr_one).a = 'a';
	printf("First value: %d\n", (*ptr_one).i);
	printf("Second value: %f\n", (*ptr_one).pi);
	printf("Third value: %c\n", (*ptr_one).a);
	free(ptr_one);
	printf("Struct is freed\n\n");
}

void	malloc_struct_s_struct(void)
{
	struct s_struct	*ptr_one;

	ptr_one = (struct s_struct *)malloc(sizeof(struct s_struct));
	if (ptr_one == 0)
		printf("ERROR: Out of memory\n");
	ptr_one->i = 10;
	ptr_one->pi = 3.14;
	ptr_one->a = 'a';
	printf("First value: %d\n", ptr_one->i);
	printf("Second value: %f\n", ptr_one->pi);
	printf("Third value: %c\n", ptr_one->a);
	free(ptr_one);
    printf("Struct is freed\n\n");
}

t_node	*make_list(void)
{
	t_node	*head;
	t_node	*midl;
	t_node	*tail;

	head = NULL;
	midl = NULL;
	tail = NULL;

	head = (t_node *)malloc(sizeof(t_node));
	if (head == 0)
		printf("ERROR: Out of memory\n");
	midl = (t_node *)malloc(sizeof(t_node));
	if (midl == 0)
		printf("ERROR: Out of memory\n");
	tail = (t_node *)malloc(sizeof(t_node));
	if (tail == 0)
		printf("ERROR: Out of memory\n");
	head->data = 1;
	head->next = midl;
	midl->data = 2;
	midl->next = tail;
	tail->data = 3;
	tail->next = NULL;
	return (head);
}

void	print_list(t_node *head)
{
    t_node	*current;

	current = head;
    while (current != NULL)
	{
        printf("The current element is %d\n", current->data);
        current = current->next;
    }
}

void	free_list(t_node *head)
{
    t_node *current;
    while (head != NULL)
	{
        current = head;
        head = head->next;
        free(current);
        printf("\nElement in linked list freed\n");
    }
}

void	malloc_linked_list(void)
{
	t_node	*head;

	head = make_list();
	print_list(head);
	free_list(head);
}

void	malloc_array(void)
{
	char	**a;
	int		i;

	i = 0;
	a = (char **)malloc(sizeof(char *) * 10);
	if (a == 0)
		printf("ERROR: Out of memory\n");
	while (i < 10)
	{
		a[i] = (char *)malloc(sizeof(char) * (i + 1));
		if (a[i] == 0)
			printf("ERROR: Out of memory\n");
		i++;
	}
	i = 0;
	while (i < 10)
	{
		free(a[i]);
		printf("char array freed\n");
		i++;
	}
	free(a);
	printf("array freed\n");
}

int	main(void)
{
	malloc_int_value();
	malloc_t_struct();
	malloc_struct_s_struct();
	malloc_linked_list();
	malloc_array();
	return (0);
}
