#include "MainWindow.h"

#include <Application.h>
#include <Menu.h>
#include <MenuItem.h>
#include <View.h>

enum
{
	M_SET_COLOR_RED = 'sred',
	M_SET_COLOR_GREEN = 'sgrn',
	M_SET_COLOR_BLUE = 'sblu',
	M_SET_COLOR_BLACK = 'sblk'
};

MainWindow::MainWindow(void)
	:	BWindow(BRect(100,100,500,400),"Weather",B_TITLED_WINDOW, B_ASYNCHRONOUS_CONTROLS)
{
	BRect r(Bounds());
	r.bottom = 20;
	fMenuBar = new BMenuBar(r,"menubar");
	AddChild(fMenuBar);

	BMenu *menu = new BMenu("Color");
	menu->AddItem(new BMenuItem("Red",new BMessage(M_SET_COLOR_RED), 'R'));
	menu->AddItem(new BMenuItem("Green",new BMessage(M_SET_COLOR_GREEN), 'G'));
	menu->AddItem(new BMenuItem("Blue",new BMessage(M_SET_COLOR_BLUE), 'B'));
	menu->AddItem(new BMenuItem("Black",new BMessage(M_SET_COLOR_BLACK), 'K'));
	menu->AddItem(new BMenuItem("Quit", new BMessage(B_QUIT_REQUESTED), 'Q'));

	fMenuBar->AddItem(menu);

	BView *view = new BView(BRect(100,100,300,200),"color", B_FOLLOW_ALL, B_WILL_DRAW);
	AddChild(view);
	view->SetViewColor(0,0,160);
}


void
MainWindow::MessageReceived(BMessage *msg)
{
	BView *view = FindView("color");

	switch (msg->what)
	{
		case M_SET_COLOR_RED:
		{
			view->SetViewColor(160,0,0);
			view->Invalidate();
			break;
		}
		case M_SET_COLOR_GREEN:
		{
			view->SetViewColor(0,160,0);
			view->Invalidate();
			break;
		}
		case M_SET_COLOR_BLUE:
		{
			view->SetViewColor(0,0,160);
			view->Invalidate();
			break;
		}
		case M_SET_COLOR_BLACK:
		{
			view->SetViewColor(0,0,0);
			view->Invalidate();
			break;
		}
		default:
		{
			BWindow::MessageReceived(msg);
			break;
		}
	}
}


bool
MainWindow::QuitRequested(void)
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
}
