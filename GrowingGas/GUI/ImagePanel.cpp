#include "StdAfx.h"
#include "ImagePanel.h"
#include <wx/dcbuffer.h>
#include "colors.h"


BEGIN_EVENT_TABLE(ImagePanel, wxPanel)
    EVT_ERASE_BACKGROUND(ImagePanel::OnEraseBackground)
    EVT_PAINT(ImagePanel::OnPaint)
    EVT_TIMER(-1, ImagePanel::OnTimer)
    EVT_BUTTON(wxID_EXIT, ImagePanel::OnExit)
END_EVENT_TABLE()

ImagePanel::ImagePanel(wxFrame* parentFrame)
    :wxPanel(parentFrame, -1, wxPoint(0, 0), wxSize(500, 500))
{
    m_bitmap_spir = new wxBitmap(500, 500, 24);
    m_bitmap_paint = new wxBitmap(500, 500, 24);
    m_timer = new wxTimer(this);
    m_timer->Start(0);
    m_layout = new wxBoxSizer(wxVERTICAL);
    SetSizer(m_layout);
    m_exit_button = new wxButton(this, wxID_EXIT, wxT("Exit"));
    m_layout->Add(m_exit_button, 0, wxALIGN_CENTER);
    paint_spiral(m_bitmap_spir);
}

ImagePanel::~ImagePanel(void)
{
    delete m_bitmap_spir;
    delete m_bitmap_paint;
    delete m_timer;
    delete m_exit_button;
}


void ImagePanel::OnTimer(wxTimerEvent& WXUNUSED(event))
{
    int w = m_bitmap_spir->GetWidth();
    int h = m_bitmap_spir->GetHeight();

    // random pixel from bitmap
    int x = rand() % w;
    int y = rand() % h;
    // pixel color
    auto img = m_bitmap_spir->ConvertToImage();
    auto red = img.GetRed(x, y);
    auto green = img.GetGreen(x, y);
    if (red > 100 && green > 100)
    {
        return;
    }
    m_dots.push_back(wxPoint(x, y));
    Refresh();
}


void ImagePanel::paint_spiral(wxBitmap* bmp)
{
    wxMemoryDC dc(*bmp);

    dc.SelectObject(*bmp);

    dc.SetBackground(wxBrush(Color::white));
    dc.Clear();
    float x{ 0.0f }, y{ 0.0f }, angle{ 0.0f };

    for (int i = 50; i < 1000; ++i)
    {
        angle = 0.02 * i;
        x = 250 + 10.0 * angle * cos(angle);
        y = 250 + 10.0 * angle * sin(angle);
        dc.SetPen(wxPen(Color::red));
        dc.SetBrush(wxBrush(Color::red));
        dc.DrawCircle(wxPoint(x, y), 5 /* radius */);
        x = 250 + 10.0 * angle * cos(3.1416 + angle);
        y = 250 + 10.0 * angle * sin(3.1416 + angle);
        dc.SetPen(wxPen(Color::green));
        dc.SetBrush(wxBrush(Color::green));
        dc.DrawCircle(wxPoint(x, y), 5 /* radius */);
    }
}

void ImagePanel::OnPaint(wxPaintEvent& WXUNUSED(event))
{
    wxBufferedPaintDC dc_dots(this, *m_bitmap_paint);

    // display spir bitmap
    dc_dots.DrawBitmap(*m_bitmap_spir, 0, 0, false /* use mask */);

    // paint a transparent circle
    auto img = m_bitmap_spir->ConvertToImage();

    for (auto p : m_dots)
    {
        auto r = img.GetRed(p.x, p.y);
        auto g = img.GetGreen(p.x, p.y);
        dc_dots.SetPen(wxPen(wxColor(r, g, 0, 10)));
        dc_dots.SetBrush(wxBrush(wxColor(r, g, 0, 10)));
        dc_dots.DrawCircle(p, 10 /* radius */);
    }
}

void ImagePanel::OnEraseBackground(wxEraseEvent& WXUNUSED(event))
{

}

void ImagePanel::OnExit(wxCommandEvent& WXUNUSED(event))
{
    auto parent = dynamic_cast<wxFrame*>(GetParent());
    parent->Close(true);
    //wxGetApp().ExitMainLoop();
}
