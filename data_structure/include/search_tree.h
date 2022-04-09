#ifndef _Tree_H
#define _Tree_H

struct TreeNode;

typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;
typedef char* ElementType;

SearchTree MakeEmpty(SearchTree T);

Position Find(ElementType x, SearchTree T);

Position FindMin(SearchTree T);

Position FindMax(SearchTree T);

SearchTree Insert(ElementType x, SearchTree T);

SearchTree Delete(ElementType x, SearchTree T);

ElementType Retrieve(Position p);

#endif
/*
Binary Search Tree.
Left Tree Node value is less than Root Node.
Right Tree Node is great than Root Node.
*/

struct TreeNode {
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};