/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:30:39 by moatieh           #+#    #+#             */
/*   Updated: 2025/11/30 02:30:39 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    init_stack(&a);
    init_stack(&b);

    // Fill stack A
    fill_stack_a(&a, argc, argv);

    printf("=== Initial Stack A ===\n");
    print_stack(&a);
    printf("========================\n\n");

    // TEST pb
    printf("TEST: pb (push from A to B)\n");
    pb(&a, &b);
    pb(&a, &b);
    printf("A after pb:\n");
    print_stack(&a);
    printf("B after pb:\n");
    print_stack(&b);
    printf("------------------------\n\n");

    // TEST pa
    printf("TEST: pa (push from B to A)\n");
    pa(&a, &b);
    pa(&a, &b);
    printf("A after pa:\n");
    print_stack(&a);
    printf("B after pa:\n");
    print_stack(&b);
    printf("------------------------\n\n");

    // TEST sa
    printf("TEST: sa (swap A)\n");
    sa(&a);
    print_stack(&a);
    printf("------------------------\n\n");

    // TEST ss
    printf("TEST: ss (swap both)\n");
    ss(&a, &b);
    printf("A after ss:\n");
    print_stack(&a);
    printf("B after ss:\n");
    print_stack(&b);
    printf("------------------------\n\n");

    // TEST ra, rb, rr
    printf("TEST: ra\n");
    ra(&a);
    print_stack(&a);

    printf("TEST: rb\n");
    rb(&b);
    print_stack(&b);

    printf("TEST: rr\n");
    rr(&a, &b);
    printf("A after rr:\n");
    print_stack(&a);
    printf("B after rr:\n");
    print_stack(&b);
    printf("------------------------\n\n");

    // TEST rra, rrb, rrr
    printf("TEST: rra\n");
    rra(&a);
    print_stack(&a);

    printf("TEST: rrb\n");
    rrb(&b);
    print_stack(&b);

    printf("TEST: rrr (reverse rotate both)\n");
    rrr(&a, &b);
    printf("A after rrr:\n");
    print_stack(&a);
    printf("B after rrr:\n");
    print_stack(&b);

    // ✨ Free stacks to remove all leaks
    free_stack(&a);
    free_stack(&b);

    return 0;
}







