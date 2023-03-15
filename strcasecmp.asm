BITS 64 ; permet de définir la taille de notre code

section .text ; permet de définir la section de notre code
global strcasecmp ; permet de rendre la fonction disponible dans d'autres fichiers

strcasecmp:
    xor rax, rax
    xor rbx, rbx
    xor r8, r8
    xor r9, r9
    cmp rdi, 0
    je .check_rsi

    .check_rsi:
        cmp rsi, 0
        je .end
    .loop:
        mov r8b, byte [rdi + rbx] ; on copie le caractère de rdi dans r8
        mov r9b, byte [rsi + rbx] ; on copie le caractère de rsi dans r9
        cmp r8b, 0 ; on compare le caractère à 0
        je .substract
        cmp r9b, 0 ; on compare le caractère à 0
        je .substract
        jmp .rdi_case_a
    .rdi_case_a:
        cmp r8b, 'A' ; on compare le caractère à 'A'
        jge .rdi_case_z ; si le caractère est supérieur ou égal à 'A', on saute à la ligne suivante
        jmp .rsi_case_a ; sinon, on saute à la ligne suivante
    .rdi_case_z:
        cmp r8b, 'Z' ; on compare le caractère à 'Z'
        jle .rdi_to_lower ; si le caractère est inférieur ou égal à 'Z', on saute à la ligne suivante
        jmp .rsi_case_a ; sinon, on saute à la ligne suivante
    .rsi_case_a:
        cmp r9b, 'A' ; on compare le caractère à 'A'
        jge .rsi_case_z ; si le caractère est supérieur ou égal à 'A', on saute à la ligne suivante
        jmp .compare ; sinon, on saute à la ligne suivante
    .rsi_case_z:
        cmp r9b, 'Z' ; on compare le caractère à 'Z'
        jle .rsi_to_lower ; si le caractère est inférieur ou égal à 'Z', on saute à la ligne suivante
        jmp .compare ; sinon, on saute à la ligne suivante
    .rdi_to_lower:
        add r8b, 32 ; on ajoute 32 à notre char
        jmp .rsi_case_a ; on saute à la ligne suivante
    .rsi_to_lower:
        add r9b, 32 ; on ajoute 32 à notre char
        jmp .compare ; on saute à la ligne suivante
    .compare:
        cmp r8b, r9b ; on compare le caractère de r8 à celui de r9
        jne .substract ; si les caractères sont différents, on saute à la ligne suivante
        inc rbx
        jmp .loop ; sinon, on saute à la ligne suivante
    .substract:
        sub r8, r9 ; on soustrait r8 à r9
        mov rax, r8 ; on move r8 dans rax
        ret
    .end:
        ret