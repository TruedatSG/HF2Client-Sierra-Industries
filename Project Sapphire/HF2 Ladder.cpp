#include "Hack.h" 

#include <algorithm>

BOOL RegisterLadder()
{
	if (!ClientReady(FALSE))
		return FALSE;

	V_MyLadderStatus = 0;

	LPROSTERUNIT pMe = *p_D2CLIENT_PlayerUnitList;

	if (pMe->dwClassId == CLASS_AMA) { V_ClassFlag = 1; }
	if (pMe->dwClassId == CLASS_SOR) { V_ClassFlag = 2; }
	if (pMe->dwClassId == CLASS_NEC) { V_ClassFlag = 3; }
	if (pMe->dwClassId == CLASS_PAL) { V_ClassFlag = 4; }
	if (pMe->dwClassId == CLASS_BAR) { V_ClassFlag = 5; }
	if (pMe->dwClassId == CLASS_DRU) { V_ClassFlag = 6; }
	if (pMe->dwClassId == CLASS_ASN) { V_ClassFlag = 7; }
	if (V_FLAG == 1) { V_ClassFlag = 8; }
	if (V_FLAG == 2) { V_ClassFlag = 9; }
	if (V_FLAG == 3) { V_ClassFlag = 10; }
	if (V_FLAG == 4) { V_ClassFlag = 11; }
	if (V_FLAG == 5) { V_ClassFlag = 12; }
	if (V_FLAG == 6) { V_ClassFlag = 13; }
	if (V_FLAG == 7) { V_ClassFlag = 14; }
	if (V_FLAG == 8) { V_ClassFlag = 15; }
	if (V_FLAG == 20) { V_ClassFlag = 16; }
	if (V_FLAG == 21) { V_ClassFlag = 17; }
	if (V_FLAG == 22) { V_ClassFlag = 18; }
	if (V_FLAG == 23) { V_ClassFlag = 19; }
	if (V_FLAG == 24) { V_ClassFlag = 20; }
	if (V_FLAG == 25) { V_ClassFlag = 21; }
	if (V_FLAG == 26) { V_ClassFlag = 22; }
	if (V_FLAG == 27) { V_ClassFlag = 23; }
	if (V_FLAG == 28) { V_ClassFlag = 24; }
	if (V_FLAG == 29) { V_ClassFlag = 25; }
	if (V_FLAG == 30) { V_ClassFlag = 26; }
	if (V_FLAG == 31) { V_ClassFlag = 27; }

	if (V_LadderDeath == TRUE)
	{
		if (pMe->dwClassId == CLASS_AMA) { V_ClassFlag = 401; }
		if (pMe->dwClassId == CLASS_SOR) { V_ClassFlag = 402; }
		if (pMe->dwClassId == CLASS_NEC) { V_ClassFlag = 403; }
		if (pMe->dwClassId == CLASS_PAL) { V_ClassFlag = 404; }
		if (pMe->dwClassId == CLASS_BAR) { V_ClassFlag = 405; }
		if (pMe->dwClassId == CLASS_DRU) { V_ClassFlag = 406; }
		if (pMe->dwClassId == CLASS_ASN) { V_ClassFlag = 407; }
		if (V_FLAG == 1) { V_ClassFlag = 408; }
		if (V_FLAG == 2) { V_ClassFlag = 409; }
		if (V_FLAG == 3) { V_ClassFlag = 410; }
		if (V_FLAG == 4) { V_ClassFlag = 411; }
		if (V_FLAG == 5) { V_ClassFlag = 412; }
		if (V_FLAG == 6) { V_ClassFlag = 413; }
		if (V_FLAG == 7) { V_ClassFlag = 414; }
		if (V_FLAG == 8) { V_ClassFlag = 415; }
		if (V_FLAG == 20) { V_ClassFlag = 416; }
		if (V_FLAG == 21) { V_ClassFlag = 417; }
		if (V_FLAG == 22) { V_ClassFlag = 418; }
		if (V_FLAG == 23) { V_ClassFlag = 419; }
		if (V_FLAG == 24) { V_ClassFlag = 420; }
		if (V_FLAG == 25) { V_ClassFlag = 421; }
		if (V_FLAG == 26) { V_ClassFlag = 422; }
		if (V_FLAG == 27) { V_ClassFlag = 423; }
		if (V_FLAG == 28) { V_ClassFlag = 424; }
		if (V_FLAG == 29) { V_ClassFlag = 425; }
		if (V_FLAG == 30) { V_ClassFlag = 426; }
		if (V_FLAG == 31) { V_ClassFlag = 427; }
	}

	strncpy_s(V_MyLadderName, sizeof(V_MyLadderName), Me->pPlayerData->szName, sizeof(V_MyLadderName));
	V_MyLadderClass = V_ClassFlag;
	V_MyLadderLevel = GetUnitStat(Me, STAT_LEVEL);
	if (V_MyLadderLevel == 99)
	{
#ifndef FFXIVMOD
		V_MyLadderExp = 3520485254LL;
#else
		V_MyLadderExp = 1995350;
#endif
	}
	else
	{
		V_MyLadderExp = GetUnitStat(Me, STAT_EXP);
	}
	V_MyLadderRank = V_Rank;

	return TRUE;
}

BOOL UpdateLadder()
{
	if (!ClientReady(FALSE))
		return FALSE;

	if (V_MyLadderLevel == 222)
		return FALSE;

	if (V_MyLadderExp == 222)
		return FALSE;

	if (V_MyLadderExp == 0)
		return FALSE;

	if (V_TempLadderNote[0] != NULL)
	{
		strncpy_s(V_MyLadderNote, sizeof(V_MyLadderNote), V_TempLadderNote, sizeof(V_MyLadderNote));

		V_TempLadderNote[0] = NULL;
	}

	for (INT i = 0; i < MAXLADDER; i++)
	{
		if(V_MyLadderID == V_LadderID[i])
		{
			strncpy_s(V_LadderName[i], sizeof(V_LadderName[i]), Me->pPlayerData->szName, sizeof(V_LadderName[i]));
			V_LadderID[i] = V_MyLadderID;
			V_LadderLevel[i] = V_MyLadderLevel;
			V_LadderClass[i] = V_MyLadderClass;
			V_LadderExp[i] = V_MyLadderExp;
			V_LadderRank[i] = V_MyLadderRank;

			if (V_MyLadderNote[0] != NULL)
			{
				strncpy_s(V_LadderNote[i], sizeof(V_LadderNote[i]), V_MyLadderNote, sizeof(V_LadderNote[i]));
			}

			if (V_ResetLadderNote == TRUE)
			{
				V_LadderNote[i][0] = NULL;

				V_ResetLadderNote = FALSE;
			}

			V_MyLadderExp = -1;

			V_MyLadderStatus = 1;

			return FALSE;
		}
	}

	return FALSE;
}

BOOL SortLadder()
{ 	
	INT64 arr[] = {
		V_LadderExp[0], V_LadderExp[1], V_LadderExp[2], V_LadderExp[3], V_LadderExp[4], V_LadderExp[5], 
		V_LadderExp[6], V_LadderExp[7], V_LadderExp[8], V_LadderExp[9], V_LadderExp[10], V_LadderExp[11], V_LadderExp[12],
		V_LadderExp[13], V_LadderExp[14], V_LadderExp[15], V_LadderExp[16], V_LadderExp[17], V_LadderExp[18], V_LadderExp[19], 
		V_LadderExp[20], V_LadderExp[21], V_LadderExp[22], V_LadderExp[23], V_LadderExp[24], V_LadderExp[25], V_LadderExp[26],
		V_LadderExp[27], V_LadderExp[28], V_LadderExp[29], V_LadderExp[30], V_LadderExp[31], V_LadderExp[32], V_LadderExp[33],
		V_LadderExp[34], V_LadderExp[35], V_LadderExp[36], V_LadderExp[37], V_LadderExp[38], V_LadderExp[39], V_LadderExp[40],
		V_LadderExp[41], V_LadderExp[42], V_LadderExp[43], V_LadderExp[44], V_LadderExp[45], V_LadderExp[46], V_LadderExp[47],
		V_LadderExp[48], V_LadderExp[49], V_LadderExp[50], V_LadderExp[51], V_LadderExp[52], V_LadderExp[53], V_LadderExp[54],
		V_LadderExp[55], V_LadderExp[56], V_LadderExp[57], V_LadderExp[58], V_LadderExp[59], V_LadderExp[60], V_LadderExp[61],
		V_LadderExp[62], V_LadderExp[63], V_LadderExp[64], V_LadderExp[65], V_LadderExp[66], V_LadderExp[67], V_LadderExp[68],
		V_LadderExp[69], V_LadderExp[70], V_LadderExp[71], V_LadderExp[72], V_LadderExp[73], V_LadderExp[74], V_LadderExp[75],
		V_LadderExp[76], V_LadderExp[77], V_LadderExp[78], V_LadderExp[79], V_LadderExp[80], V_LadderExp[81], V_LadderExp[82],
		V_LadderExp[83], V_LadderExp[84], V_LadderExp[85], V_LadderExp[86], V_LadderExp[87], V_LadderExp[88], V_LadderExp[89],
		V_LadderExp[90], V_LadderExp[91], V_LadderExp[92], V_LadderExp[93], V_LadderExp[94], V_LadderExp[95], V_LadderExp[96],
		V_LadderExp[97], V_LadderExp[98], V_LadderExp[99], V_LadderExp[100], V_LadderExp[101], V_LadderExp[102], V_LadderExp[103],
		V_LadderExp[104], V_LadderExp[105], V_LadderExp[106], V_LadderExp[107], V_LadderExp[108], V_LadderExp[109], V_LadderExp[110],
		V_LadderExp[111], V_LadderExp[112], V_LadderExp[113], V_LadderExp[114], V_LadderExp[115], V_LadderExp[116], V_LadderExp[117],
		V_LadderExp[118], V_LadderExp[119], V_LadderExp[120], V_LadderExp[121], V_LadderExp[122], V_LadderExp[123], V_LadderExp[124],
		V_LadderExp[125], V_LadderExp[126], V_LadderExp[127], V_LadderExp[128], V_LadderExp[129], V_LadderExp[130], V_LadderExp[131],
		V_LadderExp[132], V_LadderExp[133], V_LadderExp[134], V_LadderExp[135], V_LadderExp[136], V_LadderExp[137], V_LadderExp[138],
		V_LadderExp[139], V_LadderExp[140], V_LadderExp[141], V_LadderExp[142], V_LadderExp[143], V_LadderExp[144], V_LadderExp[145],
		V_LadderExp[146], V_LadderExp[147], V_LadderExp[148], V_LadderExp[149], V_LadderExp[150], V_LadderExp[151], V_LadderExp[152],
		V_LadderExp[153], V_LadderExp[154], V_LadderExp[155], V_LadderExp[156], V_LadderExp[157], V_LadderExp[158], V_LadderExp[159],
		V_LadderExp[160], V_LadderExp[161], V_LadderExp[162], V_LadderExp[163], V_LadderExp[164], V_LadderExp[165], V_LadderExp[166],
		V_LadderExp[167], V_LadderExp[168], V_LadderExp[169], V_LadderExp[170], V_LadderExp[171], V_LadderExp[172], V_LadderExp[173],
		V_LadderExp[174], V_LadderExp[175], V_LadderExp[176], V_LadderExp[177], V_LadderExp[178], V_LadderExp[179], V_LadderExp[180],
		V_LadderExp[181], V_LadderExp[182], V_LadderExp[183], V_LadderExp[184], V_LadderExp[185], V_LadderExp[186], V_LadderExp[187],
		V_LadderExp[188], V_LadderExp[189], V_LadderExp[190], V_LadderExp[191], V_LadderExp[192], V_LadderExp[193], V_LadderExp[194],
		V_LadderExp[195], V_LadderExp[196], V_LadderExp[197], V_LadderExp[198], V_LadderExp[199], V_LadderExp[200], V_LadderExp[201],
		V_LadderExp[202], V_LadderExp[203], V_LadderExp[204], V_LadderExp[205], V_LadderExp[206], V_LadderExp[207], V_LadderExp[208],
		V_LadderExp[209], V_LadderExp[210], V_LadderExp[211], V_LadderExp[212], V_LadderExp[213], V_LadderExp[214], V_LadderExp[215],
		V_LadderExp[216], V_LadderExp[217], V_LadderExp[218], V_LadderExp[219], V_LadderExp[220], V_LadderExp[221], V_LadderExp[222],
		V_LadderExp[223], V_LadderExp[224], V_LadderExp[225], V_LadderExp[226], V_LadderExp[227], V_LadderExp[228], V_LadderExp[229],
		V_LadderExp[230], V_LadderExp[231], V_LadderExp[232], V_LadderExp[233], V_LadderExp[234], V_LadderExp[235], V_LadderExp[236],
		V_LadderExp[237], V_LadderExp[238], V_LadderExp[239], V_LadderExp[240], V_LadderExp[241], V_LadderExp[242], V_LadderExp[243],
		V_LadderExp[244], V_LadderExp[245], V_LadderExp[246], V_LadderExp[247], V_LadderExp[248], V_LadderExp[249], V_LadderExp[250],
		V_LadderExp[251], V_LadderExp[252], V_LadderExp[253], V_LadderExp[254], V_LadderExp[255], V_LadderExp[256], V_LadderExp[257],
		V_LadderExp[258], V_LadderExp[259], V_LadderExp[260], V_LadderExp[261], V_LadderExp[262], V_LadderExp[263], V_LadderExp[264], 
		V_LadderExp[265], V_LadderExp[266], V_LadderExp[267], V_LadderExp[268], V_LadderExp[269], V_LadderExp[270], V_LadderExp[271],
		V_LadderExp[272], V_LadderExp[273], V_LadderExp[274], V_LadderExp[275], V_LadderExp[276], V_LadderExp[277], V_LadderExp[278],
		V_LadderExp[279], V_LadderExp[280], V_LadderExp[281], V_LadderExp[282], V_LadderExp[283], V_LadderExp[284], V_LadderExp[285],
		V_LadderExp[286], V_LadderExp[287], V_LadderExp[288], V_LadderExp[289], V_LadderExp[290], V_LadderExp[291], V_LadderExp[292], 
		V_LadderExp[293], V_LadderExp[294], V_LadderExp[295], V_LadderExp[296], V_LadderExp[297], V_LadderExp[298], V_LadderExp[299], 
		V_LadderExp[300], V_LadderExp[301], V_LadderExp[302], V_LadderExp[303], V_LadderExp[304], V_LadderExp[305], V_LadderExp[306], 
		V_LadderExp[307], V_LadderExp[308], V_LadderExp[309], V_LadderExp[310], V_LadderExp[311], V_LadderExp[312], V_LadderExp[313],
		V_LadderExp[314], V_LadderExp[315], V_LadderExp[316], V_LadderExp[317], V_LadderExp[318], V_LadderExp[319], V_LadderExp[320],
		V_LadderExp[321], V_LadderExp[322], V_LadderExp[323], V_LadderExp[324], V_LadderExp[325], V_LadderExp[326], V_LadderExp[327],
		V_LadderExp[328], V_LadderExp[329], V_LadderExp[330], V_LadderExp[331], V_LadderExp[332], V_LadderExp[333], V_LadderExp[334], 
		V_LadderExp[335], V_LadderExp[336], V_LadderExp[337], V_LadderExp[338], V_LadderExp[339], V_LadderExp[340], V_LadderExp[341],
		V_LadderExp[342], V_LadderExp[343], V_LadderExp[344], V_LadderExp[345], V_LadderExp[346], V_LadderExp[347], V_LadderExp[348],
		V_LadderExp[349], V_LadderExp[350], V_LadderExp[351], V_LadderExp[352], V_LadderExp[353], V_LadderExp[354], V_LadderExp[355],
		V_LadderExp[356], V_LadderExp[357], V_LadderExp[358], V_LadderExp[359], V_LadderExp[360], V_LadderExp[361], V_LadderExp[362],
		V_LadderExp[363], V_LadderExp[364], V_LadderExp[365], V_LadderExp[366], V_LadderExp[367], V_LadderExp[368], V_LadderExp[369],
		V_LadderExp[370], V_LadderExp[371], V_LadderExp[372], V_LadderExp[373], V_LadderExp[374], V_LadderExp[375], V_LadderExp[376],
		V_LadderExp[377], V_LadderExp[378], V_LadderExp[379], V_LadderExp[380], V_LadderExp[381], V_LadderExp[382], V_LadderExp[383],
		V_LadderExp[384], V_LadderExp[385], V_LadderExp[386], V_LadderExp[387], V_LadderExp[388], V_LadderExp[389], V_LadderExp[390],
		V_LadderExp[391], V_LadderExp[392], V_LadderExp[393], V_LadderExp[394], V_LadderExp[395], V_LadderExp[396], V_LadderExp[397],
		V_LadderExp[398], V_LadderExp[399], V_LadderExp[400], V_LadderExp[401], V_LadderExp[402], V_LadderExp[403], V_LadderExp[404],
		V_LadderExp[405], V_LadderExp[406], V_LadderExp[407], V_LadderExp[408], V_LadderExp[409], V_LadderExp[410], V_LadderExp[411],
		V_LadderExp[412], V_LadderExp[413], V_LadderExp[414], V_LadderExp[415], V_LadderExp[416], V_LadderExp[417], V_LadderExp[418],
		V_LadderExp[419], V_LadderExp[420], V_LadderExp[421], V_LadderExp[422], V_LadderExp[423], V_LadderExp[424], V_LadderExp[425],
		V_LadderExp[426], V_LadderExp[427], V_LadderExp[428], V_LadderExp[429], V_LadderExp[430], V_LadderExp[431], V_LadderExp[432],
		V_LadderExp[433], V_LadderExp[434], V_LadderExp[435], V_LadderExp[436], V_LadderExp[437], V_LadderExp[438], V_LadderExp[439],
		V_LadderExp[440], V_LadderExp[441], V_LadderExp[442], V_LadderExp[443], V_LadderExp[444], V_LadderExp[445], V_LadderExp[446],
		V_LadderExp[447], V_LadderExp[448], V_LadderExp[449], V_LadderExp[450], V_LadderExp[451], V_LadderExp[452], V_LadderExp[453],
		V_LadderExp[454], V_LadderExp[455], V_LadderExp[456], V_LadderExp[457], V_LadderExp[458], V_LadderExp[459], V_LadderExp[460],
		V_LadderExp[461], V_LadderExp[462], V_LadderExp[463], V_LadderExp[464], V_LadderExp[465], V_LadderExp[466], V_LadderExp[467],
		V_LadderExp[468], V_LadderExp[469], V_LadderExp[470], V_LadderExp[471], V_LadderExp[472], V_LadderExp[473], V_LadderExp[474],
		V_LadderExp[475], V_LadderExp[476], V_LadderExp[477], V_LadderExp[478], V_LadderExp[479], V_LadderExp[480], V_LadderExp[481],
		V_LadderExp[482], V_LadderExp[483], V_LadderExp[484], V_LadderExp[485], V_LadderExp[486], V_LadderExp[487], V_LadderExp[488],
		V_LadderExp[489], V_LadderExp[490], V_LadderExp[491], V_LadderExp[492], V_LadderExp[493], V_LadderExp[494], V_LadderExp[495],
		V_LadderExp[496], V_LadderExp[497], V_LadderExp[498], V_LadderExp[499], V_LadderExp[500], V_LadderExp[501], V_LadderExp[502],
		V_LadderExp[503], V_LadderExp[504], V_LadderExp[505], V_LadderExp[506], V_LadderExp[507], V_LadderExp[508], V_LadderExp[509],
		V_LadderExp[510], V_LadderExp[511], V_LadderExp[512], V_LadderExp[513], V_LadderExp[514], V_LadderExp[515], V_LadderExp[516],
		V_LadderExp[517], V_LadderExp[518], V_LadderExp[519], V_LadderExp[520], V_LadderExp[521], V_LadderExp[522], V_LadderExp[523],
		V_LadderExp[524], V_LadderExp[525], V_LadderExp[526], V_LadderExp[527], V_LadderExp[528], V_LadderExp[529], V_LadderExp[530],
		V_LadderExp[531], V_LadderExp[532], V_LadderExp[533], V_LadderExp[534], V_LadderExp[535], V_LadderExp[536], V_LadderExp[537],
		V_LadderExp[538], V_LadderExp[539], V_LadderExp[540], V_LadderExp[541], V_LadderExp[542], V_LadderExp[543], V_LadderExp[544],
		V_LadderExp[545], V_LadderExp[546], V_LadderExp[547], V_LadderExp[548], V_LadderExp[549], V_LadderExp[550], V_LadderExp[551],
		V_LadderExp[552], V_LadderExp[553], V_LadderExp[554], V_LadderExp[555], V_LadderExp[556], V_LadderExp[557], V_LadderExp[558],
		V_LadderExp[559], V_LadderExp[560], V_LadderExp[561], V_LadderExp[562], V_LadderExp[563], V_LadderExp[564], V_LadderExp[565],
		V_LadderExp[566], V_LadderExp[567], V_LadderExp[568], V_LadderExp[569], V_LadderExp[570], V_LadderExp[571], V_LadderExp[572],
		V_LadderExp[573], V_LadderExp[574], V_LadderExp[575], V_LadderExp[576], V_LadderExp[577], V_LadderExp[578], V_LadderExp[579],
		V_LadderExp[580], V_LadderExp[581], V_LadderExp[582], V_LadderExp[583], V_LadderExp[584], V_LadderExp[585], V_LadderExp[586],
		V_LadderExp[587], V_LadderExp[588], V_LadderExp[589], V_LadderExp[590], V_LadderExp[591], V_LadderExp[592], V_LadderExp[593],
		V_LadderExp[594], V_LadderExp[595], V_LadderExp[596], V_LadderExp[597], V_LadderExp[598], V_LadderExp[599], V_LadderExp[600],
		V_LadderExp[601], V_LadderExp[602], V_LadderExp[603], V_LadderExp[604], V_LadderExp[605], V_LadderExp[606], V_LadderExp[607],
		V_LadderExp[608], V_LadderExp[609], V_LadderExp[610], V_LadderExp[611], V_LadderExp[612], V_LadderExp[613], V_LadderExp[614],
		V_LadderExp[615], V_LadderExp[616], V_LadderExp[617], V_LadderExp[618], V_LadderExp[619], V_LadderExp[620], V_LadderExp[621],
		V_LadderExp[622], V_LadderExp[623], V_LadderExp[624], V_LadderExp[625], V_LadderExp[626], V_LadderExp[627], V_LadderExp[628],
		V_LadderExp[629], V_LadderExp[630], V_LadderExp[631], V_LadderExp[632], V_LadderExp[633], V_LadderExp[634], V_LadderExp[635],
		V_LadderExp[636], V_LadderExp[637], V_LadderExp[638], V_LadderExp[639], V_LadderExp[640], V_LadderExp[641], V_LadderExp[642],
		V_LadderExp[643], V_LadderExp[644], V_LadderExp[645], V_LadderExp[646], V_LadderExp[647], V_LadderExp[648], V_LadderExp[649],
		V_LadderExp[650], V_LadderExp[651], V_LadderExp[652], V_LadderExp[653], V_LadderExp[654], V_LadderExp[655], V_LadderExp[656],
		V_LadderExp[657], V_LadderExp[658], V_LadderExp[659], V_LadderExp[660], V_LadderExp[661], V_LadderExp[662], V_LadderExp[663],
		V_LadderExp[664], V_LadderExp[665], V_LadderExp[666], V_LadderExp[667], V_LadderExp[668], V_LadderExp[669], V_LadderExp[670],
		V_LadderExp[671], V_LadderExp[672], V_LadderExp[673], V_LadderExp[674], V_LadderExp[675], V_LadderExp[676], V_LadderExp[677],
		V_LadderExp[678], V_LadderExp[679], V_LadderExp[680], V_LadderExp[681], V_LadderExp[682], V_LadderExp[683], V_LadderExp[684],
		V_LadderExp[685], V_LadderExp[686], V_LadderExp[687], V_LadderExp[688], V_LadderExp[689], V_LadderExp[690], V_LadderExp[691],
		V_LadderExp[692], V_LadderExp[693], V_LadderExp[694], V_LadderExp[695], V_LadderExp[696], V_LadderExp[697], V_LadderExp[698],
		V_LadderExp[699], V_LadderExp[700], V_LadderExp[701], V_LadderExp[702], V_LadderExp[703], V_LadderExp[704], V_LadderExp[705],
		V_LadderExp[706], V_LadderExp[707], V_LadderExp[708], V_LadderExp[709], V_LadderExp[710], V_LadderExp[711], V_LadderExp[712],
		V_LadderExp[713], V_LadderExp[714], V_LadderExp[715], V_LadderExp[716], V_LadderExp[717], V_LadderExp[718], V_LadderExp[719],
		V_LadderExp[720], V_LadderExp[721], V_LadderExp[722], V_LadderExp[723], V_LadderExp[724], V_LadderExp[725], V_LadderExp[726],
		V_LadderExp[727], V_LadderExp[728], V_LadderExp[729], V_LadderExp[730], V_LadderExp[731], V_LadderExp[732], V_LadderExp[733],
		V_LadderExp[734], V_LadderExp[735], V_LadderExp[736], V_LadderExp[737], V_LadderExp[738], V_LadderExp[739], V_LadderExp[740],
		V_LadderExp[741], V_LadderExp[742], V_LadderExp[743], V_LadderExp[744], V_LadderExp[745], V_LadderExp[746], V_LadderExp[747],
		V_LadderExp[748], V_LadderExp[749], V_LadderExp[750], V_LadderExp[751], V_LadderExp[752], V_LadderExp[753], V_LadderExp[754],
		V_LadderExp[755], V_LadderExp[756], V_LadderExp[757], V_LadderExp[758], V_LadderExp[759], V_LadderExp[760], V_LadderExp[761],
		V_LadderExp[762], V_LadderExp[763], V_LadderExp[764], V_LadderExp[765], V_LadderExp[766], V_LadderExp[767], V_LadderExp[768],
		V_LadderExp[769], V_LadderExp[770], V_LadderExp[771], V_LadderExp[772], V_LadderExp[773], V_LadderExp[774], V_LadderExp[775],
		V_LadderExp[776], V_LadderExp[777], V_LadderExp[778], V_LadderExp[779], V_LadderExp[780], V_LadderExp[781], V_LadderExp[782],
		V_LadderExp[783], V_LadderExp[784], V_LadderExp[785], V_LadderExp[786], V_LadderExp[787], V_LadderExp[788], V_LadderExp[789],
		V_LadderExp[790], V_LadderExp[791], V_LadderExp[792], V_LadderExp[793], V_LadderExp[794], V_LadderExp[795], V_LadderExp[796],
		V_LadderExp[797], V_LadderExp[798], V_LadderExp[799], V_LadderExp[800], V_LadderExp[801], V_LadderExp[802], V_LadderExp[803],
		V_LadderExp[804], V_LadderExp[805], V_LadderExp[806], V_LadderExp[807], V_LadderExp[808], V_LadderExp[809], V_LadderExp[810],
		V_LadderExp[811], V_LadderExp[812], V_LadderExp[813], V_LadderExp[814], V_LadderExp[815], V_LadderExp[816], V_LadderExp[817],
		V_LadderExp[818], V_LadderExp[819], V_LadderExp[820], V_LadderExp[821], V_LadderExp[822], V_LadderExp[823], V_LadderExp[824],
		V_LadderExp[825], V_LadderExp[826], V_LadderExp[827], V_LadderExp[828], V_LadderExp[829], V_LadderExp[830], V_LadderExp[831],
		V_LadderExp[832], V_LadderExp[833], V_LadderExp[834], V_LadderExp[835], V_LadderExp[836], V_LadderExp[837], V_LadderExp[838],
		V_LadderExp[839], V_LadderExp[840], V_LadderExp[841], V_LadderExp[842], V_LadderExp[843], V_LadderExp[844], V_LadderExp[845],
		V_LadderExp[846], V_LadderExp[847], V_LadderExp[848], V_LadderExp[849], V_LadderExp[850], V_LadderExp[851], V_LadderExp[852],
		V_LadderExp[853], V_LadderExp[854], V_LadderExp[855], V_LadderExp[856], V_LadderExp[857], V_LadderExp[858], V_LadderExp[859],
		V_LadderExp[860], V_LadderExp[861], V_LadderExp[862], V_LadderExp[863], V_LadderExp[864], V_LadderExp[865], V_LadderExp[866],
		V_LadderExp[867], V_LadderExp[868], V_LadderExp[869], V_LadderExp[870], V_LadderExp[871], V_LadderExp[872], V_LadderExp[873],
		V_LadderExp[874], V_LadderExp[875], V_LadderExp[876], V_LadderExp[877], V_LadderExp[878], V_LadderExp[879], V_LadderExp[880],
		V_LadderExp[881], V_LadderExp[882], V_LadderExp[883], V_LadderExp[884], V_LadderExp[885], V_LadderExp[886], V_LadderExp[887],
		V_LadderExp[888], V_LadderExp[889], V_LadderExp[890], V_LadderExp[891], V_LadderExp[892], V_LadderExp[893], V_LadderExp[894],
		V_LadderExp[895], V_LadderExp[896], V_LadderExp[897], V_LadderExp[898], V_LadderExp[899], V_LadderExp[900], V_LadderExp[901],
		V_LadderExp[902], V_LadderExp[903], V_LadderExp[904], V_LadderExp[905], V_LadderExp[906], V_LadderExp[907], V_LadderExp[908],
		V_LadderExp[909], V_LadderExp[910], V_LadderExp[911], V_LadderExp[912], V_LadderExp[913], V_LadderExp[914], V_LadderExp[915],
		V_LadderExp[916], V_LadderExp[917], V_LadderExp[918], V_LadderExp[919], V_LadderExp[920], V_LadderExp[921], V_LadderExp[922],
		V_LadderExp[923], V_LadderExp[924], V_LadderExp[925], V_LadderExp[926], V_LadderExp[927], V_LadderExp[928], V_LadderExp[929],
		V_LadderExp[930], V_LadderExp[931], V_LadderExp[932], V_LadderExp[933], V_LadderExp[934], V_LadderExp[935], V_LadderExp[936],
		V_LadderExp[937], V_LadderExp[938], V_LadderExp[939], V_LadderExp[940], V_LadderExp[941], V_LadderExp[942], V_LadderExp[943],
		V_LadderExp[944], V_LadderExp[945], V_LadderExp[946], V_LadderExp[947], V_LadderExp[948], V_LadderExp[949], V_LadderExp[950],
		V_LadderExp[951], V_LadderExp[952], V_LadderExp[953], V_LadderExp[954], V_LadderExp[955], V_LadderExp[956], V_LadderExp[957],
		V_LadderExp[958], V_LadderExp[959], V_LadderExp[960], V_LadderExp[961], V_LadderExp[962], V_LadderExp[963], V_LadderExp[964],
		V_LadderExp[965], V_LadderExp[966], V_LadderExp[967], V_LadderExp[968], V_LadderExp[969], V_LadderExp[970], V_LadderExp[971],
		V_LadderExp[972], V_LadderExp[973], V_LadderExp[974], V_LadderExp[975], V_LadderExp[976], V_LadderExp[977], V_LadderExp[978],
		V_LadderExp[979], V_LadderExp[980], V_LadderExp[981], V_LadderExp[982], V_LadderExp[983], V_LadderExp[984], V_LadderExp[985],
		V_LadderExp[986], V_LadderExp[987], V_LadderExp[988], V_LadderExp[989], V_LadderExp[990], V_LadderExp[991], V_LadderExp[992],
		V_LadderExp[993], V_LadderExp[994], V_LadderExp[995], V_LadderExp[996], V_LadderExp[997], V_LadderExp[998], V_LadderExp[999],
		V_MyLadderExp
	};

	int n = sizeof(arr)/sizeof(arr[0]); 
  
	std::sort(arr, arr+n);

	V_TempLadderExp[0] = arr[1000];
	V_TempLadderExp[1] = arr[999];
	V_TempLadderExp[2] = arr[998];
	V_TempLadderExp[3] = arr[997];
	V_TempLadderExp[4] = arr[996];
	V_TempLadderExp[5] = arr[995];
	V_TempLadderExp[6] = arr[994];
	V_TempLadderExp[7] = arr[993];
	V_TempLadderExp[8] = arr[992];
	V_TempLadderExp[9] = arr[991];
	V_TempLadderExp[10] = arr[990];
	V_TempLadderExp[11] = arr[989];
	V_TempLadderExp[12] = arr[988];
	V_TempLadderExp[13] = arr[987];
	V_TempLadderExp[14] = arr[986];
	V_TempLadderExp[15] = arr[985];
	V_TempLadderExp[16] = arr[984];
	V_TempLadderExp[17] = arr[983];
	V_TempLadderExp[18] = arr[982];
	V_TempLadderExp[19] = arr[981];
	V_TempLadderExp[20] = arr[980];
	V_TempLadderExp[21] = arr[979];
	V_TempLadderExp[22] = arr[978];
	V_TempLadderExp[23] = arr[977];
	V_TempLadderExp[24] = arr[976];
	V_TempLadderExp[25] = arr[975];
	V_TempLadderExp[26] = arr[974];
	V_TempLadderExp[27] = arr[973];
	V_TempLadderExp[28] = arr[972];
	V_TempLadderExp[29] = arr[971];
	V_TempLadderExp[30] = arr[970];
	V_TempLadderExp[31] = arr[969];
	V_TempLadderExp[32] = arr[968];
	V_TempLadderExp[33] = arr[967];
	V_TempLadderExp[34] = arr[966];
	V_TempLadderExp[35] = arr[965];
	V_TempLadderExp[36] = arr[964];
	V_TempLadderExp[37] = arr[963];
	V_TempLadderExp[38] = arr[962];
	V_TempLadderExp[39] = arr[961];
	V_TempLadderExp[40] = arr[960];
	V_TempLadderExp[41] = arr[959];
	V_TempLadderExp[42] = arr[958];
	V_TempLadderExp[43] = arr[957];
	V_TempLadderExp[44] = arr[956];
	V_TempLadderExp[45] = arr[955];
	V_TempLadderExp[46] = arr[954];
	V_TempLadderExp[47] = arr[953];
	V_TempLadderExp[48] = arr[952];
	V_TempLadderExp[49] = arr[951];
	V_TempLadderExp[50] = arr[950];
	V_TempLadderExp[51] = arr[949];
	V_TempLadderExp[52] = arr[948];
	V_TempLadderExp[53] = arr[947];
	V_TempLadderExp[54] = arr[946];
	V_TempLadderExp[55] = arr[945];
	V_TempLadderExp[56] = arr[944];
	V_TempLadderExp[57] = arr[943];
	V_TempLadderExp[58] = arr[942];
	V_TempLadderExp[59] = arr[941];
	V_TempLadderExp[60] = arr[940];
	V_TempLadderExp[61] = arr[939];
	V_TempLadderExp[62] = arr[938];
	V_TempLadderExp[63] = arr[937];
	V_TempLadderExp[64] = arr[936];
	V_TempLadderExp[65] = arr[935];
	V_TempLadderExp[66] = arr[934];
	V_TempLadderExp[67] = arr[933];
	V_TempLadderExp[68] = arr[932];
	V_TempLadderExp[69] = arr[931];
	V_TempLadderExp[70] = arr[930];
	V_TempLadderExp[71] = arr[929];
	V_TempLadderExp[72] = arr[928];
	V_TempLadderExp[73] = arr[927];
	V_TempLadderExp[74] = arr[926];
	V_TempLadderExp[75] = arr[925];
	V_TempLadderExp[76] = arr[924];
	V_TempLadderExp[77] = arr[923];
	V_TempLadderExp[78] = arr[922];
	V_TempLadderExp[79] = arr[921];
	V_TempLadderExp[80] = arr[920];
	V_TempLadderExp[81] = arr[919];
	V_TempLadderExp[82] = arr[918];
	V_TempLadderExp[83] = arr[917];
	V_TempLadderExp[84] = arr[916];
	V_TempLadderExp[85] = arr[915];
	V_TempLadderExp[86] = arr[914];
	V_TempLadderExp[87] = arr[913];
	V_TempLadderExp[88] = arr[912];
	V_TempLadderExp[89] = arr[911];
	V_TempLadderExp[90] = arr[910];
	V_TempLadderExp[91] = arr[909];
	V_TempLadderExp[92] = arr[908];
	V_TempLadderExp[93] = arr[907];
	V_TempLadderExp[94] = arr[906];
	V_TempLadderExp[95] = arr[905];
	V_TempLadderExp[96] = arr[904];
	V_TempLadderExp[97] = arr[903];
	V_TempLadderExp[98] = arr[902];
	V_TempLadderExp[99] = arr[901];
	V_TempLadderExp[100] = arr[900];
	V_TempLadderExp[101] = arr[899];
	V_TempLadderExp[102] = arr[898];
	V_TempLadderExp[103] = arr[897];
	V_TempLadderExp[104] = arr[896];
	V_TempLadderExp[105] = arr[895];
	V_TempLadderExp[106] = arr[894];
	V_TempLadderExp[107] = arr[893];
	V_TempLadderExp[108] = arr[892];
	V_TempLadderExp[109] = arr[891];
	V_TempLadderExp[110] = arr[890];
	V_TempLadderExp[111] = arr[889];
	V_TempLadderExp[112] = arr[888];
	V_TempLadderExp[113] = arr[887];
	V_TempLadderExp[114] = arr[886];
	V_TempLadderExp[115] = arr[885];
	V_TempLadderExp[116] = arr[884];
	V_TempLadderExp[117] = arr[883];
	V_TempLadderExp[118] = arr[882];
	V_TempLadderExp[119] = arr[881];
	V_TempLadderExp[120] = arr[880];
	V_TempLadderExp[121] = arr[879];
	V_TempLadderExp[122] = arr[878];
	V_TempLadderExp[123] = arr[877];
	V_TempLadderExp[124] = arr[876];
	V_TempLadderExp[125] = arr[875];
	V_TempLadderExp[126] = arr[874];
	V_TempLadderExp[127] = arr[873];
	V_TempLadderExp[128] = arr[872];
	V_TempLadderExp[129] = arr[871];
	V_TempLadderExp[130] = arr[870];
	V_TempLadderExp[131] = arr[869];
	V_TempLadderExp[132] = arr[868];
	V_TempLadderExp[133] = arr[867];
	V_TempLadderExp[134] = arr[866];
	V_TempLadderExp[135] = arr[865];
	V_TempLadderExp[136] = arr[864];
	V_TempLadderExp[137] = arr[863];
	V_TempLadderExp[138] = arr[862];
	V_TempLadderExp[139] = arr[861];
	V_TempLadderExp[140] = arr[860];
	V_TempLadderExp[141] = arr[859];
	V_TempLadderExp[142] = arr[858];
	V_TempLadderExp[143] = arr[857];
	V_TempLadderExp[144] = arr[856];
	V_TempLadderExp[145] = arr[855];
	V_TempLadderExp[146] = arr[854];
	V_TempLadderExp[147] = arr[853];
	V_TempLadderExp[148] = arr[852];
	V_TempLadderExp[149] = arr[851];
	V_TempLadderExp[150] = arr[850];
	V_TempLadderExp[151] = arr[849];
	V_TempLadderExp[152] = arr[848];
	V_TempLadderExp[153] = arr[847];
	V_TempLadderExp[154] = arr[846];
	V_TempLadderExp[155] = arr[845];
	V_TempLadderExp[156] = arr[844];
	V_TempLadderExp[157] = arr[843];
	V_TempLadderExp[158] = arr[842];
	V_TempLadderExp[159] = arr[841];
	V_TempLadderExp[160] = arr[840];
	V_TempLadderExp[161] = arr[839];
	V_TempLadderExp[162] = arr[838];
	V_TempLadderExp[163] = arr[837];
	V_TempLadderExp[164] = arr[836];
	V_TempLadderExp[165] = arr[835];
	V_TempLadderExp[166] = arr[834];
	V_TempLadderExp[167] = arr[833];
	V_TempLadderExp[168] = arr[832];
	V_TempLadderExp[169] = arr[831];
	V_TempLadderExp[170] = arr[830];
	V_TempLadderExp[171] = arr[829];
	V_TempLadderExp[172] = arr[828];
	V_TempLadderExp[173] = arr[827];
	V_TempLadderExp[174] = arr[826];
	V_TempLadderExp[175] = arr[825];
	V_TempLadderExp[176] = arr[824];
	V_TempLadderExp[177] = arr[823];
	V_TempLadderExp[178] = arr[822];
	V_TempLadderExp[179] = arr[821];
	V_TempLadderExp[180] = arr[820];
	V_TempLadderExp[181] = arr[819];
	V_TempLadderExp[182] = arr[818];
	V_TempLadderExp[183] = arr[817];
	V_TempLadderExp[184] = arr[816];
	V_TempLadderExp[185] = arr[815];
	V_TempLadderExp[186] = arr[814];
	V_TempLadderExp[187] = arr[813];
	V_TempLadderExp[188] = arr[812];
	V_TempLadderExp[189] = arr[811];
	V_TempLadderExp[190] = arr[810];
	V_TempLadderExp[191] = arr[809];
	V_TempLadderExp[192] = arr[808];
	V_TempLadderExp[193] = arr[807];
	V_TempLadderExp[194] = arr[806];
	V_TempLadderExp[195] = arr[805];
	V_TempLadderExp[196] = arr[804];
	V_TempLadderExp[197] = arr[803];
	V_TempLadderExp[198] = arr[802];
	V_TempLadderExp[199] = arr[801];
	V_TempLadderExp[200] = arr[800];
	V_TempLadderExp[201] = arr[799];
	V_TempLadderExp[202] = arr[798];
	V_TempLadderExp[203] = arr[797];
	V_TempLadderExp[204] = arr[796];
	V_TempLadderExp[205] = arr[795];
	V_TempLadderExp[206] = arr[794];
	V_TempLadderExp[207] = arr[793];
	V_TempLadderExp[208] = arr[792];
	V_TempLadderExp[209] = arr[791];
	V_TempLadderExp[210] = arr[790];
	V_TempLadderExp[211] = arr[789];
	V_TempLadderExp[212] = arr[788];
	V_TempLadderExp[213] = arr[787];
	V_TempLadderExp[214] = arr[786];
	V_TempLadderExp[215] = arr[785];
	V_TempLadderExp[216] = arr[784];
	V_TempLadderExp[217] = arr[783];
	V_TempLadderExp[218] = arr[782];
	V_TempLadderExp[219] = arr[781];
	V_TempLadderExp[220] = arr[780];
	V_TempLadderExp[221] = arr[779];
	V_TempLadderExp[222] = arr[778];
	V_TempLadderExp[223] = arr[777];
	V_TempLadderExp[224] = arr[776];
	V_TempLadderExp[225] = arr[775];
	V_TempLadderExp[226] = arr[774];
	V_TempLadderExp[227] = arr[773];
	V_TempLadderExp[228] = arr[772];
	V_TempLadderExp[229] = arr[771];
	V_TempLadderExp[230] = arr[770];
	V_TempLadderExp[231] = arr[769];
	V_TempLadderExp[232] = arr[768];
	V_TempLadderExp[233] = arr[767];
	V_TempLadderExp[234] = arr[766];
	V_TempLadderExp[235] = arr[765];
	V_TempLadderExp[236] = arr[764];
	V_TempLadderExp[237] = arr[763];
	V_TempLadderExp[238] = arr[762];
	V_TempLadderExp[239] = arr[761];
	V_TempLadderExp[240] = arr[760];
	V_TempLadderExp[241] = arr[759];
	V_TempLadderExp[242] = arr[758];
	V_TempLadderExp[243] = arr[757];
	V_TempLadderExp[244] = arr[756];
	V_TempLadderExp[245] = arr[755];
	V_TempLadderExp[246] = arr[754];
	V_TempLadderExp[247] = arr[753];
	V_TempLadderExp[248] = arr[752];
	V_TempLadderExp[249] = arr[751];
	V_TempLadderExp[250] = arr[750];
	V_TempLadderExp[251] = arr[749];
	V_TempLadderExp[252] = arr[748];
	V_TempLadderExp[253] = arr[747];
	V_TempLadderExp[254] = arr[746];
	V_TempLadderExp[255] = arr[745];
	V_TempLadderExp[256] = arr[744];
	V_TempLadderExp[257] = arr[743];
	V_TempLadderExp[258] = arr[742];
	V_TempLadderExp[259] = arr[741];
	V_TempLadderExp[260] = arr[740];
	V_TempLadderExp[261] = arr[739];
	V_TempLadderExp[262] = arr[738];
	V_TempLadderExp[263] = arr[737];
	V_TempLadderExp[264] = arr[736];
	V_TempLadderExp[265] = arr[735];
	V_TempLadderExp[266] = arr[734];
	V_TempLadderExp[267] = arr[733];
	V_TempLadderExp[268] = arr[732];
	V_TempLadderExp[269] = arr[731];
	V_TempLadderExp[270] = arr[730];
	V_TempLadderExp[271] = arr[729];
	V_TempLadderExp[272] = arr[728];
	V_TempLadderExp[273] = arr[727];
	V_TempLadderExp[274] = arr[726];
	V_TempLadderExp[275] = arr[725];
	V_TempLadderExp[276] = arr[724];
	V_TempLadderExp[277] = arr[723];
	V_TempLadderExp[278] = arr[722];
	V_TempLadderExp[279] = arr[721];
	V_TempLadderExp[280] = arr[720];
	V_TempLadderExp[281] = arr[719];
	V_TempLadderExp[282] = arr[718];
	V_TempLadderExp[283] = arr[717];
	V_TempLadderExp[284] = arr[716];
	V_TempLadderExp[285] = arr[715];
	V_TempLadderExp[286] = arr[714];
	V_TempLadderExp[287] = arr[713];
	V_TempLadderExp[288] = arr[712];
	V_TempLadderExp[289] = arr[711];
	V_TempLadderExp[290] = arr[710];
	V_TempLadderExp[291] = arr[709];
	V_TempLadderExp[292] = arr[708];
	V_TempLadderExp[293] = arr[707];
	V_TempLadderExp[294] = arr[706];
	V_TempLadderExp[295] = arr[705];
	V_TempLadderExp[296] = arr[704];
	V_TempLadderExp[297] = arr[703];
	V_TempLadderExp[298] = arr[702];
	V_TempLadderExp[299] = arr[701];
	V_TempLadderExp[300] = arr[700];
	V_TempLadderExp[301] = arr[699];
	V_TempLadderExp[302] = arr[698];
	V_TempLadderExp[303] = arr[697];
	V_TempLadderExp[304] = arr[696];
	V_TempLadderExp[305] = arr[695];
	V_TempLadderExp[306] = arr[694];
	V_TempLadderExp[307] = arr[693];
	V_TempLadderExp[308] = arr[692];
	V_TempLadderExp[309] = arr[691];
	V_TempLadderExp[310] = arr[690];
	V_TempLadderExp[311] = arr[689];
	V_TempLadderExp[312] = arr[688];
	V_TempLadderExp[313] = arr[687];
	V_TempLadderExp[314] = arr[686];
	V_TempLadderExp[315] = arr[685];
	V_TempLadderExp[316] = arr[684];
	V_TempLadderExp[317] = arr[683];
	V_TempLadderExp[318] = arr[682];
	V_TempLadderExp[319] = arr[681];
	V_TempLadderExp[320] = arr[680];
	V_TempLadderExp[321] = arr[679];
	V_TempLadderExp[322] = arr[678];
	V_TempLadderExp[323] = arr[677];
	V_TempLadderExp[324] = arr[676];
	V_TempLadderExp[325] = arr[675];
	V_TempLadderExp[326] = arr[674];
	V_TempLadderExp[327] = arr[673];
	V_TempLadderExp[328] = arr[672];
	V_TempLadderExp[329] = arr[671];
	V_TempLadderExp[330] = arr[670];
	V_TempLadderExp[331] = arr[669];
	V_TempLadderExp[332] = arr[668];
	V_TempLadderExp[333] = arr[667];
	V_TempLadderExp[334] = arr[666];
	V_TempLadderExp[335] = arr[665];
	V_TempLadderExp[336] = arr[664];
	V_TempLadderExp[337] = arr[663];
	V_TempLadderExp[338] = arr[662];
	V_TempLadderExp[339] = arr[661];
	V_TempLadderExp[340] = arr[660];
	V_TempLadderExp[341] = arr[659];
	V_TempLadderExp[342] = arr[658];
	V_TempLadderExp[343] = arr[657];
	V_TempLadderExp[344] = arr[656];
	V_TempLadderExp[345] = arr[655];
	V_TempLadderExp[346] = arr[654];
	V_TempLadderExp[347] = arr[653];
	V_TempLadderExp[348] = arr[652];
	V_TempLadderExp[349] = arr[651];
	V_TempLadderExp[350] = arr[650];
	V_TempLadderExp[351] = arr[649];
	V_TempLadderExp[352] = arr[648];
	V_TempLadderExp[353] = arr[647];
	V_TempLadderExp[354] = arr[646];
	V_TempLadderExp[355] = arr[645];
	V_TempLadderExp[356] = arr[644];
	V_TempLadderExp[357] = arr[643];
	V_TempLadderExp[358] = arr[642];
	V_TempLadderExp[359] = arr[641];
	V_TempLadderExp[360] = arr[640];
	V_TempLadderExp[361] = arr[639];
	V_TempLadderExp[362] = arr[638];
	V_TempLadderExp[363] = arr[637];
	V_TempLadderExp[364] = arr[636];
	V_TempLadderExp[365] = arr[635];
	V_TempLadderExp[366] = arr[634];
	V_TempLadderExp[367] = arr[633];
	V_TempLadderExp[368] = arr[632];
	V_TempLadderExp[369] = arr[631];
	V_TempLadderExp[370] = arr[630];
	V_TempLadderExp[371] = arr[629];
	V_TempLadderExp[372] = arr[628];
	V_TempLadderExp[373] = arr[627];
	V_TempLadderExp[374] = arr[626];
	V_TempLadderExp[375] = arr[625];
	V_TempLadderExp[376] = arr[624];
	V_TempLadderExp[377] = arr[623];
	V_TempLadderExp[378] = arr[622];
	V_TempLadderExp[379] = arr[621];
	V_TempLadderExp[380] = arr[620];
	V_TempLadderExp[381] = arr[619];
	V_TempLadderExp[382] = arr[618];
	V_TempLadderExp[383] = arr[617];
	V_TempLadderExp[384] = arr[616];
	V_TempLadderExp[385] = arr[615];
	V_TempLadderExp[386] = arr[614];
	V_TempLadderExp[387] = arr[613];
	V_TempLadderExp[388] = arr[612];
	V_TempLadderExp[389] = arr[611];
	V_TempLadderExp[390] = arr[610];
	V_TempLadderExp[391] = arr[609];
	V_TempLadderExp[392] = arr[608];
	V_TempLadderExp[393] = arr[607];
	V_TempLadderExp[394] = arr[606];
	V_TempLadderExp[395] = arr[605];
	V_TempLadderExp[396] = arr[604];
	V_TempLadderExp[397] = arr[603];
	V_TempLadderExp[398] = arr[602];
	V_TempLadderExp[399] = arr[601];
	V_TempLadderExp[400] = arr[600];
	V_TempLadderExp[401] = arr[599];
	V_TempLadderExp[402] = arr[598];
	V_TempLadderExp[403] = arr[597];
	V_TempLadderExp[404] = arr[596];
	V_TempLadderExp[405] = arr[595];
	V_TempLadderExp[406] = arr[594];
	V_TempLadderExp[407] = arr[593];
	V_TempLadderExp[408] = arr[592];
	V_TempLadderExp[409] = arr[591];
	V_TempLadderExp[410] = arr[590];
	V_TempLadderExp[411] = arr[589];
	V_TempLadderExp[412] = arr[588];
	V_TempLadderExp[413] = arr[587];
	V_TempLadderExp[414] = arr[586];
	V_TempLadderExp[415] = arr[585];
	V_TempLadderExp[416] = arr[584];
	V_TempLadderExp[417] = arr[583];
	V_TempLadderExp[418] = arr[582];
	V_TempLadderExp[419] = arr[581];
	V_TempLadderExp[420] = arr[580];
	V_TempLadderExp[421] = arr[579];
	V_TempLadderExp[422] = arr[578];
	V_TempLadderExp[423] = arr[577];
	V_TempLadderExp[424] = arr[576];
	V_TempLadderExp[425] = arr[575];
	V_TempLadderExp[426] = arr[574];
	V_TempLadderExp[427] = arr[573];
	V_TempLadderExp[428] = arr[572];
	V_TempLadderExp[429] = arr[571];
	V_TempLadderExp[430] = arr[570];
	V_TempLadderExp[431] = arr[569];
	V_TempLadderExp[432] = arr[568];
	V_TempLadderExp[433] = arr[567];
	V_TempLadderExp[434] = arr[566];
	V_TempLadderExp[435] = arr[565];
	V_TempLadderExp[436] = arr[564];
	V_TempLadderExp[437] = arr[563];
	V_TempLadderExp[438] = arr[562];
	V_TempLadderExp[439] = arr[561];
	V_TempLadderExp[440] = arr[560];
	V_TempLadderExp[441] = arr[559];
	V_TempLadderExp[442] = arr[558];
	V_TempLadderExp[443] = arr[557];
	V_TempLadderExp[444] = arr[556];
	V_TempLadderExp[445] = arr[555];
	V_TempLadderExp[446] = arr[554];
	V_TempLadderExp[447] = arr[553];
	V_TempLadderExp[448] = arr[552];
	V_TempLadderExp[449] = arr[551];
	V_TempLadderExp[450] = arr[550];
	V_TempLadderExp[451] = arr[549];
	V_TempLadderExp[452] = arr[548];
	V_TempLadderExp[453] = arr[547];
	V_TempLadderExp[454] = arr[546];
	V_TempLadderExp[455] = arr[545];
	V_TempLadderExp[456] = arr[544];
	V_TempLadderExp[457] = arr[543];
	V_TempLadderExp[458] = arr[542];
	V_TempLadderExp[459] = arr[541];
	V_TempLadderExp[460] = arr[540];
	V_TempLadderExp[461] = arr[539];
	V_TempLadderExp[462] = arr[538];
	V_TempLadderExp[463] = arr[537];
	V_TempLadderExp[464] = arr[536];
	V_TempLadderExp[465] = arr[535];
	V_TempLadderExp[466] = arr[534];
	V_TempLadderExp[467] = arr[533];
	V_TempLadderExp[468] = arr[532];
	V_TempLadderExp[469] = arr[531];
	V_TempLadderExp[470] = arr[530];
	V_TempLadderExp[471] = arr[529];
	V_TempLadderExp[472] = arr[528];
	V_TempLadderExp[473] = arr[527];
	V_TempLadderExp[474] = arr[526];
	V_TempLadderExp[475] = arr[525];
	V_TempLadderExp[476] = arr[524];
	V_TempLadderExp[477] = arr[523];
	V_TempLadderExp[478] = arr[522];
	V_TempLadderExp[479] = arr[521];
	V_TempLadderExp[480] = arr[520];
	V_TempLadderExp[481] = arr[519];
	V_TempLadderExp[482] = arr[518];
	V_TempLadderExp[483] = arr[517];
	V_TempLadderExp[484] = arr[516];
	V_TempLadderExp[485] = arr[515];
	V_TempLadderExp[486] = arr[514];
	V_TempLadderExp[487] = arr[513];
	V_TempLadderExp[488] = arr[512];
	V_TempLadderExp[489] = arr[511];
	V_TempLadderExp[490] = arr[510];
	V_TempLadderExp[491] = arr[509];
	V_TempLadderExp[492] = arr[508];
	V_TempLadderExp[493] = arr[507];
	V_TempLadderExp[494] = arr[506];
	V_TempLadderExp[495] = arr[505];
	V_TempLadderExp[496] = arr[504];
	V_TempLadderExp[497] = arr[503];
	V_TempLadderExp[498] = arr[502];
	V_TempLadderExp[499] = arr[501];
	V_TempLadderExp[500] = arr[500];
	V_TempLadderExp[501] = arr[499];
	V_TempLadderExp[502] = arr[498];
	V_TempLadderExp[503] = arr[497];
	V_TempLadderExp[504] = arr[496];
	V_TempLadderExp[505] = arr[495];
	V_TempLadderExp[506] = arr[494];
	V_TempLadderExp[507] = arr[493];
	V_TempLadderExp[508] = arr[492];
	V_TempLadderExp[509] = arr[491];
	V_TempLadderExp[510] = arr[490];
	V_TempLadderExp[511] = arr[489];
	V_TempLadderExp[512] = arr[488];
	V_TempLadderExp[513] = arr[487];
	V_TempLadderExp[514] = arr[486];
	V_TempLadderExp[515] = arr[485];
	V_TempLadderExp[516] = arr[484];
	V_TempLadderExp[517] = arr[483];
	V_TempLadderExp[518] = arr[482];
	V_TempLadderExp[519] = arr[481];
	V_TempLadderExp[520] = arr[480];
	V_TempLadderExp[521] = arr[479];
	V_TempLadderExp[522] = arr[478];
	V_TempLadderExp[523] = arr[477];
	V_TempLadderExp[524] = arr[476];
	V_TempLadderExp[525] = arr[475];
	V_TempLadderExp[526] = arr[474];
	V_TempLadderExp[527] = arr[473];
	V_TempLadderExp[528] = arr[472];
	V_TempLadderExp[529] = arr[471];
	V_TempLadderExp[530] = arr[470];
	V_TempLadderExp[531] = arr[469];
	V_TempLadderExp[532] = arr[468];
	V_TempLadderExp[533] = arr[467];
	V_TempLadderExp[534] = arr[466];
	V_TempLadderExp[535] = arr[465];
	V_TempLadderExp[536] = arr[464];
	V_TempLadderExp[537] = arr[463];
	V_TempLadderExp[538] = arr[462];
	V_TempLadderExp[539] = arr[461];
	V_TempLadderExp[540] = arr[460];
	V_TempLadderExp[541] = arr[459];
	V_TempLadderExp[542] = arr[458];
	V_TempLadderExp[543] = arr[457];
	V_TempLadderExp[544] = arr[456];
	V_TempLadderExp[545] = arr[455];
	V_TempLadderExp[546] = arr[454];
	V_TempLadderExp[547] = arr[453];
	V_TempLadderExp[548] = arr[452];
	V_TempLadderExp[549] = arr[451];
	V_TempLadderExp[550] = arr[450];
	V_TempLadderExp[551] = arr[449];
	V_TempLadderExp[552] = arr[448];
	V_TempLadderExp[553] = arr[447];
	V_TempLadderExp[554] = arr[446];
	V_TempLadderExp[555] = arr[445];
	V_TempLadderExp[556] = arr[444];
	V_TempLadderExp[557] = arr[443];
	V_TempLadderExp[558] = arr[442];
	V_TempLadderExp[559] = arr[441];
	V_TempLadderExp[560] = arr[440];
	V_TempLadderExp[561] = arr[439];
	V_TempLadderExp[562] = arr[438];
	V_TempLadderExp[563] = arr[437];
	V_TempLadderExp[564] = arr[436];
	V_TempLadderExp[565] = arr[435];
	V_TempLadderExp[566] = arr[434];
	V_TempLadderExp[567] = arr[433];
	V_TempLadderExp[568] = arr[432];
	V_TempLadderExp[569] = arr[431];
	V_TempLadderExp[570] = arr[430];
	V_TempLadderExp[571] = arr[429];
	V_TempLadderExp[572] = arr[428];
	V_TempLadderExp[573] = arr[427];
	V_TempLadderExp[574] = arr[426];
	V_TempLadderExp[575] = arr[425];
	V_TempLadderExp[576] = arr[424];
	V_TempLadderExp[577] = arr[423];
	V_TempLadderExp[578] = arr[422];
	V_TempLadderExp[579] = arr[421];
	V_TempLadderExp[580] = arr[420];
	V_TempLadderExp[581] = arr[419];
	V_TempLadderExp[582] = arr[418];
	V_TempLadderExp[583] = arr[417];
	V_TempLadderExp[584] = arr[416];
	V_TempLadderExp[585] = arr[415];
	V_TempLadderExp[586] = arr[414];
	V_TempLadderExp[587] = arr[413];
	V_TempLadderExp[588] = arr[412];
	V_TempLadderExp[589] = arr[411];
	V_TempLadderExp[590] = arr[410];
	V_TempLadderExp[591] = arr[409];
	V_TempLadderExp[592] = arr[408];
	V_TempLadderExp[593] = arr[407];
	V_TempLadderExp[594] = arr[406];
	V_TempLadderExp[595] = arr[405];
	V_TempLadderExp[596] = arr[404];
	V_TempLadderExp[597] = arr[403];
	V_TempLadderExp[598] = arr[402];
	V_TempLadderExp[599] = arr[401];
	V_TempLadderExp[600] = arr[400];
	V_TempLadderExp[601] = arr[399];
	V_TempLadderExp[602] = arr[398];
	V_TempLadderExp[603] = arr[397];
	V_TempLadderExp[604] = arr[396];
	V_TempLadderExp[605] = arr[395];
	V_TempLadderExp[606] = arr[394];
	V_TempLadderExp[607] = arr[393];
	V_TempLadderExp[608] = arr[392];
	V_TempLadderExp[609] = arr[391];
	V_TempLadderExp[610] = arr[390];
	V_TempLadderExp[611] = arr[389];
	V_TempLadderExp[612] = arr[388];
	V_TempLadderExp[613] = arr[387];
	V_TempLadderExp[614] = arr[386];
	V_TempLadderExp[615] = arr[385];
	V_TempLadderExp[616] = arr[384];
	V_TempLadderExp[617] = arr[383];
	V_TempLadderExp[618] = arr[382];
	V_TempLadderExp[619] = arr[381];
	V_TempLadderExp[620] = arr[380];
	V_TempLadderExp[621] = arr[379];
	V_TempLadderExp[622] = arr[378];
	V_TempLadderExp[623] = arr[377];
	V_TempLadderExp[624] = arr[376];
	V_TempLadderExp[625] = arr[375];
	V_TempLadderExp[626] = arr[374];
	V_TempLadderExp[627] = arr[373];
	V_TempLadderExp[628] = arr[372];
	V_TempLadderExp[629] = arr[371];
	V_TempLadderExp[630] = arr[370];
	V_TempLadderExp[631] = arr[369];
	V_TempLadderExp[632] = arr[368];
	V_TempLadderExp[633] = arr[367];
	V_TempLadderExp[634] = arr[366];
	V_TempLadderExp[635] = arr[365];
	V_TempLadderExp[636] = arr[364];
	V_TempLadderExp[637] = arr[363];
	V_TempLadderExp[638] = arr[362];
	V_TempLadderExp[639] = arr[361];
	V_TempLadderExp[640] = arr[360];
	V_TempLadderExp[641] = arr[359];
	V_TempLadderExp[642] = arr[358];
	V_TempLadderExp[643] = arr[357];
	V_TempLadderExp[644] = arr[356];
	V_TempLadderExp[645] = arr[355];
	V_TempLadderExp[646] = arr[354];
	V_TempLadderExp[647] = arr[353];
	V_TempLadderExp[648] = arr[352];
	V_TempLadderExp[649] = arr[351];
	V_TempLadderExp[650] = arr[350];
	V_TempLadderExp[651] = arr[349];
	V_TempLadderExp[652] = arr[348];
	V_TempLadderExp[653] = arr[347];
	V_TempLadderExp[654] = arr[346];
	V_TempLadderExp[655] = arr[345];
	V_TempLadderExp[656] = arr[344];
	V_TempLadderExp[657] = arr[343];
	V_TempLadderExp[658] = arr[342];
	V_TempLadderExp[659] = arr[341];
	V_TempLadderExp[660] = arr[340];
	V_TempLadderExp[661] = arr[339];
	V_TempLadderExp[662] = arr[338];
	V_TempLadderExp[663] = arr[337];
	V_TempLadderExp[664] = arr[336];
	V_TempLadderExp[665] = arr[335];
	V_TempLadderExp[666] = arr[334];
	V_TempLadderExp[667] = arr[333];
	V_TempLadderExp[668] = arr[332];
	V_TempLadderExp[669] = arr[331];
	V_TempLadderExp[670] = arr[330];
	V_TempLadderExp[671] = arr[329];
	V_TempLadderExp[672] = arr[328];
	V_TempLadderExp[673] = arr[327];
	V_TempLadderExp[674] = arr[326];
	V_TempLadderExp[675] = arr[325];
	V_TempLadderExp[676] = arr[324];
	V_TempLadderExp[677] = arr[323];
	V_TempLadderExp[678] = arr[322];
	V_TempLadderExp[679] = arr[321];
	V_TempLadderExp[680] = arr[320];
	V_TempLadderExp[681] = arr[319];
	V_TempLadderExp[682] = arr[318];
	V_TempLadderExp[683] = arr[317];
	V_TempLadderExp[684] = arr[316];
	V_TempLadderExp[685] = arr[315];
	V_TempLadderExp[686] = arr[314];
	V_TempLadderExp[687] = arr[313];
	V_TempLadderExp[688] = arr[312];
	V_TempLadderExp[689] = arr[311];
	V_TempLadderExp[690] = arr[310];
	V_TempLadderExp[691] = arr[309];
	V_TempLadderExp[692] = arr[308];
	V_TempLadderExp[693] = arr[307];
	V_TempLadderExp[694] = arr[306];
	V_TempLadderExp[695] = arr[305];
	V_TempLadderExp[696] = arr[304];
	V_TempLadderExp[697] = arr[303];
	V_TempLadderExp[698] = arr[302];
	V_TempLadderExp[699] = arr[301];
	V_TempLadderExp[700] = arr[300];
	V_TempLadderExp[701] = arr[299];
	V_TempLadderExp[702] = arr[298];
	V_TempLadderExp[703] = arr[297];
	V_TempLadderExp[704] = arr[296];
	V_TempLadderExp[705] = arr[295];
	V_TempLadderExp[706] = arr[294];
	V_TempLadderExp[707] = arr[293];
	V_TempLadderExp[708] = arr[292];
	V_TempLadderExp[709] = arr[291];
	V_TempLadderExp[710] = arr[290];
	V_TempLadderExp[711] = arr[289];
	V_TempLadderExp[712] = arr[288];
	V_TempLadderExp[713] = arr[287];
	V_TempLadderExp[714] = arr[286];
	V_TempLadderExp[715] = arr[285];
	V_TempLadderExp[716] = arr[284];
	V_TempLadderExp[717] = arr[283];
	V_TempLadderExp[718] = arr[282];
	V_TempLadderExp[719] = arr[281];
	V_TempLadderExp[720] = arr[280];
	V_TempLadderExp[721] = arr[279];
	V_TempLadderExp[722] = arr[278];
	V_TempLadderExp[723] = arr[277];
	V_TempLadderExp[724] = arr[276];
	V_TempLadderExp[725] = arr[275];
	V_TempLadderExp[726] = arr[274];
	V_TempLadderExp[727] = arr[273];
	V_TempLadderExp[728] = arr[272];
	V_TempLadderExp[729] = arr[271];
	V_TempLadderExp[730] = arr[270];
	V_TempLadderExp[731] = arr[269];
	V_TempLadderExp[732] = arr[268];
	V_TempLadderExp[733] = arr[267];
	V_TempLadderExp[734] = arr[266];
	V_TempLadderExp[735] = arr[265];
	V_TempLadderExp[736] = arr[264];
	V_TempLadderExp[737] = arr[263];
	V_TempLadderExp[738] = arr[262];
	V_TempLadderExp[739] = arr[261];
	V_TempLadderExp[740] = arr[260];
	V_TempLadderExp[741] = arr[259];
	V_TempLadderExp[742] = arr[258];
	V_TempLadderExp[743] = arr[257];
	V_TempLadderExp[744] = arr[256];
	V_TempLadderExp[745] = arr[255];
	V_TempLadderExp[746] = arr[254];
	V_TempLadderExp[747] = arr[253];
	V_TempLadderExp[748] = arr[252];
	V_TempLadderExp[749] = arr[251];
	V_TempLadderExp[750] = arr[250];
	V_TempLadderExp[751] = arr[249];
	V_TempLadderExp[752] = arr[248];
	V_TempLadderExp[753] = arr[247];
	V_TempLadderExp[754] = arr[246];
	V_TempLadderExp[755] = arr[245];
	V_TempLadderExp[756] = arr[244];
	V_TempLadderExp[757] = arr[243];
	V_TempLadderExp[758] = arr[242];
	V_TempLadderExp[759] = arr[241];
	V_TempLadderExp[760] = arr[240];
	V_TempLadderExp[761] = arr[239];
	V_TempLadderExp[762] = arr[238];
	V_TempLadderExp[763] = arr[237];
	V_TempLadderExp[764] = arr[236];
	V_TempLadderExp[765] = arr[235];
	V_TempLadderExp[766] = arr[234];
	V_TempLadderExp[767] = arr[233];
	V_TempLadderExp[768] = arr[232];
	V_TempLadderExp[769] = arr[231];
	V_TempLadderExp[770] = arr[230];
	V_TempLadderExp[771] = arr[229];
	V_TempLadderExp[772] = arr[228];
	V_TempLadderExp[773] = arr[227];
	V_TempLadderExp[774] = arr[226];
	V_TempLadderExp[775] = arr[225];
	V_TempLadderExp[776] = arr[224];
	V_TempLadderExp[777] = arr[223];
	V_TempLadderExp[778] = arr[222];
	V_TempLadderExp[779] = arr[221];
	V_TempLadderExp[780] = arr[220];
	V_TempLadderExp[781] = arr[219];
	V_TempLadderExp[782] = arr[218];
	V_TempLadderExp[783] = arr[217];
	V_TempLadderExp[784] = arr[216];
	V_TempLadderExp[785] = arr[215];
	V_TempLadderExp[786] = arr[214];
	V_TempLadderExp[787] = arr[213];
	V_TempLadderExp[788] = arr[212];
	V_TempLadderExp[789] = arr[211];
	V_TempLadderExp[790] = arr[210];
	V_TempLadderExp[791] = arr[209];
	V_TempLadderExp[792] = arr[208];
	V_TempLadderExp[793] = arr[207];
	V_TempLadderExp[794] = arr[206];
	V_TempLadderExp[795] = arr[205];
	V_TempLadderExp[796] = arr[204];
	V_TempLadderExp[797] = arr[203];
	V_TempLadderExp[798] = arr[202];
	V_TempLadderExp[799] = arr[201];
	V_TempLadderExp[800] = arr[200];
	V_TempLadderExp[801] = arr[199];
	V_TempLadderExp[802] = arr[198];
	V_TempLadderExp[803] = arr[197];
	V_TempLadderExp[804] = arr[196];
	V_TempLadderExp[805] = arr[195];
	V_TempLadderExp[806] = arr[194];
	V_TempLadderExp[807] = arr[193];
	V_TempLadderExp[808] = arr[192];
	V_TempLadderExp[809] = arr[191];
	V_TempLadderExp[810] = arr[190];
	V_TempLadderExp[811] = arr[189];
	V_TempLadderExp[812] = arr[188];
	V_TempLadderExp[813] = arr[187];
	V_TempLadderExp[814] = arr[186];
	V_TempLadderExp[815] = arr[185];
	V_TempLadderExp[816] = arr[184];
	V_TempLadderExp[817] = arr[183];
	V_TempLadderExp[818] = arr[182];
	V_TempLadderExp[819] = arr[181];
	V_TempLadderExp[820] = arr[180];
	V_TempLadderExp[821] = arr[179];
	V_TempLadderExp[822] = arr[178];
	V_TempLadderExp[823] = arr[177];
	V_TempLadderExp[824] = arr[176];
	V_TempLadderExp[825] = arr[175];
	V_TempLadderExp[826] = arr[174];
	V_TempLadderExp[827] = arr[173];
	V_TempLadderExp[828] = arr[172];
	V_TempLadderExp[829] = arr[171];
	V_TempLadderExp[830] = arr[170];
	V_TempLadderExp[831] = arr[169];
	V_TempLadderExp[832] = arr[168];
	V_TempLadderExp[833] = arr[167];
	V_TempLadderExp[834] = arr[166];
	V_TempLadderExp[835] = arr[165];
	V_TempLadderExp[836] = arr[164];
	V_TempLadderExp[837] = arr[163];
	V_TempLadderExp[838] = arr[162];
	V_TempLadderExp[839] = arr[161];
	V_TempLadderExp[840] = arr[160];
	V_TempLadderExp[841] = arr[159];
	V_TempLadderExp[842] = arr[158];
	V_TempLadderExp[843] = arr[157];
	V_TempLadderExp[844] = arr[156];
	V_TempLadderExp[845] = arr[155];
	V_TempLadderExp[846] = arr[154];
	V_TempLadderExp[847] = arr[153];
	V_TempLadderExp[848] = arr[152];
	V_TempLadderExp[849] = arr[151];
	V_TempLadderExp[850] = arr[150];
	V_TempLadderExp[851] = arr[149];
	V_TempLadderExp[852] = arr[148];
	V_TempLadderExp[853] = arr[147];
	V_TempLadderExp[854] = arr[146];
	V_TempLadderExp[855] = arr[145];
	V_TempLadderExp[856] = arr[144];
	V_TempLadderExp[857] = arr[143];
	V_TempLadderExp[858] = arr[142];
	V_TempLadderExp[859] = arr[141];
	V_TempLadderExp[860] = arr[140];
	V_TempLadderExp[861] = arr[139];
	V_TempLadderExp[862] = arr[138];
	V_TempLadderExp[863] = arr[137];
	V_TempLadderExp[864] = arr[136];
	V_TempLadderExp[865] = arr[135];
	V_TempLadderExp[866] = arr[134];
	V_TempLadderExp[867] = arr[133];
	V_TempLadderExp[868] = arr[132];
	V_TempLadderExp[869] = arr[131];
	V_TempLadderExp[870] = arr[130];
	V_TempLadderExp[871] = arr[129];
	V_TempLadderExp[872] = arr[128];
	V_TempLadderExp[873] = arr[127];
	V_TempLadderExp[874] = arr[126];
	V_TempLadderExp[875] = arr[125];
	V_TempLadderExp[876] = arr[124];
	V_TempLadderExp[877] = arr[123];
	V_TempLadderExp[878] = arr[122];
	V_TempLadderExp[879] = arr[121];
	V_TempLadderExp[880] = arr[120];
	V_TempLadderExp[881] = arr[119];
	V_TempLadderExp[882] = arr[118];
	V_TempLadderExp[883] = arr[117];
	V_TempLadderExp[884] = arr[116];
	V_TempLadderExp[885] = arr[115];
	V_TempLadderExp[886] = arr[114];
	V_TempLadderExp[887] = arr[113];
	V_TempLadderExp[888] = arr[112];
	V_TempLadderExp[889] = arr[111];
	V_TempLadderExp[890] = arr[110];
	V_TempLadderExp[891] = arr[109];
	V_TempLadderExp[892] = arr[108];
	V_TempLadderExp[893] = arr[107];
	V_TempLadderExp[894] = arr[106];
	V_TempLadderExp[895] = arr[105];
	V_TempLadderExp[896] = arr[104];
	V_TempLadderExp[897] = arr[103];
	V_TempLadderExp[898] = arr[102];
	V_TempLadderExp[899] = arr[101];
	V_TempLadderExp[900] = arr[100];
	V_TempLadderExp[901] = arr[99];
	V_TempLadderExp[902] = arr[98];
	V_TempLadderExp[903] = arr[97];
	V_TempLadderExp[904] = arr[96];
	V_TempLadderExp[905] = arr[95];
	V_TempLadderExp[906] = arr[94];
	V_TempLadderExp[907] = arr[93];
	V_TempLadderExp[908] = arr[92];
	V_TempLadderExp[909] = arr[91];
	V_TempLadderExp[910] = arr[90];
	V_TempLadderExp[911] = arr[89];
	V_TempLadderExp[912] = arr[88];
	V_TempLadderExp[913] = arr[87];
	V_TempLadderExp[914] = arr[86];
	V_TempLadderExp[915] = arr[85];
	V_TempLadderExp[916] = arr[84];
	V_TempLadderExp[917] = arr[83];
	V_TempLadderExp[918] = arr[82];
	V_TempLadderExp[919] = arr[81];
	V_TempLadderExp[920] = arr[80];
	V_TempLadderExp[921] = arr[79];
	V_TempLadderExp[922] = arr[78];
	V_TempLadderExp[923] = arr[77];
	V_TempLadderExp[924] = arr[76];
	V_TempLadderExp[925] = arr[75];
	V_TempLadderExp[926] = arr[74];
	V_TempLadderExp[927] = arr[73];
	V_TempLadderExp[928] = arr[72];
	V_TempLadderExp[929] = arr[71];
	V_TempLadderExp[930] = arr[70];
	V_TempLadderExp[931] = arr[69];
	V_TempLadderExp[932] = arr[68];
	V_TempLadderExp[933] = arr[67];
	V_TempLadderExp[934] = arr[66];
	V_TempLadderExp[935] = arr[65];
	V_TempLadderExp[936] = arr[64];
	V_TempLadderExp[937] = arr[63];
	V_TempLadderExp[938] = arr[62];
	V_TempLadderExp[939] = arr[61];
	V_TempLadderExp[940] = arr[60];
	V_TempLadderExp[941] = arr[59];
	V_TempLadderExp[942] = arr[58];
	V_TempLadderExp[943] = arr[57];
	V_TempLadderExp[944] = arr[56];
	V_TempLadderExp[945] = arr[55];
	V_TempLadderExp[946] = arr[54];
	V_TempLadderExp[947] = arr[53];
	V_TempLadderExp[948] = arr[52];
	V_TempLadderExp[949] = arr[51];
	V_TempLadderExp[950] = arr[50];
	V_TempLadderExp[951] = arr[49];
	V_TempLadderExp[952] = arr[48];
	V_TempLadderExp[953] = arr[47];
	V_TempLadderExp[954] = arr[46];
	V_TempLadderExp[955] = arr[45];
	V_TempLadderExp[956] = arr[44];
	V_TempLadderExp[957] = arr[43];
	V_TempLadderExp[958] = arr[42];
	V_TempLadderExp[959] = arr[41];
	V_TempLadderExp[960] = arr[40];
	V_TempLadderExp[961] = arr[39];
	V_TempLadderExp[962] = arr[38];
	V_TempLadderExp[963] = arr[37];
	V_TempLadderExp[964] = arr[36];
	V_TempLadderExp[965] = arr[35];
	V_TempLadderExp[966] = arr[34];
	V_TempLadderExp[967] = arr[33];
	V_TempLadderExp[968] = arr[32];
	V_TempLadderExp[969] = arr[31];
	V_TempLadderExp[970] = arr[30];
	V_TempLadderExp[971] = arr[29];
	V_TempLadderExp[972] = arr[28];
	V_TempLadderExp[973] = arr[27];
	V_TempLadderExp[974] = arr[26];
	V_TempLadderExp[975] = arr[25];
	V_TempLadderExp[976] = arr[24];
	V_TempLadderExp[977] = arr[23];
	V_TempLadderExp[978] = arr[22];
	V_TempLadderExp[979] = arr[21];
	V_TempLadderExp[980] = arr[20];
	V_TempLadderExp[981] = arr[19];
	V_TempLadderExp[982] = arr[18];
	V_TempLadderExp[983] = arr[17];
	V_TempLadderExp[984] = arr[16];
	V_TempLadderExp[985] = arr[15];
	V_TempLadderExp[986] = arr[14];
	V_TempLadderExp[987] = arr[13];
	V_TempLadderExp[988] = arr[12];
	V_TempLadderExp[989] = arr[11];
	V_TempLadderExp[990] = arr[10];
	V_TempLadderExp[991] = arr[9];
	V_TempLadderExp[992] = arr[8];
	V_TempLadderExp[993] = arr[7];
	V_TempLadderExp[994] = arr[6];
	V_TempLadderExp[995] = arr[5];
	V_TempLadderExp[996] = arr[4];
	V_TempLadderExp[997] = arr[3];
	V_TempLadderExp[998] = arr[2];
	V_TempLadderExp[999] = arr[1];

	for (INT i = 0; i < MAXLADDER; i++)
	{
		if(V_MyLadderStatus == 0)
		{
			if(V_TempLadderExp[i] == V_MyLadderExp)
			{
				strncpy_s(V_UpdLadderName[i], sizeof(V_UpdLadderName[i]), V_MyLadderName, sizeof(V_UpdLadderName[i]));
				V_UpdLadderID[i] = V_MyLadderID;
				V_UpdLadderLevel[i] = V_MyLadderLevel;
				V_UpdLadderClass[i] = V_MyLadderClass;
				V_UpdLadderExp[i] = V_MyLadderExp;
				V_UpdLadderRank[i] = V_MyLadderRank;
				strncpy_s(V_UpdLadderNote[i], sizeof(V_UpdLadderNote[i]), V_MyLadderNote, sizeof(V_UpdLadderNote[i]));

				V_MyLadderExp = -1;
			}
		}
		for (INT j = 0; j < MAXLADDER; j++)
		{
			if (V_TempLadderExp[i] == V_LadderExp[j])
			{
				strncpy_s(V_UpdLadderName[i], sizeof(V_UpdLadderName[i]), V_LadderName[j], sizeof(V_UpdLadderName[i]));
				V_UpdLadderID[i] = V_LadderID[j];
				V_UpdLadderLevel[i] = V_LadderLevel[j];
				V_UpdLadderClass[i] = V_LadderClass[j];
				V_UpdLadderExp[i] = V_LadderExp[j];
				V_UpdLadderRank[i] = V_LadderRank[j];
				strncpy_s(V_UpdLadderNote[i], sizeof(V_UpdLadderNote[i]), V_LadderNote[j], sizeof(V_UpdLadderNote[i]));

				V_LadderExp[j] = -1;
			}
		}
	}

	return FALSE;
}

BOOL CheckEntryColor(INT Entry)
{
	if(V_LadderID[Entry] == V_MyLadderID)
		return 0;

	if (V_LadderClass[Entry] > 400)
		return 5;

	return 4;
}

//
// Ladder thread commands
////
VOID LadderSaveCMD()
{
	while (V_BusyUpdData == TRUE)
	{
		SleepEx(250, TRUE);
	}

	V_BusyUpdData = TRUE;

	RegisterLadder();

	UpdateLadder();
	SortLadder();

	SaveLadder();

	LoadLadder();

	V_BusyUpdData = FALSE;

	Print(1, 9, "Player ladder saved.");
}

VOID LadderResetCMD()
{
	while (V_BusyUpdData == TRUE)
	{
		SleepEx(250, TRUE);
	}

	V_BusyUpdData = TRUE;

	for (INT i = 0; i < MAXLADDER; i++)
	{
		V_UpdLadderName[i][0] = NULL;
		V_UpdLadderID[i] = NULL;
		V_UpdLadderLevel[i] = NULL;
		V_UpdLadderClass[i] = -1;
		V_UpdLadderExp[i] = NULL;
		V_UpdLadderRank[i] = NULL;
		V_UpdLadderNote[i][0] = NULL;
	}

	SaveLadder();

	LoadLadder();

	V_BusyUpdData = FALSE;

	Print(1, 9, "Player ladder reset.");
}

VOID LadderSetNoteCMD()
{
	while (V_BusyUpdData == TRUE)
	{
		SleepEx(250, TRUE);
	}

	V_BusyUpdData = TRUE;

	RegisterLadder();

	UpdateLadder();
	SortLadder();

	SaveLadder();

	LoadLadder();

	V_BusyUpdData = FALSE;

	Print(1, 9, "Player note saved.");
}

VOID LadderDeleteNoteCMD()
{
	while (V_BusyUpdData == TRUE)
	{
		SleepEx(250, TRUE);
	}

	V_ResetLadderNote = TRUE;

	V_BusyUpdData = TRUE;

	RegisterLadder();

	UpdateLadder();
	SortLadder();

	SaveLadder();

	LoadLadder();

	V_BusyUpdData = FALSE;

	Print(1, 9, "Player note deleted.");
}