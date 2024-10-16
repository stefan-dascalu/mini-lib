// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
    char *dest = destination;

    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';

    return dest;
}


char *strncpy(char *destination, const char *source, size_t len)
{
    size_t i;

    for (i = 0; i < len && source[i] != '\0'; i++) {
        destination[i] = source[i];
    }

    for (; i < len; i++) {
        destination[i] = '\0';
    }

    return destination;
}


char *strcat(char *destination, const char *source)
{
    char *dest = destination;

    while (*dest != '\0') {
        dest++;
    }

    while (*source != '\0') {
        *dest = *source;
        dest++;
        source++;
    }

    *dest = '\0';

    return destination;
}


char *strncat(char *destination, const char *source, size_t len)
{
    char *dest = destination;
    size_t i;

    while (*dest != '\0') {
        dest++;
    }

    for (i = 0; i < len && source[i] != '\0'; ++i) {
        dest[i] = source[i];
    }

    dest[i] = '\0';

    return destination;
}


int strcmp(const char *str1, const char *str2)
{
    while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0') {
        str1++;
        str2++;
    }

    return *(unsigned char *)str1 - *(unsigned char *)str2;
}


int strncmp(const char *str1, const char *str2, size_t len)
{
    for (size_t i = 0; i < len; ++i) {
        if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0') {
            return ((unsigned char *)str1)[i] - ((unsigned char *)str2)[i];
        }
    }

    return 0;
}


size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
    while (*str != (char)c) {
        if (*str == '\0') {
            return NULL;
        }
        str++;
    }

    return (char *)str;
}

char *strrchr(const char *str, int c)
{
    char *last_occurrence = NULL;

    do {
        if (*str == (char)c) {
            last_occurrence = (char *)str;
        }
    } while (*str++ != '\0');

    return last_occurrence;
}


char *strstr(const char *haystack, const char *needle)
{
    if (!*needle)
        return (char *)haystack;

    for (; *haystack; ++haystack) {
        if (*haystack == *needle) {
            const char *h = haystack;
            const char *n = needle;

            for (; *h && *n && (*h == *n); ++h, ++n) {
                ;
            }

            if (!*n)
                return (char *)haystack;
        }
    }

    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
    if (!*needle)
        return (char *)haystack;

    char *last_occurrence = NULL;

    for (; *haystack; ++haystack) {
        if (*haystack == *needle) {
            const char *h = haystack;
            const char *n = needle;

            for (; *h && *n && (*h == *n); ++h, ++n) {
                ;
            }

            if (!*n)
                last_occurrence = (char *)haystack;
        }
    }

    return last_occurrence;
}

void *memcpy(void *destination, const void *source, size_t num)
{
    char *dest = (char*)destination;
    const char *src = (const char*)source;

    while (num--)
        *dest++ = *src++;

    return destination;
}


void *memmove(void *destination, const void *source, size_t num)
{
    char *dest = (char*)destination;
    const char *src = (const char*)source;

    if (dest > src && dest < src + num) {
        dest = dest + num - 1;
        src = src + num - 1;
        while (num--)
            *dest-- = *src--;
    } else {
        while (num--)
            *dest++ = *src++;
    }

    return destination;
}


int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    const unsigned char *u1 = (const unsigned char *)ptr1;
    const unsigned char *u2 = (const unsigned char *)ptr2;

    for (size_t i = 0; i < num; i++) {
        if (u1[i] != u2[i]) {
            return u1[i] - u2[i];
        }
    }

    return 0;
}

void *memset(void *source, int value, size_t num)
{
    unsigned char *src = (unsigned char *)source;

    for (size_t i = 0; i < num; i++) {
        src[i] = (unsigned char)value;
    }

    return source;
}

