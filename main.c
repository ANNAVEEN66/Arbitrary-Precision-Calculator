/*
*Title		: main function(Driver function)
Description	: This function is used as the driver function for the all the functions
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "apc.h"

int main( int argc , char *argv[] )
{
	/* Declare the pointers */
	Dlist *head1 = NULL , *tail1 = NULL , *head2 = NULL , *tail2 = NULL , *headR = NULL , *tailR = NULL ;
	char option , operator;
		/* Code for reading the inputs */
		if ( argc == 4 )
		{
			operator = *(argv[2])  ; // Reading the operator

			// converting the inputs to linkedlists
			char * opnd1 =  argv[1]  ;
			char * opnd2 = argv[3] ;	
			if ( ( create_operands( opnd1 , &head1 , &tail1 ) == SUCCESS ) && ( create_operands( opnd2 , &head2 , &tail2 ) == SUCCESS ) ) 
			{
				printf("Operator 1 : ") ;
				print_list( head1 ) ;
				printf("\n") ;
				printf("Operator 2 : ") ;
				print_list( head2 ) ;
				printf("\n") ;
			}
		}
		else
		{
			printf("Invalid arguments\n") ;
 			return -1 ;
		}
		switch (operator)
		{
			case '+':
				/* call the function to perform the addition operation */
				if ( addition( &head1, &tail1, &head2, &tail2, &headR , &tailR ) == SUCCESS ) 
				{
					printf("Result : ") ;
					print_list( headR ) ;
					printf("\n") ;
				}
				break;
			case '-':	
				/* call the function to perform the subtraction operation */
				if( subtraction( &head1 , &tail1 , &head2 , &tail2 , &headR , &tailR , argc , argv ) == SUCCESS ) 
				{
					printf("Result : ") ;
					print_list( headR ) ;
					printf("\n") ;
				}
				break;
			case 'x':	
				/* call the function to perform the multiplication operation */
				if ( multiplication( &head1, &tail1, &head2, &tail2, &headR , &tailR , argv ) == SUCCESS )
				{
					printf("Result : ") ;
					print_list( headR ) ;
					printf("\n") ;
				} 
				break;
			case '/':	
				/* call the function to perform the division operation */
				if( division( &head1, &tail1, &head2, &tail2, &headR , &tailR , argc , argv  ) == SUCCESS ) 
				{
					if ( headR == NULL )
					{
						return SUCCESS ;
					}
					else
					{
						printf("Result : ") ;
						print_list( headR ) ; 
						printf("\n") ;
					}
				}
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}

	return 0;
}

