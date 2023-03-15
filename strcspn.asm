BITS 64 ; permet de définir la taille de notre code

section .text ; permet de définir la section de notre code
global strcspn ; permet de rendre la fonction disponible dans d'autres fichiers

strcspn:
    xor r8, r8 ; on initialise notre compteur à 0
    xor r9, r9 ; on initialise notre compteur à 0
    .loop:
        mov rax, [rdi + r8] ; on met le 1er argument dans rax
        cmp al, 0 ; on compare le compteur de la chaîne 1 à 0
        je .end ; si le compteur de la chaîne 1 est à 0, on sort de la boucle
        jmp .check_reject ; on passe à la vérification des caractères rejetés
    .check_reject:
        mov rbx, [rsi + r9] ; on met le 2ème argument dans rbx
        cmp bl, 0 ; on compare le compteur de la chaîne 2 à 0
        je .next ; si le compteur de la chaîne 2 est à 0, on passe au caractère suivant
        cmp al, bl ; on compare le caractère de la chaîne 1 à celui de la chaîne 2
        je .end ; si les caractères sont égaux, on sort de la boucle
        inc r9 ; on incrémente le compteur de la chaîne 2
        jmp .check_reject ; on revient au début de la vérification des caractères rejetés
    .next:
        inc r8 ; on incrémente le compteur de la chaîne 1
        xor r9, r9 ; on réinitialise le compteur de la chaîne 2
        jmp .loop ; on revient au début de la boucle
    .end:
        mov rax, r8 ; on met le compteur de la chaîne 1 dans rax
        ret ; on retourne le résultat
