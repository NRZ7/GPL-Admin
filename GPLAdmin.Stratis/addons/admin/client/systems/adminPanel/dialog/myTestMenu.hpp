#define myTestMenuDialog 61111

class myTestMenu
{
	idd = myTestMenuDialog;
	movingEnable = false;
	enableSimulation = true;
	
	class controls {
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by NRZ7 v1.063, #Qiquzi)
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
		class nr_commandListBox: RscListBox
		{
			idc = 1954;
			onLBSelChanged = "nr_fncIndex = _this select 1";

			x = 0.703362 * safezoneW + safezoneX;
			y = 0.11874 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.561 * safezoneH;
		};
		class nr_storedEdit: RscEdit
		{
			idc = 1955;

			x = 0.703362 * safezoneW + safezoneX;
			y = 0.67974 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.044 * safezoneH;
		};
		class RscButton_1600: w_RscButton
		{
			idc = 1956;
			onButtonClick = "[1] execVM 'addons\admin\client\systems\adminPanel\debugConsoleSelect.sqf';";

			text = "<< Previous"; //--- ToDo: Localize;
			x = 0.191862 * safezoneW + safezoneX;
			y = 0.63574 * safezoneH + safezoneY;
			w = 0.07425 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class RscButton_1601: w_RscButton
		{
			idc = 1957;
			onButtonClick = "_NR_codeExec = compile ctrlText 1953;	[6,_NR_codeExec] execVM 'addons\admin\client\systems\adminPanel\debugConsoleSelect.sqf';";

			text = "Server"; //--- ToDo: Localize;
			x = 0.274362 * safezoneW + safezoneX;
			y = 0.63574 * safezoneH + safezoneY;
			w = 0.07425 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_cmd_GlobalButton: w_RscButton
		{
			idc = 1958;
			onButtonClick = "_NR_codeExec = compile ctrlText 1953;	[7,_NR_codeExec] execVM 'addons\admin\client\systems\adminPanel\debugConsoleSelect.sqf';";

			text = "Global"; //--- ToDo: Localize;
			x = 0.356862 * safezoneW + safezoneX;
			y = 0.63574 * safezoneH + safezoneY;
			w = 0.07425 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_cmd_localButton: w_RscButton
		{
			idc = 1959;
			onButtonClick = "_NR_codeExec = compile ctrlText 1953;	 [8,_NR_codeExec] execVM 'addons\admin\client\systems\adminPanel\debugConsoleSelect.sqf';";

			text = "Local"; //--- ToDo: Localize;
			x = 0.439362 * safezoneW + safezoneX;
			y = 0.63574 * safezoneH + safezoneY;
			w = 0.07425 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class RscButton_1604: w_RscButton
		{
			idc = 1960;
			onButtonClick = "[2] execVM 'addons\admin\client\systems\adminPanel\debugConsoleSelect.sqf';";

			text = "Next >> "; //--- ToDo: Localize;
			x = 0.604362 * safezoneW + safezoneX;
			y = 0.63574 * safezoneH + safezoneY;
			w = 0.07425 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class n_consoleMonitor1: n_RscConsoleEdit
		{
			idc = 1962;
			onKeyDown = "NR_monitor = ctrlText 1962;";
			onKillFocus = "NR_monitor = ctrlText 1962;";

			x = 0.183612 * safezoneW + safezoneX;
			y = 0.69074 * safezoneH + safezoneY;
			w = 0.22275 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class n_monitorOutput1: RscEdit
		{
			idc = 1963;

			x = 0.183612 * safezoneW + safezoneX;
			y = 0.72374 * safezoneH + safezoneY;
			w = 0.22275 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class n_consoleMonitor2: n_RscConsoleEdit
		{
			idc = 1965;
			onKeyDown = "NR_monitor2 = ctrlText 1965;";
			onKillFocus = "NR_monitor2 = ctrlText 1965;";

			x = 0.183612 * safezoneW + safezoneX;
			y = 0.77874 * safezoneH + safezoneY;
			w = 0.22275 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class n_monitorOutput2: RscEdit
		{
			idc = 1966;

			x = 0.183612 * safezoneW + safezoneX;
			y = 0.81174 * safezoneH + safezoneY;
			w = 0.22275 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class n_consoleMonitor3: n_RscConsoleEdit
		{
			idc = 1969;
			onKeyDown = "NR_monitor3 = ctrlText 1969;";
			onKillFocus = "NR_monitor3 = ctrlText 1969;";

			x = 0.183612 * safezoneW + safezoneX;
			y = 0.86674 * safezoneH + safezoneY;
			w = 0.22275 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class n_monitorOutput3: RscEdit
		{
			idc = 1970;

			x = 0.183612 * safezoneW + safezoneX;
			y = 0.89974 * safezoneH + safezoneY;
			w = 0.22275 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class n_consoleMonitor4: n_RscConsoleEdit
		{
			idc = 1971;
			onKeyDown = "NR_monitor4 = ctrlText 1971;";
			onKillFocus = "NR_monitor4 = ctrlText 1971;";

			x = 0.455862 * safezoneW + safezoneX;
			y = 0.69074 * safezoneH + safezoneY;
			w = 0.22275 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class n_monitorOutput4: RscEdit
		{
			idc = 1972;

			x = 0.455862 * safezoneW + safezoneX;
			y = 0.72374 * safezoneH + safezoneY;
			w = 0.22275 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class RscButton_1605: w_RscButton
		{
			idc = 1973;
			onButtonClick = "[3] execVM 'addons\admin\client\systems\adminPanel\debugConsoleSelect.sqf';";

			text = "Load "; //--- ToDo: Localize;
			x = 0.723987 * safezoneW + safezoneX;
			y = 0.74574 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class RscButton_1606: w_RscButton
		{
			idc = 1974;
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\debugConsoleSelect.sqf';";

			text = "Save "; //--- ToDo: Localize;
			x = 0.723987 * safezoneW + safezoneX;
			y = 0.81174 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class RscButton_1607: w_RscButton
		{
			idc = 1975;
			onButtonClick = "[5] execVM 'addons\admin\client\systems\adminPanel\debugConsoleSelect.sqf';";

			text = "Delete "; //--- ToDo: Localize;
			x = 0.723987 * safezoneW + safezoneX;
			y = 0.87774 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_cmd_targetButton: w_RscButton
		{
			idc = 1976;
			onButtonClick = "_NR_codeExec = compile ctrlText 1953; [9,_NR_codeExec] execVM 'addons\admin\client\systems\adminPanel\debugConsoleSelect.sqf';";

			text = "Target"; //--- ToDo: Localize;
			x = 0.521862 * safezoneW + safezoneX;
			y = 0.63574 * safezoneH + safezoneY;
			w = 0.07425 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class n_consoleEdit: n_RscConsoleEdit
		{
			idc = 1953;
			onKeyDown = "NR_consoleLog = ctrlText 1953;";
			onKillFocus = "NR_consoleLog = ctrlText 1953;";

			x = 0.175362 * safezoneW + safezoneX;
			y = 0.11874 * safezoneH + safezoneY;
			w = 0.51975 * safezoneW;
			h = 0.506 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class n_buttonClearConsole: n_RscButtonClose
		{
			idc = 1981;
			onButtonClick = "ctrlSetText [1953,'']; NR_consoleLog = ctrlText 1953;";

			text = "X"; //--- ToDo: Localize;
			x = 0.67655 * safezoneW + safezoneX;
			y = 0.12149 * safezoneH + safezoneY;
			w = 0.0165 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0,0,0,1};
			colorBackground2[] = {0.5, 0.5,0.5, 0.1};
			colorFocused[] = {0,0,0,1}; // pulse
			colorBackgroundActive[] = {0,0,0,1};
			colorShadow[] = {0,0,0,0.1};
		};
		class n_consoleMonitor5: n_RscConsoleEdit
		{
			idc = 1977;
			onKeyDown = "NR_monitor5 = ctrlText 1977;";
			onKillFocus = "NR_monitor5 = ctrlText 1977;";

			x = 0.455862 * safezoneW + safezoneX;
			y = 0.77874 * safezoneH + safezoneY;
			w = 0.22275 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
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
			colorBackground[] = {0.863,0.376,0.376,1};
		};
		class n_monitorOutput5: RscEdit
		{
			idc = 1978;

			x = 0.455862 * safezoneW + safezoneX;
			y = 0.81174 * safezoneH + safezoneY;
			w = 0.22275 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class n_consoleMonitor6: n_RscConsoleEdit
		{
			idc = 1979;
			onKeyDown = "NR_monitor6 = ctrlText 1979;";
			onKillFocus = "NR_monitor6 = ctrlText 1979;";

			x = 0.455862 * safezoneW + safezoneX;
			y = 0.86674 * safezoneH + safezoneY;
			w = 0.22275 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class n_monitorOutput6: RscEdit
		{
			idc = 1980;

			x = 0.455862 * safezoneW + safezoneX;
			y = 0.89974 * safezoneH + safezoneY;
			w = 0.22275 * safezoneW;
			h = 0.033 * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////






	};
};