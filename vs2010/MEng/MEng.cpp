#include <stdlib.h>
#include "assertions.h"
#include "core.h"
#include "gui.h"
#include "window.h"

int main (int argc, char *argv[]){
	MEng::Window window = MEng::GUI::createWindow(800, 600, false);
	window.show();
	while(!window.shouldQuit()){
		window.pollEvents();
	}
	return 0;
}