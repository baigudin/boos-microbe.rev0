/** 
 * Functions to manipulate memory.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.util.memory.h"

/** 
 * Copies a block of memory.
 *
 * @param dst pointer to the destination array where the content is to be copied, 
 *            type-casted to a pointer of type void*.
 * @param src pointer to the source of data to be copied, type-casted to a pointer of type const void*.
 * @param len number of bytes to copy.
 * @return destination is returned.
 */
void* memoryCopy(void* dst, const void* src, size_t len)
{
  register cell* sp  = (cell*)src;
  register cell* dp  = (cell*)dst;
  while(len--) *dp++ = *sp++;
  return dst;
}

/** 
 * Fills a block of memory.
 *
 * @param dst pointer to the destination block of memory to fill.
 * @param val value to be set. The value is passed as an int, but the function fills 
 *            the block of memory using the unsigned char conversion of this value.
 * @param len Number of bytes to be set to the value.
 * @return destination is returned.
 */
void* memorySet(void* dst, cell val, size_t len)
{
  register cell* dp = (cell*)dst;
  register const cell uc = val;
  while(len--) *dp++ = uc;
  return dst;
}

/** 
 * Gets a string length.
 *
 * @param str pointer to C-string.
 * @return the length of string.
 */
size_t memoryStrlen(const char* str)
{
  register size_t len = 0;
  while(*str++) len++;
  return len;
}

/** 
 * Copies a string.
 *
 * @param dst pointer to the destination array where the content is to be copied.
 * @param src C-string to be copied.     
 * @return destination is returned.     
 */
char* memoryStrcpy(char* dst, const char* src)
{
  register char* d = dst - 1;     
  register const char* s = src  - 1;     
  while( (*++d = *++s) != 0 );
  return dst;
}

/** 
 * Concatenates strings.
 *
 * @param dst pointer to the destination array, which should contain a C string, 
 *            and be large enough to contain the concatenated resulting string.
 * @param src C-string to be appended. This should not overlap destination.
 * @return destination is returned.     
 */
char* memoryStrcat(char* dst, const char* src)
{
  register char* d = dst - 1;
  register const char* s = src - 1;
  while( *++d );
  d--;
  while( (*++d = *++s) != 0 );
  return dst;
}

/** 
 * Compares two strings.
 *
 * @param str1 C-string to be compared.
 * @param str2 C-string to be compared.
 * @return a value indicating the relationship between the strings.
 */
int32 memoryStrcmp(const char* str1, const char* str2)
{
  register int32 c1, res;
  while(1)
  {
    c1 = *str1++;
    res = c1 - *str2++;
    if(c1 == 0 || res != 0) break;
  }
  return res;
}