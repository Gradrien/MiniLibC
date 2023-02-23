/*
** EPITECH PROJECT, 2023
** B-ASM-400-BDX-4-1-asmminilibc-adrien.ricou
** File description:
** test_strcasecmp
*/

#include <criterion/criterion.h>
#include <string.h>
#include <dlfcn.h>
#include <stdio.h>
#include <signal.h>

Test(strcasecmp, empty_string)
{
    int my_result = 0;
    int sys_result = 0;
    int (*my_strcasecmp)(char const *s1, char const *s2);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        return;
    dlerror();
    my_strcasecmp = dlsym(handle, "strcasecmp");
    my_result = my_strcasecmp("", "");
    sys_result = strcasecmp("", "");
    cr_assert_eq(my_result, sys_result);
    dlclose(handle);
}

Test(strcasecmp, good_string)
{
    int my_result = 0;
    int sys_result = 0;
    int (*my_strcasecmp)(char const *s1, char const *s2);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        return;
    dlerror();
    my_strcasecmp = dlsym(handle, "strcasecmp");
    my_result = my_strcasecmp("Hello World!", "Hello World!");
    sys_result = strcasecmp("Hello World!", "Hello World!");
    cr_assert_eq(my_result, sys_result);
    dlclose(handle);
}

Test(strcasecmp, first_string_greater)
{
    int my_result = 0;
    int sys_result = 0;
    int (*my_strcasecmp)(char const *s1, char const *s2);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        return;
    dlerror();
    my_strcasecmp = dlsym(handle, "strcasecmp");
    my_result = my_strcasecmp("Hello World!", "Hello");
    sys_result = strcasecmp("Hello World!", "Hello");
    cr_assert_eq(my_result, sys_result);
    dlclose(handle);
}

Test(strcasecmp, second_string_greater)
{
    int my_result = 0;
    int sys_result = 0;
    int (*my_strcasecmp)(char const *s1, char const *s2);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        return;
    dlerror();
    my_strcasecmp = dlsym(handle, "strcasecmp");
    my_result = my_strcasecmp("Hello", "Hello World!");
    sys_result = strcasecmp("Hello", "Hello World!");
    cr_assert_eq(my_result, sys_result);
    dlclose(handle);
}

Test(strcasecmp, first_string_null, .signal = SIGSEGV)
{
    int my_result = 0;
    int sys_result = 0;
    int (*my_strcasecmp)(char const *s1, char const *s2);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        return;
    dlerror();
    my_strcasecmp = dlsym(handle, "strcasecmp");
    my_result = my_strcasecmp(NULL, "Hello World!");
    sys_result = strcasecmp(NULL, "Hello World!");
    cr_assert_eq(my_result, sys_result);
    dlclose(handle);
}

Test(strcasecmp, second_string_null, .signal = SIGSEGV)
{
    int my_result = 0;
    int sys_result = 0;
    int (*my_strcasecmp)(char const *s1, char const *s2);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        return;
    dlerror();
    my_strcasecmp = dlsym(handle, "strcasecmp");
    my_result = my_strcasecmp("Hello World!", NULL);
    sys_result = strcasecmp("Hello World!", NULL);
    cr_assert_eq(my_result, sys_result);
    dlclose(handle);
}

Test(strcasecmp, both_string_null)
{
    int my_result = 0;
    int sys_result = 0;
    int (*my_strcasecmp)(char const *s1, char const *s2);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        return;
    dlerror();
    my_strcasecmp = dlsym(handle, "strcasecmp");
    my_result = my_strcasecmp(NULL, NULL);
    sys_result = strcasecmp(NULL, NULL);
    cr_assert_eq(my_result, sys_result);
    dlclose(handle);
}

Test(strcasecmp, first_string_empty)
{
    int my_result = 0;
    int sys_result = 0;
    int (*my_strcasecmp)(char const *s1, char const *s2);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        return;
    dlerror();
    my_strcasecmp = dlsym(handle, "strcasecmp");
    my_result = my_strcasecmp("", "Hello World!");
    sys_result = strcasecmp("", "Hello World!");
    cr_assert_eq(my_result, sys_result);
    dlclose(handle);
}

Test(strcasecmp, second_string_empty)
{
    int my_result = 0;
    int sys_result = 0;
    int (*my_strcasecmp)(char const *s1, char const *s2);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        return;
    dlerror();
    my_strcasecmp = dlsym(handle, "strcasecmp");
    my_result = my_strcasecmp("Hello World!", "");
    sys_result = strcasecmp("Hello World!", "");
    cr_assert_eq(my_result, sys_result);
    dlclose(handle);
}

Test(strcasecmp, both_string_empty)
{
    int my_result = 0;
    int sys_result = 0;
    int (*my_strcasecmp)(char const *s1, char const *s2);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        return;
    dlerror();
    my_strcasecmp = dlsym(handle, "strcasecmp");
    my_result = my_strcasecmp("", "");
    sys_result = strcasecmp("", "");
    cr_assert_eq(my_result, sys_result);
    dlclose(handle);
}