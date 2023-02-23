/*
** EPITECH PROJECT, 2023
** B-ASM-400-BDX-4-1-asmminilibc-adrien.ricou
** File description:
** test_strcspn
*/

#include <criterion/criterion.h>
#include <string.h>
#include <dlfcn.h>
#include <stdio.h>
#include <signal.h>

Test(strcspn, null_string, .signal = SIGSEGV)
{
    size_t (*my_strcspn)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strcspn = dlsym(handle, "strcspn");
    my_strcspn(NULL, "Hello World!");
    dlclose(handle);
}

Test(strcspn, null_to_find, .signal = SIGSEGV)
{
    size_t (*my_strcspn)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strcspn = dlsym(handle, "strcspn");
    my_strcspn("Hello World!", NULL);
    dlclose(handle);
}

Test(strcspn, good_string)
{
    size_t result = 0;
    size_t result_sys = 0;
    size_t (*my_strcspn)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strcspn = dlsym(handle, "strcspn");
    result_sys = strcspn("Hello World!", "llo");
    result = my_strcspn("Hello World!", "llo");
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}

Test(strcspn, good_string_at_end)
{
    size_t result = 0;
    size_t result_sys = 0;
    size_t (*my_strcspn)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strcspn = dlsym(handle, "strcspn");
    result_sys = strcspn("Hello World!", "!");
    result = my_strcspn("Hello World!", "!");
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}

Test(strcspn, good_string_not_found)
{
    size_t result = 0;
    size_t result_sys = 0;
    size_t (*my_strcspn)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strcspn = dlsym(handle, "strcspn");
    result_sys = strcspn("Hello World!", "z");
    result = my_strcspn("Hello World!", "z");
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}

Test(strcspn, good_string_empty_to_find)
{
    size_t result = 0;
    size_t result_sys = 0;
    size_t (*my_strcspn)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strcspn = dlsym(handle, "strcspn");
    result_sys = strcspn("Hello World!", "");
    result = my_strcspn("Hello World!", "");
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}

Test(strcspn, good_string_empty_string)
{
    size_t result = 0;
    size_t result_sys = 0;
    size_t (*my_strcspn)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strcspn = dlsym(handle, "strcspn");
    result_sys = strcspn("", "Hello World!");
    result = my_strcspn("", "Hello World!");
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}

Test(strcspn, good_string_empty_string_and_to_find)
{
    size_t result = 0;
    size_t result_sys = 0;
    size_t (*my_strcspn)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strcspn = dlsym(handle, "strcspn");
    result_sys = strcspn("", "");
    result = my_strcspn("", "");
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}

Test(strcspn, good_string_only_to_find)
{
    size_t result = 0;
    size_t result_sys = 0;
    size_t (*my_strcspn)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strcspn = dlsym(handle, "strcspn");
    result_sys = strcspn("Hello World!", "Hello World!");
    result = my_strcspn("Hello World!", "Hello World!");
    cr_assert_eq(result_sys, result);
    dlclose(handle);
}

Test(strcspn, both_null, .signal = SIGSEGV)
{
    size_t (*my_strcspn)(char const *s, char const *to_find);
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    dlerror();
    my_strcspn = dlsym(handle, "strcspn");
    my_strcspn(NULL, NULL);
    dlclose(handle);
}