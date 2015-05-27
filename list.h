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
 
#ifndef LIST_H
#define LIST_H

/****************************************************************************
 * list_node* list = NULL;
 * list_insert(&list, list_create_node("Thiago"));
 * list_insert(&list, list_create_node("Cida"));
 * list_insert(&list, list_create_node("Arthur"));
 * list_insert(&list, list_create_node("Vitor"));
 * 
 * list_print(list);
 * 
 * list_node* removed = list_remove_at(&list, 1);
 * list_destroy(&removed);
 * 
 * list_print(list);
 * list_destroy(&list);
 *****************************************************************************/

typedef struct l_node {
  void* buffer;
  unsigned long size;
  struct l_node* prev;
  struct l_node* next;
} list;

list* list_create_node(void* buffer, int size);
void list_insert(list** head, list* newNode);
list* list_item_at(list* head, int index);
list* list_remove_at(list** head, int index);
void list_destroy(list** head);
void list_print(list* head);
int list_count(list* head);
int list_sort(list* head);

#endif