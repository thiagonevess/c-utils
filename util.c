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
#include <stdlib.h>
#include <string.h>

#include "util.h"

int Bin2Dec(const char* bin)
{
  return (int) strtol(bin, NULL, 2);
}

int Hex2Dec(const char* hex)
{
  return (int) strtol(hex, NULL, 16);
}

char* Bin2Hex(char* bin)
{
  char* ret = (char*)malloc(1024);
  char buffer[5];
  
  memset(ret, 0, 1024);
  memset(buffer, 0, 5);

  int size = strlen(bin);
  int offset = 0;
  char* init = ret;
  for (int i = 0; i < size; i += 4)
  {
    memcpy(buffer, &bin[i], 4);
    char h = hexString[Bin2Dec(buffer)];
    *ret = h;
    ret++;
  }
  ret = init;

  return ret;
}

char* Hex2Bin(char* hex)
{
  char* ret = (char*)malloc(1024);
  char buffer[5];
  
  memset(ret, 0, 1024);
  memset(buffer, 0, 5);

  int size = strlen(hex);
  char* init = ret;
  int iOff = 0;
  for (int i = 0; i < size; i++)
  {
    memcpy(buffer, &hex[i], 1);
    memcpy(&ret[iOff], binArray[Hex2Dec(buffer)], 4);
    iOff += 4;
  }

  ret = init;

  return ret;
}