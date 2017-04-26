// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2017 NRZ7 *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: ToggleAIESP.sqf
//	@file Author: NRZ7
//	@file Credits: Inspired in tonic-_- https://forums.bistudio.com/forums/topic/158494-how-to-make-3d-wasteland-style-on-screen-player-markers/
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
					_groupIcon = "\a3\ui_f\data\map\Markers\Military\arrow2_CA.paa";
					switch (side _x) do
								{
									case WEST:      	{ _iconColor = [0, 0, 1, 1] }; 
									case EAST:       	{ _iconColor = [1, 0, 0, 1] };
									case resistance: 	{ _iconColor = [1, 1, 0, 1] };
									default           	{ _iconColor = [1, 1, 1, 1] };
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
	

