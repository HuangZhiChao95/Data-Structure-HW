struct SNode{
	int data;
	SNode *next;
	SNode():data(0),next(NULL){}
};


//带表头版
void inverseLinkList(LinkList &HL){
	
	SNode *curr=HL.head;//当前节点
	SNode *pre=HL.head;//当前节点的上一节点
	
	//当节点数为0时，不同倒转
	if (curr->next==0)
	{
		return;
	}
	curr=curr->next;
	
	//倒转链表
	while (curr!=0)
	{
		SNode *temp=curr;
		curr=curr->next;
		temp->next=pre;
		pre=temp;
	}
	
	//调整表头顺序
	HL.head->next->next=0;
	HL.head->next=pre;
}

//不带表头版
void inverseLinkList(LinkList &HL){
	
	SNode *curr=HL.head;//当前节点
	SNode *pre=HL.head;//当前节点的上一节点
	
	//当节点数为1时，不同倒转
	if (curr&&curr->next==0)
	{
		return;
	}
	curr=curr->next;
	
	//倒转链表
	while (curr!=0)
	{
		SNode *temp=curr;
		curr=curr->next;
		temp->next=pre;
		pre=temp;
	}
	
}
