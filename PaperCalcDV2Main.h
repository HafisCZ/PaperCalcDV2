/***************************************************************
 * Name:      PaperCalcDV2Main.h
 * Purpose:   Defines Application Frame
 * Author:    Martin 'Hafis' Halfar (hafis@protonmail.com)
 * Created:   2015-10-18
 * Copyright: Martin 'Hafis' Halfar (hafiscz.github.io)
 * License:
 **************************************************************/

#ifndef PAPERCALCDV2MAIN_H
#define PAPERCALCDV2MAIN_H

//(*Headers(PaperCalcDV2Frame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/choice.h>
#include <wx/gbsizer.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class PaperCalcDV2Frame: public wxFrame
{
    public:

        PaperCalcDV2Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~PaperCalcDV2Frame();

    private:

        // User functions
        void RedrawOnLaunch(void);
        void parseDecScale (double *value, int scale);
        void parseThScale (double *value, int scale);
        void PushObjects(wxChoice *ch, wxString data[], int size);
        void ExchangeLanguage(wxString pack[][2], int l);
        bool validate(wxString str, double *var);
        bool PlaceToSizer(wxTextCtrl *w, int x, int y);
        bool PlaceToSizer(wxStaticText *w, int x, int y);
        bool PlaceToSizer(wxChoice *w, int x, int y);
        double calculate (double hLenght, double hWidth, double hGram, double hCount, double hWeight);

        //(*Handlers(PaperCalcDV2Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnSolve(wxCommandEvent& event);
        void OnSizeSelect(wxCommandEvent& event);
        void OnSizeChanged(wxCommandEvent& event);
        void OnCalcTypeChanged(wxCommandEvent& event);
        void OnEnglish(wxCommandEvent& event);
        void OnCzech(wxCommandEvent& event);
        //*)

        //(*Identifiers(PaperCalcDV2Frame)
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT4;
        static const long ID_CHOICE1;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL4;
        static const long ID_TEXTCTRL5;
        static const long ID_CHOICE2;
        static const long ID_CHOICE3;
        static const long ID_CHOICE5;
        static const long ID_CHOICE6;
        static const long ID_STATICLINE1;
        static const long ID_STATICTEXT7;
        static const long ID_CHOICE7;
        static const long idMenuHistory;
        static const long idMenuSolve;
        static const long idMenuUpdate;
        static const long idMenuQuit;
        static const long idMenuPriceEnabled;
        static const long idMenuLanguageEN;
        static const long idMenuLanguageCZ;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(PaperCalcDV2Frame)
        wxChoice* Choice5;
        wxMenuItem* MenuItem8;
        wxTextCtrl* TextCtrl4;
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItem5;
        wxStaticText* StaticText2;
        wxMenuItem* MenuItem2;
        wxChoice* Choice3;
        wxGridBagSizer* GridBagSizer1;
        wxMenu* Menu3;
        wxMenuItem* MenuItem1;
        wxMenuItem* MenuItem4;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxMenu* Menu1;
        wxChoice* Choice7;
        wxMenuItem* MenuItem3;
        wxStaticText* StaticText5;
        wxStaticText* StaticText7;
        wxStatusBar* StatusBar1;
        wxMenuItem* MenuItem6;
        wxStaticLine* StaticLine1;
        wxTextCtrl* TextCtrl2;
        wxChoice* Choice6;
        wxTextCtrl* TextCtrl1;
        wxMenuBar* MenuBar1;
        wxTextCtrl* TextCtrl5;
        wxMenu* Menu2;
        wxStaticText* StaticText4;
        wxTextCtrl* TextCtrl3;
        wxChoice* Choice1;
        wxChoice* Choice2;
        wxMenu* Menu4;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // PAPERCALCDV2MAIN_H
