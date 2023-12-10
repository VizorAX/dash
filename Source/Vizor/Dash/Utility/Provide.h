#pragma once

#ifdef			STATIC_BUILD
	#define		PROVIDE
#elif defined	DYNAMIC_BUILD
	#define		PROVIDE __declspec(dllexport)
#elif defined	DYNAMIC_LINK
	#define		PROVIDE __declspec(dllimport)
	#pragma		comment (lib, "Vizor.Dash.lib")
#else
	#define		PROVIDE
	#pragma		comment (lib, "Vizor.Dash.Static.lib")
#endif
