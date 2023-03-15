BITS 64 ; permet de définir la taille de notre code

section .text ; permet de définir la section de notre code
global memcpy ; permet de rendre la fonction disponible dans d'autres fichiers

memcpy:
    xor rax, rax
    xor rbx, rbx
    .loop:
        cmp rbx, rdx ; rdx = taille
        je .end ; si rbx = rdx, on sort de la boucle
        mov r8b, [rsi + rbx] ; r8 = valeur de l'adresse de départ
        mov byte[rdi + rbx], r8b; rdi = adresse de départ
        inc rbx ; on incrémente rbx pour passer à l'adresse suivante
        inc rax ; on incrémente rax pour compter le nombre de fois qu'on a rempli
        jmp .loop
    .end:
        mov rax, rdi ; on retourne l'adresse de départ
        ret
