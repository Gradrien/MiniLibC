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

Test(strlen, null_string, .signal = SIGSEGV)
{
    char *error;
    int (*strlen)(char const *str);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    strlen = dlsym(handle, "strlen");
    strlen(NULL);
    dlclose(handle);
}

Test(strlen, empty_string)
{
    int result = 0;
    char *error;
    int (*strlen)(char const *str);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    strlen = dlsym(handle, "strlen");
    result = strlen("");
    cr_assert_eq(result, 0);
    dlclose(handle);
}

Test(strlen, string)
{
    int result = 0;
    char *error;
    int (*strlen)(char const *str);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    strlen = dlsym(handle, "strlen");
    result = strlen("Hello World!");
    cr_assert_eq(result, 12);
    dlclose(handle);
}