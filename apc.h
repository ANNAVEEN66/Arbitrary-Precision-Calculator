#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1
#define EQUAL -2

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR , Dlist **tailR ) ;
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR , Dlist **tailR , int argc , char *argv[]) ;
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR , Dlist **tailR , char *argv[] ) ;
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR , Dlist **tailR , int argc , char *argv[] ) ;
int create_operands( char *opnd , Dlist **head , Dlist **tail ) ;
void print_list(Dlist *head) ;
int create_result_node( Dlist **headR , Dlist **tailR , data_t data ) ;
int remove_Zeros( Dlist **headR , Dlist **tailR ) ;
int add_zero_at_last(  Dlist **headR , Dlist **tailR  ) ;
int empty_list(  Dlist **head , Dlist **tail ) ;
int finding_the_largest_number ( Dlist **head1 , Dlist **tail1 , Dlist **head2 , Dlist **tail2 ) ;
#endif
