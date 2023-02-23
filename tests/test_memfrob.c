/*
** EPITECH PROJECT, 2023
** B-ASM-400-BDX-4-1-asmminilibc-adrien.ricou
** File description:
** test_memfrob
*/

#define _GNU_SOURCE
#include <criterion/criterion.h>
#include <string.h>
#include <dlfcn.h>
#include <stdio.h>
#include <signal.h>

Test(memfrob, null_string, .signal = SIGSEGV)
{
    void (*my_memfrob)(char *s, size_t n);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_memfrob = dlsym(handle, "memfrob");
    my_memfrob(NULL, 10);
    dlclose(handle);
}

Test(memfrob, good_string)
{
    char *result = NULL;
    char *result_sys = NULL;
    void (*my_memfrob)(char *s, size_t n);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_memfrob = dlsym(handle, "memfrob");
    result_sys = strdup("Hello World!");
    result = strdup("Hello World!");
    memfrob(result_sys, 10);
    my_memfrob(result, 10);
    cr_assert_str_eq(result_sys, result);
    dlclose(handle);
}

Test(memfrob, good_string_at_end)
{
    char *result = NULL;
    char *result_sys = NULL;
    void (*my_memfrob)(char *s, size_t n);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_memfrob = dlsym(handle, "memfrob");
    result_sys = strdup("Hello World!");
    result = strdup("Hello World!");
    memfrob(result_sys, 15);
    my_memfrob(result, 15);
    cr_assert_str_eq(result_sys, result);
    dlclose(handle);
}