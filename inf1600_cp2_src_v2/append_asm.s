.text
.globl append_asm
append_asm:
   movl 4(%esp), %ecx               /*DST*/
   movl 8(%esp), %eax               /*SRC*/

boucler_dst:

   cmpb $0, (%ecx)
   je boucler_src

   addl $1, %ecx /*on avance de 1 dans l'adresse*/
   jmp boucler_dst

boucler_src:

   cmpb $0, (%eax)
   je fin_boucler_src

   movl (%eax), %edx /*on mets le tout dans edx*/
   movl %edx, (%ecx) /*qu'on remet dans ecx*/
   addl $1, %eax
   addl $1, %ecx

   jmp boucler_src


fin_boucler_src:
   movl $0, (%ecx)
   jmp fin

fin:
   ret