#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Light_Button.H>
#include "include/Panel.h"
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Text_Editor.H>

void Quit_CB(Fl_Widget *, void *) {
    exit(0);
}

int main(int argc, char **argv) {

    fl_register_images();
    Fl_Double_Window *fl_digi_main = new Fl_Double_Window(50, 50, 800, 460);
  { //mnuFrame
    Fl_Group *mnuFrame = new Fl_Group(0,0, 800, 22);
    Fl_Menu_Bar *menu = new Fl_Menu_Bar(0,0,800-325,22);
    menu->add("File/Quit", FL_CTRL+'q', Quit_CB);
    menu->add("Op Mode");
    menu->add("Configure");
    menu->add("View");
    menu->add("Logbook");
    menu->add("Help");

    Fl_Box *tx_timer = new Fl_Box(800-325, 0, 75, 22, "");
    tx_timer->box(FL_UP_BOX);
    tx_timer->color(FL_BACKGROUND_COLOR);
    
    Fl_Light_Button *btnAutoSpot = new Fl_Light_Button(800-250, 0, 50, 22, "Spot");
    btnAutoSpot->selection_color(FL_GREEN);
    btnAutoSpot->deactivate();
    
    Fl_Light_Button *btnRSID = new Fl_Light_Button(800-200, 0, 50, 22, "RxID");
    btnRSID->selection_color(FL_GREEN);
    btnRSID->labelsize(FL_NORMAL_SIZE-1);
    btnRSID->value(1);

    Fl_Light_Button *btnTxRSID = new Fl_Light_Button(800-150, 0, 50, 22, "TxID");
    btnTxRSID->selection_color(FL_GREEN);
    btnTxRSID->labelsize(FL_NORMAL_SIZE-1);
    btnTxRSID->value(1);

    mnuFrame->end();
  }
  
    Fl_Group *TopFrame1 = new Fl_Group(0, 22, 800, 2*1+3*(24+1));
  { //TopFrame1
    Fl_Group *RigControlFrame = new Fl_Group(0,TopFrame1->y(), (int)fl_wcwidth("9")*10+3, 2*1+3*(24+1));
      { // RigControlFrame 1
        RigControlFrame->box(FL_FLAT_BOX);
        // Skipping these widgets for now
      }
    RigControlFrame->end();

    int Y = RigControlFrame->y()+2*1+3*(24+1);
    Fl_Group *center_group = new Fl_Group(0, Y, 800, 120);
    center_group->box(FL_FLAT_BOX);
    Fl_Group *text_group = new Fl_Group(0, Y, center_group->w(), center_group->h());
    text_group->box(FL_FLAT_BOX);
    Panel *text_panel = new Panel(0, Y, center_group->w(), center_group->h());
    text_panel->box(FL_FLAT_BOX);
    Fl_Group *mvgroup = new Fl_Group(text_panel->x(), text_panel->y(),
                                text_panel->w()/2, 120, "");
    Fl_Hold_Browser *mainViewer = new Fl_Hold_Browser(mvgroup->x(), mvgroup->y(), mvgroup->w(), mvgroup->h()-42, "");    
    mainViewer->box(FL_DOWN_BOX);
    mainViewer->has_scrollbar(Fl_Browser_::VERTICAL);
    mvgroup->end();
    int save_mvx = mvgroup->w();
    int rh = 0.5 * text_panel->h();

    Fl_Text_Editor *ReceiveText = new Fl_Text_Editor(
                                        text_panel->x()+mvgroup->w(), text_panel->y(),
                                        text_panel->w()-mvgroup->w(), rh, "");
    // Skipping FHdisp
    
    Fl_Text_Editor *TransmitText = new Fl_Text_Editor(
                                        text_panel->x()+mvgroup->w(), text_panel->y()+ReceiveText->h(),
                                        text_panel->w()-mvgroup->w(), text_panel->h()-ReceiveText->h());
    TransmitText->align(FL_ALIGN_CLIP);
    // Skipping minbox
    text_panel->end();
    text_group->end();

                            

  }

    fl_digi_main->end();
    fl_digi_main->show(argc, argv);
    return Fl::run();
}
