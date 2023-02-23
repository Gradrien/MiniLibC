/*
** EPITECH PROJECT, 2023
** B-ASM-400-BDX-4-1-asmminilibc-adrien.ricou
** File description:
** test_strrchr
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

Test(strrchr, null_string, .signal = SIGSEGV)
{
    char *(*my_strrchr)(char const *s, int c);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strrchr = dlsym(handle, "strrchr");
    my_strrchr(NULL, 'a');
    dlclose(handle);
}

Test(strrchr, wrong_char)
{
    char *result_sys = NULL;
    char *result = NULL;
    char *(*my_strrchr)(char const *s, int c);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strrchr = dlsym(handle, "strrchr");
    result_sys = strrchr("Hello World!", 'a');
    result = my_strrchr("Hello World!", 'a');
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}

Test(strrchr, good_char)
{
    char *result = NULL;
    char *result_sys = NULL;
    char *(*my_strrchr)(char const *s, int c);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strrchr = dlsym(handle, "strrchr");
    result_sys = strrchr("Hello World!", 'd');
    result = my_strrchr("Hello World!", 'd');
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}

Test(strrchr, good_char_at_end)
{
    char *result = NULL;
    char *result_sys = NULL;
    char *(*my_strrchr)(char const *s, int c);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strrchr = dlsym(handle, "strrchr");
    result_sys = strrchr("Hello World!", '!');
    result = my_strrchr("Hello World!", '!');
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}

Test(strrchr, null_char)
{
    char *result = NULL;
    char *result_sys = NULL;
    char *(*my_strrchr)(char const *s, int c);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strrchr = dlsym(handle, "strrchr");
    result_sys = strrchr("Hello World!", '\0');
    result = my_strrchr("Hello World!", '\0');
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}

Test(strrchr, both_null_char)
{
    char *result = NULL;
    char *result_sys = NULL;
    char *(*my_strrchr)(char const *s, int c);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strrchr = dlsym(handle, "strrchr");
    result_sys = strrchr("\0", '\0');
    result = my_strrchr("\0", '\0');
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}
