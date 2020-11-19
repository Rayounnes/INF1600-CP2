CC=gcc
CFLAGS=-g -m32 -g -Wall
RM=rm -f
TARGET=exec
OBJECTS=main.o c_functions.o append_asm.o is_lower_case_asm.o is_upper_case_asm.o caesar_encrypt_asm.o caesar_decrypt_asm.o vigenere_encrypt_asm.o vigenere_decrypt_asm.o

.PHONY: clean

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

.s.o:
	$(CC) $(CFLAGS) -c -o $@ $<

all: exec

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) *.o $(TARGET)
