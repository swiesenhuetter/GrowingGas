#pragma once
#ifndef BASIC_H
#define BASIC_H

//#include "resource.h"

class BasicApplication : public wxApp
{
public:
	virtual bool OnInit();
};
 
class BasicFrame : public wxFrame
{
public:
	BasicFrame( const wxChar *title, int xpos, int ypos, int width, int height );
	~BasicFrame();
};
 
#endif 