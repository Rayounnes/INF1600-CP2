#ifndef ASM_FUNCTIONS
#define ASM_FUNCTIONS

extern void append_asm(char* dst, const char* src);
extern int  is_lower_case_asm(const char c);
extern int  is_upper_case_asm(const char c);
extern void caesar_encrypt_asm(const char* src, char*dst, 
                               const unsigned int key);
extern void caesar_decrypt_asm(const char* src, char*dst, 
                               const unsigned int key);
extern void vigenere_encrypt_asm(const char* src, char*dst, 
                                 const char* keyword);
extern void vigenere_decrypt_asm(const char* src, char*dst, 
                                 const char* keyword);
                      
#endif
