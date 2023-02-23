/*
** EPITECH PROJECT, 2023
** B-ASM-400-BDX-4-1-asmminilibc-adrien.ricou
** File description:
** test_strchr
*/

#include <criterion/criterion.h>
#include <string.h>
#include <dlfcn.h>
#include <stdio.h>

Test(strchr, empty_string)
{
    char *my_result = NULL;
    char *sys_result = NULL;
    char *error;
    char *(*my_strchr)(char const *str, int c);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        return;
    dlerror();
    my_strchr = dlsym(handle, "strchr");
    my_result = strchr("", 'a');
    sys_result = my_strchr("", 'a');
    cr_assert_eq(my_result, sys_result);
    dlclose(handle);
}

Test(strchr, good_string)
{
    char *my_result = NULL;
    char *sys_result = NULL;
    char *error;
    char *(*my_strchr)(char const *str, int c);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        return;
    dlerror();
    my_strchr = dlsym(handle, "strchr");
    my_result = my_strchr("Hello World!", 'H');
    sys_result = strchr("Hello World!", 'H');
    cr_assert_eq(my_result, sys_result);
    dlclose(handle);
}

Test(strchr, good_string2)
{
    char *sys_result = NULL;
    char *my_result = NULL;
    char *error;
    char *(*my_strchr)(char const *str, int c);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        return;
    dlerror();
    my_strchr = dlsym(handle, "strchr");
    sys_result = strchr("Hello World!", 'e');
    my_result = my_strchr("Hello World!", 'e');
    cr_assert_eq(my_result, sys_result);
    dlclose(handle);
}

Test(strchr, bad_string)
{
    char *sys_result = NULL;
    char *my_result = NULL;
    char *error;
    char *(*my_strchr)(char const *str, int c);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        return;
    dlerror();
    my_strchr = dlsym(handle, "strchr");
    sys_result = strchr("Hello World!", 'a');
    my_result = my_strchr("Hello World!", 'a');
    cr_assert_eq(my_result, sys_result);
    dlclose(handle);
}

Test(strchr, string2_empty)
{
    char *sys_result = NULL;
    char *my_result = NULL;
    char *error;
    char *(*my_strchr)(char const *str, int c);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        return;
    dlerror();
    my_strchr = dlsym(handle, "strchr");
    sys_result = strchr("Hello World!", '\0');
    my_result = my_strchr("Hello World!", '\0');
    cr_assert_eq(my_result, sys_result);
    dlclose(handle);
}