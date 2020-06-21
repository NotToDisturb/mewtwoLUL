Forest_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Forest_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Forest_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Forest_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_FOREST_STATE, 0, Forest_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	map_script_2 VAR_FOREST_STATE, 2, Forest_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1
	.2byte 0

Forest_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_FOREST
	setvar VAR_FOREST_STATE, 1
	return

Forest_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1:
	removeobject 1, MAP_FOREST
	removeobject 2, MAP_FOREST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	setvar VAR_FOREST_STATE, 3
	return

Forest_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_FOREST_STATE, 1, Forest_ChildrenRun
	map_script_2 VAR_FOREST_STATE, 3, Forest_PlayerSequence
	.2byte 0


Forest_ChildrenRun::
	applymovement 1, ObjectGetAttentionLeft
	waitmovement 1
	msgbox Forest_ChildrenRun_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement 2, ObjectGetAttentionLeft
	waitmovement 2
	msgbox Forest_ChildrenRun_Text_1, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Child1RunRight
	applymovement OBJ_EVENT_ID_PLAYER, CameraRunRight
	applymovement 2, Child2RunRight
	waitmovement 1
	delay 16
	turnobject 1, DIR_NORTH
	delay 32
	turnobject 2, DIR_SOUTH
	delay 64
	turnobject 1, DIR_SOUTH
	delay 24
	turnobject 2, DIR_NORTH
	applymovement 1, Common_Movement_QuestionMark
	delay 16
	msgbox Forest_ChildrenRun_Text_2, MSGBOX_DEFAULT
	random 2
	compare VAR_RESULT, 0
	goto_if_eq Forest_ChildrenRun_2
	applymovement 2, ObjectDecideDown
	msgbox Forest_ChildrenRun_Text_4, MSGBOX_DEFAULT
	closemessage
Forest_ChildrenRun_1:
	delay 16
	msgbox Forest_ChildrenRun_Text_5, MSGBOX_DEFAULT
	closemessage
	delay 16
	compare VAR_RESULT, 0
	goto_if_eq Forest_ChildrenRun_6
	applymovement 1, ChildrenRunDown
	applymovement 2, ChildrenRunDown
	waitmovement 1
Forest_ChildrenRun_5:
	setvar VAR_FOREST_STATE, 2
	warpsilent MAP_FOREST, -1, 8, 13
	end

Forest_ChildrenRun_2:
	applymovement 2, ObjectDecideUp
	msgbox Forest_ChildrenRun_Text_3, MSGBOX_DEFAULT
	closemessage
	delay 8
	turnobject 1, DIR_NORTH
	goto Forest_ChildrenRun_1

Forest_ChildrenRun_6:
	applymovement 1, ChildrenRunUp
	applymovement 2, ChildrenRunUp
	waitmovement 2
	goto Forest_ChildrenRun_5


ObjectGetAttentionLeft:
	jump_in_place_left
	jump_in_place_left
	delay_16
	step_end

Child1RunRight:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

CameraRunRight:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_right
	step_end

Child2RunRight:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_slow_right
	step_end

ObjectDecideUp:
	jump_in_place_up
	step_end

ObjectDecideDown:
	jump_in_place_down
	step_end

ChildrenRunDown:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

ChildrenRunUp:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Forest_PlayerSequence::
	msgbox Forest_PlayerSequence_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerStartFreakOut
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, PlayerTryCalmDown
	msgbox Forest_PlayerSequence_Text_1, MSGBOX_DEFAULT
	closemessage
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 24
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	delay 32
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 24
	msgbox Forest_PlayerSequence_Text_2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_FOREST_STATE, 4
	end


PlayerStartFreakOut:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PlayerTryCalmDown:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	step_end

Forest_NotThatWay::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	msgbox Forest_NotThatWay_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, MoveToRight
	waitmovement OBJ_EVENT_ID_PLAYER
	end


MoveToRight:
	walk_right
	step_end

Forest_MewtwoAppearsDown::
	showobjectat 3, MAP_FOREST
	playmoncry SPECIES_MEWTWO, 2
	fadeoutbgm 0
	delay 16
	applymovement 3, MewtwoPopInDown
	delay 32
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	subvar VAR_TEMP_0, 28
	call Forest_PlayerShouldFaceMewtwo
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 3
Forest_MewtwoAppearsDown_2:
	compare VAR_TEMP_0, 5
	goto_if_lt Forest_MewtwoAppearsDown_3
	turnobject 3, DIR_SOUTH
	setobjectnewmovementtype 3, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	end

Forest_MewtwoAppearsDown_3:
	applymovement 3, MewtwoHeadToPlayer
	waitmovement 3
	addvar VAR_TEMP_0, 1
	call Forest_PlayerShouldFaceMewtwo
	goto Forest_MewtwoAppearsDown_2


MewtwoPopInDown:
	walk_down
	walk_left
	walk_down
	walk_down
	jump_2_left
	walk_left
	step_end

MewtwoHeadToPlayer:
	walk_left
	step_end

Forest_PlayerShouldFaceMewtwo::
	compare VAR_TEMP_0, 2
	goto_if_gt Forest_PlayerShouldFaceMewtwo_2
Forest_PlayerShouldFaceMewtwo_1:
	return

Forest_PlayerShouldFaceMewtwo_2:
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto Forest_PlayerShouldFaceMewtwo_1


Forest_MewtwoAppearsUp::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	addvar VAR_TEMP_1, 2
	setobjectxy 3, VAR_TEMP_0, VAR_TEMP_1
	showobjectat 3, MAP_FOREST
	turnobject 3, DIR_NORTH
	setobjectnewmovementtype 3, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	end


Forest_ChildrenRun_Text_0:
	.string "{COLOR GREEN}Johnny: {COLOR DARK_GREY}¡Jajaja! ¡No nos vas a pillar!$"

Forest_ChildrenRun_Text_1:
	.string "{COLOR GREEN}María: {COLOR DARK_GREY}¡Eso es! ¡Corre, corre!$"

Forest_ChildrenRun_Text_2:
	.string "{COLOR GREEN}Johnny: {COLOR DARK_GREY}Oh no, ¿hacia donde vamos?$"

Forest_ChildrenRun_Text_3:
	.string "{COLOR GREEN}María: {COLOR DARK_GREY}¡Por aquí arriba!$"

Forest_ChildrenRun_Text_4:
	.string "{COLOR GREEN}María: {COLOR DARK_GREY}¡Por aquí abajo!$"

Forest_ChildrenRun_Text_5:
	.string "{COLOR GREEN}Johnny: {COLOR DARK_GREY}¡Okey, vamos!$"

Forest_PlayerSequence_Text_0:
	.string "{COLOR BLUE}Benito: {COLOR DARK_GREY}¡Chicos, no corráis tanto!$"

Forest_PlayerSequence_Text_1:
	.string "{COLOR BLUE}Benito: {COLOR DARK_GREY}Lo digo en serio. \nEsperadme por favor.$"

Forest_PlayerSequence_Text_2:
	.string "{COLOR BLUE}Benito: {COLOR DARK_GREY}...\pNo puedo quedarme tan atrás. \nVenga, tengo que alcanzarles.$"

Forest_NotThatWay_Text_0:
	.string "{COLOR BLUE}Benito: {COLOR DARK_GREY}¡María y Johnny no fueron \npor aquí!$"
