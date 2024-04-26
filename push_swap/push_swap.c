/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:47:14 by tlima-de          #+#    #+#             */
/*   Updated: 2024/04/26 21:42:37 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *top;
} t_stack;

// Função para criar uma nova pilha
t_stack *create_stack() {
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack) return NULL;
    stack->top = NULL;
    return stack;
}

// Função para empurrar um elemento para o topo da pilha
void push(t_stack *stack, int value) {
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node) return;
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
}

// Função para retirar o elemento do topo da pilha
int pop(t_stack *stack) {
    if (stack->top == NULL) return -1; // Retorna -1 se a pilha estiver vazia
    t_node *top_node = stack->top;
    int value = top_node->value;
    stack->top = top_node->next;
    free(top_node);
    return value;
}

// Função para trocar os dois primeiros elementos da pilha
void swap(t_stack *stack) {
    if (stack->top == NULL || stack->top->next == NULL) return;
    t_node *first = stack->top;
    t_node *second = first->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
}

// Função para rotacionar todos os elementos da pilha para cima
void rotate(t_stack *stack) {
    if (stack->top == NULL || stack->top->next == NULL) return;
    t_node *first = stack->top;
    t_node *last = stack->top;
    while (last->next != NULL) {
        last = last->next;
    }
    stack->top = first->next;
    first->next = NULL;
    last->next = first;
}

// Função para rotacionar todos os elementos da pilha para baixo
void reverse_rotate(t_stack *stack) {
    if (stack->top == NULL || stack->top->next == NULL) return;
    t_node *last = stack->top;
    t_node *second_last = NULL;
    while (last->next != NULL) {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = stack->top;
    stack->top = last;
}
// Funções para operações compostas
void ss(t_stack *stack_a, t_stack *stack_b) {
    swap(stack_a);
    swap(stack_b);
}

void rr(t_stack *stack_a, t_stack *stack_b) {
    rotate(stack_a);
    rotate(stack_b);
}

void rrr(t_stack *stack_a, t_stack *stack_b) {
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
}
// Função para encontrar o menor elemento na pilha
int find_min(t_stack *stack) {
    t_node *current = stack->top;
    int min = current->value;
    while (current != NULL) {
        if (current->value < min) {
            min = current->value;
        }
        current = current->next;
    }
    return min;
}

// Função para posicionar o menor elemento no topo da pilha A usando a pilha B
void push_min_to_top(t_stack *stack_a, t_stack *stack_b) {
    int min = find_min(stack_a);
    while (stack_a->top->value != min) {
        if (stack_a->top->next->value == min) {
            swap(stack_a);
        } else {
            push(stack_b, pop(stack_a));
        }
    }
}

// Função para ordenar a pilha A usando a pilha B
void push_swap_sort(t_stack *stack_a, t_stack *stack_b) {
    // Mover todos os elementos para B, com o maior no topo de B
    while (!is_sorted(stack_a)) {
        push_min_to_top(stack_a, stack_b);
        push(stack_b, pop(stack_a));
    }

    // Devolver todos os elementos para A
    while (stack_b->top != NULL) {
        push(stack_a, pop(stack_b));
    }

    // Finalmente, inverter A para obter a ordenação correta
    t_stack *temp = create_stack();
    while (stack_a->top != NULL) {
        push(temp, pop(stack_a));
    }
    while (temp->top != NULL) {
        push(stack_a, pop(temp));
    }
    free(temp);
}


// Função auxiliar para verificar se a pilha está ordenada
int is_sorted(t_stack *stack) {
    if (stack->top == NULL) return 1; // Uma pilha vazia é considerada ordenada
    t_node *current = stack->top;
    while (current->next != NULL) {
        if (current->value > current->next->value) {
            return 0; // Não está ordenada
        }
        current = current->next;
    }
    return 1; // Está ordenada
}

int main() {
    // Criar as pilhas A e B
    t_stack *stack_a = create_stack();
    t_stack *stack_b = create_stack();

    // Adicionar elementos à pilha A (valores desordenados)
    push(stack_a, 3);
    push(stack_a, 1);
    push(stack_a, 4);
    push(stack_a, 1);
    push(stack_a, 5);
    push(stack_a, 9);
    push(stack_a, 2);
    push(stack_a, 6);
    push(stack_a, 5);
    push(stack_a, 3);
    push(stack_a, 5);

    // Exibir pilha A antes da ordenação
    printf("Pilha A antes da ordenação:\n");
    t_node *current = stack_a->top;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");

    // Ordenar a pilha A usando a pilha B
    push_swap_sort(stack_a, stack_b);

    // Exibir pilha A depois da ordenação
    printf("Pilha A depois da ordenação:\n");
    current = stack_a->top;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");

    // Liberar memória das pilhas
    while (stack_a->top != NULL) {
        pop(stack_a);
    }
    free(stack_a);

    while (stack_b->top != NULL) {
        pop(stack_b);
    }
    free(stack_b);

    return 0;
}
