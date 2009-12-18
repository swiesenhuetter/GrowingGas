// GUI.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "wx/wx.h"
#include "GUI.h"
#include "ImagePanel.h"
 
IMPLEMENT_APP(BasicApplication)

BEGIN_EVENT_TABLE(BasicFrame, wxFrame)
    EVT_ERASE_BACKGROUND(BasicFrame::OnEraseBackground)
    EVT_PAINT(BasicFrame::OnPaint)
	EVT_CLOSE(BasicFrame::OnClose) 
END_EVENT_TABLE()


bool BasicApplication::OnInit()
{
	BasicFrame *frame = new BasicFrame(_T("Bitmap Test"), 50, 50, 450, 300);
	frame->Show(TRUE);
	SetTopWindow(frame);
	return TRUE;
}
 
BasicFrame::BasicFrame( const wxChar *title, int xpos, int ypos, int width, int height)
: wxFrame( (wxFrame*) NULL, -1, title, wxPoint(xpos, ypos), wxSize(width, height) )
{
// 	m_panel = new ImagePanel( this );
	m_panel = new wxPanel( this, -1 ,wxPoint(0,200),wxSize(320,200));
	const wxString filename = _T("..\\data\\pattern1.bmp";
	m_bmpImage  = new wxImage(0,0);	// Create an empty Image. Size does NOT matter...
	if (m_bmpImage->LoadFile(filename), wxBITMAP_TYPE_BMP))
	{
		m_bitmap = new wxBitmap( *m_bmpImage );
	}


}
 
BasicFrame::~BasicFrame()
{
}

void BasicFrame::OnPaint(wxPaintEvent& WXUNUSED(event))
{
    //wxPaintDC dc( this );
    //dc.DrawBitmap( *m_bitmap, 0, 0, true /* use mask */ );
	wxPaintDC dc1( m_panel );
	dc1.DrawBitmap( *m_bitmap, 0, 0, true /* use mask */ );
}

void BasicFrame::OnClose(wxCloseEvent& WXUNUSED(event)){
}
