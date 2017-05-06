#define myTestMenuDialog 61111

class myTestMenu
{
	idd = myTestMenuDialog;
	movingEnable = false;
	enableSimulation = true;
	
	class controls {
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by NRZ7, v1.063, #Cohute)
		////////////////////////////////////////////////////////

		class MainBackground: w_RscPicture
		{
			idc = 1000;
			onLoad = "nr_inPlayerMenu = true;";
			onDestroy = "nr_inPlayerMenu = false;";

			text = "#(argb,8,8,3)color(0,0,0,0.6)"; //--- ToDo: Localize;
			x = 0.158862 * safezoneW + safezoneX;
			y = 0.04174 * safezoneH + safezoneY;
			w = 0.675469 * safezoneW;
			h = 0.913 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
		};
		class nr_PM_rightPic: w_RscPicture
		{
			idc = 1200;

			text = "#(argb,8,8,3)color(0,0,0,0.2)"; //--- ToDo: Localize;
			x = 0.596112 * safezoneW + safezoneX;
			y = 0.11874 * safezoneH + safezoneY;
			w = 0.22275 * safezoneW;
			h = 0.671 * safezoneH;
		};
		class nr_PM_rightFrame: RscFrame
		{
			idc = 55507;

			x = 0.596112 * safezoneW + safezoneX;
			y = 0.11874 * safezoneH + safezoneY;
			w = 0.22275 * safezoneW;
			h = 0.671 * safezoneH;
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
		class n_buttonCloseDialog: n_RscButtonClose
		{
			idc = 891600;
			onButtonClick = "closeDialog 0;";

			text = "X"; //--- ToDo: Localize;
			x = 0.802363 * safezoneW + safezoneX;
			y = 0.05274 * safezoneH + safezoneY;
			w = 0.02475 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0.863,0.376,0.376,1};
		};
		class PlayerTargetText: w_RscText
		{
			idc = 55510;

			text = "Target:"; //--- ToDo: Localize;
			x = 0.604362 * safezoneW + safezoneX;
			y = 0.14074 * safezoneH + safezoneY;
			w = 0.0433125 * safezoneW;
			h = 0.02475 * safezoneH;
		};
		class PlayerEditBox: w_RscEdit
		{
			idc = 55509;
			colorDisabled[] = {1,1,1,0.3};

			x = 0.645612 * safezoneW + safezoneX;
			y = 0.88874 * safezoneH + safezoneY;
			w = 0.175 * safezoneW;
			h = 0.0449999 * safezoneH;
		};
		class PlayerListBox: w_RscList
		{
			idc = 55505;
			onLBSelChanged = "[2,_this select 1] execVM ""addons\admin\client\systems\adminPanel\importvalues.sqf"";";

			x = 0.167112 * safezoneW + safezoneX;
			y = 0.10774 * safezoneH + safezoneY;
			w = 0.17325 * safezoneW;
			h = 0.704 * safezoneH;
			tooltip = "Select a target on Player List"; //--- ToDo: Localize;
		};
		class SpectateButton: w_RscButton
		{
			idc = 55506;
			onButtonClick = "[0] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			text = "Spectate"; //--- ToDo: Localize;
			x = 0.175362 * safezoneW + safezoneX;
			y = 0.83374 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Spectate target"; //--- ToDo: Localize;
		};
		class KickButton: w_RscButton
		{
			idc = -1;
			onButtonClick = "[3] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			text = "Kick"; //--- ToDo: Localize;
			x = 0.175362 * safezoneW + safezoneX;
			y = 0.88874 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Send the target to lobby"; //--- ToDo: Localize;
		};
		class WarnButton: w_RscButton
		{
			idc = -1;
			onButtonClick = "[1] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			text = "Warn"; //--- ToDo: Localize;
			x = 0.653862 * safezoneW + safezoneX;
			y = 0.83374 * safezoneH + safezoneY;
			w = 0.05 * safezoneW;
			h = 0.04 * safezoneH;
		};
		class NR_PM_tptome: w_RscButton
		{
			onButtonClick = "[8] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1015;

			text = "TpToMe"; //--- ToDo: Localize;
			x = 0.365112 * safezoneW + safezoneX;
			y = 0.18474 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
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
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "Teleport me to target"; //--- ToDo: Localize;
		};
		class NR_PM_heal: w_RscButton
		{
			onButtonClick = "[10] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1017;

			text = "Heal"; //--- ToDo: Localize;
			x = 0.365112 * safezoneW + safezoneX;
			y = 0.23974 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
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
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "Kill target"; //--- ToDo: Localize;
		};
		class NR_PM_unfreeze: w_RscButton
		{
			onButtonClick = "[12] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1019;

			text = "Unfreeze"; //--- ToDo: Localize;
			x = 0.365112 * safezoneW + safezoneX;
			y = 0.29474 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
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
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "Disables target input controls"; //--- ToDo: Localize;
		};
		class NR_PM_Arsenal: w_RscButton
		{
			onButtonClick = "[5] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1021;

			text = "Arsenal"; //--- ToDo: Localize;
			x = 0.365112 * safezoneW + safezoneX;
			y = 0.34974 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
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
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "Remove the gear of target"; //--- ToDo: Localize;
		};
		class NR_PM_custom1: n_RscButtonMenu
		{
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1023;

			text = "Custom #1"; //--- ToDo: Localize;
			x = 0.365112 * safezoneW + safezoneX;
			y = 0.54774 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class NR_PM_custom2: n_RscButtonMenu
		{
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1024;

			text = "Custom #2"; //--- ToDo: Localize;
			x = 0.488862 * safezoneW + safezoneX;
			y = 0.54774 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class NR_PM_Custom3: n_RscButtonMenu
		{
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1025;

			text = "Custom #3"; //--- ToDo: Localize;
			x = 0.365112 * safezoneW + safezoneX;
			y = 0.60274 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class NR_PM_custom4: n_RscButtonMenu
		{
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1026;

			text = "Custom #4"; //--- ToDo: Localize;
			x = 0.488862 * safezoneW + safezoneX;
			y = 0.60274 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class NR_PM_tempban: w_RscButton
		{
			onButtonClick = "[16] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1027;

			text = "Temp-Ban"; //--- ToDo: Localize;
			x = 0.266112 * safezoneW + safezoneX;
			y = 0.88874 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Force target to lobby until the next restart"; //--- ToDo: Localize;
		};
		class NR_PM_ban: w_RscButton
		{
			onButtonClick = "[19] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1028;

			text = "Ban"; //--- ToDo: Localize;
			x = 0.356862 * safezoneW + safezoneX;
			y = 0.88874 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Ban the target"; //--- ToDo: Localize;
		};
		class NR_PM_exec: w_RscButton
		{
			idc = 55506;
			onButtonClick = "[17] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			text = "Execute Code"; //--- ToDo: Localize;
			x = 0.266112 * safezoneW + safezoneX;
			y = 0.83374 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Execute code on target"; //--- ToDo: Localize;
		};
		class NR_PM_showmap: w_RscButton
		{
			idc = 55506;
			onButtonClick = "[18] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			text = "Teleport Target"; //--- ToDo: Localize;
			x = 0.356862 * safezoneW + safezoneX;
			y = 0.83374 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Show the target on map"; //--- ToDo: Localize;
		};
		class DialogTitleText: w_RscText
		{
			idc = 1002;

			text = "Player Menu"; //--- ToDo: Localize;
			x = 0.1733 * safezoneW + safezoneX;
			y = 0.04724 * safezoneH + safezoneY;
			w = 0.0844792 * safezoneW;
			h = 0.0448149 * safezoneH;
			sizeEx = (			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1) * GUI_GRID_H;
		};
		class NR_PM_customA: n_RscButtonMenu
		{
			idc = 55506;
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			text = "Custom #A"; //--- ToDo: Localize;
			x = 0.447612 * safezoneW + safezoneX;
			y = 0.83374 * safezoneH + safezoneY;
			w = 0.10725 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
			tooltip = "Show the target on map"; //--- ToDo: Localize;
		};
		class NR_PM_customB: n_RscButtonMenu
		{
			idc = 55506;
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";

			text = "Custom #B"; //--- ToDo: Localize;
			x = 0.447612 * safezoneW + safezoneX;
			y = 0.88874 * safezoneH + safezoneY;
			w = 0.10725 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
			tooltip = "Show the target on map"; //--- ToDo: Localize;
		};
		class NR_PM_Repair: w_RscButton
		{
			onButtonClick = "[14] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 55508;

			text = "Repair"; //--- ToDo: Localize;
			x = 0.365112 * safezoneW + safezoneX;
			y = 0.40474 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "Repair target vehicle"; //--- ToDo: Localize;
		};
		class NR_PM_Flip: w_RscButton
		{
			onButtonClick = "[15] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 55509;

			text = "Flip"; //--- ToDo: Localize;
			x = 0.488862 * safezoneW + safezoneX;
			y = 0.40474 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
			tooltip = "Flip target vehicle"; //--- ToDo: Localize;
		};
		class n_playerFrame: RscFrame
		{
			idc = 1800;

			x = 0.167112 * safezoneW + safezoneX;
			y = 0.10774 * safezoneH + safezoneY;
			w = 0.17325 * safezoneW;
			h = 0.704 * safezoneH;
		};
		class PlayerTargetOutput: n_RscOutput
		{
			idc = 55528;

			x = 0.647675 * safezoneW + safezoneX;
			y = 0.14074 * safezoneH + safezoneY;
			w = 0.160875 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class PlayerUIDText: w_RscText
		{
			idc = 55510;

			text = "UID:"; //--- ToDo: Localize;
			x = 0.604362 * safezoneW + safezoneX;
			y = 0.17374 * safezoneH + safezoneY;
			w = 0.0495 * safezoneW;
			h = 0.0275 * safezoneH;
		};
		class PlayerUIDOutput: n_RscOutput
		{
			idc = 55511;

			x = 0.647675 * safezoneW + safezoneX;
			y = 0.17374 * safezoneH + safezoneY;
			w = 0.160875 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class PlayerHealthText: w_RscText
		{
			idc = 55512;

			text = "Health:"; //--- ToDo: Localize;
			x = 0.604362 * safezoneW + safezoneX;
			y = 0.20674 * safezoneH + safezoneY;
			w = 0.0495 * safezoneW;
			h = 0.0275 * safezoneH;
		};
		class PlayerWeaponsText: w_RscText
		{
			idc = 55513;

			text = "Weapons:"; //--- ToDo: Localize;
			x = 0.604362 * safezoneW + safezoneX;
			y = 0.23974 * safezoneH + safezoneY;
			w = 0.0495 * safezoneW;
			h = 0.0275 * safezoneH;
		};
		class PlayerItemsText: w_RscText
		{
			idc = 55514;

			text = "Vehicle:"; //--- ToDo: Localize;
			x = 0.604362 * safezoneW + safezoneX;
			y = 0.27274 * safezoneH + safezoneY;
			w = 0.0495 * safezoneW;
			h = 0.0275 * safezoneH;
		};
		class PlayerPositionText: w_RscText
		{
			idc = 55515;

			text = "Position:"; //--- ToDo: Localize;
			x = 0.604362 * safezoneW + safezoneX;
			y = 0.30574 * safezoneH + safezoneY;
			w = 0.0495 * safezoneW;
			h = 0.0275 * safezoneH;
		};
		class PlayerSideText: w_RscText
		{
			idc = 55516;

			text = "Side:"; //--- ToDo: Localize;
			x = 0.604362 * safezoneW + safezoneX;
			y = 0.33874 * safezoneH + safezoneY;
			w = 0.0495 * safezoneW;
			h = 0.0275 * safezoneH;
		};
		class PlayerKillsText: w_RscText
		{
			idc = 55517;

			text = "Kills:"; //--- ToDo: Localize;
			x = 0.604362 * safezoneW + safezoneX;
			y = 0.37174 * safezoneH + safezoneY;
			w = 0.0495 * safezoneW;
			h = 0.0275 * safezoneH;
		};
		class PlayerDeathsText: w_RscText
		{
			idc = 55518;

			text = "Deaths:"; //--- ToDo: Localize;
			x = 0.604362 * safezoneW + safezoneX;
			y = 0.40474 * safezoneH + safezoneY;
			w = 0.0495 * safezoneW;
			h = 0.0275 * safezoneH;
		};
		class PlayerSquadText: w_RscText
		{
			idc = 55519;

			text = "Squad:"; //--- ToDo: Localize;
			x = 0.604362 * safezoneW + safezoneX;
			y = 0.43774 * safezoneH + safezoneY;
			w = 0.0495 * safezoneW;
			h = 0.0275 * safezoneH;
		};
		class PlayerHealthOutput: n_RscOutput
		{
			idc = 55520;

			x = 0.647675 * safezoneW + safezoneX;
			y = 0.20674 * safezoneH + safezoneY;
			w = 0.160875 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class PlayerWeaponsOutput: n_RscOutput
		{
			idc = 55521;

			x = 0.647675 * safezoneW + safezoneX;
			y = 0.23974 * safezoneH + safezoneY;
			w = 0.160875 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class PlayerItemsOutput: n_RscOutput
		{
			idc = 55522;

			x = 0.647675 * safezoneW + safezoneX;
			y = 0.27274 * safezoneH + safezoneY;
			w = 0.160875 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class PlayerPositionOutput: n_RscOutput
		{
			idc = 55523;

			x = 0.647675 * safezoneW + safezoneX;
			y = 0.30574 * safezoneH + safezoneY;
			w = 0.160875 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class PlayerSideOutput: n_RscOutput
		{
			idc = 55524;

			x = 0.647675 * safezoneW + safezoneX;
			y = 0.33874 * safezoneH + safezoneY;
			w = 0.160875 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class PlayerKillsOutput: n_RscOutput
		{
			idc = 55525;

			x = 0.647675 * safezoneW + safezoneX;
			y = 0.37174 * safezoneH + safezoneY;
			w = 0.160875 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class PlayerDeathsOutput: n_RscOutput
		{
			idc = 55526;

			x = 0.647675 * safezoneW + safezoneX;
			y = 0.40474 * safezoneH + safezoneY;
			w = 0.160875 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class PlayerSquadOutput: n_RscOutput
		{
			idc = 55527;

			x = 0.647675 * safezoneW + safezoneX;
			y = 0.43774 * safezoneH + safezoneY;
			w = 0.160875 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class RscSquadPlayerList: w_RscList
		{
			idc = 55529;

			x = 0.668299 * safezoneW + safezoneX;
			y = 0.65224 * safezoneH + safezoneY;
			w = 0.136125 * safezoneW;
			h = 0.1155 * safezoneH;
		};
		class PlayerSquadPlayersText: w_RscText
		{
			idc = 55530;

			text = "Squad Players:"; //--- ToDo: Localize;
			x = 0.604362 * safezoneW + safezoneX;
			y = 0.65774 * safezoneH + safezoneY;
			w = 0.05775 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class NR_PM_Custom5: n_RscButtonMenu
		{
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1025;

			text = "Custom #5"; //--- ToDo: Localize;
			x = 0.365112 * safezoneW + safezoneX;
			y = 0.65774 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class NR_PM_Custom6: n_RscButtonMenu
		{
			onButtonClick = "[4] execVM 'addons\admin\client\systems\adminPanel\playerSelect.sqf'";
			idc = 1026;

			text = "Custom #6"; //--- ToDo: Localize;
			x = 0.488862 * safezoneW + safezoneX;
			y = 0.65774 * safezoneH + safezoneY;
			w = 0.0825 * safezoneW;
			h = 0.033 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.6};
		};
		class customXOutput: n_RscOutput
		{
			idc = 55531;

			x = 0.647675 * safezoneW + safezoneX;
			y = 0.47074 * safezoneH + safezoneY;
			w = 0.160875 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class customYOutput: n_RscOutput
		{
			idc = 55532;

			x = 0.647675 * safezoneW + safezoneX;
			y = 0.50374 * safezoneH + safezoneY;
			w = 0.160875 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class customZOutput: n_RscOutput
		{
			idc = 55533;

			x = 0.647675 * safezoneW + safezoneX;
			y = 0.53674 * safezoneH + safezoneY;
			w = 0.160875 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
		};
		class customXText: w_RscText
		{
			idc = 55534;

			text = "Custom X:"; //--- ToDo: Localize;
			x = 0.604362 * safezoneW + safezoneX;
			y = 0.47074 * safezoneH + safezoneY;
			w = 0.0495 * safezoneW;
			h = 0.0275 * safezoneH;
		};
		class customYText: w_RscText
		{
			idc = 55535;

			text = "Custom Y:"; //--- ToDo: Localize;
			x = 0.604362 * safezoneW + safezoneX;
			y = 0.50374 * safezoneH + safezoneY;
			w = 0.0495 * safezoneW;
			h = 0.0275 * safezoneH;
		};
		class customZText: w_RscText
		{
			idc = 55536;

			text = "Custom Z:"; //--- ToDo: Localize;
			x = 0.604362 * safezoneW + safezoneX;
			y = 0.53674 * safezoneH + safezoneY;
			w = 0.0495 * safezoneW;
			h = 0.0275 * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////


	};
};