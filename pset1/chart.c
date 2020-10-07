//chart program

#include <cc50.h>	//to use the cc50 functions
#include <stdio.h>
#include <stdlib.h>

//void printChart (int n);	//to use the

int
main(void)
{
	//ask the graph values to user

	printf("M receive F: ");
	int mf = GetInt();

	printf("F receive M: ");
	int fm = GetInt();

	printf("F receive F: ");
	int ff = GetInt();

	printf("M receive M: ");
	int mm = GetInt();

	//show the text introductin to graph
	printf("\nSo the bar graph: \n");

	//make the sum of mf+fm+ff+mm
	float sum = mf + fm + ff + mm;

	//multiplies the values of mf/fm/ff/mm by the total sum and multiply by 80
	//to MF
	printf("M - F: ");
	int Chart_1;
	printf ("%.2d: ", Chart_1 = ((80 * (mf / sum))));
	//make the graph based on chart value
	for(int i = 0 ; i < Chart_1 ; i ++)
                printf("#");

        printf("\n");

	//to FM
	printf("F - M: ");
	int Chart_2;
	printf ("%.2d: ", Chart_2 = ((80 * (fm / sum))));
	for(int i = 0 ; i < Chart_2 ; i ++)
                printf("#");

        printf("\n");

	//to FF
	printf("F - F: ");
	int Chart_3;
	printf ("%.2d: ", Chart_3 = ((80 * (ff / sum))));
	for(int i = 0 ; i < Chart_3 ; i ++)
                printf("#");

        printf("\n");

	//to MM
	printf("M - M: ");
	int Chart_4;
	printf ("%.2d: ", Chart_4 = ((80 * (mm / sum))));
	for(int i = 0 ; i < Chart_4 ; i ++)
                printf("#");

        printf("\n");

}
