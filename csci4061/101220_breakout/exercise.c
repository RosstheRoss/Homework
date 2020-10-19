#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

int numOfEntries(char* path) {
    int entries = 0;
    while (readdir(path) != NULL) {
        entries++;
    } return entries;
}

int main(int argc, char** argv){
    if (argc < 2) {
        printf("Pass the path as an argument to the program");
        exit(1);
    }
    char* path = argv[1];

    DIR* dir = opendir(path);
    if(dir==NULL){
        printf("The path passed is invalid");
        return -1;
    }
    struct dirent* entry;
    DIR* current = dir;

while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == "DT_DIR"){
            printf("Directory: %s\n", entry->d_name);
            printf("    Entries: %d\n", numOfEntries(entry));
        } else if (entry->d_type == "DT_REG") {
            printf("Regular File: %s\n", entry->d_name);
            printf("    Owner: %d\n");
            printf("    Size: %f\n");
        } else {
            printf("%s\n", entry -> d_name);
        }
    }   
    /*
        Iterate through the elements in argv[1]
        Refer the ls example in slides if you have any doubts
    */
    
    closedir(dir);
    return 0;
}