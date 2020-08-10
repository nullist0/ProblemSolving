#include <cstdio>
long all[11] = {};

char robot[10][30];

int main(void){

    for(int i = 1; i < 11; i++)
        all[i] = (all[i-1] << 1) + 1;

    int T, N, flag;
    long ret, R, P, S, count = 0;

    scanf("%d", &T);

    while(T--){
        scanf("%d", &N);
        ret = all[N];
        flag = 0;

        for(int i = 0; i < N; i++)
            scanf("%s", robot[i]);
        
        for(int k = 0; robot[0][k]; k++){
            count = R = S = P = 0;
            for(int i = 0; i < N; i++){
                if((ret & (1 << i)) == 0)
                    continue;
                count ++;
                if(robot[i][k] == 'R')
                    R += (1 << i);
                else if(robot[i][k] == 'S')
                    S += (1 << i);
                else
                    P += (1 << i);
            }

            if(count == 1) break;

            if(S == 0 && R > 0 && P > 0) //R P
                ret ^= R;
            else if(R == 0 && S > 0 && P > 0) //S P
                ret ^= P;
            else if(P == 0 && R > 0 && S > 0)
                ret ^= S;

            // for(int j = 0; j < N; j++)
            //     printf("%d", ((ret >> j) & 1) > 0);
            // printf("\n");
        }

        for(int i = 0; i < N; i++){
            if(ret == (1 << i)){
                flag = printf("%d\n", i+1);
            }
        }
        if(flag == 0) printf("0\n");
    }

    return 0;
}