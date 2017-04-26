// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2017 NRZ7 *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: newDebugMenu.hpp
//	@file Author: NRZ7
//	@file Created: 17/04/2017 12:23

#define debugDialog 60001

class debugMenu
{
	idd = debugDialog;
	movingEnable = false;
	enableSimulation = true;
	
	class controls {

		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by {VS} Conky, v1.063, #Ducupa)
		////////////////////////////////////////////////////////

		class MainBackground: w_RscPicture
		{
			idc = 1000;
			onLoad = "[0] execVM 'addons\admin\client\systems\adminPanel\dialog\debugMenuCtrlShow.sqf'";

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
		class NR_deb_arsenal: w_RscButton
		{
			idc = 1600;
			onButtonClick = "[1] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Arsenal"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.20674 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_garage: w_RscButton
		{
			idc = 1601;
			onButtonClick = "[21] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Garage"; //--- ToDo: Localize;
			x = 0.348612 * safezoneW + safezoneX;
			y = 0.20674 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_serverMonitor: w_RscButton
		{
			idc = 1602;
			onButtonClick = "[41] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Server Monitor"; //--- ToDo: Localize;
			x = 0.513612 * safezoneW + safezoneX;
			y = 0.20674 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_console: w_RscButton
		{
			idc = 1603;
			onButtonClick = "[61] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Debug Console"; //--- ToDo: Localize;
			x = 0.678612 * safezoneW + safezoneX;
			y = 0.20674 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_teleport: w_RscButton
		{
			idc = 1604;
			onButtonClick = "[2] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Teleport"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.25074 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_godmode: w_RscButton
		{
			idc = 1605;
			onButtonClick = "[3] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "God Mode"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.29474 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_invisible: w_RscButton
		{
			idc = 1606;
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Invisible"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.33874 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_3dteleport: w_RscButton
		{
			idc = 1612;
			onButtonClick = "[11] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "3D Teleport"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.42674 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_zeus: w_RscButton
		{
			idc = 1614;
			onButtonClick = "[13] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Zeus"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.47074 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_vehicleManager: w_RscButton
		{
			idc = 1615;
			onButtonClick = "[22] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Vehicle Manager"; //--- ToDo: Localize;
			x = 0.348612 * safezoneW + safezoneX;
			y = 0.25074 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_flip: w_RscButton
		{
			idc = 1616;
			onButtonClick = "[23] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Flip"; //--- ToDo: Localize;
			x = 0.348612 * safezoneW + safezoneX;
			y = 0.29474 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_AIESP: w_RscButton
		{
			idc = 1617;
			onButtonClick = "[26] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "AI ESP"; //--- ToDo: Localize;
			x = 0.348612 * safezoneW + safezoneX;
			y = 0.42674 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_RRR: w_RscButton
		{
			idc = 1618;
			onButtonClick = "[24] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Repair, Refuel, Rearm"; //--- ToDo: Localize;
			x = 0.348612 * safezoneW + safezoneX;
			y = 0.33874 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_playerESP: w_RscButton
		{
			idc = 1619;
			onButtonClick = "[25] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Player ESP"; //--- ToDo: Localize;
			x = 0.348612 * safezoneW + safezoneX;
			y = 0.38274 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_changeWeather: w_RscButton
		{
			idc = 1622;
			onButtonClick = "[42] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Change Weather"; //--- ToDo: Localize;
			x = 0.513612 * safezoneW + safezoneX;
			y = 0.25074 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_globalViewDistance: w_RscButton
		{
			idc = 1623;
			onButtonClick = "[43] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Global View Distance"; //--- ToDo: Localize;
			x = 0.513612 * safezoneW + safezoneX;
			y = 0.29474 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_dayNight: w_RscButton
		{
			idc = 1624;
			onButtonClick = "[44] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Day / Night"; //--- ToDo: Localize;
			x = 0.513612 * safezoneW + safezoneX;
			y = 0.33874 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_spectator: w_RscButton
		{
			idc = 1626;
			onButtonClick = "[62] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Spectator"; //--- ToDo: Localize;
			x = 0.678612 * safezoneW + safezoneX;
			y = 0.25074 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_freeCam: w_RscButton
		{
			idc = 1627;
			onButtonClick = "[63] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Free Cam"; //--- ToDo: Localize;
			x = 0.678612 * safezoneW + safezoneX;
			y = 0.29474 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_configViewer: w_RscButton
		{
			idc = 1628;
			onButtonClick = "[64] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Config Viewer"; //--- ToDo: Localize;
			x = 0.678612 * safezoneW + safezoneX;
			y = 0.33874 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_funcView: w_RscButton
		{
			idc = 1629;
			onButtonClick = "[65] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Function Viewer"; //--- ToDo: Localize;
			x = 0.678612 * safezoneW + safezoneX;
			y = 0.38274 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_animations: w_RscButton
		{
			idc = 1630;
			onButtonClick = "[66] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Animations"; //--- ToDo: Localize;
			x = 0.678612 * safezoneW + safezoneX;
			y = 0.42674 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_GUIEditor: w_RscButton
		{
			idc = 1631;
			onButtonClick = "[67] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "GUI Editor"; //--- ToDo: Localize;
			x = 0.678612 * safezoneW + safezoneX;
			y = 0.47074 * safezoneH + safezoneY;
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
			y = 0.47074 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_globalMessage: w_RscButton
		{
			idc = 1624;
			onButtonClick = "[45] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Global Message"; //--- ToDo: Localize;
			x = 0.513612 * safezoneW + safezoneX;
			y = 0.38274 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_deb_provingGround: w_RscButton
		{
			idc = 1631;
			onButtonClick = "[68] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Proving Ground"; //--- ToDo: Localize;
			x = 0.678612 * safezoneW + safezoneX;
			y = 0.51474 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_cusom_player11: n_RscButtonMenu
		{
			idc = 1614;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Disabled"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.51474 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class NR_cusom_player12: n_RscButtonMenu
		{
			idc = 1614;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Disabled"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.55874 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class NR_cusom_player13: n_RscButtonMenu
		{
			idc = 1614;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Disabled"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.60274 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class NR_cusom_player14: n_RscButtonMenu
		{
			idc = 1614;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Disabled"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.64674 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class NR_deb_NPCMarkers: w_RscButton
		{
			idc = 1614;
			onButtonClick = "[28] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "NPC Markers"; //--- ToDo: Localize;
			x = 0.348612 * safezoneW + safezoneX;
			y = 0.51474 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
		};
		class NR_cusom_vehicle9: n_RscButtonMenu
		{
			idc = 1614;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Disabled"; //--- ToDo: Localize;
			x = 0.348612 * safezoneW + safezoneX;
			y = 0.55874 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class NR_cusom_vehicle10: n_RscButtonMenu
		{
			idc = 1614;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Disabled"; //--- ToDo: Localize;
			x = 0.348612 * safezoneW + safezoneX;
			y = 0.60274 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class NR_cusom_server6: n_RscButtonMenu
		{
			idc = 1614;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Disabled"; //--- ToDo: Localize;
			x = 0.513612 * safezoneW + safezoneX;
			y = 0.42674 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class NR_cusom_server7: n_RscButtonMenu
		{
			idc = 1614;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Disabled"; //--- ToDo: Localize;
			x = 0.513612 * safezoneW + safezoneX;
			y = 0.47074 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class NR_cusom_server9: n_RscButtonMenu
		{
			idc = 1614;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Disabled"; //--- ToDo: Localize;
			x = 0.513612 * safezoneW + safezoneX;
			y = 0.55874 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class NR_cusom_server8: n_RscButtonMenu
		{
			idc = 1614;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Disabled"; //--- ToDo: Localize;
			x = 0.513612 * safezoneW + safezoneX;
			y = 0.51474 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class NR_cusom_server10: n_RscButtonMenu
		{
			idc = 1614;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Disabled"; //--- ToDo: Localize;
			x = 0.513612 * safezoneW + safezoneX;
			y = 0.60274 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class NR_cusom_debug9: n_RscButtonMenu
		{
			idc = 1614;
			onButtonClick = "createDialog 'myTestMenu'";

			text = "Test Menu"; //--- ToDo: Localize;
			x = 0.678612 * safezoneW + safezoneX;
			y = 0.55874 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class NR_cusom_debug10: n_RscButtonMenu
		{
			idc = 1614;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Disabled"; //--- ToDo: Localize;
			x = 0.678612 * safezoneW + safezoneX;
			y = 0.60274 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class NR_cusom_player15: n_RscButtonMenu
		{
			idc = 1614;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\debugSelect.sqf'";

			text = "Disabled"; //--- ToDo: Localize;
			x = 0.183612 * safezoneW + safezoneX;
			y = 0.69074 * safezoneH + safezoneY;
			w = 0.132 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class CustomFrame: RscFrame
		{
			idc = 1800;

			x = 0.332112 * safezoneW + safezoneX;
			y = 0.66874 * safezoneH + safezoneY;
			w = 0.48675 * safezoneW;
			h = 0.253 * safezoneH;
		};
		class NR_configBackground: w_RscPicture
		{
			idc = 2200;

			text = "#(argb,8,8,3)color(0,0,0,0.6)"; //--- ToDo: Localize;
			x = 0.332112 * safezoneW + safezoneX;
			y = 0.66874 * safezoneH + safezoneY;
			w = 0.48675 * safezoneW;
			h = 0.253 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
		};

		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////
	
		////////////////////////////////////////////////////////
		//					WEATHER CHANGES
		// GUI EDITOR OUTPUT START (by NRZ7, v1.063, #Razysu)
		////////////////////////////////////////////////////////

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
			x = 0.513612 * safezoneW + safezoneX;
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
			w = 0.099 * safezoneW;
			h = 0.018975 * safezoneH;
			tooltip = "Overcast need to be +50%"; //--- ToDo: Localize;
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
			x = 0.670362 * safezoneW + safezoneX;
			y = 0.864815 * safezoneH + safezoneY;
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
			tooltip = "Negative value for West"; //--- ToDo: Localize;
		};
		class NR_Edit_windNorth: RscEdit
		{
			idc = 1911;

			x = 0.563112 * safezoneW + safezoneX;
			y = 0.78259 * safezoneH + safezoneY;
			w = 0.0495 * safezoneW;
			h = 0.031625 * safezoneH;
			tooltip = "Negative value for South"; //--- ToDo: Localize;
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
			x = 0.670362 * safezoneW + safezoneX;
			y = 0.83319 * safezoneH + safezoneY;
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

		////////////////////////////////////////////////////////
		//					GLOBAL MESSAGE
		// GUI EDITOR OUTPUT START (by NRZ7, v1.063, #Razysu)
		////////////////////////////////////////////////////////

		class NR_globalMessage_ButtonOk: w_RscButton
		{
			idc = 1921;
			onButtonClick = "NR_GlobalMessage = ctrlText 1922;  [NR_GlobalMessage] execVM 'addons\admin\client\systems\adminPanel\clientGlobalMessage.sqf';";

			text = "Done!"; //--- ToDo: Localize;
			x = 0.538362 * safezoneW + safezoneX;
			y = 0.864815 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_Edit_globalMessage: n_RscEdit
		{
			idc = 1922;

			text = "Write your global message here"; //--- ToDo: Localize;
			x = 0.348612 * safezoneW + safezoneX;
			y = 0.687715 * safezoneH + safezoneY;
			w = 0.45375 * safezoneW;
			h = 0.158125 * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////

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
			onButtonClick = "NR_serverView = parseNumber ctrlText 1924;	[NR_serverView] execVM 'addons\admin\client\systems\adminPanel\clientSendServerViewDistance.sqf';";

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
			text = "Max view distance in meters"; //--- ToDo: Localize;
			x = 0.488862 * safezoneW + safezoneX;
			y = 0.70669 * safezoneH + safezoneY;
			w = 0.1815 * safezoneW;
			h = 0.0506 * safezoneH;
			style = ST_CENTER;
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