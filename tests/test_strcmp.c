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

Test(strcmp, first_str_greater)
{
    int result = 0;
    char *error;
    int (*strcmp)(char const *s1, char const *s2);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    strcmp = dlsym(handle, "strcmp");
    result = strcmp("ABC", "AB");
    cr_assert_eq(result, 67);
    dlclose(handle);
}

Test(strcmp, first_str_greater2)
{
    int result = 0;
    char *error;
    int (*strcmp)(char const *s1, char const *s2);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    strcmp = dlsym(handle, "strcmp");
    result = strcmp("ABC", "AB");
    cr_assert_eq(result, 67);
    dlclose(handle);
}

Test(strcmp, second_str_greater)
{
    int result = 0;
    char *error;
    int (*strcmp)(char const *s1, char const *s2);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    strcmp = dlsym(handle, "strcmp");
    result = strcmp("ABA", "ABZ");
    cr_assert_eq(result, -25);
    dlclose(handle);
}

Test(strcmp, string_equals)
{
    int result = 0;
    char *error;
    int (*strcmp)(char const *s1, char const *s2);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    strcmp = dlsym(handle, "strcmp");
    result = strcmp("123", "123");
    cr_assert_eq(result, 0);
    dlclose(handle);
}

Test(strcmp, both_string_null)
{
    int result = 0;
    int (*strcmp)(char const *s1, char const *s2);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    strcmp = dlsym(handle, "strcmp");
    result = strcmp(NULL, NULL);
    cr_assert_eq(result, 0);
    dlclose(handle);
}
