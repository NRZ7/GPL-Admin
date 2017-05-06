if ((getPlayerUID player) call isAdmin) then
{
	if(isNil "NR_toggleAIESP") then
	{
		NR_toggleAIESP = false;
	};
	
	if (!NR_toggleAIESP) then 
	{ 
		hint "NPC Markers ON";
		NR_toggleAIESP=true;
		
		// 2D Markers
		NR_EH_NPCDraw = findDisplay 12 displayCtrl 51 ctrlAddEventHandler ["Draw", {  
		 private ["_iconColor"];
		 {
		 switch (side _x) do
			{
				case WEST:      { _iconColor = [0, 0, 1, 1] }; 
				case EAST:       { _iconColor = [1, 0, 0, 1] };
				case resistance: { _iconColor = [0.118,1,0,1] };
				default           { _iconColor = [1, 1, 1, 1] };
			};
		  
		_this select 0 drawIcon [  
		  'iconManVirtual',  
		  _iconColor,  
		  getPos _x,  
		  24,  
		  24,  
		  getDir _x,  
		  'AI',  
		  1,  
		  0.05,  
		  'TahomaB',  
		  'right'  
		 ] 
		} foreach allUnits - allPlayers;  
		}];
		
		//3D Markers
		nr_EH_Draw3DNPC = addMissionEventHandler ["Draw3D", 
		{ 
			private["_vis","_pos","_groupIcon","_iconColor"]; 
			{ 
				if(!isPlayer _x && player distance _x < 2500) then 
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
			} foreach allUnits  - allPlayers; 
		}];
	} else 
	{ 
		NR_toggleAIESP=false;
		hint "NPC Markers OFF";
		removeMissionEventHandler ["Draw3D",nr_EH_Draw3DNPC];
		findDisplay 12 displayCtrl 51 ctrlRemoveEventHandler ["Draw", NR_EH_NPCDraw];
	};
};
	


