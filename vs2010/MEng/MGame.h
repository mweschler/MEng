#pragma once

#include "MApp.h"

namespace MEng {
	class MGame : public MApp
	{
	public:
		MGame();
		virtual bool Initialize();
		virtual void Update(double time);
		virtual void Render(double time);
		virtual void Shutdown();
	};
}