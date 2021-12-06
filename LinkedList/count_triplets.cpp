int countTriplets(struct Node* head, int x) 
{ 
    unordered_map<int,bool>map;
    Node* curr = head;
    while(curr){
        map[curr->data] = true;
        curr = curr->next;
    }
    
    curr = head;
    int count = 0;
    while(curr){
        int val1 = curr->data;
        Node* pointer = curr->next;
        while(pointer){
            int val2 = pointer->data;
            int target = (x - val1 - val2);
            
            if(map.count(target) and target != val1 and target != val2 and target > val1 and target >val2)
            count++;
                
            pointer = pointer->next;
        }
        curr = curr->next;
    }
    return count;
    
    // code here.
} 