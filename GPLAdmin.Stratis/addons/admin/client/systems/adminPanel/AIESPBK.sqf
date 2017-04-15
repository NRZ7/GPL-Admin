// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2014 A3Wasteland.com *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: AIESP.sqf
//	@file Author: Tonic, AgentRev, NRZ7
//	@file Created: 15/04/2017
//	@file Args:

if ((getPlayerUID player) call isAdmin) then
{
	if(isNil "NR_toggleAIESP") then
	{
		NR_toggleAIESP = false;
	};
	if (!NR_toggleAIESP) then 
	{ 
		hint "NPC 3DMarkers ON";
		NR_toggleAIESP=true;
		onEachFrame 
		{ 
		private["_vis","_pos","_groupIcon","_iconColor"]; 
			{ 
				if(!isPlayer _x && player distance _x < 2500 && _x != player) then 
				{ 
					switch (side _x) do
								{
									case WEST:      { _groupIcon = "\a3\ui_f\data\map\Markers\Military\arrow2_CA.paa"; _iconColor = [0, 0, 1, 1] }; /*b_inf.paa*/
									case EAST:       { _groupIcon = "\a3\ui_f\data\map\Markers\NATO\o_inf.paa"; _iconColor = [1, 0, 0, 1] };
									case resistance: { _groupIcon = "\a3\ui_f\data\map\Markers\NATO\n_inf.paa"; _iconColor = [1, 1, 0, 1] };
									default           { _groupIcon = "\a3\ui_f\data\map\Markers\NATO\c_unknown.paa"; _iconColor = [1, 1, 1, 1] };
								};
							   _pos = visiblePosition _x; 
							   _pos set[2,(getPosATL _x select 2) + 2.2]; 
							   drawIcon3D [_groupIcon,_iconColor,_pos,0.5,0.5,180,format ["[%1] %2",round (_x distance player),name _x],0,0.04]; 
				}; 
			} foreach allUnits; 
		};
	} else 
	{ 
		NR_toggleAIESP=false;
		hint "NPC 3DMarkers OFF";
		onEachFrame {};		
	};
};
	

