#ifndef C_FUNCTIONS
#define C_FUNCTIONS

void usage(const char* program);
void init_with_string(char* dst, const char* src);
void get_sentence_q09(unsigned int matricule, char* sentence);

void upper_case_c(char* dst);
void append_c(char* dst, const char* src);
int  is_lower_case_c(const char c);
int  is_upper_case_c(const char c);
void caesar_encrypt_c(const char* src, char*dst, 
                      const unsigned int key);
void caesar_decrypt_c(const char* src, char*dst, 
                      const unsigned int key);
void vigenere_encrypt_c(const char* src, char*dst, 
                        const char* keyword);
void vigenere_decrypt_c(const char* src, char*dst, 
                        const char* keyword);

void ceasar_q9(char* sentence, int matricule);

#endif
