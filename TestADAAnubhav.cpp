Build_skiplist( linked_list* head, linked list* sl, int length)
{
	sl->next=head;
	linked_list* Temp=head;
	int index_length=lg(length);     //the indices height should not be more than lg(n)
	while(indices_length-->0){
        sl=sl->indices;
        Linked_list* sl_temp=sl;
        while(Temp!=NULL){
            int val=Random(0,1);
            if(val){
                int i=0;
                while(i++<indices_length){
                    temp=temp->indices;
                }
                sl_temp->next=temp->indices;
                sl_temp=sl_temp->next;					
            }
            temp=temp->next;
        }
    }
}
