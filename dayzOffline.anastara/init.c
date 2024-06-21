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
};
Mission CreateCustomMission(string path)
{
	return new CustomMission();
}