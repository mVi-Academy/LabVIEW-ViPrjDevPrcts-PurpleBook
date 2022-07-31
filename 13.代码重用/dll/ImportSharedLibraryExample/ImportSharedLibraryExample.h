#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
//Handle the case that has no parameter
void DWTest_Void (void);

void DWTest_VoidPointer (void*);

void DWTest_VoidPointerPointer (void**);

// StructWithOnlyIntElement
typedef struct{
	int left;
	int top;
} StructWithOnlyIntElement;

void DWTest_Copy_Struct_To_StructPointer (StructWithOnlyIntElement inputTest, 
													   StructWithOnlyIntElement* outputTest);

void DWTest_String (const char* inputTest, 
							  char* outputTest);

void DWTest_String2 (const char inputTest[], 
							   char outputTest[]);

void DWTest_Boolean  (bool inputTest, 
								bool* outputTest);

void DWTest_Array_FixedSize (int inputTest[10], 
									  int outputTest[10]);

void DWTest_Array_RuntimeSize (unsigned int size, 
										int inputTest[], 
										int outputTest[]);

typedef enum {
	kType = 1,
	uType = 2,
}MyEnum;

enum YourEnum{
	iType = 3,
	jType = 4,
};

void DWTest_Enum (MyEnum inputEnum1, 
							MyEnum* outputEnum1, 
							enum YourEnum inputEnum2, 
							enum YourEnum* outputEnum2);

void DWTest_Unsupported(size_t inputTest, 
								  size_t* outputTest);

typedef struct
{
	int ID_number;
	char* name;
	long salary;
}MemberInfo;

typedef enum
{
  good = 0,
  middle,
  bad
} evaluation;

void DWTest_Change_Info(MemberInfo* member, evaluation* evl );

void DWTest_Copy(MyEnum inputEnum1, 
				 MyEnum* outputEnum1, 
				 enum YourEnum inputEnum2, 
				 enum YourEnum* outputEnum2,
				 unsigned int runtimeSize, 
				 int inputRunTimeSizeArray[], 
				 int outputRunTimeSizeArray[],
				 bool inputBool, 
				 bool* outputBool,
				 const char inputString[], 
				 char outputString[],
				 StructWithOnlyIntElement inputStruct, 
				 StructWithOnlyIntElement* outputStruct);

#ifdef __cplusplus
}
#endif
