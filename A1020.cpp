#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 100 + 10;

struct Node {
	int n;
	struct Node *leftChild;
	struct Node *rightChild;
};

Node *node[MAXN];

Node *trans( int *in, int *post, int len ) {
	if( len == 0 ) return NULL;
	Node *tmp = new Node();
	tmp->n = post[len - 1];
	int index = 0;
	for( index = 0; index < len; ++index ) {
		if( in[index] == post[len - 1] ) break;
	}
	tmp->leftChild = trans( in, post, index );
	tmp->rightChild = trans( in + index + 1, post + index, len - index - 1 );
	return tmp;
}

int inOrder[MAXN], postOrder[MAXN];

int main() {
	int n;
	scanf( "%d", &n );
	for( int i = 0; i < n; ++i ) scanf( "%d", postOrder + i );
	for( int i = 0; i < n; ++i ) scanf( "%d", inOrder + i );
	Node *root = trans( inOrder, postOrder, n );
	int mf, me; mf = me = 0;
	node[me++] = root; ++mf;
	if( root->leftChild ) node[me++] = root->leftChild; 
	if( root->rightChild ) node[me++] = root->rightChild;
	printf( "%d", root->n );
	while( mf < me ) {
		Node *tmp = node[mf++];
		printf( " %d", tmp->n );
		if( tmp->leftChild ) node[me++] = tmp->leftChild; 
		if( tmp->rightChild ) node[me++] = tmp->rightChild;
	}
	puts( "" );
	return 0;
}
