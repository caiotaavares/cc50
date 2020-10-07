
//teste

#include <stdio.h>
#include <stdlib.h>
#include <cc50.h>
#include <string.h>

int
main(void)
{
	string s = GetString();
	int n = GetInt();
	int num;
	for (int i = n ; n < strlen(s) ; i ++)
		num = s[i];
	printf("finish");
}
