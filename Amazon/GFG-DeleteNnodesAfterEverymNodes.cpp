class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        // delete n nodes after every m nodes
        Node* curr=head;
        while(curr){
            for(int j=1;j<m&&curr;j++){
                curr=curr->next;
            }
            if(curr==NULL)break;
            temp=curr->next;
            for(int j=0;j<n&&temp;j++)
                temp=temp->next;
            curr->next=temp;
            curr=temp;
        }
        
        return head;
    }
};