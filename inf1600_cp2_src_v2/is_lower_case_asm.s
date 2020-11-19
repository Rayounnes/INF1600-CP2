.text
.globl is_lower_case_asm
is_lower_case_asm:
   
   movb 4(%esp),%al

   cmpb $'a', %al
   jl pas_lower

   cmpb $'z', %al
   jg pas_lower

   jmp lower

pas_lower:
   movl $0, %eax
   ret
lower:
   movl $1, %eax
   ret
