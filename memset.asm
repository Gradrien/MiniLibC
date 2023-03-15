BITS 64 ; permet de définir la taille de notre code

section .text ; permet de définir la section de notre code
global memset ; permet de rendre la fonction disponible dans d'autres fichiers

memset:
    xor rax, rax
    xor rbx, rbx
    .loop:
        cmp rbx, rdx ; rdx = taille
        je .end ; si rbx = rdx, on sort de la boucle
        mov byte[rdi + rbx], sil ; rdi = adresse de départ, sil = valeur à mettre on utilise sil prce que c'est un byte c'est int
        inc rbx ; on incrémente rbx pour passer à l'adresse suivante
        inc rax ; on incrémente rax pour compter le nombre de fois qu'on a rempli
        jmp .loop
    .end:
        mov rax, rdi ; on retourne l'adresse de départ
        ret
