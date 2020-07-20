#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    struct filedata {
        int ID;
        int gender;
        double height;
    }sample;

int main(void){

    double height;
    int ID,gender;
    char fname1[FILENAME_MAX],fname2[FILENAME_MAX];
    char buf[256];
    int i=0,k=0,search_id;
    FILE* fp1;
    FILE* fp2;
    struct filedata sample[14] ;


    printf("input the filename1 of sample:");
    fgets(fname1,sizeof(fname1),stdin);
    fname1[strlen(fname1)-1] = '\0';
    printf("the filename1 of sample: %s\n",fname1);

    fp1 = fopen(fname1,"r");
    if(fp1==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
        fgets(buf,sizeof(buf),fp1);     //fp1のファイルを一行進めておく。１行目のgender,height(cm)の分だけ。
        while(fgets(buf,sizeof(buf),fp1) != NULL){
        sscanf(buf,"%d,%lf",&gender,&height);
        sample[i].gender=gender;
        sample[i].height=height;

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
        sscanf(buf,"%d",&ID);
        sample[i].ID=ID;
        i++;
    }

    if(fclose(fp2) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("性別、身長、ID番号データのインプットが完了しました。\n<ID list>\n");
    for(i=0;i<14;i++){           //14個のIDを全て表示する。
        if((0 == i%5)&&(i != 0)){
            printf("\n");
        }
        printf("%d\t",sample[i].ID);
    }
    printf("\n");

    printf("探したいIDを入力してください。>>>");
    scanf("%d",&search_id);

    for(i=0;i<14;i++){
        if(search_id == sample[i].ID){
            printf("ID      >>>%d\n",sample[i].ID);
            if(1 == sample[i].gender){
                printf("gender  >>>male\nheight  >>>%.2f[cm]\n",sample[i].height);
            }else{
                printf("gender  >>>female\nheight  >>>%.2f[cm]\n",sample[i].height);
            }
        }else{
            k++;
        }
    }

    if(14 == k){
        printf("No data\n");
    }

    return 0;

}