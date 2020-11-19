.text
.globl is_upper_case_asm
is_upper_case_asm:
   
   movb 4(%esp),%al

   cmpb $'A', %al
   jl pas_upper

   cmpb $'Z', %al
   jg pas_upper

   jmp upper

pas_upper:
   movl $0, %eax
   ret
upper:
   movl $1, %eax
   ret
