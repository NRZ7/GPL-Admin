#define myTestMenuDialog 61111

class myTestMenu
{
	idd = myTestMenuDialog;
	movingEnable = false;
	enableSimulation = true;
	
	class controls {
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by NRZ7, v1.063, #Huwyko)
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
		class NR_timemultiplierButton: w_RscButton
		{
			idc = 1934;

			text = "Send!"; //--- ToDo: Localize;
			x = 0.530112 * safezoneW + safezoneX;
			y = 0.852165 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.044 * safezoneH;
		};
		class NR_TimeMultiplierEdit: RscEdit
		{
			idc = 1935;

			x = 0.548675 * safezoneW + safezoneX;
			y = 0.76994 * safezoneH + safezoneY;
			w = 0.0464063 * safezoneW;
			h = 0.044 * safezoneH;
		};
		class NR_TimeMultiplierText: RscText
		{
			idc = 1936;

			text = "Set Time Multiplier"; //--- ToDo: Localize;
			x = 0.530112 * safezoneW + safezoneX;
			y = 0.700365 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.055 * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////



	};
};