UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
    
    if(!node)
        return NULL;
    
    UndirectedGraphNode *root = NULL;
    queue<UndirectedGraphNode*> qu;
    
    qu.push(node);
    
    root = new UndirectedGraphNode(node->label);
    mp.insert(make_pair(node, root));
    
    while (!qu.empty())
    {
        UndirectedGraphNode *t = NULL;
        t = qu.front();
        qu.pop();
        
        UndirectedGraphNode *pt = NULL;
        pt = mp.find(t)->second;
                
        
        for (int i = 0; i < t->neighbors.size(); i++)
        {
            if (mp.find(t->neighbors[i]) == mp.end())
            {
                UndirectedGraphNode *n = new UndirectedGraphNode (t->neighbors[i]->label);
                mp.insert(make_pair(t->neighbors[i],n));
                
                
                pt->neighbors.push_back(n);
                
                qu.push(t->neighbors[i]);
            }
            else
            {
                UndirectedGraphNode *p = NULL;
                p = mp.find(t->neighbors[i])->second;
                
                pt->neighbors.push_back(p);
            }
        }
    }
    
    return root;

}
