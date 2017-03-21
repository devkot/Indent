#include <stdio.h>
																		/* Program used to beautifully indent another C type program */
int main(void){
	
	int ch, tab_counter=0, i,j, line_changed=0, flag=0,counter=0; 		/* flag: 1 when we have found space, 0 when parsing another character */
	ch = getchar();														
	while ( ch != EOF){													
				if ( (ch == '\n') || (ch =='\t')){						/* Line change or tab */
					ch = getchar();
					continue;
					flag = 0;
				}
				if ( (ch != '}') && (line_changed==1)){					/* Close bracket in another line */
					putchar('\t');
					flag = 0;
				}
				if ( ch == '{'){										/* Prints bracket in as many tabs needed */
					putchar('\n');
					for(j=0; j<tab_counter; j++){
						putchar('\t');
					}
					putchar('{');
					tab_counter++;
					putchar('\n');
					for ( i=0; i <tab_counter;i++){						/* Prints white space characters */
						putchar('\t');
					}
					ch = getchar();
					while (( ch == ' ')||(ch == '\n')||(ch=='\t')){		/* Removes excess spaces */
						ch= getchar();
					}
					flag = 1;
				}
				else if (ch == '}'){								
					tab_counter--;
					putchar('}');
					putchar('\n');
					for (i=0; i<(tab_counter-1);i++){					/* After ; or } so it allows } which will be one /t pio before that */
						putchar('\t');
					}
					ch = getchar();
					while (( ch == ' ')||(ch == '\n')||(ch=='\t')){
						ch= getchar();
					}
					flag = 1;
				}
				else if(ch==';'){
					putchar(';');
					if ( counter ==0){									/* For when it is between parentheses since that is the only time we can see ; inbetween () */
						putchar('\n');
						for ( i=0; i <(tab_counter-1);i++){					/* After ; or } so it allows } which will be one /t pio before that */
							putchar('\t');
						}
						ch = getchar();
						while (( ch == ' ')||(ch == '\n')||(ch=='\t')){
							ch= getchar();
						}
						flag = 1;
						line_changed=1;
					}
					else
						flag = 0;
				}
				else if(ch == '\'' ){									/* When meeting ' prints exactly what is in between quotation marks and then closes */
					putchar(ch);
					ch =getchar();
					if ( ch == '\\'){
						putchar(ch);
						ch = getchar();
						putchar(ch);									/* In case a quotation mark is muted using a slash */
						ch = getchar();
					}
					while( ch != '\''){	
						putchar(ch);
						ch = getchar();
					}	
					putchar(ch);
					flag = 0;
				}
				else if(ch == '\"' ){									/* When meeting '' prints exactly what is in between quotation marks and then closes */
					putchar(ch);
					ch =getchar();
					if ( ch == '\\'){
						putchar(ch);
						ch = getchar();
						putchar(ch);
						ch = getchar();
					}
					while( ch != '\"'){	
						putchar(ch);
						ch = getchar();
						if ( ch == '\\'){								/* Prevents quotation mark mistakes */
							putchar(ch);
							ch = getchar();
							putchar(ch);
							ch = getchar();
						}
					}
					putchar(ch);
					flag = 0;
				}
				else if ( ch == '#'){									/* Used to filter define */
					putchar(ch);
					while ( ch != '\n'){
						ch = getchar();
						putchar(ch);
					}
					flag = 0;
				}
				else if ( ch == ' '){									/* When there are many blank spaces it only outputs one when it meets a normal character */
					putchar(ch);
					ch = getchar();
						while (( ch == ' ')||(ch == '\n')||(ch=='\t')){
							ch = getchar();
							
						}
					flag = 1;											/* flag is 1 because we found a space */
				}
				else if ( ch == '('){									/* used for For statements parentheses */
					putchar(ch);
					counter++;
					flag=0;
				}														
				else if ( ch == ')'){									/* used for For statements parentheses */
					putchar(ch);
					counter--;
					flag = 0;
				}
				else {
					putchar(ch);
					line_changed=0;
					flag = 0;
				}
				if ( flag ==0 )											/* when we haven't found a space yet */
					ch = getchar();	
	}
	
}
