#ifndef __TJVXMAINWINDOWCONTROL_H__
#define __TJVXMAINWINDOWCONTROL_H__

typedef enum
{
	JVX_MAINWINDOWCONTROLLER_TRIGGER_NONE,
	JVX_MAINWINDOWCONTROLLER_TRIGGER_UPDATE_WINDOW,
	JVX_MAINWINDOWCONTROLLER_TRIGGER_START,
	JVX_MAINWINDOWCONTROLLER_TRIGGER_STOP,
	JVX_MAINWINDOWCONTROLLER_TRIGGER_SHOW_EXPERT_UI,
	JVX_MAINWINDOWCONTROLLER_TRIGGER_HIDE_EXPERT_UI,
	JVX_MAINWINDOWCONTROLLER_TRIGGER_SET_WINDOW_TITLE /* plus const char* */,
	JVX_MAINWINDOWCONTROLLER_TRIGGER_ADJUST_SIZE,
	JVX_MAINWINDOWCONTROLLER_TRIGGER_SAFE_CONFIG 
} jvxMainWindowController_trigger_operation_ids;

typedef enum
{
	JVX_MAINWINDOWCONTROLLER_REGISTER_NONE,
	JVX_MAINWINDOWCONTROLLER_REGISTER_MENU_ITEM_ONOFF,
	JVX_MAINWINDOWCONTROLLER_REGISTER_MENU_ITEM_INT_VALUE
} jvxMainWindowController_register_functional_ids;

typedef void (*jvxMainWindowController_uiCallback)(jvxHandle* privData, jvxHandle* contentData, jvxInt32 id);


#endif