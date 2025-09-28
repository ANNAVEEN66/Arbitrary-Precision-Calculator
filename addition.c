/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
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

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR , Dlist **tailR )
{
	/* Definition goes here */
	// declaring operands 

	int data ;
	int carry = 0  ;
	int i = 0 ;
	int beforecarry ;
	//printf("The value of i is %d \n" , ++i ) ;
	Dlist *temp1 = *tail1  ;
	Dlist *temp2 = *tail2  ;
	
	//printf("temp1 of data = %d\n" , temp1->data ) ; 
	//printf("temp2 of data = %d\n" , temp2->data ) ;

	while ( ( temp1 != NULL ) || ( temp2 != NULL ) )
	{
		// printf("temp2 of data = %d\n" , temp1->data ) ; 
		if ( ( temp1 != NULL ) && ( temp2 != NULL )  )
		{
			data = (temp1->data)  + (temp2->data) + carry ;
			if ( data > 9 )
			{
				beforecarry = data % 10 ;
				carry = data / 10 ;
				// update beforecarry
				if ( create_result_node( headR , tailR , beforecarry ) == SUCCESS ) ;
			}
			else
			{
				if ( create_result_node( headR , tailR , data ) == SUCCESS ) ;
				// Update carry = 0  , if data is not greater than 9
				carry = 0 ;  
			}
			// Update the operand node to prev 
			temp1 = temp1->prev ;
			temp2 = temp2->prev ;
		}
		else if ( ( temp1 == NULL ) &&  ( temp2 != NULL ) )
		{
			data = carry + ( temp2->data ) ;	
			if ( data > 9 )
			{
				beforecarry = data % 10 ;
				carry = data / 10 ;
				// update beforecarry
				if ( create_result_node( headR , tailR , beforecarry ) == SUCCESS ) ;
					printf("DOne\n") ;
			}
			else
			{
				if ( create_result_node( headR , tailR , data ) == SUCCESS ) ;
				// Update carry = 0  , if data is not greater than 9
				carry = 0 ;  
			}
			// Update the operand node to prev 
			temp2 = temp2->prev ;		
		}
		else if ( ( temp1 != NULL ) && ( temp2 == NULL ) )
		{
			data = carry + ( temp1->data ) ;	
			if ( data > 9 )
			{
				beforecarry = data % 10 ;
				carry = data / 10 ;
				// update beforecarry
				if ( create_result_node( headR , tailR , beforecarry ) == SUCCESS ) ;
			}
			else
			{
				if ( create_result_node( headR , tailR , data ) == SUCCESS ) ;
				// Update carry = 0  , if data is not greater than 9
				carry = 0 ;  
			}
			// Update the operand node to prev 
			temp1 = temp1->prev ;
		}	
	}
	// Updating the carry at last
	if ( carry == 1 )
	{
		if ( create_result_node( headR , tailR , carry ) == SUCCESS ) ;
	}
	// Remove leading Zeroes
	remove_Zeros( headR , tailR ) ;
	return SUCCESS ;
	print_list ( *headR ) ;
}

