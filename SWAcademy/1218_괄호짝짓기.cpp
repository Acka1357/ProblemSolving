#include <stdio.h>

char s[100001], mat[128], st[100001];

int main()
{
	mat[')'] = '(', mat[']'] = '[', mat['}'] = '{', mat['>'] = '<';

	for(int tc = 1; tc <= 10; tc++){
		int l; scanf("%d %s", &l, s);

		bool ans = true;
		int top = 0;
		for(int i = 0; i < l; i++){
			if(mat[s[i]]){
				if(top && st[top - 1] == mat[s[i]]) top--;
				else{
					ans = false;
					break;
				}
			}
			else st[top++] = s[i];
		}
		printf("#%d %d\n", tc, ans & !top);
	}

	return 0;
}