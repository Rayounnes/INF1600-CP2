.text
.globl is_prime_asm
is_prime_asm:
   push  %ebp      /* Save old base pointer */
   mov   %esp, %ebp /* Set ebp to current esp */
   pushl %ebx

   /* Programme ici */
   movl  8(%ebp), %ebx

   cmpl  $0, %ebx
   je    not_prime

   cmpl  $1, %ebx
   je    not_prime

   cmpl  $2, %ebx
   je    prime

   cmpl  $3, %ebx
   je    prime

   movl  %ebx, %eax
   and   $1, %eax 
   cmpl  $0, %eax
   je    not_prime

   movl  $3, %ecx
   
test:
   movl  %ecx, %eax
   mul   %ecx

   cmpl  %ebx, %eax
   ja    prime   
   
loop: 

   movl  $0, %edx
   movl  %ebx, %eax
   div   %ecx
   cmp   $0, %edx
   je    not_prime

   addl  $2, %ecx

   jmp  test

prime:
   movl  $1, %eax
   jmp   bye

not_prime:
   movl  $0, %eax

bye:
   popl  %ebx
   leave          /* Restore ebp and esp */
   ret            /* Return to the caller */

