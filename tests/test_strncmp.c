/*
** EPITECH PROJECT, 2023
** B-ASM-400-BDX-4-1-asmminilibc-adrien.ricou
** File description:
** test_strlen
*/

#include <criterion/criterion.h>
#include <string.h>
#include <dlfcn.h>
#include <stdio.h>
#include <signal.h>

Test(strncmp, first_str_greater)
{
    int result = 0;
    char *error;
    int (*strncmp)(char const *s1, char const *s2, int n);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    strncmp = dlsym(handle, "strncmp");
    result = strncmp("World", "Hello", 3);
    cr_assert_eq(result, 15);
    dlclose(handle);
}

Test(strncmp, second_str_greater)
{
    int result = 0;
    char *error;
    int (*strncmp)(char const *s1, char const *s2, int n);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    strncmp = dlsym(handle, "strncmp");
    result = strncmp("Hello", "World", 3);
    cr_assert_eq(result, -15);
    dlclose(handle);
}

Test(strncmp, string_equals)
{
    int result = 0;
    char *error;
    int (*strncmp)(char const *s1, char const *s2, int n);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    strncmp = dlsym(handle, "strncmp");
    result = strncmp("World", "World", 4);
    cr_assert_eq(result, 0);
    dlclose(handle);
}

Test(strncmp, both_string_null)
{
    int result = 0;
    int (*strncmp)(char const *s1, char const *s2, int n);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    strncmp = dlsym(handle, "strncmp");
    result = strncmp(NULL, NULL, 3);
    cr_assert_eq(result, 0);
    dlclose(handle);
}
