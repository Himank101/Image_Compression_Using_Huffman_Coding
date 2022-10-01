#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct djdj //USE IT: the node structure
{
	int intensity;
	int frequency;
	struct djdj* next;
	struct djdj* left;
	struct djdj* right;
} node;

//creates a newnode
//NOTE: you can copy paste this fxn n change the arguments to use it in you favour
node* newNode(int d, int p) 
{
	node* temp = (node*)malloc(sizeof(node));
	temp->intensity = d;
	temp->frequency = p;
	temp->next = NULL;
	temp->left = NULL;
	temp->right= NULL;
	return temp;
}

//returns intensity of 1st node
int peek(node** head) 
{
	return (*head)->intensity;
}

//USE IT: the universal dequeue function 
void dequeue(node** head)
{
	node* temp = *head;
	(*head) = (*head)->next;
	free(temp);
}
void make_node_huffman(node** head, node** parent){
	node* temp = *head;
	(*head) = (*head)->next;
	temp->next = *parent;

}

void eq(node** head, int d, int p)//the enqueue function you shouldnt use. dont waste ur time on this
{
	node* start = (*head);
	node* temp = newNode(d, p);

	
	if ((*head)->frequency > p)
	{
		
		temp->next = *head;
		(*head) = temp;
	}
	else
	{
		
		while (start->next != NULL &&
			start->next->frequency < p)
		{
			start = start->next;
		}

		temp->next = start->next;
		start->next = temp;
	}
	printf("enqueued %d at %d priority", start->intensity, start->frequency);
}

//USE THIS: the universal enqueue function
void enqueue(node **head, node **temp)
{
	node* start = (*head);

	if ((*head)->frequency > (*temp)->frequency)
	{
		
		(*temp)->next = *head;
		(*head) = *temp;
	}
	else
	{
		
		while (start->next != NULL && start->next->frequency < (*temp)->frequency)
		{
			start = start->next;
		}

		(*temp)->next = start->next;
		start->next =(*temp);
	}
	printf("enqueued %d at %d priority", start->intensity, start->frequency);
}

int isEmpty(node** head)// to  check if queue is empty. we dont need this
{
	return (*head) == NULL;
}

void display(node** head)// shows your entire queue. you wont need this
{
	while (!isEmpty(head)){
		node *p= *head;
		if(p->next != NULL){
			printf("%d ", peek(&p));
			*p=*p->next;
		}
	}
}

void huffman_display(node** root){
	node* start = (*root);
	printf("\n%d\n", start->frequency);
	huffman_display(&start->left);
	printf("left above");
	huffman_display(&start->right);
	printf("right above");
	printf("Hehe");
}
void encode(node* root,int bin[] ,int index){
	
	int i, count;
		if(root->left == NULL ){
			//if(root->intensity != 300){
				printf("\n%d\t%d ",root->intensity, root->frequency);
				// printf("%s\n", bin);
				for(i=0;i<index;i++){
					printf("%d", bin[i]);
				}
		// }
		}
			
		if(root->left){
		bin[index] = 0;
		printf("OWOi%d%d%d", bin[0], bin[1], bin[2]);
		encode(root->left, bin, index+1);
		printf("OWOf%d%d%d", bin[0], bin[1], bin[2]);
		}
		if(root->right){
		bin[index] = 1;
		printf("UWUi%d%d%d", bin[0], bin[1], bin[2]);
		encode(root->right, bin, index+1);
		printf("UWUf%d%d%d", bin[0], bin[1], bin[2]);
		}
	
}


void huffman(node** head)
{
	node* temp;
	while((*head)->next != NULL){
		temp = newNode(300,(*head)->frequency + (*head)->next->frequency);
	    temp->left= *head;
        temp->right=(*head)->next;
        make_node_huffman(head, &temp);
		if((*head)->next == NULL){	
			(*head)->next = temp;
			*head = temp;

		printf("\nlast node this is");
		}
		else{
			make_node_huffman(head, &temp);
			enqueue(head, &temp);
			printf("\nNewNode made %d", temp->frequency);
		}
		
		
    }
			printf("\ntree completed\n");
}

int main()
{

	
	node* pq *a;
	int sizeinta,i;
	int inta[16]={0,1,2,2,1,3,6,9,8,7,8,9,8,5,6,1 };
	sizeinta=sizeof(inta)/sizeof(inta[0]);
	int freq[256];
	
	for(int i=0;i<10;i++)
	{	int count=0;
		
		for(int j=0;j<sizeinta;j++)
		{
			if(i==inta[j])
				count++;
		}
		freq[i]=count;
		//printf("%d %d\n",freq[i],i);
	}
	//printf("frequency array created");
	//int sizefreq = sizeof(freq)/sizeof(freq[0]);
	
	for(i=0;i<10;i++)
	{
		if(freq[i]!=0)
		{
			*a = newNode()
			eq(&pq,i,freq[i]);
		}
		display(&pq);

	}

	/*int arr[5] = {'\0', '\0', '\0', '\0', '\0'};
	node* a,*b,*c,*d;
	node* pq = newNode(1, 1);
	a = newNode (2, 2);
	enqueue(&pq,&a);
	b = newNode (3, 3);
	enqueue(&pq,&b);
	c = newNode(0, 0);
	enqueue(&pq,&c);
	// display(&pq);
	huffman(&pq);
	printf("running?");
	encode(pq, arr, 0);
*/
	return 0;
}