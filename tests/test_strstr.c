/*
** EPITECH PROJECT, 2023
** B-ASM-400-BDX-4-1-asmminilibc-adrien.ricou
** File description:
** tests_strstr
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

Test(strstr, null_string, .signal = SIGSEGV)
{
    char *(*my_strstr)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strstr = dlsym(handle, "strstr");
    my_strstr(NULL, "Hello World!");
    dlclose(handle);
}

Test(strstr, null_to_find, .signal = SIGSEGV)
{
    char *(*my_strstr)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strstr = dlsym(handle, "strstr");
    my_strstr("Hello World!", NULL);
    dlclose(handle);
}

Test(strstr, good_string)
{
    char *result = NULL;
    char *result_sys = NULL;
    char *(*my_strstr)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strstr = dlsym(handle, "strstr");
    result_sys = strstr("Hello World!", "llo");
    result = my_strstr("Hello World!", "llo");
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}

Test(strstr, good_string_at_end)
{
    char *result = NULL;
    char *result_sys = NULL;
    char *(*my_strstr)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strstr = dlsym(handle, "strstr");
    result_sys = strstr("Hello World!", "World!");
    result = my_strstr("Hello World!", "World!");
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}

Test(strstr, good_string_at_begin)
{
    char *result = NULL;
    char *result_sys = NULL;
    char *(*my_strstr)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strstr = dlsym(handle, "strstr");
    result_sys = strstr("Hello World!", "Hello");
    result = my_strstr("Hello World!", "Hello");
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}

Test(strstr, wrong_string)
{
    char *result = NULL;
    char *result_sys = NULL;
    char *(*my_strstr)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strstr = dlsym(handle, "strstr");
    result_sys = strstr("Hello World!", "zebi");
    result = my_strstr("Hello World!", "zebi");
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}

Test(strstr, wrong_string_at_end)
{
    char *result = NULL;
    char *result_sys = NULL;
    char *(*my_strstr)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strstr = dlsym(handle, "strstr");
    result_sys = strstr("Hello World!", "World?");
    result = my_strstr("Hello World!", "World?");
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}

Test(strstr, wrong_string_at_begin)
{
    char *result = NULL;
    char *result_sys = NULL;
    char *(*my_strstr)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strstr = dlsym(handle, "strstr");
    result_sys = strstr("Hello World!", "Heelo");
    result = my_strstr("Hello World!", "Heelo");
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}

Test(strstr, empty_string)
{
    char *result = NULL;
    char *result_sys = NULL;
    char *(*my_strstr)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strstr = dlsym(handle, "strstr");
    result_sys = strstr("", "Hello World!");
    result = my_strstr("", "Hello World!");
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}

Test(strstr, empty_to_find)
{
    char *result = NULL;
    char *result_sys = NULL;
    char *(*my_strstr)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strstr = dlsym(handle, "strstr");
    result_sys = strstr("Hello World!", "");
    result = my_strstr("Hello World!", "");
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}

Test(strstr, empty_string_and_to_find)
{
    char *result = NULL;
    char *result_sys = NULL;
    char *(*my_strstr)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strstr = dlsym(handle, "strstr");
    result_sys = strstr("", "");
    result = my_strstr("", "");
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}
