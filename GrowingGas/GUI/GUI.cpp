// GUI.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "wx/wx.h"
#include "GUI.h"
#include "ImagePanel.h"
 
IMPLEMENT_APP(BasicApplication)

BEGIN_EVENT_TABLE(BasicFrame, wxFrame)
	EVT_CLOSE(BasicFrame::OnClose) 
END_EVENT_TABLE()


bool BasicApplication::OnInit()
{
	BasicFrame *frame = new BasicFrame(_T("Bitmap Test"), 50, 50, 500, 500);
	frame->Show(TRUE);
	SetTopWindow(frame);
	return TRUE;
}
 
BasicFrame::BasicFrame( const wxChar *title, int xpos, int ypos, int width, int height)
: wxFrame( (wxFrame*) NULL, -1, title, wxPoint(xpos, ypos), wxSize(width, height) )
{
 	m_panel = new ImagePanel( this );
}
 
BasicFrame::~BasicFrame()
{
}

void BasicFrame::OnClose(wxCloseEvent& WXUNUSED(event)){
	Destroy();
}
