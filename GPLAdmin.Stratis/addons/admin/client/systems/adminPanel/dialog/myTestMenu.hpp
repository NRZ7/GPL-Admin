#define myTestMenuDialog 61111

class myTestMenu
{
	idd = myTestMenuDialog;
	movingEnable = false;
	enableSimulation = true;
	
	class controls {
		////////////////////////////////////////////////////////
		//					WEATHER CHANGES
		// GUI EDITOR OUTPUT START (by NRZ7, v1.063, #Tinaji)
		////////////////////////////////////////////////////////

		class NR_invisibleBackground: w_RscPicture
		{
			idc = 1902;

			text = "#(argb,8,8,3)color(0,0,0,0)"; //--- ToDo: Localize;
			x = 0.332112 * safezoneW + safezoneX;
			y = 0.66874 * safezoneH + safezoneY;
			w = 0.48675 * safezoneW;
			h = 0.253 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
		};
		class RscFrame_1800: RscFrame
		{
			idc = 1903;

			x = 0.657987 * safezoneW + safezoneX;
			y = 0.704765 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.198 * safezoneH;
		};
		class NR_slider_overcast: n_RscSlider
		{
			idc = 1904;
			onSliderPosChanged = "NR_overcast = _this select 1; NR_overcast = NR_overcast * 0.1;";

			text = "Overcast"; //--- ToDo: Localize;
			x = 0.356862 * safezoneW + safezoneX;
			y = 0.71934 * safezoneH + safezoneY;
			w = 0.099 * safezoneW;
			h = 0.018975 * safezoneH;
		};
		class NR_weather_ButtonOk: w_RscButton
		{
			idc = 1905;
			onButtonClick = "NR_windEast = parseNumber ctrlText 1910; NR_windNorth = parseNumber ctrlText 1911; [NR_overcast,NR_fog,NR_rain,NR_Waves,NR_Lightnings,NR_windEast,NR_windNorth] execVM 'addons\admin\client\systems\adminPanel\clientWeather.sqf';";

			text = "Done!"; //--- ToDo: Localize;
			x = 0.530112 * safezoneW + safezoneX;
			y = 0.85849 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_slider_fog: n_RscSlider
		{
			idc = 1906;
			onSliderPosChanged = "NR_fog = _this select 1; NR_fog = NR_fog * 0.1;";

			text = "Fog"; //--- ToDo: Localize;
			x = 0.356862 * safezoneW + safezoneX;
			y = 0.788915 * safezoneH + safezoneY;
			w = 0.099 * safezoneW;
			h = 0.018975 * safezoneH;
		};
		class NR_slider_rain: n_RscSlider
		{
			idc = 1907;
			onSliderPosChanged = "NR_rain = _this select 1; NR_rain = NR_rain * 0.1;";

			text = "Rain"; //--- ToDo: Localize;
			x = 0.356862 * safezoneW + safezoneX;
			y = 0.852165 * safezoneH + safezoneY;
			w = 0.1155 * safezoneW;
			h = 0.018975 * safezoneH;
		};
		class NR_slider_waves: n_RscSlider
		{
			idc = 1908;
			onSliderPosChanged = "NR_waves = _this select 1; NR_waves = NR_waves * 0.1;";

			text = "Waves"; //--- ToDo: Localize;
			x = 0.670156 * safezoneW + safezoneX;
			y = 0.786 * safezoneH + safezoneY;
			w = 0.1155 * safezoneW;
			h = 0.018975 * safezoneH;
		};
		class NR_slider_lightnings: n_RscSlider
		{
			idc = 1909;
			onSliderPosChanged = "NR_lightnings = _this select 1; NR_lightnings = NR_lightnings * 0.1;";

			text = "Lightnings"; //--- ToDo: Localize;
			x = 0.670156 * safezoneW + safezoneX;
			y = 0.874 * safezoneH + safezoneY;
			w = 0.1155 * safezoneW;
			h = 0.018975 * safezoneH;
		};
		class NR_Edit_windEast: RscEdit
		{
			idc = 1910;

			x = 0.563112 * safezoneW + safezoneX;
			y = 0.725665 * safezoneH + safezoneY;
			w = 0.0495 * safezoneW;
			h = 0.031625 * safezoneH;
		};
		class NR_Edit_windNorth: RscEdit
		{
			idc = 1911;

			x = 0.563112 * safezoneW + safezoneX;
			y = 0.78259 * safezoneH + safezoneY;
			w = 0.0495 * safezoneW;
			h = 0.031625 * safezoneH;
		};
		class NR_text_overcast: RscText
		{
			idc = 1912;

			text = "Overcast:"; //--- ToDo: Localize;
			x = 0.356862 * safezoneW + safezoneX;
			y = 0.69404 * safezoneH + safezoneY;
			w = 0.05775 * safezoneW;
			h = 0.018975 * safezoneH;
		};
		class NR_text_Fog: RscText
		{
			idc = 1913;

			text = "Fog:"; //--- ToDo: Localize;
			x = 0.356862 * safezoneW + safezoneX;
			y = 0.763615 * safezoneH + safezoneY;
			w = 0.05775 * safezoneW;
			h = 0.018975 * safezoneH;
		};
		class NR_text_windEast: RscText
		{
			idc = 1914;

			text = "Wind East:"; //--- ToDo: Localize;
			x = 0.497112 * safezoneW + safezoneX;
			y = 0.73199 * safezoneH + safezoneY;
			w = 0.05775 * safezoneW;
			h = 0.018975 * safezoneH;
		};
		class NR_text_windNorth: RscText
		{
			idc = 1915;

			text = "Wind North:"; //--- ToDo: Localize;
			x = 0.497112 * safezoneW + safezoneX;
			y = 0.788915 * safezoneH + safezoneY;
			w = 0.05775 * safezoneW;
			h = 0.018975 * safezoneH;
		};
		class NR_text_waves: RscText
		{
			idc = 1916;

			text = "Waves:"; //--- ToDo: Localize;
			x = 0.670156 * safezoneW + safezoneX;
			y = 0.753 * safezoneH + safezoneY;
			w = 0.05775 * safezoneW;
			h = 0.018975 * safezoneH;
		};
		class NR_text_lightnings: RscText
		{
			idc = 1917;

			text = "Lightnings:"; //--- ToDo: Localize;
			x = 0.670156 * safezoneW + safezoneX;
			y = 0.841 * safezoneH + safezoneY;
			w = 0.05775 * safezoneW;
			h = 0.018975 * safezoneH;
		};
		class NR_text_note: RscText
		{
			idc = 1918;

			text = "*Note"; //--- ToDo: Localize;
			x = 0.701094 * safezoneW + safezoneX;
			y = 0.709 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = " This command will have no effect unless ""Manual Override"" option is selected in the editor in the Intel, which is normally off."; //--- ToDo: Localize;
		};
		class NR_text_Rain: RscText
		{
			idc = 1919;

			text = "Rain:"; //--- ToDo: Localize;
			x = 0.356862 * safezoneW + safezoneX;
			y = 0.826865 * safezoneH + safezoneY;
			w = 0.05775 * safezoneW;
			h = 0.018975 * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////

	};
};