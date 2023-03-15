BITS 64 ; permet de définir la taille de notre code

section .text ; permet de définir la section de notre code
global strchr ; permet de rendre la fonction disponible dans d'autres fichiers

strchr:
    xor rax, rax ; on initialise rax à 0
    xor rcx, rcx ; on initialise rcx à 0
    .loop:
        cmp byte[rdi + rcx], sil ; on compare le caractère à sil
        jz .good ; si c'est le cas, on sort de la boucle

        cmp byte[rdi + rcx], 0 ; on compare le caractère à 0
        jz .endloop ; si c'est le cas, on sort de la boucle

        inc rcx ; on incrémente rcx
        jmp .loop ; on retourne au début de la boucle
    .good:
        mov rax, rdi ; on copie rdi dans rax
        add rax, rcx ; on ajoute rcx à rax
        ret
    .endloop:
        xor rax, rax ; on initialise rax à 0
        ret