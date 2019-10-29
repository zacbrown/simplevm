/*******************************************************************************
 * filename    : stack.c
 * author      : Zac Brown <zac@zacbrown.org>
 * date        : 11.17.2009
 * description : stack implementation
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "include/stack.h"

int simplevm_stack_init(simplevm_stack_p stack)
{
    CHECK_NULL(stack,
        "ERROR(simplevm_stack_init:%d): null stack pointer\n",
        __LINE__, -1);

    stack_element_p elem = (stack_element_p) malloc(sizeof(stack_element_t));
    elem->type = 0x00000;
    elem->next = NULL;
    elem->previous = NULL;
    stack->base = stack->top = elem;
    stack->size = 0;

    return 0;
}

stack_element_p simplevm_stack_peek(simplevm_stack_p stack)
{
    CHECK_NULL(stack,
        "ERROR(simplevm_stack_peek:%d): null stack pointer\n",
        __LINE__, NULL);

    return stack->top;
}

stack_element_p simplevm_stack_pop(simplevm_stack_p stack)
{
    CHECK_NULL(stack,
        "ERROR(simplevm_stack_pop:%d): null stack pointer\n",
        __LINE__, NULL);

    if (stack->size > 0)
    {
        stack_element_p ret_elem = stack->top;
        stack->top = ret_elem->next;
        stack->size--;
        return ret_elem;
    }

    return NULL;
}

int simplevm_stack_push(simplevm_stack_p stack, stack_element_p elem)
{
    CHECK_NULL(stack,
        "ERROR(simplevm_stack_push:%d): null stack pointer\n",
        __LINE__, -1);

    CHECK_NULL(elem,
        "ERROR(simplevm_stack_push:%d): null stack element pointer\n",
        __LINE__, -2);

    stack->top->previous = elem;
    elem->next = stack->top;
    elem->previous = NULL;
    stack->top = elem;
    stack->size++;

    return 0;
}

long simplevm_stack_size(simplevm_stack_p stack)
{
    CHECK_NULL(stack,
        "ERROR(simplevm_stack_size:%d): null stack element pointer\n",
        __LINE__, -1);
    return stack->size;
}
