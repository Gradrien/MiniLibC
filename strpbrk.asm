BITS 64 ; permet de définir la taille de notre code

section .text ; permet de définir la section de notre code
global strpbrk ; permet de définir la fonction strpbrk comme étant globale

strpbrk:
    xor r8, r8 ; initialize our first string counter to 0
    .loop:
        mov al, [rdi + r8] ; get the current character of the first string
        cmp al, 0 ; check if the first string has ended
        je .end ; if the first string has ended, return null
        xor r9, r9 ; initialize our second string counter to 0
        .inner_loop:
            mov bl, [rsi + r9] ; get the current character of the second string
            cmp bl, 0 ; check if the second string has ended
            je .next ; if the second string has ended, move to the next character of the first string
            cmp al, bl ; compare the characters of the two strings
            je .found ; if the characters match, return the current character of the first string
            inc r9 ; increment the second string counter
            jmp .inner_loop ; loop again
        .next:
            inc r8 ; increment the first string counter
            jmp .loop ; loop again
    .found:
        mov rax, rdi ; move the first string into rax
        add rax, r8 ; add the first string counter to the address of the first string
        ret ; return the address of the current character of the first string
    .end:
        xor rax, rax ; set rax to 0 to return null
        ret ; return null
