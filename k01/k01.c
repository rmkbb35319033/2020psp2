#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int N);
extern double var_online(double val, double ave, double square_ave,int N);
int gen;
int i=0;
double AVE=0,AVE_BF=0,AVE_2=0,AVE_2BF,VAL=0,UVAR=0;
int main(void)
{
    double val,var;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
  
    while(fgets(buf,sizeof(buf),fp) != NULL){
        i++;
        sscanf(buf," %lf",&val);
        AVE_BF=AVE;//VALを求める際に、(N-1)番目の平均を使うためこの位置で(N-1)番目の平均を保存しておく。
        AVE=ave_online(val,AVE,i);//平均を求める
        AVE_2BF=AVE_2;//VALを求める際に、(N-1)番目の２乗の平均を使うためこの位置で(N-1)番目の２乗の平均を保存しておく。
        AVE_2=ave_online(val*val,AVE_2,i);//２乗の平均を求める。
        var=var_online(val,AVE_BF,AVE_2BF,i);//分散を求める
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("AVE=%4.1lf\n",AVE);
    printf("VAL=%4.1lf\n",var);

    UVAR=(double)i/(double)(i-1)*var;//不偏分散を求める。
    
    printf("est ave=%4.1lf\n",AVE);
    printf("UVAL=%4.1lf\n",UVAR);

    return 0;


}

double ave_online(double val,double ave,int N){
     double n= (double)N;//整数の割り算ができないので、double型にキャスト変換しておく。
    return((n-1)/n*ave+val/n);
}

double var_online(double val, double ave, double square_ave,int N){
    double n= (double)N;//整数の割り算ができないので、double型にキャスト変換しておく。
    return((n-1)/n*square_ave+(val*val)/n-pow(((n-1)/n*ave+val/n),2));
}