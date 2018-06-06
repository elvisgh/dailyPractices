/**
 *
 * A linked list is given such that each node contains an additional random pointer which could point to any node 
 * in the list or null. Return a deep copy of the list.
 *
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return NULL;
         
        RandomListNode *node = head;
        std::queue<RandomListNode*> copyNodes;
        std::unordered_map<RandomListNode*, RandomListNode*> nodesM, randomM;
        while (node != NULL)
        {
            RandomListNode *copyNode = new RandomListNode(node->label);
             
            copyNodes.push(copyNode);
            nodesM.insert(std::pair<RandomListNode*, RandomListNode*>(node, copyNode));
            randomM.insert(std::pair<RandomListNode*, RandomListNode*>(node, node->random));
             
            node = node->next;
        }
         
        RandomListNode *p = copyNodes.front();
        RandomListNode *n = p;
        copyNodes.pop();
        while(copyNodes.size())
        {
            RandomListNode *q = copyNodes.front();
            copyNodes.pop();
             
            p->next = q;
            p = q;
        }
        p->next = NULL;
         
        for (std::unordered_map<RandomListNode*, RandomListNode*>::iterator nIt = nodesM.begin();
             nIt != nodesM.end(); ++nIt)
        {
            std::unordered_map<RandomListNode*, RandomListNode*>::iterator rIt;
            rIt = randomM.find(nIt->first);
            if (rIt != randomM.end())
            {
                if (rIt->second == NULL)
                {
                    nIt->second->random = NULL;
                }
                else
                {
                    std::unordered_map<RandomListNode*, RandomListNode*>::iterator nIter;
                    nIter = nodesM.find(rIt->second);
                    if (nIter != nodesM.end())
                    {
                        nIt->second->random = nIter->second;
                    }
                }
            }
        }    
        //return nodesM.begin()->second;
        return n;
    }
};