#include "main.h"

int convert(char* input, int key){
  
  // Loop over each letter in string iteratively
  for ( int n = 0, len = strlen(input); n < len; n++ ){
    int offset;
    char ciphertext;
    int letter = input[n];
    
    // Change spaces to ASCII '!'
    if( letter == ' '){
      letter = '!';
    }
    
    // if the letter is not a - z and not A - Z, change to '!'
    if( !(letter >= 97 && letter <= 122) && !(letter >= 65 && letter <= 90) ){
      letter = '!'; // TODO: fixed unexpected conversions
    }
    
    // set ASCII offset depending on upper/lower case
    if(isupper(letter)){ 
      offset = 'A';
    } else if (islower(letter)){
      offset = 'a';
    } 
    
    // Shift 13 positions
    ciphertext = letter + key;
    // Check for overflow into unwanted ASCII values, if so, alter key
    if ( ((letter - offset) + key) > 26 ){
      key = ((letter - offset) + key ) % 26;
      ciphertext = offset + key;
    }
    
    // Fix some of the ASCII inconsistencies.
    // Once '!' converts over to '.', convert back to space
    if ( ciphertext == '.'){
      ciphertext = ' ';
    //TODO: remove this part and add efficiency!
    } else if ( ciphertext == '{'){ 
      ciphertext = 'a';
    } else if ( ciphertext == '['){
      ciphertext = 'A';
    }
    
    printf("%c", ciphertext);
    key = 13;
  } 
  printf("\n");
  return 0;
}

int check_extension(char* input){
  char *f = strrchr(input, '.');
  if (f == NULL){
    return 1;
  }
  
  return 0;
}

int main( int argc, char *argv[] )
{
    const char * output;
    char * input; // used to store input
        
    errno = 0;
    
    int key;
    
    if(argc < 2 || argc > 3){
      printf("Usage: %s <STRING/FILE> (13)\n", argv[0]);
      return 1;
    }
    
    if( argv[2] != NULL ){
      key = atoi(argv[2]);
    } else {
      key = 13;
    }
      
    // Check if file has an extension
    if( check_extension(argv[1]) == 0){
      // First, find the file in directory
      if( access(argv[1], F_OK) != -1){
        // Open, with read-only permission
        int f = open(argv[1], O_RDONLY);
        // Store length of file
        int len = lseek(f, 0, SEEK_END);
        
        // Use POSIX-standard mmap() to do a memory map on contents of file. 
        // Is much more performance efficient. TODO: write WIN32 alternative
        //
        //  void *mmap(addr, len, prot, flags, fildes, off);
        //
        input = mmap(0, len, PROT_READ, MAP_PRIVATE, f, 0);
        // If errno is set to nonzero, then error has occurred (i.e empty file).
        if(errno != 0){
          fprintf(stderr, "Could not read file!\n");
        }
      } else {
        fprintf(stderr, "File doesn't exist. Exiting.\n");
        return 1;
      }
    // If file doesn't have extension, just store it in input
    } else {
      input = argv[1];
    }
    
    printf("Input: %s\nCipher: %i\nOutput: ", input, key);
    
    if( convert(input, key) != 0){
      fprintf(stderr, "Failed to encrypt input. Exiting.");
      return 1;
    }
        
    
    return 0;
}
