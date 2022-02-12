/*
	Author: Yin Xi;
	Date: 2022/02/12
	Info: Practice c language basic grammar.
*/
// preprocessor define.
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef unsigned char BYTE;
typedef int* intptr;
typedef char* charstr;

struct fraction {
	int32_t numeration;
	int32_t denominator;
	char* c_arr;
};

typedef struct {
	int32_t val;
}valstr;

typedef union{
	short count;
	float weight;
	float volume;
}quantity;

enum colors{
	RED,
	GREEN,
	BLUE
};

void increment(uint32_t* v1) {
	*v1=*v1+1;
}

void (*increment_ptr)(uint32_t*) = increment;

static void decrement(uint32_t* v1) {
	*v1-=1;
}


static void decrementForbid(const uint32_t* v1) {
	// Error not allowed to modify value, but can modify address.
	// *v1 = 100;
	int a = 12;
	v1 = &a;
	// but v1 address is danguage, it's gone after executed this method.
}

static void decrementForbidv2(uint32_t* const v1) {
	uint32_t val1 = 100;
	*v1 = 100;
}

static void decrementForbidv3(const uint32_t* const v1) {
	uint32_t val1 = 100;
	// double const is forbid both modify value and address.
	//*v1 = 100;
}

void arr_ptr(uint32_t arr[], int len) {

}

// up and below is equal.
void arr_ptr1(uint32_t* arr, int len) {
	for(uint8_t i = 0; i < len; ++i) {
		printf("%d,", *(arr+i));
	}
}

void char_ptr1(char* arr) {
	printf("\n");
	for(uint8_t i=0; i<strlen(arr); ++i) {
		printf("%c,", *(arr+i));
	}
	printf("\n");
}

void test_struct() {
	struct fraction ff = {
		.numeration = 1,
		.denominator = 2,
	};

	struct fraction ff2 = {
		1,2,"TEST"
	};
	
	ff.numeration = 22;
	ff2.numeration = 33;
}

void test_struct2(struct fraction* t){
	t->numeration = t->numeration+1;
	(*t).numeration = (*t).numeration+2;
	
	t->denominator = t->denominator+100;
}

int main(int argc, char *argv[]) {
	short* p1 = NULL;
	short s1 = 200;
	p1 = &s1;

	printf("pointer p1 is %p\n", p1);
	printf("pointer p1 value is %d\n", *p1);

	unsigned char uc1; /* 0-255  -128-127 1 byte*/
	unsigned short us1;
	unsigned int ui1;
	uint8_t uint8t;
	printf("size of %d\n", sizeof(uint8t));
	uint16_t uint16t;
	printf("size of %d\n", sizeof(uint16t));
	uint32_t uint32t;
	uint64_t uint64t;

	unsigned long ul1;
	unsigned long long ull1;
	printf("%d\n", sizeof(ull1));

	char** pp1;
	uint32_t uint32t1 = 10;
	increment(&uint32t1);
	printf("%d\n", uint32t1);

	increment_ptr(&uint32t1);
	printf("%d\n", uint32t1);

	uint32_t arr[5];
	arr_ptr1(arr, 5);

	printf("\n");
	char c_arr[5] = {'H','E','L','L','A'};
	printf("%d\n", sizeof(c_arr));
	char_ptr1(c_arr);

	char c_arr2[5] = "Hello";
	char_ptr1(c_arr2);

	char* c_arr3 = "World";
	printf("%d\n", sizeof(c_arr3));
	printf("%d\n", strlen(c_arr3));

	char c_arr4[] = "Points";
	printf("%d\n", sizeof(c_arr4)); // 7 contains last char '\0'.
	printf("%d\n", strlen(c_arr4)); // 6

	struct fraction f11 = {
		2,3,"TE"
	};
	
	test_struct2(&f11);
	printf("\n");
	printf("%d %d\n", f11.numeration, f11.denominator);

printf("%d\n", RED);

	return 0;
}