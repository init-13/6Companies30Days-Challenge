/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
/*
store the map prefixsum to ListNode. 
whenever the seen sum is encountered attach the startingNode to currentNode->next
remove all prefixsums from the map from starting Node->next to current node */
    void update(unordered_map<int,ListNode*>& MP,ListNode* start,ListNode* end, int sumT){

        while( start!=end){ 
            sumT+=start->val;
            MP.erase(sumT);
            start = start->next;
        }
        ;
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> MP;
        ListNode* trav  = head;
        int sumT = 0;

        while(trav!=NULL){
            sumT+=trav->val;


            if(sumT==0) {head = trav->next; MP.clear();}

            if(MP.find(sumT)!=MP.end()){
                //cout<<MP[sumT]->val<<"& ";
                 update(MP,MP[sumT]->next,trav,sumT);
                    MP[sumT]->next = trav->next ;
                   
            }

            else MP.insert({sumT,trav});
                
            

            trav = trav->next;
        }
        return head;
    }
};