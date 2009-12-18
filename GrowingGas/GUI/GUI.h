#pragma once
#ifndef BASIC_H
#define BASIC_H

class ImagePanel;

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
	void OnClose(wxCloseEvent& WXUNUSED(event));

private:
    ImagePanel      *m_panel;
    DECLARE_EVENT_TABLE()
};
#endif 