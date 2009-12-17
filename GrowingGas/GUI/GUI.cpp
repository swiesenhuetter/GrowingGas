// GUI.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "wx/wx.h"
#include "GUI.h"
 
IMPLEMENT_APP(BasicApplication)
 
bool BasicApplication::OnInit()
{
	BasicFrame *frame = new BasicFrame(_T("Bitmap Test"), 50, 50, 450, 300);
 	wxPanel* panel = new wxPanel( frame, -1 ,wxPoint(0,200),wxSize(320,200));
	frame->Show(TRUE);
	SetTopWindow(frame);
	return TRUE;
}
 
BasicFrame::BasicFrame( const wxChar *title, int xpos, int ypos, int width, int height)
: wxFrame( (wxFrame*) NULL, -1, title, wxPoint(xpos, ypos), wxSize(width, height) )
{
	m_bmpImage  = new wxImage(0,0);	// Create an empty Image. Size does NOT matter...
	if (m_bmpImage->LoadFile(_T("..\\data\\pattern1.bmp"), wxBITMAP_TYPE_BMP))
	{
		//wxMessageBox(_T("image loaded correctly"));
		m_bitmap = new wxBitmap( *m_bmpImage );
	}
}
 
BasicFrame::~BasicFrame()
{
}

void BasicFrame::OnPaint(wxPaintEvent& WXUNUSED(event))
{
    wxPaintDC dc( this );
    dc.DrawBitmap( *m_bitmap, 0, 0, true /* use mask */ );
}
