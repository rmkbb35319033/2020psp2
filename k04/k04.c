#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    struct filedata {
        int ID;
        int gender;
        double height;
    }sample[14];

int main(void){

    double height;
    int ID,gender;
    char fname1[FILENAME_MAX],fname2[FILENAME_MAX];
    char buf[256];
    int i=0;
    FILE* fp1;
    FILE* fp2;
    struct filedata ;


    printf("input the filename1 of sample:");
    fgets(fname1,sizeof(fname1),stdin);
    fname1[strlen(fname1)-1] = '\0';
    printf("the filename1 of sample: %s\n",fname1);

    fp1 = fopen(fname1,"r");
    if(fp1==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

        while(fgets(buf,sizeof(buf),fp1) != NULL){
        sscanf(buf,"%d,%lf",&gender,&height);
        sample.gender[i]=gender;
        sample.height[i]=height;

        i++;
    }

    if(fclose(fp1) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }


     printf("input the filename2 of IDs:");
    fgets(fname2,sizeof(fname2),stdin);
    fname2[strlen(fname2)-1] = '\0';
    printf("the filename2 of sample: %s\n",fname2);

    fp2 = fopen(fname2,"r");
    if(fp2==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

        i=0;

        while(fgets(buf,sizeof(buf),fp2) != NULL){
        sscanf(buf,"%ld",&ID);
        sample.ID[i]=ID;
        i++;
    }

    if(fclose(fp2) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("ID????????????????B>>>?i?????l??????Žˆ??????j\n");
 

    return 0;

}