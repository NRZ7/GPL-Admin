// *****************************************************************************************
// * This script is licensed under the GNU Lesser GPL v3. Copyright © 2015 A3Wasteland.com *
// *****************************************************************************************
#define playerMenuDialog 55500
#define playerMenuPlayerSkin 55501
#define playerMenuPlayerGun 55502
#define playerMenuPlayerItems 55503
#define playerMenuPlayerPos 55504
#define playerMenuPlayerList 55505
#define playerMenuSpectateButton 55506
#define playerMenuPlayerObject 55507
#define playerMenuPlayerHealth 55508
#define playerMenuWarnMessage 55509
#define playerMenuPlayerUID 55510

class PlayersMenu
{
	idd = playerMenuDialog;
	movingEnable = false;
	enableSimulation = true;
	
	class controls {

		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by NRZ7, v1.063, #Dymoso)
		////////////////////////////////////////////////////////

		class MainBackground: w_RscPicture
		{
			idc = 1000;

			text = "#(argb,8,8,3)color(0,0,0,0.6)"; //--- ToDo: Localize;
			x = 0.1875 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.6 * safezoneW;
			h = 0.661111 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
		};
		class TopBar: w_RscPicture
		{
			idc = 1001;

			text = "#(argb,8,8,3)color(0.25,0.51,0.96,0.8)"; //--- ToDo: Localize;
			x = 0.1875 * safezoneW + safezoneX;
			y = 0.15 * safezoneH + safezoneY;
			w = 0.6 * safezoneW;
			h = 0.05 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
		};
		class DialogTitleText: w_RscText
		{
			idc = 1002;

			text = "Player Menu"; //--- ToDo: Localize;
			x = 0.2 * safezoneW + safezoneX;
			y = 0.155 * safezoneH + safezoneY;
			w = 0.0844792 * safezoneW;
			h = 0.0448148 * safezoneH;
			sizeEx = (			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1) * 	(0.04) * GUI_GRID_H;
		};
		class PlayerUIDText: w_RscText
		{
			idc = 55510;

			text = "UID:"; //--- ToDo: Localize;
			x = 0.52 * safezoneW + safezoneX;
			y = 0.215 * safezoneH + safezoneY;
			w = 0.25 * safezoneW;
			h = 0.04 * safezoneH;
		};
		class PlayerObjectText: w_RscText
		{
			idc = 55507;

			text = "Slot:"; //--- ToDo: Localize;
			x = 0.52 * safezoneW + safezoneX;
			y = 0.235 * safezoneH + safezoneY;
			w = 0.25 * safezoneW;
			h = 0.04 * safezoneH;
		};
		class PlayerSkinText: w_RscText
		{
			idc = 55501;

			text = "Score:"; //--- ToDo: Localize;
			x = 0.52 * safezoneW + safezoneX;
			y = 0.255 * safezoneH + safezoneY;
			w = 0.25 * safezoneW;
			h = 0.04 * safezoneH;
		};
		class PlayerGunText: w_RscText
		{
			idc = 55502;

			text = "Poptabs:"; //--- ToDo: Localize;
			x = 0.52 * safezoneW + safezoneX;
			y = 0.275 * safezoneH + safezoneY;
			w = 0.25 * safezoneW;
			h = 0.04 * safezoneH;
		};
		class PlayerItemsText: w_RscText
		{
			idc = 55503;

			text = "Items:"; //--- ToDo: Localize;
			x = 0.52 * safezoneW + safezoneX;
			y = 0.295 * safezoneH + safezoneY;
			w = 0.4 * safezoneW;
			h = 0.04 * safezoneH;
		};
		class PlayerHealthText: w_RscText
		{
			idc = 55508;

			text = "Health:"; //--- ToDo: Localize;
			x = 0.52 * safezoneW + safezoneX;
			y = 0.315 * safezoneH + safezoneY;
			w = 0.25 * safezoneW;
			h = 0.04 * safezoneH;
		};
		class PlayerPosistionText: w_RscText
		{
			idc = 55504;

			text = "Position:"; //--- ToDo: Localize;
			x = 0.52 * safezoneW + safezoneX;
			y = 0.335 * safezoneH + safezoneY;
			w = 0.25 * safezoneW;
			h = 0.04 * safezoneH;
		};
		class PlayerEditBox: w_RscEdit
		{
			idc = 55509;
			colorDisabled[] = {1,1,1,0.3};

			x = 0.6 * safezoneW + safezoneX;
			y = 0.745 * safezoneH + safezoneY;
			w = 0.175 * safezoneW;
			h = 0.045 * safezoneH;
		};
		class PlayerListBox: w_RscList
		{
			idc = 55505;
			onLBSelChanged = "[2,_this select 1] execVM ""addons\admin\client\systems\adminPanel\importvalues.sqf"";";

			x = 0.2 * safezoneW + safezoneX;
			y = 0.225 * safezoneH + safezoneY;
			w = 0.159844 * safezoneW;
			h = 0.462 * safezoneH;
		};
		class SpectateButton: w_RscButton
		{
			idc = 55506;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			text = "Spectate"; //--- ToDo: Localize;
			x = 0.206094 * safezoneW + safezoneX;
			y = 0.709 * safezoneH + safezoneY;
			w = 0.05 * safezoneW;
			h = 0.04 * safezoneH;
		};
		class KickButton: w_RscButton
		{
			idc = -1;
			onButtonClick = "[3] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			text = "Kick"; //--- ToDo: Localize;
			x = 0.206094 * safezoneW + safezoneX;
			y = 0.764 * safezoneH + safezoneY;
			w = 0.05 * safezoneW;
			h = 0.04 * safezoneH;
		};
		class WarnButton: w_RscButton
		{
			idc = -1;
			onButtonClick = "[1] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			text = "Warn"; //--- ToDo: Localize;
			x = 0.6 * safezoneW + safezoneX;
			y = 0.7 * safezoneH + safezoneY;
			w = 0.05 * safezoneW;
			h = 0.04 * safezoneH;
		};
		class NR_PM_tptome: w_RscButton
		{
			onButtonClick = "[8] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			idc = 1015;
			text = "TpToMe"; //--- ToDo: Localize;
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.247 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class NR_PM_tpmeto: w_RscButton
		{
			onButtonClick = "[9] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			idc = 1016;
			text = "TpMeTo"; //--- ToDo: Localize;
			x = 0.448438 * safezoneW + safezoneX;
			y = 0.247 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class NR_PM_heal: w_RscButton
		{
			onButtonClick = "[10] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			idc = 1017;
			text = "Heal"; //--- ToDo: Localize;
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class NR_PM_kill: w_RscButton
		{
			onButtonClick = "[2] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			idc = 1018;
			text = "Kill"; //--- ToDo: Localize;
			x = 0.448438 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class NR_PM_unfreeze: w_RscButton
		{
			onButtonClick = "[12] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			idc = 1019;
			text = "Unfreeze"; //--- ToDo: Localize;
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.335 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class NR_PM_freeze: w_RscButton
		{
			onButtonClick = "[13] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			idc = 1020;
			text = "Freeze"; //--- ToDo: Localize;
			x = 0.448438 * safezoneW + safezoneX;
			y = 0.335 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class NR_PM_Arsenal: w_RscButton
		{
			onButtonClick = "[5] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			idc = 1021;
			text = "Arsenal"; //--- ToDo: Localize;
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.379 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class NR_PM_RemoveGear: w_RscButton
		{
			onButtonClick = "[6] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			idc = 1022;
			text = "Remove Gear"; //--- ToDo: Localize;
			x = 0.448438 * safezoneW + safezoneX;
			y = 0.379 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class NR_PM_custom1: w_RscButton
		{
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			idc = 1023;
			text = "Custom #1"; //--- ToDo: Localize;
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class NR_PM_custom2: w_RscButton
		{
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			idc = 1024;
			text = "Custom #2"; //--- ToDo: Localize;
			x = 0.448438 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class NR_PM_Custom3: w_RscButton
		{
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			idc = 1025;
			text = "Custom #3"; //--- ToDo: Localize;
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class NR_PM_custom4: w_RscButton
		{
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			idc = 1026;
			text = "Custom #4"; //--- ToDo: Localize;
			x = 0.448438 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class NR_PM_tempban: w_RscButton
		{
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			idc = 1027;
			text = "Temp-Ban"; //--- ToDo: Localize;
			x = 0.273125 * safezoneW + safezoneX;
			y = 0.764 * safezoneH + safezoneY;
			w = 0.05 * safezoneW;
			h = 0.04 * safezoneH;
		};
		class NR_PM_ban: w_RscButton
		{
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			idc = 1028;
			text = "Ban"; //--- ToDo: Localize;
			x = 0.335 * safezoneW + safezoneX;
			y = 0.764 * safezoneH + safezoneY;
			w = 0.05 * safezoneW;
			h = 0.04 * safezoneH;
		};
		class NR_PM_exec: w_RscButton
		{
			idc = 55506;
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			text = "Execute Code"; //--- ToDo: Localize;
			x = 0.273125 * safezoneW + safezoneX;
			y = 0.709 * safezoneH + safezoneY;
			w = 0.05 * safezoneW;
			h = 0.04 * safezoneH;
		};
		class NR_PM_showmap: w_RscButton
		{
			idc = 55506;
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			text = "Show on map"; //--- ToDo: Localize;
			x = 0.335 * safezoneW + safezoneX;
			y = 0.709 * safezoneH + safezoneY;
			w = 0.05 * safezoneW;
			h = 0.04 * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////

	};
};

