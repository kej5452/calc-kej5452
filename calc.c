#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp_f = NULL;
	double (*fp) (int,int);
	int operand1, operand2;
	char operator = ' ';
	double result;
	int line = 0;

	fp_f = fopen("read.txt","r");
	if(fp_f!=NULL){
		fscanf(fp_f, "%d", &line);
	
		for(int i=0; i<line-1; i++) {
			fscanf(fp_f, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				fp = *add;
				result = fp(operand1, operand2);
				break;
				case '-':
				fp = *minus;
				result = fp(operand1, operand2);
				break;
				case '*':
				fp = *mul;
				result = fp(operand1, operand2);
				break;
				case '/':
				fp = *div;
				result = fp(operand1, operand2);
				break;
			}		
			printf("%d %c %d = %.6f\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

