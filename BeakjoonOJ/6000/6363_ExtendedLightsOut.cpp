//
// Created by Acka on 4/23/16.
//

#include <stdio.h>
#include <memory.h>

int main()
{
    int dr[5] = {0, 0, 1, 0, -1}, dc[5] = {0, 1, 0, -1, 0};

    int tc, st = 1; for(scanf("%d", &tc); tc--;){
        bool target[5][6], on[5][6], ans[5][6];
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 6; j++)
                scanf("%d", &target[i][j]);

        for(int i = (1 << 6) - 1; 0 <= i; i--){
            memset(on, false, sizeof(on));
            memset(ans, false, sizeof(ans));
            for(int j = 0, b = 1; j < 6; j++, b <<= 1)
                if(i & b) {
                    ans[0][j] = true;
                    for (int k = 0; k < 5; k++) {
                        int nr = dr[k], nc = j + dc[k];
                        if(0 <= nr && 0 <= nc && nr < 5 && nc < 6)
                            on[nr][nc] = !on[nr][nc];
                    }
                }

            for(int r = 1; r < 5; r++)
                for (int c = 0; c < 6; c++) {
                    if (on[r - 1][c] != target[r - 1][c]) {
                        ans[r][c] = true;
                        for (int k = 0; k < 5; k++) {
                            int nr = r + dr[k], nc = c + dc[k];
                            if (0 <= nr && 0 <= nc && nr < 5 && nc < 6)
                                on[nr][nc] = !on[nr][nc];
                        }
                    }
                }

            bool psb = true;
            for(int c = 0; c < 6; c++)
                if(on[4][c] != target[4][c]){
                    psb = false; break;
                }

            if(psb) break;
        }

        printf("PUZZLE #%d\n", st++);
        for(int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++)
                printf("%d ", ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}

