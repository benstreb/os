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

