#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_functions.h"

void usage(const char* program) {
   fprintf(stderr, "Usage:\n\t%s matricule\n", program);
   exit(1);
}

void init_with_string(char* dst, const char* src){

   unsigned int i = 0;
   while(src[i] != 0){
      dst[i] = src[i];
      i++;
   }
}

void append_c(char* dst, const char* src){

   unsigned int i = 0, j = 0;

   while( dst[j] != 0 ) j++;

   while( src[i] != 0 )
      dst[j++] = src[i++];

   dst[j] = '\0';
}

int is_lower_case_c(const char c){
   if ( c >= 'a' && c <= 'z')
      return 1;
   return 0;
}

int is_upper_case_c(const char c){
   if ( c >= 'A' && c <= 'Z')
      return 1;
   return 0;
}

void caesar_encrypt_c(const char* src, char*dst, 
                      const unsigned int key){
   unsigned int i = 0;
   while( src[i] != 0 ){
      if( is_lower_case_c(src[i]) )
         dst[i] = (src[i] - 'a' + key) % 26 + 'a';
      else if( is_upper_case_c(src[i]) )
         dst[i] = (src[i] - 'A' + key) % 26 + 'A';
      else
         dst[i] = src[i];
      i++;
   }
   dst[i] = '\0';
}

void caesar_decrypt_c(const char* src, char*dst, 
                      const unsigned int key){
   unsigned int i = 0;
   while( src[i] != 0 ){
      if( is_lower_case_c(src[i]) )
         dst[i] = (src[i] - 'a' + (26 - key)) % 26 + 'a';
      else if( is_upper_case_c(src[i]) )
         dst[i] = (src[i] - 'A' + (26 - key)) % 26 + 'A';
      else
         dst[i] = src[i];
      i++;
   }
   dst[i] = '\0';
}

void vigenere_encrypt_c(const char* src, char*dst, 
                        const char* keyword){
   unsigned int i = 0, j = 0, key = 0;
   while( src[i] != 0 ){
   
      if( keyword[j] != 0 ){
         key = (unsigned int)(keyword[j] & 0xF);
         j++;  
      }
      else{
         j = 0;
         key = (unsigned int)(keyword[j] & 0xF);
      }
       
      if( is_lower_case_c(src[i]) )
         dst[i] = (src[i] - 'a' + key) % 26 + 'a';
      else if( is_upper_case_c(src[i]) )
         dst[i] = (src[i] - 'A' + key) % 26 + 'A';
      else
         dst[i] = src[i];
      i++;
   }
   dst[i] = '\0';
}

void vigenere_decrypt_c(const char* src, char*dst, 
                        const char* keyword){
   unsigned int i = 0, j = 0, key = 0;
   while( src[i] != 0 ){
   
      if( keyword[j] != 0 ){
         key = (unsigned int)(keyword[j] & 0xF);
         j++;  
      }
      else{
         j = 0;
         key = (unsigned int)(keyword[j] & 0xF);
      }
       
      if( is_lower_case_c(src[i]) )
         dst[i] = (src[i] - 'a' + (26 - key)) % 26 + 'a';
      else if( is_upper_case_c(src[i]) )
         dst[i] = (src[i] - 'A' + (26 - key)) % 26 + 'A';
      else
         dst[i] = src[i];
      i++;
   }
   dst[i] = '\0';
}

void get_sentence_q09(unsigned int matricule, char* sentence){
   unsigned int A, B, C, D;
   A = matricule % 2;
   B = matricule % 3;
   C = matricule % 5;
   D = matricule % 7;
   int i = 0, idx = ((A*3 + B)*5 + C)*7 + D;
   
   FILE *fp;
   char * line = NULL;
   size_t len = 0;
   ssize_t read;

   fp = fopen("q9.txt", "r");
   if (fp == NULL){
      printf("Le fichier n'a pas ete trouve.");
      return;
   }
      

    while ((read = getline(&line, &len, fp)) != -1)
      if( i++ == idx ){
         init_with_string(sentence, line);
         if( read > 0 ) sentence[read-1] = '\0';
      }

    fclose(fp);
    if (line) free(line);
}

void ceasar_q9(char* sentence,  int matricule)
{
   
   const char* save = sentence;

   for(unsigned int i = 1; i < 26; i++)
   {  
      printf("Key numero : %d\n", i);
      caesar_decrypt_c(sentence,sentence,i);
      printf("%s\n", sentence);
      printf("\n");
      get_sentence_q09(matricule, sentence);
   }
}