//Felix Rieg-Baumhauer Pd 5, 11/02/2016

#include <stdio.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

//FROM PAST HW
void size_enator(int bytes) {
  if (bytes >= pow(2,30))
    //.1f - 1 digit after floating point
    printf("Size: %.1f GB\n", bytes/(pow(2,30)));
  else if (bytes >= pow(2,20) && bytes < pow(2,30))
    printf("Size: %.1f MB\n", bytes/(pow(2,20)));
  else if (bytes >= pow(2,10) && bytes < pow(2,20))
    printf("Size: %.1f KB\n", bytes/(pow(2,10)));
  printf("Size: %d B\n\n", bytes);
}

int size_it(struct stat *buff){
  return buff->st_size;
}

int get_size(DIR *all){
  int total_size = 0;
  int size = 0;

  struct dirent *each;
  each = readdir(all);
  //if failuer, each is NULL, then the while doenst fire
  printf("SiZE OF FILES:\n");
  while(each){
    //char filename [1024] = "";
    //filename = each->d_name;
    //printf("%s\n", each->d_name);//filename);
    //filename = strcat("test/",filename);

    struct stat buff;
    stat(each->d_name, &buff);
    size = size_it(&buff);//(buff->st_size);
    //printf("%d\n", size);
    total_size+=size;
    
    each = readdir(all);
  }

  return total_size;
}


int print_all(DIR *all){
  int size=0;
  
  struct dirent *each;
  each = readdir(all);
  //printf("%d--\n", each->d_reclen);
  //if failuer, each is NULL, then the while doenst fire
  printf("ALL FILES:\n");
  while(each){
    size++;
    printf("%s  ---- ", each->d_name);
    char hold_type = each->d_type;
    
    if(hold_type == DT_DIR){
      printf("DIRECTORY\n");
    }
    
    if(hold_type == DT_REG){
      printf("FILE\n");
    } 

    each = readdir(all);
  }
  return size;//gives us total size
}

int print_files(DIR *all){
  int size=0;
  struct dirent *each;
  each = readdir(all);
  //if failuer, each is NULL, then the while doenst fire
  printf("REGULAR FILES:\n");
  while(each){
    size++;
    char hold_type = each->d_type;
    if(hold_type == DT_REG){
      printf("%s\n", each->d_name);
    } 
    each = readdir(all);
  }
  return size;
}

int print_dirs(DIR *all){
  int size=0;
  struct dirent *each;
  each = readdir(all);
  //if failuer, each is NULL, then the while doenst fire
  printf("DIRECTORIES:\n");
  while(each){
    size++;
    char hold_type = each->d_type;
    if(hold_type == DT_DIR){
      printf("%s\n", each->d_name);
    } 
    each = readdir(all);
  }
  return size;
}

int main(){
  DIR *hold_dir;
  hold_dir = opendir("test");
  int size = print_all(hold_dir);
  closedir(hold_dir);
  printf("----------------------------\n");

  hold_dir = opendir("test");
  print_dirs(hold_dir);
  closedir(hold_dir);
  printf("----------------------------\n");

  hold_dir = opendir("test");
  print_files(hold_dir);
  closedir(hold_dir);
  printf("----------------------------\n");

  hold_dir = opendir("test");
  int file_size = get_size(hold_dir);
  printf("THE TOTAL SIZE IS: %d BYTES\n",file_size);
  size_enator(file_size);
  closedir(hold_dir);
  printf("----------------------------\n");

  
  return 0;
}
  /*
  each = readdir(hold_dir);
  printf("%d--\n", each->d_reclen);
  //if failuer, each is NULL, then the while doenst fire
  while(each){
    printf("%s\n", each->d_name);
    char hold_type = each->d_type;
    
    if(hold_type == DT_DIR){
      printf("DIRECTORY\n");
    }
    
    if(hold_type == DT_REG){
      printf("FILE\n");
    } 

    each = readdir(hold_dir);
  }
  */

  
  /*
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
  */
