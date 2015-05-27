/*
 * This file is copyright 2015 Thiago Neves <thiago.nsantos@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THIAGO NEVES BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef STACK_H
#define STACK_H

/****************************************************************************
 * stack_node* stack = NULL;
 * stack_push(&stack, stack_create_node("Thiago"));
 * stack_push(&stack, stack_create_node("Cida"));
 * stack_push(&stack, stack_create_node("Arthur"));
 * 
 * stack_print(stack);
 * 
 * stack_node* removed = stack_pop(&stack);
 * stack_destroy(&removed);

 * stack_push(&stack, stack_create_node("Vitor"));
 * stack_print(stack);
 * stack_destroy(&stack);
 ****************************************************************************/

typedef struct s_node {
  char* buffer;
  struct s_node* next;
} stack_node;

stack_node* stack_create_node(char* buffer);
void stack_push(stack_node** head, stack_node* newNode);
stack_node* stack_pop(stack_node** head);

void stack_destroy(stack_node** head);
void stack_print(stack_node* head);

#endif