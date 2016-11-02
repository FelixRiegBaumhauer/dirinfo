#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <dirent.h>
#include <sys/types.h>

int main(){
  DIR *hold_dir;
  hold_dir = opendir("test");
  struct dirent *each;
 
  each = readdir(hold_dir);
  printf("%s\n", each->d_name);

  each = readdir(hold_dir);
  printf("%s\n", each->d_name);

  each = readdir(hold_dir);
  printf("%s\n", each->d_name);

  
  each = readdir(hold_dir);
  printf("%s\n", each->d_name);

  each = readdir(hold_dir);
  printf("%s\n", each->d_name);

  
  each = readdir(hold_dir);
  printf("%s\n", each->d_name);


  closedir(hold_dir);

  return 0;
}
