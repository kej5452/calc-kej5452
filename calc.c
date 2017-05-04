#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp_f = NULL;
	double (*fp) (int,int);
	int operand1, operand2;
	char operator = ' ';
	int result, line = 0;

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=0; i<line; i++) {
			fscanf(fp_f, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				fp = add;
				result = fp(operand1, operator);
				break;
				case '-':
				fp = minus;
				result = fp(operand1, operator);
				break;
				case '*':
				fp = mul;
				result = fp(operand1, operator);
				case '/':
				fp = div;
				result = fp(operand1, operator);
				break;
			}		
			printf("%d %c %d = %d\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

