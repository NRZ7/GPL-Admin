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
		// GUI EDITOR OUTPUT START (by NRZ7, v1.063, #Fufyhy)
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

			text = "Debug Menu"; //--- ToDo: Localize;
			x = 0.1733 * safezoneW + safezoneX;
			y = 0.04724 * safezoneH + safezoneY;
			w = 0.0844792 * safezoneW;
			h = 0.0448149 * safezoneH;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		};
		class NR_deb_arsenal: w_RscButton
		{
			idc = 1600;
			onButtonClick = "[1] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";
			
			text = "Arsenal"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.16274 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_garage: w_RscButton
		{
			idc = 1601;
			onButtonClick = "[21] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";
			
			text = "Garage"; //--- ToDo: Localize;
			x = 0.348612 * safezoneW + safezoneX;
			y = 0.16274 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_serverMonitor: w_RscButton
		{
			idc = 1602;
			onButtonClick = "[41] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Server Monitor"; //--- ToDo: Localize;
			x = 0.513612 * safezoneW + safezoneX;
			y = 0.16274 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_console: w_RscButton
		{
			idc = 1603;
			onButtonClick = "[61] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Debug Console"; //--- ToDo: Localize;
			x = 0.678612 * safezoneW + safezoneX;
			y = 0.16274 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_teleport: w_RscButton
		{
			idc = 1604;
			onButtonClick = "[2] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Teleport"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.20674 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_godmode: w_RscButton
		{
			idc = 1605;
			onButtonClick = "[3] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "God Mode"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.25074 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_invisible: w_RscButton
		{
			idc = 1606;
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Invisible"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.29474 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_aimcoef: w_RscButton
		{
			idc = 1607;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Aim coef"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.42674 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_unlimammo: w_RscButton
		{
			idc = 1608;
			onButtonClick = "[5] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Unlimited Ammo"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.33874 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_recoilcoef: w_RscButton
		{
			idc = 1609;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Recoil coef"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.47074 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_grass: w_RscButton
		{
			idc = 1610;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Set Grass"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.51474 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_localViewDistance: w_RscButton
		{
			idc = 1611;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Set View Distance"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.55874 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_3dteleport: w_RscButton
		{
			idc = 1612;
			onButtonClick = "[11] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "3D Teleport"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.60274 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_environment: w_RscButton
		{
			idc = 1613;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Enable environment"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.64674 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_zeus: w_RscButton
		{
			idc = 1614;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Zeus"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.69074 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_vehicleManager: w_RscButton
		{
			idc = 1615;
			onButtonClick = "[22] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Vehicle Manager"; //--- ToDo: Localize;
			x = 0.348612 * safezoneW + safezoneX;
			y = 0.20674 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_flip: w_RscButton
		{
			idc = 1616;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Flip"; //--- ToDo: Localize;
			x = 0.348612 * safezoneW + safezoneX;
			y = 0.25074 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_AIESP: w_RscButton
		{
			idc = 1617;
			onButtonClick = "[26] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "AI ESP"; //--- ToDo: Localize;
			x = 0.348612 * safezoneW + safezoneX;
			y = 0.38274 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_RRR: w_RscButton
		{
			idc = 1618;
			onButtonClick = "[24] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Repair, Refuel, Rearm"; //--- ToDo: Localize;
			x = 0.348612 * safezoneW + safezoneX;
			y = 0.29474 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_playerESP: w_RscButton
		{
			idc = 1619;
			onButtonClick = "[25] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Player ESP"; //--- ToDo: Localize;
			x = 0.348612 * safezoneW + safezoneX;
			y = 0.33874 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_changeWeather: w_RscButton
		{
			idc = 1622;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Change Weather"; //--- ToDo: Localize;
			x = 0.513612 * safezoneW + safezoneX;
			y = 0.20674 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_globalViewDistance: w_RscButton
		{
			idc = 1623;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Global View Distance"; //--- ToDo: Localize;
			x = 0.513612 * safezoneW + safezoneX;
			y = 0.25074 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_dayNight: w_RscButton
		{
			idc = 1624;
			onButtonClick = "[44] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Day / Night"; //--- ToDo: Localize;
			x = 0.513612 * safezoneW + safezoneX;
			y = 0.29474 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_spectator: w_RscButton
		{
			idc = 1626;
			onButtonClick = "[62] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Spectator"; //--- ToDo: Localize;
			x = 0.678612 * safezoneW + safezoneX;
			y = 0.20674 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_freeCam: w_RscButton
		{
			idc = 1627;
			onButtonClick = "[63] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Free Cam"; //--- ToDo: Localize;
			x = 0.678612 * safezoneW + safezoneX;
			y = 0.25074 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_configViewer: w_RscButton
		{
			idc = 1628;
			onButtonClick = "[64] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Config Viewer"; //--- ToDo: Localize;
			x = 0.678612 * safezoneW + safezoneX;
			y = 0.29474 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_funcView: w_RscButton
		{
			idc = 1629;
			onButtonClick = "[65] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Function Viewer"; //--- ToDo: Localize;
			x = 0.678612 * safezoneW + safezoneX;
			y = 0.33874 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_animations: w_RscButton
		{
			idc = 1630;
			onButtonClick = "[66] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Animations"; //--- ToDo: Localize;
			x = 0.678612 * safezoneW + safezoneX;
			y = 0.38274 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_GUIEditor: w_RscButton
		{
			idc = 1631;
			onButtonClick = "[67] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "GUI Editor"; //--- ToDo: Localize;
			x = 0.678612 * safezoneW + safezoneX;
			y = 0.42674 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_stamina: w_RscButton
		{
			idc = 1607;
			onButtonClick = "[6] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Stamina"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.38274 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_objectSearch: w_RscButton
		{
			idc = 1617;
			onButtonClick = "[27] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Object Search"; //--- ToDo: Localize;
			x = 0.348612 * safezoneW + safezoneX;
			y = 0.42674 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_globalMessage: w_RscButton
		{
			idc = 1624;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Global Message"; //--- ToDo: Localize;
			x = 0.513612 * safezoneW + safezoneX;
			y = 0.33874 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_provingGround: w_RscButton
		{
			idc = 1631;
			onButtonClick = "[68] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Proving Ground"; //--- ToDo: Localize;
			x = 0.678612 * safezoneW + safezoneX;
			y = 0.47074 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////


		
		////////////////////////////////////////////////////////
		// CAUTION EDITOR BUG, ALWAYS OVERWRITE THIS LINE
		////////////////////////////////////////////////////////

		/*
		class DialogTitleText: w_RscText
		{
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		};
		*/


	};
};