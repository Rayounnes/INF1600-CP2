.text
.globl caesar_encrypt_asm
caesar_encrypt_asm:
   
   pushl %ebp
   movl %esp, %ebp

   pushl %ecx  
   pushl %esi  /*src*/
   pushl %edi  /*dst*/
   pushl %ebx  /*key*/

   movl 8(%ebp), %esi
   movl 12(%ebp), %edi
   movl 16(%ebp), %ebx


encryptage_bcl :

   cmpb $0, (%esi)  /* if src[0] == 0 */
   je fin

   /* if is_lower_case_asm */
   pushl (%esi)
   call is_lower_case_asm
   addl $4, %esp
   cmp $1, %eax
   je traitement_lower_case


   /* if is_upper_case_asm */
   pushl (%esi)
   call is_upper_case_asm
   addl $4, %esp
   cmp $1, %eax
   je traitement_upper_case

   /*else*/
   movl (%esi), %edx
   movl %edx, (%edi)

   jmp incrementer

traitement_lower_case:

   movzx (%esi), %eax
   subl $'a', %eax      /* retirer la valeure ascii de a minuscule de eax*/
   addl %ebx, %eax      /* ajouter la valeure de la key (ecx) dans eax */

   movl $26, %ecx
   movl $0, %edx
   div %ecx
   addl $'a', %edx

   movl %edx, (%edi)
   jmp incrementer
traitement_upper_case:
   movzx (%esi), %eax
   subl $'A', %eax      /* retirer la valeure ascii de A majuscule de eax*/
   addl %ebx, %eax      /* ajouter la valeure de la key (ecx) dans eax */

   movl $26, %ecx
   movl $0, %edx
   div %ecx
   addl $'A', %edx

   movl %edx, (%edi)
   jmp incrementer

incrementer:

   addl $1, %esi
   addl $1, %edi

   jmp encryptage_bcl
fin :

   movl $0, (%edi)
   popl %ebx
   popl %edi
   popl %esi
   popl %ecx
   leave
   ret
