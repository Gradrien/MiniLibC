BITS 64 ; permet de définir la taille de notre code

section .text ; permet de définir la section de notre code
global strstr ; permet de rendre la fonction disponible dans d'autres fichiers

strstr:
    xor r8, r8 ; initialize our first string index to 0
    xor r9, r9 ; initialize our second string index to 0
    xor rax, rax ; initialize our return value to 0
    xor rbx, rbx ; initialize our temporary register to 0
    xor rcx, rcx ; initialize our temporary register to 0
    cmp byte[rdi], 0 ; check if the first string is null
    je .first_null ; if the first string is null, return null
    .loop:
        mov bl, byte [rdi + r8] ; get the character from the first string
        mov cl, byte [rsi + r9] ; get the character from the second string
        cmp bl, cl ; compare the two characters
        je .next ; if they are equal, go to the next character
        cmp bl, 0 ; if the character from the first string is null, exit the loop
        je .end
        cmp cl, 0 ; if the character from the second string is null, exit the loop
        je .end
        xor r9, r9 ; reset the index of the second string to 0
        inc r8 ; go to the next character in the first string
        jmp .loop ; restart the loop
    .next:
        inc r8 ; increment the index of the first string
        inc r9 ; increment the index of the second string
        cmp byte [rsi + r9], 0 ; check if the second string has finished
        je .found ; if the second string has finished, return the match
        jmp .loop ; restart the loop
    .found:
        mov rax, rdi ; get the address of the first string
        add rax, r8 ; add the index of the first string
        sub rax, r9 ; subtract the index of the second string
        ret ; return the result
    .end:
        cmp bl, 0 ; check if the first string has finished
        je .null ; if the first string has finished, return null
        mov rax, rdi ; get the address of the first string
        add rax, r8 ; add the index of the first string
        sub rax, r9 ; subtract the index of the second string
        ret ; return the result
    .null:
        xor rax, rax ; return null
        ret
    .first_null:
        cmp byte[rsi], 0 ; check if the second string is null
        jne .loop ; if the second string is not null, return null
        mov rax, rdi ; return the address of the first string
        ret