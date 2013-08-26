#include "memalloc.h"
#include "assertions.h"
#include <stdlib.h>

namespace MEng{


	void *allocMem(int size){
		ASSERT(size > 0);
		return malloc(size);
	}

	void freeMem(void *item){
		ASSERT(item != NULL);
		delete item;
	}


}