#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_functions.h"
#include "asm_functions.h"

#define TEST_Q2 0
#define TEST_Q3 0
#define TEST_Q4 0
#define TEST_Q5 0
#define TEST_Q6 0
#define TEST_Q7 0
#define TEST_Q8 0

int main(int argc, char** argv) {

   if(argc != 2) usage(argv[0]);

   char* salutation = malloc( sizeof(char) * 1024 );
   char* src        = malloc( sizeof(char) * 1024 );
   char* enc        = malloc( sizeof(char) * 1024 );
   char* keyword    = malloc( sizeof(char) * 1024 );

   init_with_string(salutation, "Mon matricule est ");
   init_with_string(src, "Trump a-t-il gagne les elections?");
   init_with_string(keyword, argv[1]);
   
   unsigned int matricule = atoi(argv[1]);
   unsigned int A, B, C, D;
   A = matricule % 2;
   B = matricule % 3;
   C = matricule % 5;
   D = matricule % 7;
   unsigned int key = (A + B + C + D ) % 25 + 1;
   
   printf("\n ** Controle periodique 2 ** \n\n");

   printf("A = %d, B = %d, C = %d, D = %d, key = %d\n", A, B, C, D, key);
   printf("keyword = %s\n", keyword);
   
   printf("\n- Q2 \n");
   if( TEST_Q2 ){
      append_asm( salutation, argv[1] );
      append_c( salutation, " (ASM)" );
      printf("%s\n", salutation);
   }
   else{
      append_c( salutation, argv[1] );
      printf("%s\n", salutation);
   }
   
   printf("\n- Q3 \n");
   if( TEST_Q3 ){
   
      if( is_lower_case_asm( 'a' ) )
         printf("is_lower_case_asm a vu que 'a' est une minuscule. (ASM)\n");
      else
         printf("is_lower_case_asm n'a pas vu que 'a' est une minuscule. (ASM)\n");
         
      if( !is_lower_case_asm( 'A' ) )
         printf("is_lower_case_asm a vu que 'A' n'est pas une minuscule. (ASM)\n");
      else
         printf("is_lower_case_asm n'a pas vu que 'A' n'est pas une minuscule. (ASM)\n");
         
   }
   else{
   
      if( is_lower_case_c( 'a' ) )
         printf("is_lower_case_c a vu que 'a' est une minuscule.\n");
      else
         printf("is_lower_case_c n'a pas vu que 'a' est une minuscule.\n");
         
      if( !is_lower_case_c( 'A' ) )
         printf("is_lower_case_c a vu que 'A' n'est pas une minuscule.\n");
      else
         printf("is_lower_case_c n'a pas vu que 'A' n'est pas une minuscule.\n");
         
   }
   
   printf("\n- Q4 \n");
   if( TEST_Q4 ){
   
      if( is_upper_case_asm( 'A' ) )
         printf("is_upper_case_asm a vu que 'A' est une majuscule (ASM).\n");
      else
         printf("is_upper_case_asm n'a pas vu que 'A' est une majuscule (ASM).\n");
         
      if( !is_upper_case_asm( 'a' ) )
         printf("is_upper_case_asm a vu que 'a' n'est pas une majuscule (ASM).\n");
      else
         printf("is_upper_case_asm n'a pas vu que 'a' n'est pas une majuscule (ASM).\n");
         
   }
   else{
   
      if( is_upper_case_c( 'A' ) )
         printf("is_upper_case_c a vu que 'A' est une majuscule.\n");
      else
         printf("is_upper_case_c n'a pas vu que 'A' est une majuscule.\n");
         
      if( !is_upper_case_c( 'a' ) )
         printf("is_upper_case_c a vu que 'a' n'est pas une majuscule.\n");
      else
         printf("is_upper_case_c n'a pas vu que 'a' n'est pas une majuscule.\n");
         
   }
   
   printf("\n- Q5 \n");
   if( TEST_Q5 ){
      printf("Encryption de Cesar (ASM):\n");
      caesar_encrypt_asm(src, enc, key);   
      printf("%s\n", enc);
   }
   else{
      printf("Encryption de Cesar:\n");
      caesar_encrypt_c(src, enc, key);
      printf("%s\n", enc);
   }
   
   printf("\n- Q6 \n");
   if( TEST_Q6 ){
      printf("Decryption de Cesar (ASM):\n");
      caesar_decrypt_asm(enc, enc, key);
      printf("%s\n", enc);
   }
   else{
      printf("Decryption de Cesar:\n");
      caesar_decrypt_c(enc, enc, key);
      printf("%s\n", enc);
   }
   
   printf("\n- Q7 \n");
   if( TEST_Q7 ){
      printf("Encryption de Vigenere (ASM):\n");
      vigenere_encrypt_asm(src, enc, keyword);   
      printf("%s\n", enc);
   }
   else{
      printf("Encryption de Vigenere:\n");
      vigenere_encrypt_c(src, enc, keyword);
      printf("%s\n", enc);
   }
   
   printf("\n- Q8 \n");
   if( TEST_Q8 ){
      printf("Decryption de Vigenere (ASM):\n");
      vigenere_decrypt_asm(enc, enc, keyword);
      printf("%s\n", enc);
   }
   else{
      printf("Decryption de Vigenere:\n");
      vigenere_decrypt_c(enc, enc, keyword);
      printf("%s\n", enc);
   }
   
   printf("\n- Q09 - Bonus \n");
   
  

   get_sentence_q09(matricule, enc);
   printf("Encryption de Cesar:\n");
   printf("%s\n", enc);
   printf("Decryption de Cesar:\n");

   ceasar_q9(enc,matricule);


   free(salutation);
   free(src);
   free(enc);
   free(keyword);

   return 0;
}

