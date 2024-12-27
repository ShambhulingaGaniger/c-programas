tree* smallEle(tree* root){
	if(!root)
	return NULL;
	if(!root->l)
	return root;
    else return smallEle(root->l);
}
tree* largeEle(tree* root){
	if(!root)
	return NULL;
	if(!root->r)
	return root;
    else return largeEle(root->r);
}

void _delete(tree *a,tree *b,tree *c){
	if(a->r==b)
	a->r=c;
    else a->l=c;
}
tree* removeNode(tree *root,int d){
	tree* parent,*small,*ps;
	tree* temp=searchKey(root,d);
	if(!temp)
		return NULL;
	parent=parentKey(root,NULL,d);
	if(!parent){
		small=smallEle(root->r);
		if(!small)
		return root->l;
		ps=parentKey(root,NULL,small->data);
		if(ps==root)
		ps->r=small->r;
		else ps->l=NULL;
		small->l=root->l;
		small->r=root->r;
		return small;
	}
	else if((!temp->l)&&(!temp->r)){
	_delete(parent,temp,NULL);
	}
	else if(!temp->r){
	_delete(parent,temp,temp->l);
	}
	else if(!temp->l){
	_delete(parent,temp,temp->r);
	}
	else{
		small=smallEle(temp->r);
		ps=parentKey(root,NULL,small->data);
		if(ps==temp)
		temp->r=small->r;
		else ps->l=NULL;
		small->r=temp->r;
		small->l=temp->l;
		_delete(parent,temp,small);
	}
	return root;
}

