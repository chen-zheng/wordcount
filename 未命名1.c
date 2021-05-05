#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int countChar(FILE *f);
int countWord(FILE *f);

int main(int argc, char *argv[]){
    FILE *f;
    int cnt;
    char c;

    if(argc == 3){  //��������Ϊ3
        f = fopen(argv[2], "r"); //argv[2]��ʾ�ڶ���������Ҳ�����ļ�, "r"��ʾֻ��
        if(f == NULL){      //��ʧ��
            printf("Failed to open the file!!!");
            exit(1);
        }

        //����argv[1]�б���Ĳ�����ȷ��Ҫ��ɵĹ���
        if(!strcmp(argv[1], "-c")){   //ͳ���ַ�����
            cnt = countChar(f);
            printf("The number of charactor: %d\n", cnt);
        }else if(!strcmp(argv[1], "-w")){   //ͳ�Ƶ��ʸ���
            cnt = countWord(f);
            printf("The number of word: %d\n", cnt);
        }else{
            printf("����Ĳ�������");
        }
    }
}

int countChar(FILE *f){
    int cnt = 0;   //���ڼ�¼�ַ�����
    char c; //���ڱ��浱ǰ�ַ�

    while( (c = fgetc(f)) != EOF){   //while�е��ж���������ж��Ƿ�����ļ���β
        cnt++;
    }

    rewind(f);    //���ļ�ָ��ָ���ļ���ͷ��������һ��ʹ��
    return cnt;
}

int countWord(FILE *f){
    int cnt = 0;   //����ͳ�Ƶ��ʸ���
    char c;

    while(feof(f) == 0){    //�ж��Ƿ񵽴��ļ�ĩβ
        c = fgetc(f);    //��c�����浱ǰ���ַ�
        if( c == ' ' || c == ','){
            cnt++;
        }
    }
    cnt++;   //����ĩβ�ĵ���

    rewind(f);    //���ļ�ָ��ָ���ļ���ͷ
    return cnt;
}
