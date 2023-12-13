#pragma once

#ifdef			EXPORT_STATIC
	#define		PROVIDE

#elif defined	EXPORT_SHARED
	#define		PROVIDE __declspec(dllexport)

#elif defined	IMPORT_SHARED
	#define		PROVIDE __declspec(dllimport)
	#pragma		comment (lib, "Vizor.Dash.Shared.lib")

#else
	#define		PROVIDE
	#pragma		comment (lib, "Vizor.Dash.Static.lib")

#endif
