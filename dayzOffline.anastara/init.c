

void main()
{
	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();
	
	//GetCEApi().ExportProxyData("5120 0 5120", 10240);
	
	//GetCEApi().ExportClusterData();
	//GetCEApi().ExportProxyProto();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
}



class CustomMission: MissionServer
{
	
	override void OnInit()
    {
        super.OnInit();
        
        // Anastara Weather Events
        if ( m_EventManager )
        {
            // min time between events, max time between events, max number of events at the same time - 10 mins and 20 mins atm
            m_EventManager.Run( 600, 1200, 1 );
            // registering events and their probability
            m_EventManager.RegisterEvent( LXDThunderStorm, 0.2 );
            m_EventManager.RegisterEvent( LXDRainShower, 0.1 );
            m_EventManager.RegisterEvent( LXDCloudySkies, 0.2 );
            m_EventManager.RegisterEvent( LXDHeavyFog, 0.0 );
            m_EventManager.RegisterEvent( LXDClearSkies, 0.0 );
        }
	}

	
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.45, 0.65 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}
	
	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
		Class.CastTo( m_player, playerEnt );

		GetGame().SelectPlayer( identity, m_player );

		return m_player;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		EntityAI itemClothing;
		EntityAI itemEnt;
		ItemBase itemBs;
		float rand;

		itemClothing = player.FindAttachmentBySlotName( "Body" );
		if ( itemClothing )
		{
			SetRandomHealth( itemClothing );
			
			itemEnt = itemClothing.GetInventory().CreateInInventory( "BandageDressing" );
			player.SetQuickBarEntityShortcut(itemEnt, 2);

			string chemlightArray[] = { "Chemlight_White", "Chemlight_Yellow", "Chemlight_Green", "Chemlight_Red" };
			int rndIndex = Math.RandomInt( 0, 4 );
			itemEnt = itemClothing.GetInventory().CreateInInventory( chemlightArray[rndIndex] );
			player.SetQuickBarEntityShortcut(itemEnt, 1);
			SetRandomHealth( itemEnt );
		}
		
			//EntityAI bandage = player.GetInventory().CreateInInventory("BandageDressing");
			EntityAI tmap = player.GetInventory().CreateInInventory("ChernarusMap");
			EntityAI splum = player.GetInventory().CreateInInventory("Plum");
			
		
		itemClothing = player.FindAttachmentBySlotName( "Legs" );
		if ( itemClothing )
			SetRandomHealth( itemClothing );
		
		itemClothing = player.FindAttachmentBySlotName( "Feet" );
	}
	
	
	

	//override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	//{
	//	EntityAI itemTop;
	//	EntityAI itemEnt;
	//	ItemBase itemBs;
		
	//	ItemBase clothing;
		
	//	float rand;

	//	itemTop = player.FindAttachmentBySlotName("Body");
 
     //   if ( itemTop )
    //    {
    //        player.RemoveAllItems();
			
			
			
			
			
			
	//		itemEnt = player.GetInventory().CreateInInventory("PrisonUniformJacket");
	//		itemEnt = player.GetInventory().CreateInInventory("PrisonUniformPants");
	//		itemEnt = player.GetInventory().CreateInInventory("PrisonerCap");
	//		itemEnt = player.GetInventory().CreateInInventory("AthleticShoes_Grey");
			
			//player.GetHumanInventory().CreateInHands("HandcuffsLocked");
			
			
			//itemEnt = player.GetInventory().CreateInInventory("BallisticHelmet_Black");
			
			//itemEnt = player.GetInventory().CreateInInventory("BalaclavaMask_Black");
			//itemEnt = player.GetInventory().CreateInInventory("TacticalGoggles");
			//itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Black");
            //itemEnt = player.GetInventory().CreateInInventory("CargoPants_Black");
            //EntityAI belt = player.GetInventory().CreateInInventory("MilitaryBelt");
            //itemEnt = belt.GetInventory().CreateInInventory("Canteen");
            //itemEnt = belt.GetInventory().CreateInInventory("NylonKnifeSheath");
            //itemEnt = belt.GetInventory().CreateInInventory("PlateCarrierHolster_Black");
            //itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
            //itemEnt = player.GetInventory().CreateInInventory("CombatKnife"); 
            //EntityAI bag = player.GetInventory().CreateInInventory("DryBag_Black"); 
            //EntityAI jacket = player.GetInventory().CreateInInventory("M65Jacket_Khaki");  
			
            //EntityAI vest = player.GetInventory().CreateInInventory("PlateCarrierVest_Black"); 
			//EntityAI vest = player.GetInventory().CreateInInventory("PressVest_Blue"); 
			
            //EntityAI g1 = jacket.GetInventory().CreateInInventory("Magnum"); 
            //itemEnt = g1.GetInventory().CreateInInventory("PistolSuppressor"); 
            //itemEnt = g1.GetInventory().CreateInInventory("FNP45_MRDSOptic"); 
            //itemEnt = g1.GetInventory().CreateInInventory("TLRLight");
            //itemEnt = jacket.GetInventory().CreateInInventory("Mag_FNX45_15Rnd"); 
            //itemEnt = jacket.GetInventory().CreateInInventory("Mag_FNX45_15Rnd"); 
            //itemEnt = jacket.GetInventory().CreateInInventory("Mag_FNX45_15Rnd"); 
			
			//itemEnt = jacket.GetInventory().CreateInInventory("Ammo_357"); 
			//itemEnt = jacket.GetInventory().CreateInInventory("Ammo_357"); 
            
			
			//SVD
			//EntityAI g2 = player.GetInventory().CreateInInventory("SVD"); 
            //itemEnt = g2.GetInventory().CreateInInventory("AK_Suppressor");
            //itemEnt = g2.GetInventory().CreateInInventory("PSO1Optic");
			
			//itemEnt = jacket.GetInventory().CreateInInventory("Mag_Aug_30Rnd");
			//itemEnt = jacket.GetInventory().CreateInInventory("Mag_Aug_30Rnd");
			//itemEnt = jacket.GetInventory().CreateInInventory("Mag_Aug_30Rnd");
			//itemEnt = jacket.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
            //itemEnt = jacket.GetInventory().CreateInInventory("Mag_SVD_10Rnd");  
			//itemEnt = jacket.GetInventory().CreateInInventory("Mag_SVD_10Rnd"); 
			
			//MP5K
			//EntityAI g2 = player.GetInventory().CreateInInventory("MP5K"); 
			//itemEnt = g2.GetInventory().CreateInInventory("MP5_RailHndgrd");
			//itemEnt = g2.GetInventory().CreateInInventory("MP5k_StockBttstck");
			//itemEnt = g2.GetInventory().CreateInInventory("M68Optic");
			
			//EntityAI g2 = player.GetInventory().CreateInInventory("AK74"); 
			//itemEnt = g2.GetInventory().CreateInInventory("AK74_Hndgrd");
			//itemEnt = g2.GetInventory().CreateInInventory("AK74_WoodBttstck");
			//itemEnt = g2.GetInventory().CreateInInventory("KobraOptic");
			//itemEnt = jacket.GetInventory().CreateInInventory("Mag_AK74_30Rnd");
			//itemEnt = jacket.GetInventory().CreateInInventory("Mag_AK74_30Rnd");
			//itemEnt = jacket.GetInventory().CreateInInventory("Mag_AK74_30Rnd");
			
			//itemEnt = jacket.GetInventory().CreateInInventory("Mag_MP5_30Rnd");
			//itemEnt = jacket.GetInventory().CreateInInventory("Mag_MP5_30Rnd");
			
			//itemEnt = jacket.GetInventory().CreateInInventory("Ammo_762x54");
			
            //itemEnt = jacket.GetInventory().CreateInInventory("TacticalBaconCan_Opened"); 
			//EntityAI grenade = jacket.GetInventory().CreateInInventory("M67Grenade"); 
			//itemEnt = jacket.GetInventory().CreateInInventory("M67Grenade"); 
			//itemEnt = jacket.GetInventory().CreateInInventory("M67Grenade"); 
            //itemEnt = jacket.GetInventory().CreateInInventory("Battery9v"); 
            //itemEnt = jacket.GetInventory().CreateInInventory("Battery9v"); 
            //itemEnt = jacket.GetInventory().CreateInInventory("Battery9v"); 
			
			
			//EntityAI g3 = player.GetInventory().CreateInInventory("AugShort");
			//EntityAI g3 = player.GetInventory().CreateInInventory("B95");
			//EntityAI g3 = player.GetInventory().CreateInInventory("Mosin9130");
			//itemEnt = g3.GetInventory().CreateInInventory("PUScopeOptic");
			
			
		//	EntityAI bandage = player.GetInventory().CreateInInventory("BandageDressing");
		//	EntityAI tmap = player.GetInventory().CreateInInventory("ChernarusMap");
		//	EntityAI splum = player.GetInventory().CreateInInventory("Plum");
			
			
			
			
			
			//player.SetQuickBarEntityShortcut(g2, 0, true);
			//player.SetQuickBarEntityShortcut(g3, 1, true);
			//player.SetQuickBarEntityShortcut(g1, 2, true);
			//player.SetQuickBarEntityShortcut(grenade, 3, true);
			//player.SetQuickBarEntityShortcut(bandage, 4, true);
			
			
			
        //}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	//}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}