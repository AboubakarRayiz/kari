#include "../includes/core.h"
#include "../includes/sys/sys.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



char* getFlutterProjectName(){
    FILE *pubspec;
    char projectName[255];
    
    if(flutterProjetName == NULL){
        if( access("pubspec.yaml", F_OK) == -1){
            fprintf(stderr, "\nNo flutter project found\n");
            exit(EXIT_FAILURE);
        }
        pubspec = fopen("pubspec.yaml", "r");
        if(pubspec != NULL){
            fscanf(pubspec, "%s%s", projectName, projectName);
            printf("project name == %s\n", projectName);
            fclose(pubspec);
            flutterProjetName = (char*) malloc(sizeof(char)*strlen(projectName)+1);
            strcpy(flutterProjetName, projectName);
            return flutterProjetName;
        }
    }
    return flutterProjetName;
}

void  freeProjetName(){
    if(flutterProjetName != NULL)
        free(flutterProjetName);
}

int setDependencies(){
    
    char entry[255], c;
    FILE *pubspeck, *save;
    
    if(access("pubspec.yaml", F_OK) == 0){
        mv("pubspec.yaml", ".pubspec.yaml.save");
        pubspeck = fopen("pubspec.yaml", "w+");
        save = fopen(".pubspec.yaml.save", "r+");
        if(pubspeck != null && save != null){
            fseek(save, 0, SEEK_END);
            fprintf(save, "\n$$karee$$ ");
            fseek(save, 0, SEEK_SET);
            do{
                
                fscanf(save, "%s%c", entry, &c);
                if(strcmp(entry, "$$karee$$") == true){
                    break;
                }
                if(strcmp("sdk:", entry) == true)
                    fprintf(pubspeck, "    %s %c",entry, c);
                else
                    fprintf(pubspeck, "%s %c",entry, c);

                if(strcmp(entry, "dependencies:") == true){
                    fprintf(pubspeck, 
                        "    reflectable: any\n"
                        "    build_runner: any\n"
                        "    build: '>=0.12.0 <2.0.0'\n"  
                        "    source_gen: ^0.9.0\n"
                        "    view_reporter: \n" 
                        "        path: lib/core/view/\n"
                    );
                }
                if(strcmp(entry, "dev_dependencies:") == true){
                    fprintf(pubspeck, "    view_reporter_generator:\n"
                        "        path: lib/core/view/generator/\n"
                    );
                }
            }while(strcmp(entry, "$$karee$$") == true || rindex(entry, EOF) == null || c == EOF);
        }
    }
    return true;
  
}

