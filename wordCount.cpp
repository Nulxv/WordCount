#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]){
    FILE *fis;
    int num = 0; //����
    
    if ((fis = fopen(argv[2], "r")) == NULL){
        	puts("Error!!!!\n");
        	return 0;
   	}
    if (argv[1][1] == 'w') {// ������
	    char sum[1023];
	    while (fscanf(fis, "%s", sum) != EOF){
	        num++;
	        for (int i = 1; i < strlen(sum) - 1; i++)
	            if (sum[i] == ',' && sum[i - 1] != ',' && sum[i + 1] != ',') 
	                num++;
	    }
	    printf("������=%d\n", num);
	}
    else if (argv[1][1] == 'c') {// �ַ���
        char ch;
        while ((ch = fgetc(fis)) != EOF) 
			num++;
        printf("�ַ���=%d", num);
    }
    fclose(fis);
    return 0;
}

