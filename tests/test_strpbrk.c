/*
** EPITECH PROJECT, 2023
** B-ASM-400-BDX-4-1-asmminilibc-adrien.ricou
** File description:
** test_strpbrk
*/

#include <criterion/criterion.h>
#include <string.h>
#include <dlfcn.h>
#include <stdio.h>

Test(strpbrk, first_string_null)
{
    char *result = NULL;
    char *error;
    char *(*strpbrk)(char const *s, char const *accept);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        return;
    dlerror();
    strpbrk = dlsym(handle, "strpbrk");
    result = strpbrk("", "needle");
    cr_assert_eq(result, NULL);
    dlclose(handle);
}

Test(strpbrk, second_string_null)
{
    char *result = NULL;
    char *error;
    char *(*strpbrk)(char const *s, char const *accept);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        return;
    dlerror();
    strpbrk = dlsym(handle, "strpbrk");
    result = strpbrk("haystack", "");
    cr_assert_eq(result, NULL);
    dlclose(handle);
}

Test(strpbrk, no_match)
{
    char *result = NULL;
    char *error;
    char *(*strpbrk)(char const *s, char const *accept);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        return;
    dlerror();
    strpbrk = dlsym(handle, "strpbrk");
    result = strpbrk("haystack", "needle");
    cr_assert_eq(result, NULL);
    dlclose(handle);
}

Test(strpbrk, match_found)
{
    char *result_sys = NULL;
    char *result = NULL;
    char *error;
    char *(*my_strpbrk)(char const *s, char const *accept);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        return;
    dlerror();
    my_strpbrk = dlsym(handle, "strpbrk");
    result = my_strpbrk("haystack", "y");
    result_sys = strpbrk("haystack", "y");
    cr_assert_eq(result, result_sys);
    dlclose(handle);
}