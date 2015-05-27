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

#ifndef QUEUE_H
#define QUEUE_H

/****************************************************************************
 * Example usage:
 * queue_node* queue = NULL;
 * queue_insert(&queue, queue_create_node("Thiago"));
 * queue_insert(&queue, queue_create_node("Cida"));
 * queue_insert(&queue, queue_create_node("Arthur"));
 * 
 * queue_node* removed = queue_remove(&queue);
 * queue_destroy(&removed);
 * 
 * queue_insert(&queue, queue_create_node("Vitor"));
 * queue_print(queue);
 * queue_destroy(&queue);
 ****************************************************************************/

typedef struct q_node {
  char* buffer;
  struct q_node* next;
} queue_node;

queue_node* queue_create_node(char* buffer);
void queue_insert(queue_node** head, queue_node* newNode);
queue_node* queue_remove(queue_node** head);
void queue_destroy(queue_node** head);
void queue_print(queue_node* head);

#endif