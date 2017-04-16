#define myTestMenuDialog 61111

class myTestMenu
{
	idd = myTestMenuDialog;
	movingEnable = false;
	enableSimulation = true;
	
	class controls {
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by NRZ7, v1.063, #Lyfuju)
		////////////////////////////////////////////////////////

		class NR_Background: w_RscPicture
		{
			idc = 1800;

			text = "#(argb,8,8,3)color(0,0,0,0.6)"; //--- ToDo: Localize;
			x = 0.333281 * safezoneW + safezoneX;
			y = 0.394667 * safezoneH + safezoneY;
			w = 0.319688 * safezoneW;
			h = 0.308 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
		};
		class NR_test_slider: n_RscSlider
		{
			idc = 1900;
			
			//onMouseClick = "sliderValue = _this;";
			//onMouseMoving = "systemChat str _this;";
			onSliderPosChanged = "sliderValue = _this select 1;";//"call myFunction;";
			x = 0.412344 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.159844 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class NR_test_ButtonOk: w_RscButton
		{
			idc = 1001;
			onButtonClick = "hint format ['Slider Value = %1',sliderValue];";
			
			text = "Done!"; //--- ToDo: Localize;
			x = 0.448438 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.033 * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////


	};
};