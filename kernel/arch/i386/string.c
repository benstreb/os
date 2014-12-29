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

void *memcpy(void *restrict dest, const void *restrict src, size_t n)
{
    return memmove(dest, src, n);
}

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
