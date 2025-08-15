#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
    MainFrame();
 
private:
    wxTextCtrl* inputBox;
    wxTextCtrl* outputBox;

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnClick(wxCommandEvent& event);
};

#endif