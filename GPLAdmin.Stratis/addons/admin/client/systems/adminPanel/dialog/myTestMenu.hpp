#define myTestMenuDialog 61111

class myTestMenu
{
	idd = myTestMenuDialog;
	movingEnable = false;
	enableSimulation = true;
	
	class controls {
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by NRZ7, v1.063, #Rysyje)
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
		class RscStructuredText_1100: RscStructuredText
		{
			idc = 1100;
			text = "About GPL Admin<br />Development: NRZ7 <br />Forked from: A3Wasteland"; //--- ToDo: Localize;
			x = 0.340362 * safezoneW + safezoneX;
			y = 0.67974 * safezoneH + safezoneY;
			w = 0.1485 * safezoneW;
			h = 0.077 * safezoneH;
			colorBackground[] = {0,0,0,0};
		};
		class RscStructuredText_1101: RscStructuredText
		{
			idc = 1101;
			text = "Contribute: <br /> Donate <br /> GitHub"; //--- ToDo: Localize;
			x = 0.348612 * safezoneW + safezoneX;
			y = 0.77874 * safezoneH + safezoneY;
			w = 0.1485 * safezoneW;
			h = 0.132 * safezoneH;
			colorBackground[] = {0,0,0,0};
		};
		class RscStructuredText_1102: RscStructuredText
		{
			idc = 1102;
			text = "These people are not affiliated in any way with GPL admin, but they have contributed by releasing their code under the GPL therms<br /><br />"; //--- ToDo: Localize;
			x = 0.505362 * safezoneW + safezoneX;
			y = 0.67974 * safezoneH + safezoneY;
			w = 0.30525 * safezoneW;
			h = 0.066 * safezoneH;
			colorBackground[] = {0,0,0,0};
		};
		class RscStructuredText_1103: RscStructuredText
		{
			idc = 1103;
			text = "AgentRev<br />[404] Deadbeat<br />Team Wasteland"; //--- ToDo: Localize;
			x = 0.530112 * safezoneW + safezoneX;
			y = 0.77874 * safezoneH + safezoneY;
			w = 0.1155 * safezoneW;
			h = 0.11 * safezoneH;
			colorBackground[] = {0,0,0,0};
		};
		class RscStructuredText_1104: RscStructuredText
		{
			idc = 1104;
			text = "Biabock<br />wiking-at<br />conKORD<br />CBA Team"; //--- ToDo: Localize;
			x = 0.678612 * safezoneW + safezoneX;
			y = 0.77874 * safezoneH + safezoneY;
			w = 0.1155 * safezoneW;
			h = 0.11 * safezoneH;
			colorBackground[] = {0,0,0,0};
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////




	};
};