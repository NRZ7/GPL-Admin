#define debugConsoleMenuDialog 62111

class debugConsoleMenu
{
	idd = debugConsoleMenuDialog;
	movingEnable = false;
	enableSimulation = true;
	
	class controls {
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by {VS} Conky, v1.063, #Dafaju)
		////////////////////////////////////////////////////////

		class MainBackground: w_RscPicture
		{
			idc = 1950;
			onLoad = "execVM 'addons\admin\client\systems\adminPanel\dialog\loadDebugConsole.sqf'";
			onDestroy = "inDebugConsole = false;";

			text = "#(argb,8,8,3)color(0,0,0,0.6)"; //--- ToDo: Localize;
			x = 0.158862 * safezoneW + safezoneX;
			y = 0.04174 * safezoneH + safezoneY;
			w = 0.675469 * safezoneW;
			h = 0.913 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
		};
		class TopBar: w_RscPicture
		{
			idc = 1951;

			text = "#(argb,8,8,3)color(0.25,0.51,0.96,0.8)"; //--- ToDo: Localize;
			x = 0.158862 * safezoneW + safezoneX;
			y = 0.0414741 * safezoneH + safezoneY;
			w = 0.675469 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
		};
		class DialogTitleText: w_RscText
		{
			idc = 1952;

			text = "Debug Console"; //--- ToDo: Localize;
			x = 0.1733 * safezoneW + safezoneX;
			y = 0.04724 * safezoneH + safezoneY;
			w = 0.0844792 * safezoneW;
			h = 0.0448149 * safezoneH;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		};
		class n_buttonCloseDialog: n_RscButtonClose
		{
			idc = 891600;
			onButtonClick = "closeDialog 0;";

			text = "X"; //--- ToDo: Localize;
			x = 0.802363 * safezoneW + safezoneX;
			y = 0.05274 * safezoneH + safezoneY;
			w = 0.02475 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class n_consoleEdit: n_RscConsoleEdit
		{
			idc = 1953;
			onKeyDown = "NR_consoleLog = ctrlText 1953;";

			x = 0.175362 * safezoneW + safezoneX;
			y = 0.11874 * safezoneH + safezoneY;
			w = 0.51975 * safezoneW;
			h = 0.506 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class RscListbox_1500: RscListBox
		{
			idc = 1954;

			x = 0.711612 * safezoneW + safezoneX;
			y = 0.11874 * safezoneH + safezoneY;
			w = 0.1155 * safezoneW;
			h = 0.561 * safezoneH;
		};
		class RscEdit_1401: RscEdit
		{
			idc = 1955;

			x = 0.711612 * safezoneW + safezoneX;
			y = 0.67974 * safezoneH + safezoneY;
			w = 0.1155 * safezoneW;
			h = 0.044 * safezoneH;
		};
		class RscButton_1600: w_RscButton
		{
			idc = 1956;

			text = "<< Previous"; //--- ToDo: Localize;
			x = 0.175362 * safezoneW + safezoneX;
			y = 0.64674 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class RscButton_1601: w_RscButton
		{
			idc = 1957;
			onButtonClick = "NR_codeExec = compile ctrlText 1953;	[NR_codeExec,2] call NR_fnc_remoteCode;";

			text = "Server"; //--- ToDo: Localize;
			x = 0.282612 * safezoneW + safezoneX;
			y = 0.64674 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_cmd_GlobalButton: w_RscButton
		{
			idc = 1958;
			onButtonClick = "NR_codeExec = compile ctrlText 1953;	[NR_codeExec,0] call NR_fnc_remoteCode;";

			text = "Global"; //--- ToDo: Localize;
			x = 0.389862 * safezoneW + safezoneX;
			y = 0.64674 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_cmd_localButton: w_RscButton
		{
			idc = 1959;
			onButtonClick = "NR_codeExec = compile ctrlText 1953;	call NR_codeExec;";

			text = "Local"; //--- ToDo: Localize;
			x = 0.497112 * safezoneW + safezoneX;
			y = 0.64674 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class RscButton_1604: w_RscButton
		{
			idc = 1960;

			text = "Next >> "; //--- ToDo: Localize;
			x = 0.604362 * safezoneW + safezoneX;
			y = 0.64674 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class RscCheckbox_2800: RscCheckbox
		{
			idc = 1961;

			x = 0.175362 * safezoneW + safezoneX;
			y = 0.76774 * safezoneH + safezoneY;
			w = 0.0165 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class n_consoleMonitor1: n_RscConsoleEdit
		{
			idc = 1962;
			onKeyDown = "NR_monitor = ctrlText 1962;";

			x = 0.200112 * safezoneW + safezoneX;
			y = 0.75674 * safezoneH + safezoneY;
			w = 0.18975 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class n_monitorOutput1: RscEdit
		{
			idc = 1963;

			x = 0.200112 * safezoneW + safezoneX;
			y = 0.78974 * safezoneH + safezoneY;
			w = 0.18975 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class RscCheckbox_2801: RscCheckbox
		{
			idc = 1964;

			x = 0.175362 * safezoneW + safezoneX;
			y = 0.85574 * safezoneH + safezoneY;
			w = 0.0165 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class n_consoleMonitor2: n_RscConsoleEdit
		{
			idc = 1965;
			onKeyDown = "NR_monitor2 = ctrlText 1965;";

			x = 0.200112 * safezoneW + safezoneX;
			y = 0.85574 * safezoneH + safezoneY;
			w = 0.18975 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class n_monitorOutput2: RscEdit
		{
			idc = 1966;

			x = 0.200112 * safezoneW + safezoneX;
			y = 0.88874 * safezoneH + safezoneY;
			w = 0.18975 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class RscCheckbox_2802: RscCheckbox
		{
			idc = 1967;

			x = 0.455862 * safezoneW + safezoneX;
			y = 0.76774 * safezoneH + safezoneY;
			w = 0.0165 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscCheckbox_2803: RscCheckbox
		{
			idc = 1968;

			x = 0.455862 * safezoneW + safezoneX;
			y = 0.85574 * safezoneH + safezoneY;
			w = 0.0165 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class n_consoleMonitor3: n_RscConsoleEdit
		{
			idc = 1969;
			onKeyDown = "NR_monitor3 = ctrlText 1969;";

			x = 0.480612 * safezoneW + safezoneX;
			y = 0.75674 * safezoneH + safezoneY;
			w = 0.18975 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class n_monitorOutput3: RscEdit
		{
			idc = 1970;

			x = 0.480612 * safezoneW + safezoneX;
			y = 0.78974 * safezoneH + safezoneY;
			w = 0.18975 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class n_consoleMonitor4: n_RscConsoleEdit
		{
			idc = 1971;
			onKeyDown = "NR_monitor4 = ctrlText 1971;";

			x = 0.480612 * safezoneW + safezoneX;
			y = 0.85574 * safezoneH + safezoneY;
			w = 0.18975 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class n_monitorOutput4: RscEdit
		{
			idc = 1972;

			x = 0.480612 * safezoneW + safezoneX;
			y = 0.88874 * safezoneH + safezoneY;
			w = 0.18975 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class RscButton_1605: w_RscButton
		{
			idc = 1973;

			text = "Load "; //--- ToDo: Localize;
			x = 0.728112 * safezoneW + safezoneX;
			y = 0.74574 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class RscButton_1606: w_RscButton
		{
			idc = 1974;

			text = "Save "; //--- ToDo: Localize;
			x = 0.728112 * safezoneW + safezoneX;
			y = 0.81174 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class RscButton_1607: w_RscButton
		{
			idc = 1975;

			text = "Delete "; //--- ToDo: Localize;
			x = 0.728112 * safezoneW + safezoneX;
			y = 0.87774 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////



	};
};