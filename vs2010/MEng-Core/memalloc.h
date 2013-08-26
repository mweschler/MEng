#pragma once

namespace MEng{
	template <typename Type>
	inline Type *allocNew(){
		return (Type *)allocMem(sizeof(Type));
	}

	void *allocMem(int bytes);

	void freeMem(void *item);

}