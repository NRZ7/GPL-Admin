#define myTestMenuDialog 61111

class myTestMenu
{
	idd = myTestMenuDialog;
	movingEnable = false;
	enableSimulation = true;
	
	class controls {
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by NRZ7, v1.063, #Xekyja)
		////////////////////////////////////////////////////////
		class NR_invisibleBackground: w_RscPicture
		{
			idc = 1920;

			text = "#(argb,8,8,3)color(0,0,0,0)"; //--- ToDo: Localize;
			x = 0.332112 * safezoneW + safezoneX;
			y = 0.66874 * safezoneH + safezoneY;
			w = 0.48675 * safezoneW;
			h = 0.253 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
		};
		class NR_serverView_ButtonOk: w_RscButton
		{
			idc = 1923;
			onButtonClick = "NR_serverView = ctrlText 1924;	[NR_serverView] execVM 'addons\admin\client\systems\adminPanel\clientSendServerView.sqf';";

			text = "Done!"; //--- ToDo: Localize;
			x = 0.538362 * safezoneW + safezoneX;
			y = 0.864815 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_serverView_Edit: n_RscEdit
		{
			idc = 1924;

			x = 0.488862 * safezoneW + safezoneX;
			y = 0.79524 * safezoneH + safezoneY;
			w = 0.17325 * safezoneW;
			h = 0.03795 * safezoneH;
			tooltip = "Insert value between 0 and 10000"; //--- ToDo: Localize;
		};
		class NR_serverView_text: RscText
		{
			idc = 1925;
			text = "Max view distance in meters (max. 10000)"; //--- ToDo: Localize;
			x = 0.488862 * safezoneW + safezoneX;
			y = 0.70669 * safezoneH + safezoneY;
			w = 0.1815 * safezoneW;
			h = 0.0506 * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////


	};
};