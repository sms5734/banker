#include <stdio.h>
#include <stdlib.h>
#define bool int
void main() {

    
    int all[5][4] = { 3,0,1,4,  2,2,1,0,  3,1,2,1, 0,5,1,0, 4,2,1,2};
    int max[5][4] = { 5,1,1,7, 3,2,1,1, 3,3,2,1, 4,6,1,2, 6,3,2,5 };
    int ava[4] = { 1,0,0,2 };
    int need[5][4], work[4], req[4];
    bool fin[5];
    int i, j, k, num, inp;
    int true = 1, false = 0;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            need[i][j] = max[i][j] - all[i][j];
        }
    }
    printf("      Allocation          Max          Need        Available \n");
    printf("\n");
    printf("      A  B  C  D     A  B  C  D     A  B  C  D    A  B  C  D  \n");
    for (i = 0; i < 5; i++) {
        printf("T[%d] ", i);
        for (j = 0; j < 4; j++) printf(" %d ", all[i][j]);
        printf("   ");
        for (j = 0; j < 4; j++) printf(" %d ", max[i][j]);
        printf("   ");
        for (j = 0; j < 4; j++) printf(" %d ", need[i][j]);
        printf("  ");
        if (i == 0)for (j = 0; j < 4; j++) printf(" %d ", ava[j]);
        printf("\n");
    }
    printf("자원을 추가적으로 할당받으려면 0번 :");
    scanf_s("%d", &inp);
    if (inp == 0) {
        printf("자원을 할당할 프로세스 번호");
        scanf_s("%d", &num);
        for (i = 0; i < 4; i++) {
            printf("%1c : ", ('A' + i));
            scanf_s("%d", &req[i]);
        }
        for (i = 0; i < 4; i++) {
            if (req[i] <= ava[i]) {
                ava[i] = ava[i] - req[i];
                all[num][i] = all[num][i] + req[i];
            }
            else {
                printf("자원이 부족하여 T[%d] 대기함 \n", num);
                exit(1);
            }
        }
    }

    printf("      Allocation         Max          Need        Available \n");
    printf("\n");
    printf("      A  B  C  D     A  B  C  D     A  B  C  D    A  B  C  D   \n");
    for (i = 0; i < 5; i++) {
        printf("T[%d] ", i);
        for (j = 0; j < 4; j++) printf(" %d ", all[i][j]);
        printf("   ");
        for (j = 0; j < 4; j++) printf(" %d ", max[i][j]);
        printf("   ");
        for (j = 0; j < 4; j++)
            printf(" %d ", abs(max[i][j] - all[i][j]));
        printf("  ");
        if (i == 0)for (j = 0; j < 4; j++) printf(" %d ", ava[j]);
        printf("\n");
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            need[i][j] = max[i][j] - all[i][j];
        }
    }
    for (i = 0; i < 4; i++)
        work[i] = ava[i];
    for (i = 0; i < 5; i++)  
        fin[i] = false;
    printf("\n");

    for (i = 0; i < 5; i++)  
        for (j = 0; j < 5; j++)  
            if (fin[j] == false)
                if (need[j][0] <= work[0] && need[j][1] <= work[1] && need[j][2] <= work[2]) { 
                    for (k = 0; k < 4; k++)
                        work[k] = work[k] + all[j][k];
                    fin[j] = true; 
                    printf("T[%d] -> ", j); 
                } 



    for (i = 0; i < 5; i++)
        if (fin[i] != true) {
            printf("안전상태가 아닙니다.\n");
            exit(1);
        }
    printf("안전상태\n");
}