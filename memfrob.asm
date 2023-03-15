BITS 64 ; permet de définir la taille de notre code

section .text ; permet de définir la section de notre code
global memfrob ; permet de rendre la fonction disponible dans d'autres fichiers

memfrob:
    xor rcx, rcx ; initialise rax à 0
    .loop:
        cmp rcx, rsi ; compare le caractère à notre index
        je .end ; si c'est le cas, on sort de la boucle
        xor byte [rdi + rcx], 42 ; on xor le caractère avec 42
        inc rcx ; on incrémente rcx
        jmp .loop ; on boucle
    .end:
        mov rax, rdi ; on retourne le pointeur
        ret ; on retourne