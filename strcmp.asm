BITS 64 ; permet de définir la taille de notre code

section .text ; permet de définir la section de notre code
global strcmp ; permet de rendre la fonction disponible dans d'autres fichiers

strcmp:
    xor rax, rax
    xor rbx, rbx
    xor r8, r8
    xor r9, r9
    .loop:
        cmp rdi, 0
        je .check_rsi
        mov r8b, byte[rdi + rbx] ; on récupère le caractère du premier arg dans r8
        mov r9b, byte[rsi + rbx] ; on récupère le caractère du deuxième arg dans r9
        cmp r8b, r9b ; on compare les deux caractères
        jne .end ; si ils sont différents, on sort de la boucle
        inc rbx ; on incrémente notre index temp
        cmp r8b, 0 ; on compare le caractère du premier arg avec 0
        jne .loop ; si ils sont différents, on continue la boucle
        cmp r9b, 0 ; on compare le caractère du deuxième arg avec 0
        jne .loop ; si ils sont différents, on continue la boucle
    .check_rsi:
        cmp rsi, 0
        jmp .end
    .end:
        mov rax, r8 ; on met le caractère à l'index temp dans rax
        sub rax, r9 ; on soustrait le caractère à l'index temp à rax
        ret