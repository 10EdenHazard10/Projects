//
//  Dialog.h
//
//  417001974
//
//  Created by Kofi McCollin with the use of Dr. John Charley's Code
//
//
//  This Software or code may not be distributed with the intent 
//  of attaning monetary gain
//  This Software can be distrubited with the permission of the 
//  proprietary owner
//
//  Copyright KMax Studios 2020
//  

#ifndef Dialog_h
#define Dialog_h



struct record {
    wxString ID;
    wxString fName;
    wxString lName;
    wxString major;
    wxString gpa;
    
};


typedef struct record studentRecord;

class Dialog: public wxDialog {
    
public:
    Dialog(const wxString& title, const wxPoint& pos, const wxSize& size);
    
    wxTextCtrl* idEditBox;
    
    wxTextCtrl* firstNameEditBox;
    wxTextCtrl*  lastNameEditBox;
   // wxTextCtrl* majorEditBox;
    wxTextCtrl* gpaEditBox;
    
    wxComboBox* majorCombo;
    
    
};

Dialog::Dialog ( const wxString& title, const wxPoint& pos,  const wxSize& size): wxDialog((wxDialog *)NULL, -1, title, pos, size)
{
    //Set up the panel
    wxPanel*    panel = new wxPanel(this, -1);
    
    //Define and position the StaticTexts
    
    wxStaticText *idLabel = new wxStaticText (panel, wxID_ANY, wxT("Student ID"), wxPoint(20, 20) );
    
    wxStaticText *firstNameLabel = new wxStaticText(panel, wxID_ANY, wxT("Name"), wxPoint(15, 80) );
    
    wxStaticText *lastNameLabel = new wxStaticText(panel, wxID_ANY, wxT("Surname"), wxPoint(15, 140) );
    
    
    
    wxStaticText*  majorLabel = new wxStaticText (panel, wxID_ANY, wxT("Major"), wxPoint(15, 200) );
    
    wxStaticText *gpaLabel = new wxStaticText(panel, wxID_ANY, wxT("GPA"), wxPoint(15, 260) );
    
    
    
    //Define and position the Data Entry Boxes
    
    idEditBox = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxPoint(116, 16));
    
    firstNameEditBox = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxPoint(116, 76));
    
    lastNameEditBox = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxPoint(116, 136));
    
   /* majorEditBox = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxPoint(75, 88)); */
    
    gpaEditBox = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxPoint(116,256));
    
    //Edit
    wxArrayString major;
    //major.Add(wxT(""));
    major.Add(wxT("COMP"));
    major.Add(wxT("IT"));
    major.Add(wxT("MATH"));
    major.Add(wxT("ELET"));
    major.Add(wxT("PHYS"));
    
    majorCombo = new wxComboBox( panel, -1, wxT("COMP"), wxPoint(116, 196), wxSize(120, -1), major, wxCB_READONLY);
    
    
    
    
    // Define and position the Response buttons (OK and CANCEL)
    
    // The OK button
    wxButton* ok = new wxButton( panel, wxID_OK, wxT("OK"), wxPoint(100, 320), wxDefaultSize, 0);
    
    // The CANCEL button
    wxButton* cancel = new wxButton ( panel, wxID_CANCEL, wxT("CANCEL"), wxPoint(240, 320), wxDefaultSize, 0 );
    
    // Centre the dialog on the parent's window
    Centre();
    
    Maximize(); // Maximize the window to full definition size
    
}


// Grab the data to display it in the MainEditBox


wxString getRecord(studentRecord dataRec)
{
    wxString str = wxT("\n\n");
    
    wxString idStr;
    idStr << dataRec.ID;
    
    
    
    str.Append(idStr);
    str.Append(wxT("\t"));
    str.Append(dataRec.fName);
    str.Append(wxT("\t"));
    str.Append(dataRec.lName);
    str.Append(wxT("\t"));
    str.Append(dataRec.major);
    str.Append(wxT("\t"));
    str.Append(dataRec.gpa);
    //str.Append(wxT("\t"));
    
    
    str.Append(wxT("\n"));
    
    return str;
}



#endif /* Dialog_h */
