#include "apc.h"
#include <stdlib.h>
#include <stdio.h>
int create_operands( char *opnd , Dlist **head , Dlist **tail ) 
{
    int i = 0 ;
    while ( opnd[i]  != '\0' )
			{
				char buffer[2] ;
				buffer[0] = opnd[i] ;
				buffer[1] = '\0' ;
				Dlist *new = malloc( sizeof(Dlist)) ;
				if ( new == NULL )
					return FAILURE ;
				new->data = atoi( buffer ) ;
				new->prev = NULL ;
				new->next = NULL ;

				if ( *head == NULL )
				{
					*head = new ;
					*tail = new ;
				}
				else 
				{
					(*tail)->next = new ;
					new->prev = *tail ;
					*tail = new ;
				}
				i++ ;
			}
            return SUCCESS ;
}

void print_list(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    printf("Head -> ");
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
		    //if (head)
		        //printf("> ");
	    }
    	printf(" Tail\n");
    }
}

int create_result_node( Dlist **headR , Dlist **tailR , data_t data )  // insert_at_first 
{
	Dlist *new = malloc(sizeof(Dlist)) ;
		if ( new == NULL )
			return FAILURE ;
		new->data = data ;
		new->prev = NULL ;
		new->next = NULL ;
		
		if ( *headR == NULL )
		{
			*headR = new ;
			*tailR = new ;
			return SUCCESS ;
		}
		else
		{
			(*headR)->prev  = new ;
			new->next = *headR ;
			*headR = new ;
			return SUCCESS ;
		}
		return FAILURE ;
}

int remove_Zeros( Dlist **headR , Dlist **tailR )
{
	if ( *headR == NULL )
		return FAILURE ;
	
	Dlist *temp = *headR ;

	while ( temp->data == 0 )
	{
		*headR = temp->next ;
		(*headR)->prev = NULL ;
		free( temp ) ;
		temp = *headR ;
	}
	return SUCCESS ;
}

int add_zero_at_last(  Dlist **head , Dlist **tail  )
{
	
    Dlist *new = malloc( sizeof(Dlist)) ;
    if ( new == NULL )
        return FAILURE ;
    new->data = 0 ;
    new->prev = NULL ;
    new->next = NULL ;

    if ( *head == NULL )
    {
        *head = new ;
        *tail = new ;
        return SUCCESS ;
    }
    
    (*tail)->next = new ;
    new->prev = *tail ;
    *tail = new ;
    return SUCCESS ;
}

int empty_list(  Dlist **head , Dlist **tail )
{
	if (*head == NULL) 
    	return FAILURE; 

    Dlist *temp = *head;  

    while (temp != NULL) 
	{
    	Dlist *next_node = temp->next;  
    	free(temp);  
    	temp = next_node; 
    }

	*head = NULL;  
	*tail = NULL;  
	return SUCCESS;
}


int finding_the_largest_number( Dlist **head1 , Dlist **tail1 , Dlist **head2 , Dlist **tail2 ) 
{
	// Find the size of the two lists 
	int size1 = 0 ;
	int size2 = 0 ;

	Dlist *temp1 = *head1 ;
	while ( temp1 != NULL )
	{
		size1++ ;
		temp1 = temp1->next ;
	}

	Dlist *temp2 = *head2 ;
	while ( temp2 != NULL )
	{
		size2++ ;
		temp2 = temp2->next ; 
	}
	
	if ( size1 > size2 )
	{
		return SUCCESS ;
	}

	if ( size2 > size1 )
	{
		return FAILURE ;
	}

	temp1 = *head1 ;
	temp2 = *head2 ;

	while (temp1 != NULL && temp2 != NULL) 
    {
        if (temp1->data > temp2->data) 
        {
            return SUCCESS;
        }
        else if (temp1->data < temp2->data) 
        {
            return FAILURE;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return EQUAL;
}
