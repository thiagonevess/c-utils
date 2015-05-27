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
#include <windows.h>

#include "queue.h"

queue_node* queue_create_node(char* buffer)
{
  queue_node* node = (queue_node*)malloc(sizeof(queue_node));
  node->buffer = (char*)malloc(sizeof(buffer));
  strcpy(node->buffer, buffer);
  node->next = NULL;

  return node;
}

void queue_insert(queue_node** head, queue_node* newNode)
{
  if (*head == NULL)
  {
    //first insert?
    *head = newNode;
  }
  else
  {
    queue_node* headAux = *head;
    while ((*head)->next != NULL)
      (*head) = (*head)->next;
    
    (*head)->next = newNode;
    *head = headAux;
  }
}

queue_node* queue_remove(queue_node** head)
{
  //clone the struct **head into *node, node needs to be freed elsewhere
  queue_node* node = queue_create_node((*head)->buffer);
  *node = **head; 
  node->next = NULL;

  //change head and free old head
  queue_node* oldHead = *head;
  (*head) = (*head)->next;
  free(oldHead);
  return node;
}

void queue_destroy(queue_node** head)
{
  queue_node* node = NULL;

  while (*head != NULL)
  {
    node = *head;
    (*head) = (*head)->next;
    
    free(node);
  }
}

void queue_print(queue_node* head)
{
  int i = 0;
  char* token = (char*)malloc(8);
  memset(token, 0, 8);
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