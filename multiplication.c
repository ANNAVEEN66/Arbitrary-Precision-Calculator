/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR , Dlist **tailR , char *argv[] )
{
	/* Definition goes here */
	int data ;
	int carry = 0 ;
	int beforecarry ; 
	int zerocount = 0 ;
	int flag = 0 ;
	int i ;
	
	// Temp variables  
	Dlist *temp1 = *tail1 ;
	Dlist *temp2 = *tail2 ;

	// Temp variable for storing result
	Dlist *headres1 = NULL , *tailres1 = NULL  ;
	Dlist *headres2 = NULL , *tailres2 = NULL  ;
	Dlist *headres3 = NULL , *tailres3 = NULL  ;
			
	if ( ( strlen(argv[3]) ) > ( strlen(argv[1]) )  )
	{
		//printf("Swappe successfully\n") ;
		temp1 = *tail1 ;
		temp2 = *tail2 ;
	}
	// hear we Checking for zeroess 
	if ( *argv[3] == '0' || *argv[1] == '0' )
	{
		data = 0 ;
		create_result_node( headR , tailR , data ) ;
		//print_list ( *headR ) ;
		return SUCCESS ;
	}
	while ( ( temp2 != NULL ) )
	{
		temp1 = *tail1 ;
		headres1 = NULL ;
		tailres1 = NULL ;
		carry = 0 ;
		while ( temp1 != NULL )
		{
			data = ( ( temp1->data ) * ( temp2->data ) ) + carry ;
				beforecarry = data % 10 ;
				carry = data / 10 ;
				create_result_node ( &headres1 , &tailres1 , beforecarry )  ;
			temp1 = temp1->prev ;	
		}
		if ( carry )
		{
			create_result_node (  &headres1 , &tailres1 , carry )  ;
			carry = 0 ;
 		}
		// Ading Zeroes
		for ( i = 0 ; i < zerocount ; i++ )
		{
			 add_zero_at_last( &headres1 , &tailres1 )  ;
		}
		zerocount++ ;
		//printf("HEADRES1 is \n" ) ;
		//print_list( headres1 ) ;
		if ( flag == 0 )
		{
			// SWAPPING
			headres3 = headres1 ;
			tailres3 = tailres1 ;
			//empty_list( &headres1 , &tailres1 ) ;
			flag = 1;
		}
		else
		{
			addition( &headres3 , &tailres3 , &headres1 , &tailres1 , &headres2 , &tailres2 ) ;
			headres3 = headres2 ; 
			tailres3 = tailres2 ;
			//empty_list( &headres1 , &tailres1 ) ;
			headres2 = NULL ;
			tailres2 = NULL ;
			//empty_list( &headres2 , &tailres2 ) ;
			//printf("IN ELSE PART \n") ;
			//print_list ( headres3 ) ;
		}
		
		temp2 = temp2->prev ;
	}
	*headR = headres3 ;
	*tailR = tailres3 ;
	//print_list( headres3 ) ;
 	if ( remove_Zeros ( headR , tailR ) == SUCCESS ) ;
	//print_list ( *headR ) ;
}


