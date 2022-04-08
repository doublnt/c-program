#include <stddef.h>
#include <stdlib.h>

#include "search_tree.h"

SearchTree MakeEmpty(SearchTree T) {
	if(NULL != T) {
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);

		free(T);
	}

	return NULL;
}

Position Find(ElementType x, SearchTree T) {
	if(NULL == T) {
		return NULL;
	}

	if(T->Element < x) {
		return Find(x, T->Left);
	} else if(T->Element > x) {
		return Find(x, T->Right);
	} else {
		return T;
	}
}

Position FindMin(SearchTree T) {
	if(NULL == T) {
		return NULL;
	} else if(NULL == T->Left) {
		return T;
	} else {
		return FindMin(T->Left);
	}
}

Position FindMax(SearchTree T) {
	if(NULL == T) {
		return NULL;
	} else if(NULL == T->Right) {
		return T;
	} else {
		return FindMax(T->Right);
	}
}

Position FindMax2(SearchTree T) {
	if(NULL == T) {
		return NULL;
	}

	while(T->Right != NULL) {
		T = T->Right;
	}

	return T;
}

SearchTree Insert(ElementType x, SearchTree T) {
	if(NULL == T) {
		T = malloc(sizeof(SearchTree));

		if(NULL == T) {
			perror("Out of Space.");
			exit(EXIT_FAILURE);
		} else {
			/*
			The final inserted result T->Left T->Right is NULL.
			*/
			T->Element = x;
			T->Left = T->Right = NULL;
		}
	}

	if(x < T->Element) {
		T->Left = Insert(x, T->Left);
	} else if(x > T->Element) {
		T->Right = Insert(x, T->Right);
	}

	return T;
}

SearchTree Delete(ElementType x, SearchTree T) {
	Position TempCell;

	if(NULL == T) {
		perror("Element not found.");
	} else if(x < T->Element) {
		T->Left = Delete(x, T->Left);
	} else if(x > T->Element) {
		T->Right = Delete(x, T->Right);
	} else if(T->Left && T->Right) {
		TempCell = FindMin(T->Right);
		T->Element = TempCell->Element;
		T->Right = Delete(T->Element, T->Right);
	} else {
		TempCell = T;
		if(T->Left == NULL) {
			T = T->Right;
		} else if(T->Right == NULL) {
			T = T->Left;
		}
		free(TempCell);
	}

	return T;
}