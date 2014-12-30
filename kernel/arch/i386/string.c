#include <stddef.h>
#include <string.h>

int memcmp(const void *s1, const void *s2, size_t n)
{
    char *s1_blob = (char*) s1;
    char *s2_blob = (char*) s2;
    for (size_t i = 0; i < n; i++)
    {
        if (s1_blob[i] > s2_blob[i])
            return 1;
        else if (s1_blob[i] < s2_blob[i])
            return -1;
    }
    return 0;
}

//"", "", 0 == 0
//"a", "b", 0 == 0
//"a", "a", 1 == 0
//"a", "b", 1 == -1
//"b", "a", 1 == 1
//"aa", "ab", 2 == -1

void *memcpy(void *restrict dest, const void *restrict src, size_t n)
{
    return memmove(dest, src, n);
}

//zeroed array, "a", 0 == zeroed array
//zeroed array, "a", 1 == "a"
//zeroed array, "ab", 2 == "ab"

void *memmove(void *dest, const void *src, size_t n)
{
    char *src_blob = (char*) src;
    char *dest_blob = (char*) dest;
    if (src_blob > dest_blob)
    {
        for (size_t i = 0; i < n; i++)
        {
            dest_blob[i] = src_blob[i];
        }
    }
    else if (src_blob < dest_blob)
    {
        for (size_t i = 0; i < n; i++)
        {
            dest_blob[(n-1)-i] = src_blob[(n-1)-i];
        }
    }
    return dest;
}

//"abc", "bc", 2 == "bcc"
//"bc", "abc", 2 == "aab"
//"abc", "abc", 3 == "abc"

void *memset(void *s, int c, size_t n)
{
    char *src_blob = (char*) s;
    for (size_t i = 0; i < n; i++)
    {
        src_blob[i] = c;
    }
    return s;
}

//zeroed array, 'a', 0 == zeroed array
//zeroed array, 'a', 1 == 'a'
//zeroed array, 'a', 2 == 'aa'
