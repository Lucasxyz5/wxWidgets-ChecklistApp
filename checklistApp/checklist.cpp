#include "checklist.h"
#include "mainframe.h"
#include "occurence.h"
 
wxIMPLEMENT_APP(Checklist);
 
enum //where we store all the ID's
{
    ID_Hello = 1,
    ID_ABOUT = 2,
    ID_Button = 3,
    ID_InputBox = 4,
    ID_OutputBox = 5
};
 
bool Checklist::OnInit() // initilizes the program. Probably doesn't need to be touched, ever.
{
    MainFrame *frame = new MainFrame();
    frame->Show(true);
    return true;
}
 
//the main frame of the program
MainFrame::MainFrame()
    : wxFrame(nullptr, wxID_ANY, "Checklist")
{
    wxMenu *menuHelp = new wxMenu;
    wxMenuBar *menuBar = new wxMenuBar;

    menuHelp->Append(ID_ABOUT, "&About...\tCtrl-H",
                     "About this program");
    menuBar->Append(menuHelp, "&Help");
 
    SetMenuBar( menuBar );

    // ^^^ Menu bar setup ^^^

    wxButton *button = new wxButton(this, ID_Button, "Create Task");
    inputBox = new wxTextCtrl(this, ID_InputBox);
    outputBox = new wxTextCtrl(this, ID_OutputBox, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);

    // ^^ Elements (buttons and stuff) ^^^

    wxBoxSizer *hor_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *ver_sizer = new wxBoxSizer(wxVERTICAL);

    // ^^^ Sizer setup ^^^

    hor_sizer->Add(button, 1, wxALL, 10);    
    hor_sizer->Add(inputBox, 3, wxALL | wxSHAPED, 10); //Top horizontal sizer

    ver_sizer->Add(hor_sizer, 0, wxALL | wxALIGN_LEFT, 5);
    ver_sizer->Add(outputBox, 5, wxALL | wxALIGN_CENTER | wxEXPAND, 10); //vertical sizer (contains other sizers)

    this->SetSizer(ver_sizer); //sets "main" sizer

    // ^^^ Sizer deployment ^^^

    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, ID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_BUTTON, &MainFrame::OnClick, this, ID_Button);

    // ^^^ binds events ^^^
}
 
//this handles those events we bound earlier
void MainFrame::OnExit(wxCommandEvent& event) //on pressing the close button, close the program
{
    Close(true);
}
 
void MainFrame::OnAbout(wxCommandEvent& event) //on pressing the about button, give this information in a text box
{
    wxMessageBox("This is a program designed to make a checklist. It is currently VERY WIP.",
                 "About This Program", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnClick(wxCommandEvent& event)
{
    wxString word = inputBox->GetValue();
    if (!word.IsEmpty()) {
        outputBox->AppendText(word + "\n");
        inputBox->Clear();
    }
}