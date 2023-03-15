BITS 64 ; permet de définir la taille de notre code

section .text ; permet de définir la section de notre code
global strrchr ; permet de rendre la fonction disponible dans d'autres fichiers

strrchr:
    xor rax, rax ; on initialise rax à 0
    xor rcx, rcx ; on initialise rcx à 0
    .loop_end:
        cmp byte[rdi], 0 ; on compare le caractère à 0
        je .loop ; si c'est le cas, on sort de la boucle
        inc rdi ; on incrémente rdi, pour aller à la fin de la string
        inc rcx ; on incrémente rcx, pour compter le nombre de caractères -> va servir de condition d'arrêt
        jmp .loop_end ; on boucle
    .loop:
        cmp byte[rdi], sil ; on compare le caractère à sil
        je .good ; si c'est le cas, on sort de la boucle

        cmp rcx, 0  ; on compare le caractère à 0
        je .endloop ; si c'est le cas, on sort de la boucle

        dec rcx ; on incrémente rcx
        dec rdi
        jmp .loop ; on retourne au début de la boucle
    .good:
        mov rax, rdi ; on copie rdi dans rax
        ret
    .endloop:
        xor rax, rax ; on initialise rax à 0
        ret