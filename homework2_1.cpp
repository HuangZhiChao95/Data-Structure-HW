struct SNode{
	int data;
	SNode *next;
	SNode():data(0),next(NULL){}
};



void mergeList(LinkList &HA,LinkList &HB,LinkList &HC){
	/*第一个表的指针*/
	SNode *fir=HA.head;
	fir=fir->next;
	/*第二个表的指针*/
	SNode *sec=HB.head;
	sec=sec->next;
	/*结果表的指针*/
	SNode *res=HC.head;
	/*存储临时需要保存的下一节点*/
	SNode *temp=0;
	while (fir!=0&&sec!=0)
	{
		if (fir.data<sec.data)
		{
			/*第一个链表节点较小，移动第一个*/
			temp=fir;
			fir=fir->next;
			HA.head->next=fir;
		}else{
			/*第二个链表节点较小，移动第二个*/
			temp=sec;
			sec=sec->next;
			HB.head->next=sec;
		}
		/*加临时节点添加到结果表中并移动结果表节点*/
		res->next=temp;
		res=res->next;
	}

	/*一个表到尽头后，将另一个表的所有节点加入*/
	
	while (fir!=0)
	{
		temp=fir;
		fir=fir->next;
		HA.head->next=fir;
		res->next=temp;
		res=res->next;
	}
	
	while (sec!=0)
	{
		temp=sec;
		sec=sec->next;
		HB.head->next=sec;
		res->next=temp;
		res=res->next;
	}
		
		
	
}
