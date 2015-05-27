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
 
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list* list_create_node(void* buffer, int size)
{
  list* node = (list*)calloc(1, sizeof(list));
  if (node == NULL)
    return NULL;
  
  node->buffer = buffer;
  node->size = size;

  return node;
}

void list_insert(list** head, list* newNode)
{
  if ((*head)->buffer == NULL) //only head
  {
    //first insert?
    *head = newNode;
  }
  else
  {
    list* headAux = *head;
    while ((*head)->next != NULL)
      (*head) = (*head)->next;
    
    (*head)->next = newNode;
    newNode->prev = *head;
    *head = headAux;
  }
}

list* list_item_at(list* head, int index)
{
  list* node = NULL;
  int count = 0;
  while (head != NULL)
  {
    if (index == count)
    {
      node = head;
      break;
    }

    head = head->next;
    count++;
  }

  return node;
}

list* list_remove_at(list** head, int index)
{
  list* node = list_item_at(*head, index);

  //clone the struct node into removed, removed needs to be freed elsewhere
  list* removed = list_create_node(node->buffer, node->size);
  *removed = *node; 
  removed->next = NULL;
  removed->prev = NULL;

  node->prev->next = node->next;
  node->next->prev = node->prev;

  //free node
  free(node);

  return removed;
}

void list_destroy(list** head)
{
  list* node = NULL;

  while (*head != NULL)
  {
    node = *head;
    (*head) = (*head)->next;
    
    free(node);
  }
}

void list_print(list* head)
{
  int i = 0;
  char* token = (char*)calloc(8, sizeof(char));
  strcpy(token, "<HEAD> ");
  while (head != NULL)
  {
    if (i++ > 0) memset(token, 0, 8);
    printf("%u is:\t%s\t%s\n", head, head->buffer, token);
    head = head->next;
  }
  printf("\n");
  free(token);
}

int list_count(list* head)
{
  int count = 0;
  while (head != NULL)
  {
    head = head->next;
    count++;
  }

  return count;
}