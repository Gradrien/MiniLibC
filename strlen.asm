BITS 64 ; permet de définir la taille de notre code

section .text ; permet de définir la section de notre code
global strlen ; permet de rendre la fonction disponible dans d'autres fichiers


strlen: ; nom de la fonction
    xor rax, rax
    ; mov permet de set notre rax
    ; rax contient notre index qu'on initialise à 0
    .loop:
    ; point d'entrée de la boucle
    cmp byte[rdi + rax], 0
    ; cmp pour comparer deux values
    ; byte pour accéder au caractère
    ;rdi contient le 1er argument, rax contient notre index à incrémenter
    ; rdi + rax permet de se déplacer sans toucher au pointeur
    ; on compare le char actuel avec 0
    je .endloop
    ; je pour jump if equal
    ; si le cmp est true alors on jump à .end
    inc rax
    ; inc pour incrémenter, on incrémente notre index
    jmp .loop
    ; on jump à .loop pour recommencer
    .endloop:
    ; point de sortie de la boucle
        ret
        ; ret pour return, on retourne la valeur de rax
