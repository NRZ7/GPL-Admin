// *****************************************************************************************
// * This script is licensed under the GNU Lesser GPL v3. Copyright © 2015 A3Wasteland.com *
// *****************************************************************************************
#define newDebugDialog 60001

class newDebugMenu
{
	idd = newDebugDialog;
	movingEnable = false;
	enableSimulation = true;
	
	class controls {

		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by NRZ7, v1.063, #Raxuqu)
		////////////////////////////////////////////////////////

		class MainBackground: w_RscPicture
		{
			idc = 1000;

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
			idc = 1001;

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
			idc = 1002;
			font = "PuristaMedium";
			text = "Debug Menu"; //--- ToDo: Localize;
			x = 0.1733 * safezoneW + safezoneX;
			y = 0.04724 * safezoneH + safezoneY;
			w = 0.0844792 * safezoneW;
			h = 0.0448149 * safezoneH;
			//sizeEx = (			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1) * 	(0.04) * 	(0.04) * 	(0.04) * 	(0.04) * 	(0.04) * 	(0.04) * GUI_GRID_H;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////


	};
};