void inverseSeqList(SeqList &L){
	for (int i=0,j=L.length-1; i<j; ++i,--j)
	{
		int temp=L.list[i];
		L.list[i]=L.list[j];
		L.list[j]=temp;
	}
}
