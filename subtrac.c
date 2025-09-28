/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>
#include <string.h>


int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR , Dlist **tailR  , int argc , char *argv[] )
{
	/* Definition goes here */
	int data ;
	int borrow =  0 ;
	int flag = 0 ;
	Dlist *temp1 ;
	Dlist *temp2 ;

	// if the second argument is larger than first --> swap the lists
	if ( ( strlen(argv[3]) ) >  ( strlen(argv[1]) ) ) 
	{
		// SWAPPING 
		temp1 = *tail2 ;
		temp2 = *tail1 ;
		flag = 1 ; // flag set 
	}
	else if ( ( strlen(argv[3]) ) == ( strlen(argv[1]) ) )
	{
		if ( strcmp(argv[1] , argv[3]) ==  0 )
		{
			data = 0 ;
			create_result_node( headR , tailR , data ) ;
			//print_list( *headR ) ;
			return SUCCESS ;
		}
		else if ( strcmp(argv[1] , argv[3]) > 0 )
		{
			temp1 = *tail1 ;
			temp2 = *tail2 ;
		}
		else
		{
			// SWAPPING 
			temp1 = *tail2 ;
			temp2 = *tail1 ;
			flag = 1 ;  // flag set 
		}
	}
	else
	{
		temp1 = *tail1 ;
		temp2 = *tail2 ;
		//printf("Normal Test case \n") ;
	}

	
	while ( ( temp1 != NULL ) || ( temp2 != NULL )  )
	{
		if ( ( temp1 != NULL ) && ( temp2 != NULL ) )
		{	
			if ( ( temp1->data ) < (temp2->data) )
			{
				data = ( temp1->data ) + 10 - ( temp2->data ) - borrow  ;
				borrow = 1 ;
			}
			else
			{
				data = ( temp1->data ) - ( temp2->data ) - borrow  ;
				if ( data < 0 )
				{
					data = data + 10 ;
				}
				else
				{
					borrow = 0 ;
				}
			}
			if ( create_result_node( headR , tailR , data ) == SUCCESS ) ;
					//printf("DOne\n") ;
			// update the temp
			temp1 = temp1->prev ;
			temp2 = temp2->prev ;
		}
		else if ( ( temp1 != NULL ) && ( temp2 == NULL ) )
		{
				data = ( temp1->data ) - borrow  ;
				if ( data < 0 )
				{
					data = data + 10 ;
				}
				else
				{
					borrow = 0 ;
				}
			if ( create_result_node( headR , tailR , data ) == SUCCESS ) ;
			// updating the link 
			temp1 = temp1->prev ;
		}
		else if ( ( temp1 == NULL ) && ( temp2 != NULL ) )
		{
			data = ( temp2->data ) - borrow ;
			if ( data < 0 )
			{
				data = data + 10 ;
			}
			else
			{
				borrow = 0 ;
			}
			if ( create_result_node( headR , tailR , data ) == SUCCESS ) ;
			// updating the link 
			temp2 = temp2->prev ;
		}	
	}

	// Remove the Zeros 
	if ( remove_Zeros ( headR , tailR ) == SUCCESS ) ;
	// multiply with minus if the flag is set 
	if ( flag == 1 )
	{
		(*headR)->data = -(*headR)->data ; 
	}
	return SUCCESS ;
	// Print the result
	//print_list ( *headR ) ;
}

