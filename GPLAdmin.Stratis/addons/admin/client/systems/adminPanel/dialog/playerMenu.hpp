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
		class PlayerUIDText: w_RscText
		{
			idc = 55510;

			text = "UID:"; //--- ToDo: Localize;
			x = 0.6023 * safezoneW + safezoneX;
			y = 0.12974 * safezoneH + safezoneY;
			w = 0.237187 * safezoneW;
			h = 0.0275 * safezoneH;
		};
		class PlayerObjectText: w_RscText
		{
			idc = 55507;

			text = "Slot:"; //--- ToDo: Localize;
			x = 0.6023 * safezoneW + safezoneX;
			y = 0.18474 * safezoneH + safezoneY;
			w = 0.237187 * safezoneW;
			h = 0.0275 * safezoneH;
		};
		class PlayerSkinText: w_RscText
		{
			idc = 55501;

			text = "Score:"; //--- ToDo: Localize;
			x = 0.6023 * safezoneW + safezoneX;
			y = 0.15724 * safezoneH + safezoneY;
			w = 0.237187 * safezoneW;
			h = 0.0275 * safezoneH;
		};
		class PlayerGunText: w_RscText
		{
			idc = 55502;

			text = "Poptabs:"; //--- ToDo: Localize;
			x = 0.6023 * safezoneW + safezoneX;
			y = 0.21224 * safezoneH + safezoneY;
			w = 0.237187 * safezoneW;
			h = 0.0275 * safezoneH;
		};
		class PlayerItemsText: w_RscText
		{
			idc = 55503;

			text = "Items:"; //--- ToDo: Localize;
			x = 0.6023 * safezoneW + safezoneX;
			y = 0.23974 * safezoneH + safezoneY;
			w = 0.237187 * safezoneW;
			h = 0.0275 * safezoneH;
		};
		class PlayerHealthText: w_RscText
		{
			idc = 55508;

			text = "Health:"; //--- ToDo: Localize;
			x = 0.6023 * safezoneW + safezoneX;
			y = 0.26592 * safezoneH + safezoneY;
			w = 0.237187 * safezoneW;
			h = 0.0275 * safezoneH;
		};
		class PlayerPosistionText: w_RscText
		{
			idc = 55504;

			text = "Position:"; //--- ToDo: Localize;
			x = 0.6023 * safezoneW + safezoneX;
			y = 0.29474 * safezoneH + safezoneY;
			w = 0.237187 * safezoneW;
			h = 0.0275 * safezoneH;
		};
		class PlayerEditBox: w_RscEdit
		{
			idc = 55509;
			colorDisabled[] = {1,1,1,0.3};

			x = 0.653862 * safezoneW + safezoneX;
			y = 0.87224 * safezoneH + safezoneY;
			w = 0.175 * safezoneW;
			h = 0.0449999 * safezoneH;
		};
		class PlayerListBox: w_RscList
		{
			idc = 55505;
			onLBSelChanged = "[2,_this select 1] execVM ""addons\admin\client\systems\adminPanel\importvalues.sqf"";";

			x = 0.168556 * safezoneW + safezoneX;
			y = 0.11126 * safezoneH + safezoneY;
			w = 0.168919 * safezoneW;
			h = 0.698196 * safezoneH;
			tooltip = "Select a target on Player List"; //--- ToDo: Localize;
		};
		class SpectateButton: w_RscButton
		{
			idc = 55506;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			text = "Spectate"; //--- ToDo: Localize;
			x = 0.180312 * safezoneW + safezoneX;
			y = 0.83 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.04125 * safezoneH;
			tooltip = "Spectate target"; //--- ToDo: Localize;
		};
		class KickButton: w_RscButton
		{
			idc = -1;
			onButtonClick = "[3] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			text = "Kick"; //--- ToDo: Localize;
			x = 0.180312 * safezoneW + safezoneX;
			y = 0.885 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.04125 * safezoneH;
			tooltip = "Send the target to lobby"; //--- ToDo: Localize;
		};
		class WarnButton: w_RscButton
		{
			idc = -1;
			onButtonClick = "[1] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			text = "Warn"; //--- ToDo: Localize;
			x = 0.664175 * safezoneW + safezoneX;
			y = 0.81724 * safezoneH + safezoneY;
			w = 0.05 * safezoneW;
			h = 0.04 * safezoneH;
		};
		class NR_PM_tptome: w_RscButton
		{
			onButtonClick = "[8] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1015;

			text = "TpToMe"; //--- ToDo: Localize;
			x = 0.385737 * safezoneW + safezoneX;
			y = 0.18474 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "Teleport target to me"; //--- ToDo: Localize;
		};
		class NR_PM_tpmeto: w_RscButton
		{
			onButtonClick = "[9] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1016;

			text = "TpMeTo"; //--- ToDo: Localize;
			x = 0.488862 * safezoneW + safezoneX;
			y = 0.18474 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "Teleport me to target"; //--- ToDo: Localize;
		};
		class NR_PM_heal: w_RscButton
		{
			onButtonClick = "[10] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1017;

			text = "Heal"; //--- ToDo: Localize;
			x = 0.385737 * safezoneW + safezoneX;
			y = 0.23974 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "Heal target"; //--- ToDo: Localize;
		};
		class NR_PM_kill: w_RscButton
		{
			onButtonClick = "[2] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1018;

			text = "Kill"; //--- ToDo: Localize;
			x = 0.488862 * safezoneW + safezoneX;
			y = 0.23974 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "Kill target"; //--- ToDo: Localize;
		};
		class NR_PM_unfreeze: w_RscButton
		{
			onButtonClick = "[12] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1019;

			text = "Unfreeze"; //--- ToDo: Localize;
			x = 0.385737 * safezoneW + safezoneX;
			y = 0.29474 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "Allow target controls"; //--- ToDo: Localize;
		};
		class NR_PM_freeze: w_RscButton
		{
			onButtonClick = "[13] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1020;

			text = "Freeze"; //--- ToDo: Localize;
			x = 0.488862 * safezoneW + safezoneX;
			y = 0.29474 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "Disables target input controls"; //--- ToDo: Localize;
		};
		class NR_PM_Arsenal: w_RscButton
		{
			onButtonClick = "[5] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1021;

			text = "Arsenal"; //--- ToDo: Localize;
			x = 0.385737 * safezoneW + safezoneX;
			y = 0.34974 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "Open BIS Arsenal on target"; //--- ToDo: Localize;
		};
		class NR_PM_RemoveGear: w_RscButton
		{
			onButtonClick = "[6] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1022;

			text = "Remove Gear"; //--- ToDo: Localize;
			x = 0.488862 * safezoneW + safezoneX;
			y = 0.34974 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "Remove the gear of target"; //--- ToDo: Localize;
		};
		class NR_PM_custom1: w_RscButton
		{
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1023;

			text = "Custom #1"; //--- ToDo: Localize;
			x = 0.385737 * safezoneW + safezoneX;
			y = 0.54224 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_PM_custom2: w_RscButton
		{
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1024;

			text = "Custom #2"; //--- ToDo: Localize;
			x = 0.488862 * safezoneW + safezoneX;
			y = 0.54224 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_PM_Custom3: w_RscButton
		{
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1025;

			text = "Custom #3"; //--- ToDo: Localize;
			x = 0.385737 * safezoneW + safezoneX;
			y = 0.59724 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_PM_custom4: w_RscButton
		{
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1026;

			text = "Custom #4"; //--- ToDo: Localize;
			x = 0.488862 * safezoneW + safezoneX;
			y = 0.59724 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_PM_tempban: w_RscButton
		{
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1027;

			text = "Temp-Ban"; //--- ToDo: Localize;
			x = 0.2723 * safezoneW + safezoneX;
			y = 0.88588 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.04125 * safezoneH;
			tooltip = "Force target to lobby until the next restart"; //--- ToDo: Localize;
		};
		class NR_PM_ban: w_RscButton
		{
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1028;

			text = "Ban"; //--- ToDo: Localize;
			x = 0.365112 * safezoneW + safezoneX;
			y = 0.88588 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.04125 * safezoneH;
			tooltip = "Ban the target"; //--- ToDo: Localize;
		};
		class NR_PM_exec: w_RscButton
		{
			idc = 55506;
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			text = "Execute Code"; //--- ToDo: Localize;
			x = 0.2723 * safezoneW + safezoneX;
			y = 0.83088 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.04125 * safezoneH;
			tooltip = "Execute code on target"; //--- ToDo: Localize;
		};
		class NR_PM_showmap: w_RscButton
		{
			idc = 55506;
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			text = "Show on map"; //--- ToDo: Localize;
			x = 0.365937 * safezoneW + safezoneX;
			y = 0.83 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.04125 * safezoneH;
			tooltip = "Show the target on map"; //--- ToDo: Localize;
		};
		class DialogTitleText: w_RscText
		{
			idc = 1002;
			font = "PuristaMedium";
			text = "Player Menu"; //--- ToDo: Localize;
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

