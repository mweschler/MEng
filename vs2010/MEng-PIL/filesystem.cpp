#ifdef _WIN32
#include <Windows.h>
#endif
#include "filesystem.h"


namespace MEng{

	const int _PATH_MAX_SIZE = 2048;

	MEng::String Filesystem::getExecutableDir(){
#ifdef _WIN32
		TCHAR path[_PATH_MAX_SIZE];
		DWORD numChars;

		numChars = GetModuleFileName(NULL, path, _PATH_MAX_SIZE);
		for(int i  = numChars - 1; i > 0; i--){
			if(path[i] == '\\'){
				path[i] = '\0';
				break;
			}
		}
		return String(path);

#endif
	}

	String Filesystem::getCurrentDir(){
#ifdef _WIN32
		TCHAR path[_PATH_MAX_SIZE];
		GetCurrentDirectory(_PATH_MAX_SIZE, path);
		return String(path);
#endif
	}
}